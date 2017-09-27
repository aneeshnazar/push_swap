# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anazar <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/22 11:17:12 by anazar            #+#    #+#              #
#    Updated: 2017/09/05 12:09:05 by anazar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = checker
NAME2 = push_swap
NAME = both
S_DIR = ./shared/
STACK_OPS = push push_from_stack r_rotate rotate swap pop free_stack 
S_FILES =	error ft_multi_strsplit validate check_sort init_stack is_sorted \
			get_list_len in_stack free_str_list $(STACK_OPS)
S_SRCS = $(addprefix $(S_DIR), $(patsubst %, %.c, $(S_FILES)))
S_OBJS = $(patsubst %, %.o, $(S_FILES))
P_DIR = ./p_srcs/
STACK_OUTPUT =	op_push_a op_push_b op_r_rotate_a op_r_rotate_b op_rotate_a op_rotate_b \
				op_double_r op_double_rr op_ra_rrb op_rra_rb op_r_rotate_r op_rotate_r \
				op_swap_a
P_FILES =	p_main push_swap find_min find_max last optimize_move rev_sorted $(STACK_OUTPUT) \
			brute_force is_max
P_SRCS = $(addprefix $(P_DIR), $(patsubst %, %.c, $(P_FILES)))
P_OBJS = $(patsubst %, %.o, $(P_FILES))
C_DIR = ./c_srcs/
C_FILES = c_main checker handle_op
C_SRCS = $(addprefix $(C_DIR), $(patsubst %, %.c, $(C_FILES)))
C_OBJS = $(patsubst %, %.o, $(C_FILES))
INCLUDES = includes/
LIB_DIR = ./libft/
LIB = libft.a
FLAGS = -Wall -Werror -Wextra -I./$(INCLUDES) -I$(LIB_DIR)$(INCLUDES) -g
L_FLAGS = -L $(LIB_DIR) -lft

all: $(NAME)
   
$(NAME):   $(S_OBJS) $(NAME1) $(NAME2)

lib:
	@make -C libft/ re

$(S_OBJS): $(S_SRCS)
	@gcc $(FLAGS) -c $(S_SRCS) 

$(C_OBJS): $(S_SRCS) $(C_SRCS)
	@gcc $(FLAGS) -c $(C_SRCS)

$(P_OBJS): $(S_SRCS) $(P_SRCS)
	@gcc $(FLAGS) -c $(P_SRCS)

$(NAME1): $(C_OBJS) $(S_OBJS) 
	@$(MAKE) lib
	@gcc $(S_OBJS) $(C_OBJS) $(L_FLAGS) -o $(NAME1) 

$(NAME2): $(P_OBJS) $(S_OBJS) 
	@$(MAKE) lib
	@gcc $(S_OBJS) $(P_OBJS) $(L_FLAGS) -o $(NAME2)

clean:
	@make -C libft/ clean
	@rm -rf *.o

fclean:
	@make -C libft/ fclean
	@$(MAKE) clean
	@rm -rf $(NAME1) $(NAME2)

re:
	@$(MAKE) fclean
	@$(MAKE) all
