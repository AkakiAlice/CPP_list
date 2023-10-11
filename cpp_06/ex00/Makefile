## COLORS ##

DEFAULT		=	\e[39m
GREEN		=	\e[92m
YELLOW		=	\e[93m
MAGENTA		=	\e[95m
CYAN		=	\e[96m

# **************************************************************************** #

NAME = convert

# COMPILATION #

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

# DELETE #

RM = rm -rf

# FILES #

FILES = main.cpp\
		ScalarConverter.cpp

# COMPILED_SOURCES #

OBJ_DIR = ./obj/
OBJS = $(addprefix $(OBJ_DIR), $(notdir $(FILES:.cpp=.o)))

# **************************************************************************** #

## RULES ##


$(OBJ_DIR)%.o: %.cpp
		@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
		@echo "\n$(CYAN)----------------------------------------"
		@echo "-------------- MAKE EX00 ---------------"
		@echo "----------------------------------------\n$(DEFAULT)"
		@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS): | $(OBJ_DIR)

$(OBJ_DIR):
		@mkdir $(OBJ_DIR)

clean:
		@$(RM) $(OBJ_DIR)

fclean: clean
		@$(RM) $(NAME)
		@echo "\n$(MAGENTA)----------------------------------------"
		@echo "------------- CLEANING DONE ------------"
		@echo "----------------------------------------\n$(DEFAULT)"

re: fclean all

.PHONY: all clean fclean re
