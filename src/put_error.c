/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** put_error
*/

#include "my.h"
#include <unistd.h>

int put_error(char *str)
{
    write(2, str, my_strlen(str));;
    return 84;
}
