# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sel-mars <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/29 14:26:52 by sel-mars          #+#    #+#              #
#    Updated: 2021/12/29 15:18:17 by sel-mars         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

CC		=	gcc

AR		=	ar rc

RM		=	rm -f

CFLAGS	=	-Wall -Wextra -Werror

SRCS	=	push_swap_ext00.c push_swap_ext01.c push_swap_ext02.c\
			push_swap_ext03.c push_swap_ext04.c push_swap_ext05.c\
			push_swap_ext06.c push_swap_ext07.c  push_swap_ext08.c\
			checker_ext00.c checker_ext01.c\
			gnl/get_next_line.c gnl/get_next_line_utils.c

OBJS	=	$(SRCS:.c=.o)

GNL		=	get_next_line.o get_next_line_utils.o

PGM		=	push_swap.c

CHK		=	checker.c

HDFL	=	push_swap.h

LIB		=	libpush_swap.a

all: $(NAME)

$(NAME): $(OBJS) $(PGM) $(HDFL)
	@(cd libft/; make;)
	@$(CC) $(CFLAGS) -c $(SRCS) -I $(HDFL)
	@$(AR) $(LIB) $(OBJS)
	@$(CC) $(CFLAGS) $(PGM) -L./libft/ -lft -L. -lpush_swap -o $(NAME)

bonus: $(NAME) $(CHK)
	@$(CC) $(CFLAGS) $(CHK) -L./libft/ -lft -L. -lpush_swap -o checker

clean:
	@(cd libft/; make clean;)
	@$(RM) $(OBJS) $(GNL)

fclean: clean
	@(cd libft/; make fclean;)
	@$(RM) $(OBJS) $(NAME) checker

re: fclean all

.PHONY:	all bonus clean fclean re
