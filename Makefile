SRCS	= srcs/ft_error.c srcs/ft_list_utils.c srcs/ft_push_and_swap.c srcs/ft_reverse_rotate.c srcs/ft_rotate.c srcs/ft_sort_three.c srcs/ft_sorting.c srcs/ft_split.c srcs/ft_turk.c srcs/ft_turk_rushb.c srcs/ft_turk_utils.c srcs/ft_turk_utils_a.c srcs/ft_turk_utils_b.c srcs/libft.c srcs/ft_stack_init.c
OBJ_DIR	= srcs/
OBJS	= $(%.c,$(OBJ_DIR)%.o,$(SRCS))
MAIN	= srcs/main.c
CFLAGS		= -Wextra -Werror -Wall
CC			= cc
RM			= rm -f
NAME	= push_swap

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${MAIN} ${OBJS} -o push_swap

.c.o:
	${CC} ${CFLAGS} -c $< -o $@

clean: 
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re

