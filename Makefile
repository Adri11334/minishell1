##
## EPITECH PROJECT, 2021
## Project Generator
## File description:
## Autocreated Makefile
##

SRC			=	src/freezer.c					\
				src/put_error.c					\
				src/builtins/cd.c				\
				src/builtins/env.c				\
				src/builtins/exit.c				\
				src/builtins/pwd.c				\
				src/env/destroy.c				\
				src/env/get.c					\
				src/env/set.c					\
				src/shell/base_prompt.c			\
				src/shell/env_to_char.c			\
				src/shell/execute_cmd.c			\
				src/shell/wait_command.c		\

CRITERION	=	tests/t_redirect.c				\
				tests/t_base_prompt.c			\
				tests/t_cd_1.c					\
				tests/t_cd.c					\
				tests/t_env_1.c					\
				tests/t_env.c					\
				tests/t_exit.c					\
				tests/t_paths_determination.c	\
				tests/t_put_error.c				\
				tests/t_pwd.c					\

OBJ			=	$(SRC:.c=.o)

NAME		=	mysh

CFLAGS		+=	-W -Wall -Wextra -Werror -Wshadow -Wimplicit -pedantic

LDFLAGS		+=	-L./lib -lmy
CPPFLAGS	+=	-I./include/
CPPFLAGS	+=	-g

all:			lib	$(NAME)
PHONY		+=	all

lib:
				make -C ./lib/my
PHONY		+=	lib

$(NAME):		$(OBJ)
				gcc src/main.c $^ -o $@ -ggdb3 $(CPPFLAGS) $(LDFLAGS)

debug:			CPPFLAGS += -ggdb3
debug:			CPPFLAGS += -g
debug:			lib	$(OBJ)
				gcc src/main.c $(OBJ) -o $@ $(CPPFLAGS) $(LDFLAGS)
				valgrind ./$@
PHONY		+=	debug

tests_run:		CPPFLAGS += --coverage
tests_run:		CPPFLAGS += -lcriterion
tests_run:		lib
				gcc -o uts $(SRC) $(CRITERION) $(CPPFLAGS) $(LDFLAGS)
				-./uts
				rm -f uts
PHONY		+=	tests_run

cover:
				mkdir -p covr
				gcovr --exclude tests/ --html --html-details -o covr/cover.html
				gcovr --branches --exclude tests/
				make -C ./ clean
PHONY		+=	cover

clean:
				make -s -C ./lib/my clean
				@find . -type f | xargs touch
				@rm -f $(OBJ)
				@rm -f *.o
				@rm -f *~
				@rm -f vgcore*
				@rm -f #*
				@rm -f *.gcda
				@rm -f *.identifier
				@rm -f *.gcno
PHONY		+=	clean

fclean:			clean
				make -s -C ./lib/my fclean
				rm -f $(NAME)
				@rm -f covr/*.html
				@rm -f covr/*.css
				@rm -rf covr/
				@rm -f *Zone.Identifier
				@rm -f projet
				@rm -f *.gcno
PHONY		+=	fclean

my_tests: 		tests_run cover
PHONY		+=	my_tests

re:				fclean all
PHONY		+=	re

run:			all
				-./$(NAME)
PHONY		+=	run

.PHONY:			$(PHONY)