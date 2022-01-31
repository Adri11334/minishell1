/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** env_to_char
*/

#include "shell.h"

int boucle_env_to_char(int i, env_t *current_env, char **new_env)
{
    int name_l = 0;
    int path_l = 0;
    int name_size = my_strlen(current_env->NAME) + 1;
    int path_size = my_strlen(current_env->PATH) + 1;

    if ((new_env[i] = my_malloc(sizeof(char) * (name_size + path_size + 1),
    current_env->NAME)) == NULL)
        return 84;
    name_l = my_strlen(new_env[i]);
    new_env[i][name_l] = '=';
    path_l = name_l + 1;
    for (int j = 0; current_env->PATH[j] != '\0'; j++)
        new_env[i][path_l++] = current_env->PATH[j];
    return 0;
}

char **env_to_char(linked_list *env)
{
    char **new_env = my_malloc(sizeof(char *) * node_length(env) + 1, NULL);
    env_t *current_env = NULL;
    int index = 0;

    if (new_env == NULL || env == NULL)
        return NULL;
    back_to_start(&env);
    for (; env != NULL; env = env->next) {
        if (env->data == NULL)
            continue;
        current_env = env->data;
        if (current_env->NAME == NULL || current_env->PATH == NULL)
            continue;
        if (boucle_env_to_char(index, current_env, new_env) == 84)
            return NULL;
        index++;
    }
    new_env[index] = NULL;
    back_to_start(&env);
    return new_env;
}
