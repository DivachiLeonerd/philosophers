# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afonso <afonso@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/15 15:45:01 by afonso            #+#    #+#              #
#    Updated: 2022/10/17 11:22:08 by afonso           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := philo
HEADER := -I./
OBJS:= aux_functions.o
#OBJS_T :=
CC := gcc
CFLAGS := -fsanitize=thread -pthread #-Wall -Wextra -Werror
RM := rm -f

all:philo

philo: $(OBJS)
	${CC} ${CFLAGS} ${NAME}.c ${OBJS} ${HEADER} -o ${NAME}

test:${OBJS}
	${CC} ${CFLAGS} teste.c ${OBJS} ${HEADER} -o tester

clean:
	${RM} *.o
	${RM} tester

fclean: clean
	${RM} philo

re: fclean test

 .PHONY:linux test