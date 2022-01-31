/*
** EPITECH PROJECT, 2022
** shell
** File description:
** builtins pwd tetst
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "shell.h"

void redirect_all_stdout(void);

Test(test_pwd_success, test_pwd_success)
{
    shell *my_sh = my_malloc(sizeof(shell), NULL);
    char **args = my_malloc(sizeof(char *) * 1, NULL);
    args[0] = my_malloc(4, "pwd");

    cr_assert_eq(show_pwd(my_sh, args), 0);
    free_double_char(args);
    free(my_sh);
}

Test(test_pwd_fail_no_sh, test_pwd_fail_no_sh)
{
    char **args = my_malloc(sizeof(char *) * 1, NULL);
    args[0] = my_malloc(4, "pwd");

    cr_assert_eq(show_pwd(NULL, args), 84);
    free_double_char(args);
}

Test(test_pwd_fail_no_args, test_pwd_fail_no_args)
{
    shell *my_sh = my_malloc(sizeof(shell), NULL);
    char **args = my_malloc(sizeof(char *) * 1, NULL);
    args[0] = NULL;

    cr_assert_eq(show_pwd(my_sh, args), 84);
    free_double_char(args);
    free(my_sh);
}

Test(test_pwd_fail_no_args_2, test_pwd_fail_no_args_2)
{
    shell *my_sh = my_malloc(sizeof(shell), NULL);

    cr_assert_eq(show_pwd(my_sh, NULL), 84);
    free(my_sh);
}
