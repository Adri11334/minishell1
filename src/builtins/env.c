/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** env
*/

#include "shell.h"

int display_env(shell *my_sh, char **argv)
{
    linked_list *env = my_sh->env;
    env_t *current_env = NULL;

    if (argv[0] == NULL)
        return 84;
    go_to_last(&env);
    for (; env != NULL; env = env->prev) {
        if (env->data == NULL)
            continue;
        current_env = env->data;
        my_printf("%s=%s\n", current_env->NAME, current_env->PATH);
    }
    back_to_start(&env);
    return 0;
}

int unset_env(shell *my_sh, char **argv)
{
    linked_list *env = my_sh->env;
    env_t *current_env = NULL;

    if (env == NULL || argv[1] == NULL)
        return put_error("Unsetenv: Too few arguments");
    back_to_start(&env);
    for (; env != NULL; env = env->next) {
        if (env->data == NULL)
            continue;
        current_env = env->data;
        if (my_strcmp(current_env->NAME, argv[1]) == 0) {
            free(current_env->NAME);
            free(current_env->PATH);
            delete_node(&env, env);
        }
    }
    back_to_start(&env);
    return 0;
}

int set_env(shell *my_sh, char **argv)
{
    linked_list *env = my_sh->env;
    env_t *new_env = NULL;

    if (argv[1] == NULL || argv[2] == NULL)
        return display_env(my_sh, argv);
    if ((new_env = my_malloc(sizeof(env_t), NULL)) == NULL)
        return 84;
    if ((new_env->PATH = my_malloc(my_strlen(argv[2]) + 1, argv[2])) == NULL)
        return 84;
    if ((new_env->NAME = my_malloc(my_strlen(argv[1]) + 1, argv[1])) == NULL)
        return 84;
    push_node(&env, new_env);
    return 0;
}
