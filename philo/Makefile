# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/13 16:03:59 by mochegri          #+#    #+#              #
#    Updated: 2021/11/14 16:47:52 by mochegri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = philosopher

flags = -Wall -Wextra -Werror 
SRCS = 	main.c \


MAND = $(SRCS)

$(NAME): $(SRCS)
	@gcc $(flags) -c $(SRCS) 

all : $(NAME)

clean:
	@rm -f $(SRC:.c=.o) $(MAND:.c=.o) philo

fclean:	clean
	@rm -f $(NAME)

re:		fclean all
