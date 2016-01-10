/*
** main.c for main function in /home/troncy_l/prog/Rush1/step_1
** 
** Made by 
** Login   <troncy_l@epitech.net>
** 
** Started on  Fri Jan  8 20:23:09 2016 
** Last update Sat Jan  9 22:09:07 2016 
*/

#include "main.h"

int		main(int argc, char **argv)
{
  int		fd;
  int		len;

  if (argc != 2)
    {
      printf("wrong Usage\n");
      return (0);
    }
  fd = open(argv[1], O_RDONLY);
  len = my_untar(fd);
  if (len == 0)
    close(fd);
  return (0);
}
