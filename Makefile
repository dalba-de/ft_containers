# COLORS #

# This is a minimal set color codes
_END		=	\033[0m
_BOLD		=	\033[1m
_UNDER		=	\033[4m
_REV		=	\033[7m

# Colors
_GREY		=	\033[30m
_RED		=	\033[31m
_GREEN		=	\033[32m
_YELLOW		=	\033[33m
_BLUE		=	\033[34m
_PURPLE		=	\033[35m
_CYAN		=	\033[36m
_WHITE		=	\033[37m

# Inverted, i.e. colored backgrounds
_IGREY		=	\033[40m
_IRED		=	\033[41m
_IGREEN		=	\033[42m
_IYELLOW	=	\033[43m
_IBLUE		=	\033[44m
_IPURPLE	=	\033[45m
_ICYAN		=	\033[46m
_IWHITE		=	\033[47m

# **************************************************************************** #

NAME = tester

CC = @c++

FLAGS = -Wall -Werror -Wextra

SRC_DIR = Test/

OBJ_DIR = objects/

SRC = Test.cpp ListTest.cpp VectorTest.cpp MapTest.cpp QueueTest.cpp StackTest.cpp

OBJ = $(addprefix ${OBJ_DIR}, ${SRC:.cpp=.o})

all:	${NAME}

${NAME}:		${OBJ}
			@echo "$(_CYAN) All files compiled. $(_END)✅"
			${CC} ${FLAGS} ${OBJ} -o ${NAME}
			@echo "$(_CYAN) Executable $(_BOLD)$(_CYAN)'$(NAME)'$(_END)$(_CYAN) compiled. $(_END)✅"

${OBJ_DIR}%.o: ${SRC_DIR}%.cpp
	@mkdir -p ${OBJ_DIR}
	${CC} ${FLAGS} -o $@ -c $<

clean:
		@rm -f ${OBJ}
		@rm -rf ${OBJ_DIR}
		@echo "$(_RED)$(_BOLD)'"$(OBJ_DIR)"'$(_END)$(_RED)has been deleted. $(_END)🗑️"

fclean:	clean
		@rm -f ${NAME}
		@echo "$(_RED)$(_BOLD)'"$(NAME)"'$(_END)$(_RED) has been deleted. $(_END)🗑️"

re: fclean all

# **************************************************************************** #

# TEST #

run:	all
		@clear
		"./tester"

.PHONY:	clean fclean all re