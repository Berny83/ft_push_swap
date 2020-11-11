# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/03 18:03:52 by aagrivan          #+#    #+#              #
#    Updated: 2020/11/11 19:46:04 by aagrivan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME_C = checker
NAME_P = push_swap

CC = gcc

FLAGS = -Wall -Wextra -Werror -g

SRCS_DIR = srcs/
SRCS =	push_swap.c\
		validate.c\
		is_duplicate.c\
		sort.c\
		sort_5.c\
		sort_100_500.c\
		chunk_a.c\
		chunk_b.c\
		sw_pp.c\
		sw_rr.c\
		sw_rrr.c\
		sw_ss.c\
		util.c
SRCS_P = $(addprefix $(SRCS_DIR),$(SRCS))

HEAD_DIR = includes/
HEAD =	push_struct.h\
		push_swap.h
HEAD_P = $(addprefix $(HEAD_DIR),$(HEAD))

OBJDIR = obj/
OBJ_P = $(addprefix $(OBJDIR),$(SRCS:%.c=%.o))

LIBFT = libft/
LFLAGS = -L $(LIBFT) -lft

vpath %.c srcs libft
vpath %.h includes

# COLOR
GREEN = \033[0;32m
RED = \033[0;31m
BASE = \033[0m

all: $(NAME_P)

$(NAME_P): $(OBJ_P)
	@make -C $(LIBFT)
	@$(CC) $(FLAGS) $(OBJ_P) $(LFLAGS) -o $(NAME_P)
	@echo "$(GREEN)$(NAME_P) was created.$(BASE)"

$(OBJDIR)%.o: $(SRCS_DIR)%.c $(HEAD_P)
	@mkdir -p $(OBJDIR)
	@$(CC) $(FLAGS) -I $(LIBFT) -I $(HEAD_DIR) -c $< -o $@

clean:
	@rm -rf $(OBJDIR)
	@make -C $(LIBFT) clean
	
fclean: clean
	@rm -rf $(NAME_P)
	@make -C $(LIBFT) fclean
	@echo "$(RED)$(NAME_P) was deleted.$(BASE)"

re: fclean all

.PHONY: all clean fclean re