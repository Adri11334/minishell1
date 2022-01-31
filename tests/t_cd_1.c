/*
** EPITECH PROJECT, 2022
** shell
** File description:
** builtins cd tests 1
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "shell.h"

void redirect_all_stdout(void);

Test(test_cd_success, test_cd_success)
{
    shell *my_sh = my_malloc(sizeof(shell), NULL);
    char **args = my_malloc(sizeof(char *) * 2, NULL);
    args[0] = my_malloc(3, "cd");
    args[1] = my_malloc(4, "src");

    cr_assert_eq(change_directory(my_sh, args), 0);
    free_double_char(args);
    free(my_sh);
}

Test(test_cd_no_folder, test_cd_no_folder)
{
    shell *my_sh = my_malloc(sizeof(shell), NULL);
    char **args = my_malloc(sizeof(char *) * 2, NULL);
    args[0] = my_malloc(3, "cd");
    args[1] = my_malloc(5, "none");

    cr_assert_eq(change_directory(my_sh, args), 84);
    free_double_char(args);
}
