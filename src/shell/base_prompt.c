/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** base_prompt
*/

#include <unistd.h>

#include "shell.h"

void display_prompt(linked_list *env)
{
    char *cwd = my_malloc(256, NULL);

    if (env == NULL || cwd == NULL) {
        my_putstr("$ > ");
        free(cwd);
        return;
    }
    getcwd(cwd, 256);
    write_purple(get_env("XDG_SESSION_CLASS", env));
    write_white("@");
    write_purple(get_env("LOGNAME", env));
    write_white(": ");
    write_blue(cwd);
    write_green(" % ");
    free(cwd);
}
