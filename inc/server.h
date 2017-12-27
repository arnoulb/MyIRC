/*
** server.h for  in /home/arnoulb/rendu/PSU/PSU_2016_myftp
**
** Made by arnoul_b
** Login   <arnoulb@epitech.net>
**
** Started on  Sun May 21 17:56:17 2017 arnoul_b
** Last update Sun Jun 11 21:27:47 2017 arnoul_b
*/

#ifndef __SERVER_H_
#define __SERVER_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include <string.h>
#include <pwd.h>
#include <crypt.h>
#include <dirent.h>
#include <netdb.h>

typedef struct		s_cli
{
  int			fd;
  char			nick[200];
  char			chan[200];
  struct sockaddr_in	addr;
  struct s_cli		*next;
}			t_cli;

typedef struct		s_serv
{
  int			fd;
  int			max;
  struct sockaddr_in	srv_addr;
  fd_set		master;
  fd_set		readf;
  t_cli			*cli;
}			t_srv;

t_cli	*lister(t_cli **);
t_cli	*get_client_byid(int, t_srv *, t_cli *);
void	init_socket(t_srv *, int);
void	bind_socket(t_srv *, int);
void	accept_srv(t_srv *);
void	interract(t_srv *, int);
void	error_argv(char *);
char	**get_cmd();
int	is_cmd(char *);
void	welcome(t_cli *, t_srv *);
void	my_parser(char *, t_cli *, t_srv *);
void	my_exec(char *, t_cli *, t_srv *);
char	**my_str_to_wordtab(char *);
char	**split_line(char *);
void	my_free(char **);
void	nickname(char *, t_srv *, t_cli *);
void	join(char **, t_srv *, t_cli *);
void	part(char **, t_srv *, t_cli *);
void	send_privatemsg(t_cli *, t_srv *, char **);
void	send_msg(t_cli *, char *, t_srv *, char *);
char	*my_merge(char **);
void	srv_list(t_cli *, t_srv *);
void	channel_list(t_cli *, t_srv *, char **);
void	remove_byfd(int, t_cli **);
#endif
