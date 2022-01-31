/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** execute_cmd
*/

#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#include "shell.h"

char *complete_path(char *t_path, char *binary)
{
    char *exec_path = NULL;
    int binary_l = my_strlen(binary);
    int cmpl_i = my_strlen(t_path);

    if ((exec_path = my_malloc((cmpl_i + binary_l) + 2, t_path)) == NULL)
        return NULL;
    if (cmpl_i == 0) {
        exec_path[0] = '.';
        exec_path[1] = '/';
        cmpl_i += 2;
    } else {
        exec_path[cmpl_i] = '/';
        cmpl_i++;
    }
    for (int i = 0; binary[i] != '\0'; i++) {
        exec_path[cmpl_i] = binary[i];
        cmpl_i++;
    }
    free(t_path);
    return exec_path;
}

char *explore_paths(char *path, char *binary, DIR* dir, char *last_founded)
{
    struct dirent *file = NULL;

    while ((file = readdir(dir)) != NULL)
        if (my_strcmp(binary, file->d_name) == 0)
            return path;
    return last_founded;
}

char *get_binary_path(char *binary, char *PATH)
{
    DIR *dir = NULL;
    char *t_path = NULL;
    char **paths = NULL;

    if (binary == NULL || PATH == NULL)
        return NULL;
    if ((paths = my_str_to_words_array(PATH, (char[]){ '=', ':' })) == NULL)
        return NULL;
    for (int i = 0; paths[i] != NULL; i++)
        if ((dir = opendir(paths[i])) != NULL)
            t_path = explore_paths(paths[i], binary, dir, t_path);
    if (t_path == NULL)
        return NULL;
    free(PATH);
    return complete_path(t_path, binary);
}

int program_call(char *binary_path, char **argv, char **env)
{
    pid_t child_id = 0;
    int execution_result;

    if (binary_path == NULL || *env == NULL)
        return 84;
    if ((child_id = fork()) == -1)
        my_printf("minishell -> %s: can't create new child.\n", binary_path);
    else if (child_id == 0) {
        execution_result = execve(binary_path, argv, env);
        exit(1);
    } else {
        waitpid(child_id, &execution_result, 0);
        if (WEXITSTATUS(execution_result) != 0)
            my_printf("%s: %s\n", binary_path,
            strerror(WEXITSTATUS(execution_result)));
    }
    return WEXITSTATUS(execution_result);
}

int execute_command(char *binary, char **argv, char **env)
{
    char *binary_path = NULL;
    int prog_return = 0;

    if (!binary || !env)
        return 84;
    if ((binary_path = get_binary_path(binary,
    get_from_char_env(env, "PATH"))) == NULL)
        binary_path = binary;
    prog_return = program_call(binary_path, argv, env);
    if (my_strcmp(binary_path, binary) != 0)
        free(binary_path);
    return prog_return;
}
