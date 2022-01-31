/*
** EPITECH PROJECT, 2021
** Project Generator
** File description:
** Autocreated main File
*/

#include "shell.h"

int display_help(void);

int main(int argc, char **argv, char **env)
{
    shell *my_sh = my_malloc(sizeof(shell), NULL);
    int return_status = -4;

    if (*env == NULL || my_sh == NULL)
        return put_error("FATAL ERROR: sh can't be loaded, maybe no env set.");
    if ((my_sh->env = set_my_env(env)) == NULL)
        return put_error("FATAL ERROR: can't set environment.");
    my_sh->status = RUNNING;
    my_sh->last_execution_result = 0;
    while (my_sh->status == RUNNING)
        wait_for_a_command(&my_sh);
    return_status = my_sh->last_execution_result;
    delete_env(my_sh->env);
    free(my_sh);
    return return_status;
}
