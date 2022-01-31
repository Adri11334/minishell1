/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** freezer
*/

#include "shell.h"

int free_double_char(char **array)
{
    if (array == NULL)
        return -1;
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
    return 0;
}
