/*
** EPITECH PROJECT, 2022
** shell
** File description:
** env tests 1
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "shell.h"

void redirect_all_stdout(void);

Test(test_set_env, test_set_env)
{
    char **env = my_malloc(sizeof(char *) * 2, NULL);
    env[0] = my_malloc(9, "tata=toto");
    env[1] = my_malloc(8, "test=oui");
    linked_list *new_env = set_my_env(env);
    env_t *current_env = new_env->data;

    cr_assert_eq(my_strcmp(current_env->NAME, "test"), 0);
    free_double_char(env);
    delete_env(new_env);
}

Test(test_env_to_char, test_env_to_char)
{
    char **env = my_malloc(sizeof(char *) * 2, NULL);
    env[0] = my_malloc(9, "tata=toto");
    env[1] = my_malloc(8, "test=oui");
    linked_list *new_env = set_my_env(env);
    char **my_env = env_to_char(new_env);

    cr_assert_eq(my_strcmp(my_env[0], "test=oui"), 0);
    cr_assert_eq(my_strcmp(my_env[1], "tata=toto"), 0);
    free_double_char(env);
    delete_env(new_env);
}
