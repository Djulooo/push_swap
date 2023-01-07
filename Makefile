.PHONY:		all re clean fclean

SRCS	=	push_swap.c	ps_small_list.c	\
			ps_split.c	\
			ps_utils_list.c	ps_utils.c	ps_stack_utils.c	\
			ps_fill_stack_a.c	ps_oper_stack_bis.c	ps_oper_stack.c	ps_sort_stack.c

OBJS	=	${SRCS:.c=.o}

FLAGS	=	-Wall -Wextra -Werror

LIB		=	${AR} rc

HEADER	=	push_swap.h

NAME	=	push_swap.a

all:		${NAME} Makefile

%.o:		%.c ${HEADER} Makefile
			${CC} ${FLAGS} -I${HEADER} -c $< -o $@

${NAME}:	${OBJS}
			${LIB} $@ ${OBJS} push_swap.a
			${CC} ${FLAGS} $@ -o push_swap

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}
			${RM} push_swap

re:			fclean all