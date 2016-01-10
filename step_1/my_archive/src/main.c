/*
** main.c for tarball
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Fri Jan  8 21:16:14 2016 marc brout
** Last update Sun Jan 10 07:13:32 2016 marc brout
*/

#include "main.h"

int		main(int ac, char **av, char **ev)
{
  if (ac < 2 || ev == NULL)
    return (1);
  if (launch_my_archive(av))
    return (1);
  return (0);
}
