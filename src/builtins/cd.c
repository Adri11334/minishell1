/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** cd command
*/

#include<unistd.h>
#include "shell.h"

int change_directory(shell *my_sh, char **argv)
{
    char cwd[256];

    if (my_sh == NULL)
        return put_error("cd: invalid sh. Please restart the program.");
    if (argv == NULL)
        return 84;
    if (argv[1] == NULL && chdir(get_env("HOME", my_sh->env)) == 0)
        return 0;
    if (chdir(argv[1]) != 0) {
        my_printf("cd: no such file or directory: %s", argv[1]);
        return 84;
    } else
        if (getcwd(cwd, sizeof(cwd)) == NULL)
            return put_error("cd: getcwd failed.");
    return 0;
}
