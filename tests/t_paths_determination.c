/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** paths_determination tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "shell.h"

void redirect_all_stdout(void);

Test(test_complete_path, test_complete_path)
{
    char *t_path = my_malloc(5, "/bin");
    char *binary = my_malloc(3, "ls");
    char *exec_path = complete_path(t_path, binary);

    cr_assert_eq(my_strcmp(exec_path, "/bin/ls"), 0);
}

Test(test_complete_path_cudir, test_complete_path_cudir)
{
    char *binary = my_malloc(3, "ls");
    char *exec_path = complete_path(NULL, binary);

    cr_assert_eq(my_strcmp(exec_path, "./ls"), 0);
}

Test(test_get_bin_path, test_get_bin_path)
{
    char *PATH = my_malloc(13, "PATH=./tests");
    char *binary = my_malloc(5, "cd.c");
    char *exec_path = get_binary_path(binary, PATH);

    cr_assert_eq(my_strcmp(exec_path, "./tests/cd.c"), 0);
}

Test(test_get_bin_no_path, test_get_bin_non_path)
{
    char *PATH = my_malloc(17, "PATH=/empty_pass");
    char *binary = my_malloc(5, "cd.c");
    char *exec_path = get_binary_path(binary, PATH);

    cr_assert_eq(my_strcmp(exec_path, "./cd.c"), 0);
}

Test(test_get_bin_null, test_get_bin_null)
{
    char *exec_path = get_binary_path(NULL, NULL);

    cr_assert_eq(my_strcmp(exec_path, NULL), 0);
}
