/*
** options.c for option functions in /home/troncy_l/prog/Rush1/step_1/my_unarchive
** 
** Made by 
** Login   <troncy_l@epitech.net>
** 
** Started on  Sat Jan  9 23:52:49 2016 
** Last update Sun Jan 10 09:37:12 2016 marc brout
*/

#include "main.h"

void		disp_tar(int fd)
{
  int		len;
  t_header	header;

  while ((len = read(fd, &header, sizeof(t_header))) != 0)
    {
      if (header.type[0] < '0' || header.type[0] > '7')
	continue;
      printf("%s\n", header.name);
      if (header.type[0] == '5')
	continue;
      lseek(fd, (int)strtol(header.size, NULL, 8), SEEK_CUR);
      lseek(fd, 512 - (int)strtol(header.size, NULL, 8) % 512, SEEK_CUR);
    }
}
