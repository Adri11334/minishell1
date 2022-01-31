/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** set
*/

#include <stdlib.h>
#include "shell.h"

char **env_parser(char *string)
{
    char *str_1 = NULL;
    char *str_2 = NULL;
    char **env = malloc(sizeof(char *) * 2);
    int str_index = 0;

    if ((str_1 = my_malloc(my_strlen(string) + 1, NULL)) == NULL
    || (str_2 = my_malloc(my_strlen(string) + 1, NULL)) == NULL)
        return NULL;
    while (string[str_index] != '=') {
        str_1[str_index] = string[str_index];
        str_index++;
    }
    str_index++;
    for (int i = 0; string[str_index] != '\0'; i++) {
        str_2[i] = string[str_index];
        str_index++;
    }
    env[0] = str_1;
    env[1] = str_2;
    return env;
}

void temp_free_ac(char **ac_env)
{
    free(ac_env[0]);
    free(ac_env[1]);
    free(ac_env);
}

linked_list *set_my_env(char **base_env)
{
    linked_list *my_env = NULL;
    env_t *current_env = NULL;
    char **ac_env = NULL;
    int env_length = 0;

    while (base_env[env_length] != NULL)
        env_length++;
    if ((my_env = my_malloc(sizeof(char *) * (env_length + 1), NULL)) == NULL)
        return NULL;
    for (int i = 0; i < env_length; i++) {
        if ((current_env = my_malloc(sizeof(env_t), NULL)) == NULL)
            return NULL;
        if ((ac_env = env_parser(base_env[i])) == NULL)
            return NULL;
        current_env->PATH = my_malloc(my_strlen(ac_env[1]) + 1, ac_env[1]);
        current_env->NAME = my_malloc(my_strlen(ac_env[0]) + 1, ac_env[0]);
        temp_free_ac(ac_env);
        push_node(&my_env, current_env);
    }
    return my_env;
}
