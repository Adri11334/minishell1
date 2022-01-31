/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** exit
*/

#include "shell.h"

int exit_shell(shell *my_sh, char **argv)
{
    if (my_sh == NULL || argv == NULL || argv[0] == NULL)
        return 84;
    my_sh->status = EXIT;
    return 0;
}
