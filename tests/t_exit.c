/*
** EPITECH PROJECT, 2022
** shell
** File description:
** builtins exit tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "shell.h"

void redirect_all_stdout(void);

Test(test_exit_success, test_exit_success)
{
    shell *my_sh = my_malloc(sizeof(shell), NULL);
    char **args = my_malloc(sizeof(char *) * 1, NULL);
    args[0] = my_malloc(5, "exit");

    cr_assert_eq(exit_shell(my_sh, args), 0);
    free_double_char(args);
    free(my_sh);
}

Test(test_exit_fail_no_sh, test_exit_fail_no_sh)
{
    char **args = my_malloc(sizeof(char *) * 1, NULL);
    args[0] = my_malloc(5, "exit");

    cr_assert_eq(exit_shell(NULL, args), 84);
    free_double_char(args);
}

Test(test_exit_fail_no_args, test_exit_fail_no_args)
{
    shell *my_sh = my_malloc(sizeof(shell), NULL);
    char **args = my_malloc(sizeof(char *) * 1, NULL);
    args[0] = NULL;

    cr_assert_eq(exit_shell(my_sh, args), 84);
    free_double_char(args);
    free(my_sh);
}

Test(test_exit_fail_no_args_2, test_exit_fail_no_args_2)
{
    shell *my_sh = my_malloc(sizeof(shell), NULL);

    cr_assert_eq(exit_shell(my_sh, NULL), 84);
    free(my_sh);
}
