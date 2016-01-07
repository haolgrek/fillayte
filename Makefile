# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tandrieu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/02 18:31:57 by tandrieu          #+#    #+#              #
#    Updated: 2016/01/07 17:16:41 by rluder           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJET_NAME = $(SRC_NAME:.c=.o)
	CC = gcc
	EXE = fillit
	LIBRARY = libfillit.a
	MAIN = main.o
	CFLAGS = -Werror -Wextra -Werror 
	SRC_NAME = backtracking.c\
				check.c\
				registration.c\
				resolution.c\
				set_left_up.c

all : $(EXE)

$(EXE) : $(LIBRARY) $(MAIN)
		gcc -o fillit $(CFLAGS) $(MAIN) $(LIBRARY) libft.a

$(LIBRARY) : $(OBJET_NAME)
		ar -r $(LIBRARY) $(OBJET_NAME)

$(MAIN) : main.c
		$(CC) $(CFLAGS) -c $<

%.o : %.c
		$(CC) -c $(CFLAGS) $<

clean :
		rm $(SRC_NAME:.c=.o) main.o

fclean : clean
		rm -rf $(LIBRARY) $(EXE)

re : fclean all
