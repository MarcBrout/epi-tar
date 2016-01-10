/*
** my_start.c for launcher functions in /home/troncy_l/prog/Rush1/step_3
** 
** Made by 
** Login   <troncy_l@epitech.net>
** 
** Started on  Sun Jan 10 08:08:28 2016 
** Last update Sun Jan 10 08:31:00 2016 
*/

#include "main.h"

int		my_start(int args[], char **tarball)
{
  int		fd;
  
  if (args[0] == 1)
    {
      fd = open(tarball[0], O_RDONLY);
      if (fd != -1)
	return (my_untar(fd));
    }
  else if (args[1] == 1)
    printf("Ret:%d\n", launch_my_archive(tarball));
  return (0);
}