/*
** code.c for  in /home/arnoulb/rendu/PSU/PSU_2016_myirc
**
** Made by arnoul_b
** Login   <arnoulb@epitech.net>
**
** Started on  Sun Jun 11 02:00:08 2017 arnoul_b
** Last update Thu Jun 15 15:36:05 2017 arnoul_b
*/

#include "server.h"

void	welcome(t_cli *cli, t_srv *srv)
{
  int	i;
  dprintf(cli->fd, "001 Welcome to IRN %s\r\n", cli->nick);
  dprintf(cli->fd,
	  "002 Your host is %s, running version 0.1\r\n",
	  inet_ntoa(cli->addr.sin_addr));
  dprintf(cli->fd, "003 This server was created %s\r\n", __DATE__);
  dprintf(cli->fd, "004 Useless infos\r\n");
}
