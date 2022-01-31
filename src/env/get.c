/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** get
*/

#include "shell.h"

char *get_env(char *variable, linked_list *env)
{
    env_t *current = NULL;

    if (env == NULL || variable == NULL)
        return NULL;
    for (; env != NULL; env = env->next) {
        if (env->data == NULL)
            return NULL;
        current = env->data;
        if (my_strcmp(variable, current->NAME) == 0)
            return current->PATH;
    }
    return NULL;
}

char *get_from_char_env(char **env, char *variable)
{
    char **current_env = NULL;

    if (env == NULL || variable == NULL)
        return NULL;
    for (int i = 0; env[i] != NULL; i++) {
        if ((current_env = env_parser(env[i])) == NULL)
            return NULL;
        if (my_strcmp(variable, current_env[0]) == 0) {
            free(current_env[0]);
            free(current_env[1]);
            free(current_env);
            return env[i];
        }
    }
    return NULL;
}
