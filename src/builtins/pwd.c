/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** pwd command
*/

#include <unistd.h>

#include "shell.h"

int show_pwd(shell *my_sh, char **argv)
{
    char *cwd = my_malloc(256, NULL);

    if (my_sh == NULL || argv == NULL || argv[0] == NULL)
        return 84;
    getcwd(cwd, 256);
    my_putstr(cwd);
    my_putchar('\n');
    free(cwd);
    return 0;
}
