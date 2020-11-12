# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/03 18:03:52 by aagrivan          #+#    #+#              #
#    Updated: 2020/11/12 21:40:30 by aagrivan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CH = checker
NAME_PS = push_swap

CC = gcc

FLAGS = -Wall -Wextra -Werror -g

SRCS_DIR = srcs/
SRCS_PS = push_swap.c
SRCS_CH = checker.c
SRCS =	initiate.c\
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
SRCS_P = $(addprefix $(SRCS_DIR),$(SRCS_PS))
SRCS_C = $(addprefix $(SRCS_DIR),$(SRCS_CH))
SRCS_ALL = $(addprefix $(SRCS_DIR),$(SRCS))

HEAD_DIR = includes/
HEAD =	push_struct.h\
		push_swap.h
HEAD_P = $(addprefix $(HEAD_DIR),$(HEAD))

OBJDIR = obj/
OBJ_P = $(addprefix $(OBJDIR),$(SRCS_PS:%.c=%.o))
OBJ_C = $(addprefix $(OBJDIR),$(SRCS_CH:%.c=%.o))
OBJ_ALL = $(addprefix $(OBJDIR),$(SRCS:%.c=%.o))

LIBFT = libft/
LFLAGS = -L $(LIBFT) -lft

vpath %.c srcs libft
vpath %.h includes

# COLOR
GREEN = \033[0;32m
RED = \033[0;31m
BASE = \033[0m

all: libft.a $(NAME_PS) $(NAME_CH)

$(NAME_PS): $(OBJ_P) $(OBJ_ALL) $(HEAD_P)
	@$(CC) $(FLAGS) $(OBJ_P) $(OBJ_ALL) $(LFLAGS) -o $(NAME_PS)
	@echo "$(GREEN)$(NAME_PS) was created.$(BASE)"

$(NAME_CH): $(OBJ_C) $(OBJ_ALL) $(HEAD_P)
	@$(CC) $(FLAGS) $(OBJ_C) $(OBJ_ALL) $(LFLAGS) -o $(NAME_CH)
	@echo "$(GREEN)$(NAME_CH) was created.$(BASE)"

libft.a:
	@make -C $(LIBFT)

$(OBJDIR)%.o: $(SRCS_DIR)%.c $(HEAD_P)
	@mkdir -p $(OBJDIR)
	@$(CC) $(FLAGS) -I $(LIBFT) -I $(HEAD_DIR) -c $< -o $@

clean:
	@rm -rf $(OBJDIR)
	@make -C $(LIBFT) clean
	
fclean: clean
	@rm -rf $(NAME_PS)
	@rm -rf $(NAME_CH)
	@make -C $(LIBFT) fclean
	@echo "$(RED)$(NAME_PS) was deleted.$(BASE)"
	@echo "$(RED)$(NAME_CH) was deleted.$(BASE)"

re: fclean all

.PHONY: all clean fclean re