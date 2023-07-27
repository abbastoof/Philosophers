# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/24 14:29:40 by atoof             #+#    #+#              #
#    Updated: 2023/07/27 15:12:15 by atoof            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SRC_DIR = src/
SRC = main.c checker.c ft_atoi.c ft_isdigit.c init_data.c \
		free_malloc.c create_threads.c time_utils.c monitoring.c
SRCS = $(addprefix $(SRC_DIR), $(SRC))
HEADER_DIR = header/
HEADER = philo.h
OBJ_DIR = obj/
OBJS = $(SRCS:%.c=$(OBJ_DIR)%.o)
FLAGS = -Wall -Werror -Wextra -pthread #-fsanitize=thread

# ANSI escape sequences for text formatting
BOLD = \033[1m
GREEN = \033[0;32m
YELLOW = \033[0;33m
CYAN = \033[0;36m
NC = \033[0m

vpath %.c $(SRC_DIR) $(BUILT_IN_DIR) $(LEXER_D) $(UTILS_D)
vpath %.h $(HEADER_DIR)

all: $(NAME)

$(NAME): $(OBJS)
	@if [ -f $(NAME) ] && [ "$(OBJS)" -ot "$(NAME)" ]; then \
		echo "$(GREEN)$(BOLD)$(NAME) is already up-to-date!$(NC)"; \
	else \
		echo "$(YELLOW)$(BOLD)Compiling $(NAME)...$(NC)"; \
		cc $(FLAGS) $(OBJS) -I$(HEADER_DIR) -o $@ ; \
		echo "$(GREEN)$(BOLD)$(NAME) successfully compiled!$(NC)"; \
	fi

$(OBJ_DIR)%.o: %.c $(HEADER_DIR)$(HEADER)
	@echo "$(YELLOW)$(BOLD)Compiling $<...$(NC)"
	@mkdir -p $(@D)
	@cc $(FLAGS) -I$(HEADER_DIR) -c -o $@ $<

clean:
	@echo "$(CYAN)$(BOLD)Cleaning object files...$(NC)"
	@/bin/rm -rf $(OBJ_DIR)

fclean: clean
	@echo "$(CYAN)$(BOLD)Cleaning $(NAME)...$(NC)"
	@/bin/rm -f $(NAME)
	@echo "$(GREEN)$(BOLD)$(NAME) successfully cleaned!$(NC)"

re: fclean all

