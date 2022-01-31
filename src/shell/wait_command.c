/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** wait_command
*/

#include <unistd.h>
#include <stdio.h>

#include "shell.h"

const commands_t bi_cmd[] = {
    { "cd", &change_directory },
    { "setenv", &set_env },
    { "unsetenv", &unset_env },
    { "env", &display_env },
    { "exit", &exit_shell },
    { "pwd", &show_pwd },
};

char *get_input(void)
{
    size_t line_size = 0;
    char *input = NULL;
    int length = 0;

    if (getline(&input, &line_size, stdin) == -1)
        return NULL;
    if (input[0] == '\0')
        return NULL;
    length = my_strlen(input);
    input[length - 1] = '\0';
    return input;
}

int send_command(shell *my_sh, char **commands)
{
    int is_builtin = 0;

    for (int i = 0; i < 6; i++)
        if (my_strcmp(commands[0], bi_cmd[i].cmd) == 0) {
            is_builtin++;
            return bi_cmd[i].function(my_sh, commands);
        }
    return execute_command(commands[0], commands, env_to_char(my_sh->env));
}

int wait_for_a_command(shell **my_sh)
{
    char *input = NULL;
    char **command = NULL;

    if ((*my_sh) == NULL || (*my_sh)->status != RUNNING)
        return -1;
    display_prompt((*my_sh)->env);
    if ((input = get_input()) == NULL) {
        (*my_sh)->status = EXIT;
        return 0;
    }
    if ((command = my_str_to_words_array(input, (char[]){' ', '\t'})) == NULL)
        return 84;
    (*my_sh)->last_execution_result = send_command((*my_sh), command);
    free(input);
    return 0;
}
