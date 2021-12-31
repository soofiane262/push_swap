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

SRCS	=	push_swap_ext01.c push_swap_ext02.c

OBJS	=	$(SRCS:.c=.o)

PGM		=	push_swap.c

HDFL	=	push_swap.h

LIB		=	libpush_swap.a

all: $(NAME)

$(NAME): $(OBJS) $(PGM) $(HDFL)
	@(cd libft/; make;)
	@$(CC) $(CFLAGS) -c $(SRCS) -I $(HDFL)
	@$(AR) $(LIB) $(OBJS)
	@$(CC) $(CFLAGS) $(PGM) -L./libft/ -lft -L. -lpush_swap -o $(NAME)

norm:
	@norminette

clean:
	@(cd libft/; make clean;)
	@$(RM) $(OBJS)

fclean: clean
	@(cd libft/; make fclean;)
	@$(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean re
