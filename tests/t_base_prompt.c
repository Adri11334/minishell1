/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** base_prompt test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "shell.h"

void redirect_all_stdout(void);

Test(test_prompt_error, test_prompt_error)
{
    display_prompt(NULL);
    redirect_all_stdout();
    cr_assert_stdout_eq_str("$ > ");
}

Test(test_prompt, test_prompt)
{
    char **env = my_malloc(sizeof(char *) * 2, NULL);
    env[0] = my_malloc(23, "XDG_SESSION_CLASS=toto");
    env[1] = my_malloc(12, "LOGNAME=oui");
    linked_list *new_env = set_my_env(env);

    display_prompt(new_env);
    redirect_all_stdout();
    cr_assert_stdout_neq_str("$ > ");
}
