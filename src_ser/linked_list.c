/*
** linked_list.c for  in /home/arnoulb/rendu/PSU/PSU_2016_myirc
**
** Made by arnoul_b
** Login   <arnoulb@epitech.net>
**
** Started on  Thu Jun  8 17:51:22 2017 arnoul_b
** Last update Sun Jun 11 22:23:55 2017 arnoul_b
*/

#include "server.h"

t_cli	*get_client_byid(int i, t_srv *srv, t_cli *cli)
{
  t_cli *tmp;

  tmp = srv->cli;
  while (tmp)
    {
      if (tmp->fd == i)
	cli = tmp;
      tmp = tmp->next;
    }
  return (cli);
}

t_cli	*lister(t_cli **cli)
{
  t_cli *tmp;
  t_cli	*add;

  if (cli[0] == NULL)
    {
      cli[0] = malloc(sizeof (t_cli));
      cli[0]->next = NULL;
      return (cli[0]);
    }
  else
    {
      tmp = cli[0];
      add = malloc(sizeof (t_cli));
      while (tmp->next)
	tmp = tmp->next;
      add->next = NULL;
      tmp->next = add;
      return (add);
    }
}
void	show_cli(t_cli *cli)
{
  t_cli *tmp;

  tmp = cli;
  while (tmp)
    {
      printf("Client n°%d\n", tmp->fd);
      printf("\tnom : %s\n", tmp->nick);
      printf("\tchan : %s\n", tmp->chan);
      tmp = tmp->next;
    }
}

void	remove_byfd(int fd, t_cli **cli)
{
  t_cli *tmp;
  int	i;

  tmp = *cli;
  i = -1;
  if (tmp->next == NULL)
    {
      *cli = NULL;
      return;
    }
  while (tmp->next)
    {
      if (tmp->next->fd == fd)
	{
	  tmp->next = tmp->next->next;
	  return ;
	}
      tmp = tmp->next;
    }
}
