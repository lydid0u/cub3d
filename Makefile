NAME    = cub
 
CC      = cc

CFLAGS  = -Wall -Wextra -Werror -g3 

RM      = rm -f

LIBFT          = libft

FT_LIBFT        = libft/libft.a

DIR_SRCS		=	srcs

DIR_OBJS		=	objs

SRCS_NAMES		=	main.c parsing_directions.c map_value.c utils.c game_map.c\
					gnl/get_next_line.c gnl/get_next_line_utils.c \

OBJS_NAMES		=	${SRCS_NAMES:.c=.o}

DEPS			=	${SRCS_NAMES:.c=.d}

SRCS			=	$(addprefix $(DIR_SRCS)/,$(SRCS_NAMES))

OBJS			=	$(addprefix $(DIR_OBJS)/,$(OBJS_NAMES))

HEAD	=	-I.

all : ${NAME}

${NAME} : ${DIR_OBJS} ${OBJS}
		${MAKE} -C ${LIBFT}
		${CC} ${OBJS} ${HEAD} -o ${NAME} ${FT_LIBFT} 
		@echo "\033[31;5mCUB\033[0m"

${OBJS} : ${DIR_OBJS}/%.o : ${DIR_SRCS}/%.c
	${CC} ${CFLAGS} ${HEAD} -c $< -o $@

$(DIR_OBJS):
	mkdir -p $(DIR_OBJS)
	mkdir -p objs/

clean :
	${RM} ${OBJS} 
	make clean -C libft

fclean : clean
	${RM} ${NAME} 
	make fclean -C libft
	${RM} ${FT_LIBFT}
	${RM} ${FT_PRINTF}

re : fclean all

-include $(DEPS)

.PHONY : all clean fclean re