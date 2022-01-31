/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** shell
*/

#ifndef SHELL_H_
#define SHELL_H_
    #include "my.h"
    #include <stdlib.h>
    #include <dirent.h>

    typedef enum shell_status_s {
        RUNNING,
        EXIT
    } shell_status;

    typedef struct env_s {
        char *NAME;
        char *PATH;
    } env_t;

    typedef struct shell_s {
        int last_execution_result;
        shell_status status;
        linked_list *env;
    } shell;

    typedef struct commands_s
    {
        char *cmd;
        int (*function) (shell*, char**);
    } commands_t;

    int free_double_char(char **array);
    int put_error(char *str);

    int exit_shell(shell *my_sh, char **argv);

    void display_prompt(linked_list *env);

    char *get_from_char_env(char **env, char *variable);
    char *get_env(char *variable, linked_list *env);
    int display_env(shell *my_sh, char **argv);
    linked_list *set_my_env(char **base_env);
    int unset_env(shell *my_sh, char **argv);
    int set_env(shell *my_sh, char **argv);
    int delete_env(linked_list *env);
    char **env_parser(char *string);
    char **path_parsing(char *str);

    char **env_to_char(linked_list *env);

    int change_directory(shell *my_sh, char **argv);
    int show_pwd(shell *my_sh, char **argv);

    char *complete_path(char *t_path, char *binary);
    char *explore_paths(char *path, char *binary, DIR* dir,
    char *last_founded);
    char *get_binary_path(char *binary, char *PATH);
    int program_call(char *binary_path, char **argv, char **env);
    int execute_command(char *binary, char **argv, char **env);
    int wait_for_a_command(shell **sh);

#endif /* !SHELL_H_ */
