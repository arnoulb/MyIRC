##
## Makefile for  in /home/arnould_b/Igraph
## 
## Made by jean-michel arnould
## Login   <arnould_b@epitech.net>
## 
## Started on  Mon Dec 21 09:21:05 2015 jean-michel arnould
## Last update Sun Jun 11 19:24:11 2017 arnoul_b
##

NAME_SER		:=	server
NAME_CLI		:=	client

CC			:=	gcc
RM			:= 	rm -f

SRC_DIR_SER		:= 	src_ser
SRC_DIR_CLI		:= 	src_cli

OBJ_DIR_SER		:=	obj_ser
OBJ_DIR_CLI		:=	obj_cli

INC_DIR			:=	inc
LIB			:=	lib

#CFLAGS			:=	-Wextra -Wall -Werror
CFLAGS			+=	-g
CFLAGS			+=	-I$(INC_DIR)

#LDFLAGS			+=	-lcrypt

SRC_SER			:=	main.c\
				error.c\
				tools.c\
				socket.c\
				linked_list.c\
				exec.c\
				my_str_to_wordtab.c\
				code.c\
				split.c\
				nickname.c\
				join.c\
				send_msg.c\
				users.c

SRC_CLI			:=	main.c\
				parser.c\
				my_str_to_wordtab.c\
				tools.c

SRC_SER			:=	$(addprefix $(SRC_DIR_SER)/, $(SRC_SER))
SRC_CLI			:=	$(addprefix $(SRC_DIR_CLI)/, $(SRC_CLI))

OBJ_SER			:=	$(patsubst $(SRC_DIR_SER)/%.c, $(OBJ_DIR_SER)/%.o, $(SRC_SER))
OBJ_CLI			:=	$(patsubst $(SRC_DIR_CLI)/%.c, $(OBJ_DIR_CLI)/%.o, $(SRC_CLI))

$(OBJ_DIR_SER)/%.o:	$(SRC_DIR_SER)/%.c
			$(CC) $(CFLAGS) -c -o $@ $< $(LDFLAGS)

$(OBJ_DIR_CLI)/%.o:	$(SRC_DIR_CLI)/%.c
			$(CC) $(CFLAGS) -c -o $@ $< $(LDFLAGS)

all:			$(NAME_SER) $(NAME_CLI)


$(NAME_SER): 		$(OBJ_SER)
			$(CC) -o $(NAME_SER) $(OBJ_SER) $(LDFLAGS)

$(NAME_CLI): 		$(OBJ_CLI)
			$(CC) -o $(NAME_CLI) $(OBJ_CLI) $(LDFLAGS)

clean:
			$(RM) $(OBJ_SER) $(OBJ_CLI)
			$(RM) $(SRC_DIR_SER)/*~ $(OBJ_DIR_SER)/*\#
			$(RM) $(OBJ_DIR_SER)/*~ $(OBJ_DIR_SER)/*\#
			$(RM) $(INC_DIR)/*~ $(INC_DIR)/*\#
			$(RM) $(SRC_DIR_CLI)/*~ $(OBJ_DIR_CLI)/*\#
			$(RM) $(OBJ_DIR_CLI)/*~ $(OBJ_DIR_CLI)/*\#
			$(RM) *~ *\#

fclean: 		clean
			$(RM) $(NAME_SER)
			$(RM) $(NAME_CLI)

re:			fclean all


.PHONY: 		all clean fclean re
