# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: pniezen <pniezen@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2022/03/08 13:54:39 by pniezen       #+#    #+#                  #
#    Updated: 2022/04/15 10:53:54 by pniezen       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SRC_PATH = ./src/
OBJ_PATH = ./obj/
INC_PATH = ./include/ ./lib/libft/include/
LIB_PATH = ./lib/libft/

NAME_SERVER = server
NAME_CLIENT = client

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SERVER_SRC_NAME = server.c utils.c error_msg.c
CLIENT_SRC_NAME = client.c utils.c error_msg.c

SERVER_OBJ = $(addprefix $(OBJ_PATH), $(SERVER_SRC_NAME:.c=.o))
CLIENT_OBJ = $(addprefix $(OBJ_PATH), $(CLIENT_SRC_NAME:.c=.o))

LIB_NAME = libft.a

INC = $(addprefix -I, $(INC_PATH))
LIB = $(LIB_PATH)$(LIB_NAME)

BOLD = \033[1m
GREEN = \033[32;1m
RED	= \033[31;1m
YELLOW	= \033[33;1m
RESET = \033[0m

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(SERVER_OBJ)
	@make -C $(LIB_PATH)
	@$(CC) $(CFLAGS) $(LIB) $(INC) $(SERVER_OBJ) -o $(NAME_SERVER) && printf "$(YELLOW)$(BOLD)\rBuild $(NAME_SERVER)\r\e[35C[OK]\n$(RESET)"

$(NAME_CLIENT): $(CLIENT_OBJ)
	@make -C $(LIB_PATH)
	@$(CC) $(CFLAGS) $(LIB) $(INC) $(CLIENT_OBJ) -o $(NAME_CLIENT) && printf "$(YELLOW)$(BOLD)\rBuild $(NAME_CLIENT)\r\e[35C[OK]\n$(RESET)"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $< && printf "$(GREEN)$(BOLD)\rCompiling: $(notdir $<)\r\e[35C[OK]\n$(RESET)"

cleanlib:
	@make -C $(LIB_PATH) clean

fcleanlib:
	@make -C $(LIB_PATH) fclean

clean: cleanlib
	@echo "$(RED)Cleaning$(RESET)"
	@rm -f $(OBJ)
	@rm -rf $(OBJ_PATH)

fclean: clean fcleanlib
	@rm -fv $(NAME_SERVER) $(NAME_CLIENT)

re: fclean all

.PHONY: clean fclean re all
