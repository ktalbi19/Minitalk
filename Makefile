# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ktalbi <ktalbi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/18 17:30:50 by ktalbi            #+#    #+#              #
#    Updated: 2021/11/18 19:06:53 by ktalbi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CLIENT = client
SERVER = server
NAME = $(CLIENT) $(SERVER)
RM = rm -rf

CFLAGS = -Werror -Wextra -Wall

SRC_C = client.c
OBJ_C = $(SRC_C:.c=.o)

SRC_S = server.c
OBJ_S = $(SRC_S:.c=.o)

all: $(NAME)

$(CLIENT): $(OBJ_C)
	$(CC) $(CFLAGS) -o $(CLIENT) $(OBJ_C)

$(SERVER): $(OBJ_S)
	$(CC) $(CFLAGS) -o $(SERVER) $(OBJ_S)

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(CLIENT) $(SERVER)

re: clean all

.PHONY: all clean fclean re