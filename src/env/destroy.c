/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** destroy
*/

#include <stdlib.h>
#include "my.h"
#include "shell.h"

int delete_env(linked_list *env)
{
    env_t *current_env = NULL;

    back_to_start(&env);
    for (; env != NULL; env = env->next) {
        if (env->data == NULL)
            continue;
        current_env = env->data;
        free(current_env->NAME);
        free(current_env->PATH);
        free(current_env);
    }
    destroy_node(&env);
    return 0;
}
