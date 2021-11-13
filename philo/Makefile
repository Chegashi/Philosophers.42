# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/13 16:03:59 by mochegri          #+#    #+#              #
#    Updated: 2021/11/13 16:07:46 by mochegri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = philosopher

flags = -Wall -Wextra -Werror 
SRCS = 	main.c \
		# src/libft.c \
		# src/win.c \
		# src/key.c \
		# src/render.c \
		# src/ft_math.c \
		# src/colors.c \
		# src/hcv2rgb.c \
		# src/mandelbrot.c \
		# src/ft_math2.c \

MAND = $(SRCS)

$(NAME): $(SRCS)
	@gcc $(flags) -c $(SRCS) 
	# @ar -rc fractol.a *.o
	# @ranlib fractol.a 
	# @gcc $(flags) -I /usr/local/include fractol.a -L /usr/local/lib/ \
	# -lmlx -framework OpenGL -framework AppKit -o $(NAME) -I0g
	# @rm *.o
	# @rm fractol.a


all : $(NAME)

clean:
	@rm -f $(SRC:.c=.o) $(MAND:.c=.o) fractol

fclean:	clean
	@rm -f $(NAME)

re:		fclean all

Julia: re
	./fractol Julia

Mandelbrot : re
	./fractol Mandelbrot

Mandelbrot_4 : re
	./fractol Mandelbrot_4

Flower: re
	./fractol Flower