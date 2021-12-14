# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/13 16:03:59 by mochegri          #+#    #+#              #
#    Updated: 2021/12/14 19:22:03 by mochegri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = philo

flags = -Wall -Wextra -Werror -fsanitize=address -g
SRCS = 	main.c libft.c philo.c table.c\


MAND = $(SRCS)

$(NAME): $(SRCS)
	@cc $(flags) $(SRCS) -o $(NAME)

all : $(NAME)

clean:
	@rm -f $(SRC:.c=.o) $(MAND:.c=.o) philo

fclean:	clean
	@rm -f $(NAME)

re:		fclean all

test_1:	all
	@echo "the philosopher should not eat and should die!"
	./philo 1 800 200 200

test_2 : all
	@echo "no one should die and the simulation should stop when all the philosopher has eaten at least 7 times each"
	./philo 5 800 200 200 7

test_3 : all
	@echo "no one should die"
	./philo 4 410 200 200

test_4 : all
	@echo " philosopher should die!"
	./philo 2 160 60 100