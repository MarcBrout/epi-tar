/*
** ope.c for tar operations in /home/troncy_l/prog/Rush1/step_1/my_unarchive
** 
** Made by 
** Login   <troncy_l@epitech.net>
** 
** Started on  Fri Jan  8 21:13:56 2016 
** Last update Fri Jan  8 23:14:34 2016 
*/

#include "main.h"

int		my_untar(int fd)
{
  t_header	header;
  int		len;
  char		*tmp;
  int		fa;

  while ((len = read(fd, &header, 512)) != 0)
    {
      if (header.name == NULL || header.name[0] == '\0')
	return (0);
      printf("Mode is :%s\n", header.mode);
      fa = creat(header.name, strtol(header.mode, NULL, 8));/*(mode_t)atoi(header.mode)*/
      printf("Name:%s\n", header.name);
      tmp = malloc(sizeof(char) * atoi(header.size));
      read(fd, tmp, atoi(header.size));
      write(fa, tmp, strlen(tmp));
      free(tmp);
      close(fa);
    }
  return (0);
}
