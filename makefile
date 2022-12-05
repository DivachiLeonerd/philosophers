# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afonso <afonso@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/15 15:45:01 by afonso            #+#    #+#              #
#    Updated: 2022/12/05 19:19:54 by afonso           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := philo
HEADER := -I./
OBJS:= aux_functions.o ft_atol.o check_input.o free_functions.o load_philosnforks.o routine.o set_struct_var.o aux_functions2.o ft_itoa.o ft_lutoa.o ft_strlen.o
#OBJS_T :=
CC := gcc
CFLAGS := -pthread -g -Wall -Wextra -Werror -fsanitize=thread #-fsanitize=thread
RM := rm -f

all:philo

philo: $(OBJS)
	${CC} ${CFLAGS} ${NAME}.c ${OBJS} ${HEADER} -o ${NAME}

test:${OBJS}
	${CC} -pthread -g -Wextra -Wall -fsanitize=thread teste.c ${OBJS} ${HEADER} -o tester

clean:
	${RM} *.o
	${RM} tester

fclean: clean
	${RM} philo

re: fclean all

 .PHONY:linux test