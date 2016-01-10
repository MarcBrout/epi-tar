/*
** main.c for main function in /home/troncy_l/prog/Rush1/step_1
** 
** Made by 
** Login   <troncy_l@epitech.net>
** 
** Started on  Fri Jan  8 20:23:09 2016 
** Last update Sun Jan 10 01:17:53 2016 
*/

#include "main.h"

int		main(int argc, char **argv)
{
  int		fd;
  int		len;
  int		i;

  if (argc == 1)
    {
      printf("wrong Usage\n");
      return (0);
    }
  i = 1;
  while (i < argc)
    {
      if ((fd = open(argv[i], O_RDONLY)) == -1)
	{
	  printf("failed to open tarball\n");
	  return (1);
	}
      /*len = my_untar(fd);*/
      len = 0;
      disp_tar(fd);
      if (len == 0)
	close(fd);
      i++;
    }
  return (0);
}
