/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** put_error test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "shell.h"

void redirect_all_stdout(void);

Test(test_write_error, test_write_error)
{
    cr_assert_eq(put_error("test"), 84);
    redirect_all_stdout();
    cr_assert_stderr_eq_str("test");
}
