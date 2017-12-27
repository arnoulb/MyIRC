/*
** tools.c for  in /home/arnoulb/rendu/PSU/PSU_2016_myftp
**
** Made by arnoul_b
** Login   <arnoulb@epitech.net>
**
** Started on  Sun May 21 18:48:02 2017 arnoul_b
** Last update Sun Jun 11 16:57:11 2017 arnoul_b
*/

#include "server.h"

void	my_free(char **cmd)
{
  int	i;

  i = -1;
  while (cmd[++i])
    free(cmd[i]);
  free(cmd);
}

int	my_tablen(char **cmd)
{
  int	i;

  i = -1;
  while (cmd[++i]);
  return (i);
}

int	get_sizetab(char **tab)
{
  int	i;
  int	size;

  i = -1;
  size = 0;
  while (tab[++i])
    size += strlen(tab[i]);
  return (size);
}

char	*my_merge(char **tab)
{
  int	i;
  int	j;
  int	k;
  int	size;
  char	*str;

  size = get_sizetab(tab) + my_tablen(tab) + 3;
  str = malloc(sizeof (char) * (size));
  i = -1;
  k = -1;
  while (tab[++i])
    {
      j = -1;
      while (tab[i][++j])
	str[++k] = tab[i][j];
      str[++k] = ' ';
    }
  str[k] = 0;
  printf("%s\n", str);
  return (str);
}
