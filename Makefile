# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeonjeon <jeonjeon@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/08 17:13:59 by jeonjeon          #+#    #+#              #
#    Updated: 2022/07/08 18:19:18 by jeonjeon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

SERVER	=	server
CLIENT	=	client

SERVER_B	=	server_bonus
CLIENT_B	=	client_bonus

SRCS_SERVER	=	srcs/server.c
SRCS_SERVER_B	=	srcs_bonus/server_bonus.c

SRCS_CLIENT	=	srcs/client.c
SRCS_CLIENT_B	=	srcs_bonus/client_bonus.c

SRCS_UTILS	=	srcs/utils.c
SRCS_UTILS_B	=	srcs_bonus/utils_bonus.c

OBJS_SERVER	=	$(SRCS_SERVER:.c=.o)
OBJS_SERVER_B	=	$(SRCS_SERVER_B:.c=.o)

OBJS_CLIENT	=	$(SRCS_CLIENT:.c=.o)
OBJS_CLIENT_B	=	$(SRCS_CLIENT_B:.c=.o)

OBJS_UTILS	=	$(SRCS_UTILS:.c=.o)
OBJS_UTILS_B	=	$(SRCS_UTILS_B:.c=.o)

ifdef WITH_BONUS
	OBJS_SERVER = $(OBJS_SERVER_B), \
	OBJS_CLIENT = $(OBJS_CLIENT_B), \
	OBJS_UTILS = $(OBJS_UTILS_B)
else
	
endif

all:		$(SERVER) $(CLIENT)

$(SERVER):	$(OBJS_SERVER) $(OBJS_UTILS)
			$(CC) $(CFLAGS) $(OBJS_SERVER) $(OBJS_UTILS) -o $(SERVER)
$(CLIENT):	$(OBJS_CLIENT) $(OBJS_UTILS)
			$(CC) $(CFLAGS) $(OBJS_CLIENT) $(OBJS_UTILS) -o $(CLIENT)

bonus:		$(SERVER_B) $(CLIENT_B)

$(SERVER_B):	$(OBJS_SERVER_B) $(OBJS_UTILS_B)
			$(CC) $(CFLAGS) $(OBJS_SERVER_B) $(OBJS_UTILS_B) -o $(SERVER_B)
$(CLIENT_B):	$(OBJS_CLIENT_B) $(OBJS_UTILS_B)
			$(CC) $(CFLAGS) $(OBJS_CLIENT_B) $(OBJS_UTILS_B) -o $(CLIENT_B)

clean:
			rm -f $(OBJS_SERVER) $(OBJS_CLIENT) $(OBJS_UTILS)\
				$(OBJS_SERVER_B) $(OBJS_CLIENT_B) $(OBJS_UTILS_B)

fclean:		clean
			rm -f $(SERVER) $(CLIENT) $(SERVER_B) $(CLIENT_B)

re:			fclean all

.PHONY:		all clean fclean re bonus
