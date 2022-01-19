#==================================>COLORS<====================================#

_RED		=	\e[31m
_YELLOW		=	\e[33m
_GREEN		=	\e[32m
_END		=	\e[0m

#==================================>FILES<=====================================#

SRC			=	srcs/actions.c \
				srcs/allfree.c \
				srcs/compare_stack_b.c \
				srcs/continue_algoritm.c \
				srcs/doiflot.c \
				srcs/init.c \
				srcs/main.c \
				srcs/push_stack_a.c \
				srcs/push_types.c \
				srcs/stack_operation.c \
				srcs/stack_operation_2.c \
				srcs/start_algoritm.c

SRCS		=	${SRC}

SRC_BONUS	=	srcs_bonus/check_right.c \
				srcs_bonus/main.c \
				srcs_bonus/start_read.c \
				srcs/init.c \
				srcs/allfree.c \
				srcs/stack_operation.c \
				srcs/stack_operation_2.c

SRCS_BONUS	=	${SRC_BONUS}

#===============================>COMPILATIONS<=================================#

GCC			=	gcc

CFLAGS		=	-Wall -Werror -Wextra

#===================================>DELETE<===================================#

RM			=	rm -rf

#=================================>DIRECTORIES<================================#

DIR_HEAD	=	./includes

LIB_HEAD	=	./libft/libft.h

LIB			=	./libft/Libft.a

#===============================>COMPILED_SOURCES<=============================#

OBJS		=	${SRCS:%.c=%.o}

OBJS_BONUS	=	${SRCS_BONUS:%.c=%.o}

NAME		=	push_swap

NAME_BONUS	=	checker

#================================>COMPILED_RULES<==============================#

all:			${NAME}

${NAME}:		${OBJS}
				@${MAKE} -C ./libft
				@${GCC} ${CFLAG} -o ${NAME} ${OBJS} ${LIB}
				@printf "\033[2K\r${_GREEN} File create: '${NAME}'. ${_END}✅\n"

#===========================>COMPILED_SOURCES_RULES<===========================#

%.o:			%.c
				@$(GCC) $(CFLAGS) -I $(DIR_HEAD) -I $(DIR_HEAD) -c $< -o $@
				@printf "\033[2K\r$(_YELLOW) Compiling $< $(_END)⌛"

#===================================>NORM_RULES<===============================#

norm:
				@norminette .

#==================================>BONUS_RULES<===============================#

bonus:			${NAME_BONUS}

${NAME_BONUS}:	${OBJS_BONUS}
				@${MAKE} -C ./libft
				@${GCC} ${CFLAG} -o ${NAME_BONUS} ${OBJS_BONUS} ${LIB}
				@printf "\033[2K\r${_GREEN} File create: '${NAME_BONUS}'. ${_END}✅\n"

#====================================>CLEAN_RULES<=============================#

clean:
				@make clean -C ./libft
				@rm -f ${OBJS}
				@rm -f ${OBJS_BONUS}
				@printf "\033[2K\r${_RED} '".o"' has been deleted. ${_END}🗑️\n"

fclean:			clean
				@make fclean -C ./libft
				@rm -f ${NAME}
				@rm -f ${NAME_BONUS}
				@printf "\033[2K\r${_RED} '"${NAME}"' has been deleted. ${_END}🗑️\n"
				@printf "\033[2K\r${_RED} '"${NAME_BONUS}"' has been deleted. ${_END}🗑️\n"

re:				fclean all

.PHONY: all clean fclean re