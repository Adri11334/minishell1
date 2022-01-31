/*
** EPITECH PROJECT, 2022
** shell
** File description:
** env tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "shell.h"

void redirect_all_stdout(void);

Test(test_one_env_to_char, test_one_env_to_char)
{
    char **env = my_malloc(sizeof(char *) * 2, NULL);
    env[0] = my_malloc(9, "tata=toto");
    env[1] = my_malloc(8, "test=oui");
    linked_list *new_env = set_my_env(env);
    char **my_env = env_to_char(new_env);
    char *spec_env = get_from_char_env(my_env, "tata");

    cr_assert_eq(my_strcmp(spec_env, "tata=toto"), 0);
    free_double_char(env);
    delete_env(new_env);
}

Test(test_one_env_var_to_char, test_one_env_var_to_char)
{
    char **env = my_malloc(sizeof(char *) * 2, NULL);
    env[0] = my_malloc(9, "tata=toto");
    env[1] = my_malloc(8, "test=oui");
    linked_list *new_env = set_my_env(env);
    char *spec_env = get_env("tata", new_env);

    cr_assert_eq(my_strcmp(spec_env, "toto"), 0);
    free_double_char(env);
    delete_env(new_env);
}

Test(test_one_env_var_to_char_fail, test_one_env_var_to_char_fail)
{
    char *spec_env = get_env("tata", NULL);

    cr_assert_eq(my_strcmp(spec_env, "toto"), 84);
}

Test(test_one_env_var_to_char_fail_2, test_one_env_var_to_char_fail_2)
{
    char *spec_env = get_env("tata", NULL);

    cr_assert_eq(my_strcmp(spec_env, NULL), 84);
}

