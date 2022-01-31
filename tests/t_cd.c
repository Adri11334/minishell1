/*
** EPITECH PROJECT, 2022
** shell
** File description:
** builtins cd tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "shell.h"

void redirect_all_stdout(void);

Test(test_cd_no_args, test_cd_no_args)
{
    shell *my_sh = my_malloc(sizeof(shell), NULL);

    cr_assert_eq(change_directory(my_sh, NULL), 84);
    free(my_sh);
}

Test(test_cd_not_enough_args, test_cd_not_enough_args)
{
    shell *my_sh = my_malloc(sizeof(shell), NULL);
    char **env = my_malloc(sizeof(char *) * 1, NULL);
    env[0] = my_malloc(9, "HOME=/");
    my_sh->env = set_my_env(env);
    char **args = my_malloc(sizeof(char *) * 2, NULL);
    args[0] = my_malloc(3, "cd");
    args[1] = NULL;

    cr_assert_eq(change_directory(my_sh, args), 0);
    free_double_char(args);
    free(my_sh);
}

Test(test_cd_no_sh, test_cd_no_sh)
{
    cr_assert_eq(change_directory(NULL, NULL), 84);
}
