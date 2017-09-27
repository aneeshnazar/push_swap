# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anazar <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/05 10:07:33 by anazar            #+#    #+#              #
#    Updated: 2017/09/04 16:16:23 by anazar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
PART1 = ft_atoi ft_bzero ft_isdigit ft_memmove ft_memset ft_strchr ft_strcmp \
	  	ft_strcpy ft_strdup ft_strlen
PART2 =	ft_memalloc ft_putchar ft_putstr ft_putendl ft_strdel \
	   	ft_strjoin ft_strnew ft_strsplit ft_strsub
ADDIT =	ft_atoll ft_iswhitespace ft_min ft_max ft_split_by_delims get_next_line
FILES = $(PART1) $(PART2) $(ADDIT)
MAINSRC = tst/main.c
MAINOBJ = main.o
TESTOUT = libtest
LIB = ar rc
FLAGS = -Wall -Werror -Wextra -I./includes/
SRCS = $(patsubst %, %.c, $(FILES))
OBJS = $(patsubst %, %.o, $(FILES))

all:	$(NAME)

test:
	@gcc $(FLAGS) -c $(SRCS) $(MAINSRC) ./libft.h
	@gcc $(OBJS) $(MAINOBJ) -o $(TESTOUT)
	@$(MAKE) clean
	@rm -rf *.gch

tclean:
	@rm -rf $(TESTOUT)

$(OBJS): $(SRCS)
	@gcc $(FLAGS) -c $(SRCS)

$(NAME): $(OBJS)
	@$(LIB) $(NAME) $(OBJS)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJS) $(MAINOBJ)

fclean:	clean
	@rm -f $(NAME)

re:	fclean all
