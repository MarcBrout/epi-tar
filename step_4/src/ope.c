/*
** ope.c for tar operations in /home/troncy_l/prog/Rush1/step_1/my_unarchive
** 
** Made by 
** Login   <troncy_l@epitech.net>
** 
** Started on  Fri Jan  8 21:13:56 2016 
** Last update Sun Jan 10 11:58:24 2016 marc brout
*/

#include "main.h"

int		create_file(t_header header, int fd)
{
  int		fa;
  char		*tmp;
  int		len;

  if (header.type[0] < 0 || header.type[0] > 7)
    fa = creat(header.name, strtol(header.mode, NULL, 8));
  if (fa == -1)
    {
      disp_err(NO_RIGHTS);
      return (-1);
    }
  tmp = malloc(sizeof(char) * (int)strtol(header.size, NULL, 8));
  if (tmp == NULL)
    return (-1);
  if ((len = read(fd, tmp, (int)strtol(header.size, NULL, 8))) < 0)
    return (-1);
  if (header.type[0] < 0 || header.type[0] > 7)
    write(fa, tmp, len);
  free(tmp);
  if (header.type[0] < 0 || header.type[0] > 7)
    close(fa);
  if ((len = (int)strtol(header.size, NULL, 8)) != 0)
    len = read(fd, &header, 512 - (int)strtol(header.size, NULL, 8) % 512);
  return (0);
}

int		my_untar(int fd, int args[])
{
  t_header	header;
  int		len;

  while ((len = read(fd, &header, 512)) != 0)
    {
      if (len != 512 && (header.name == NULL || header.name[0] == '\0'))
	return (0);
      if (args[2] == 1)
	printf("Name:%s\n", header.name);
      if (header.type[0] == '5')
	{
	  if (mkdir(header.name, S_IRWXU | S_IRWXG | S_IRWXO) != 0)
	    {
	      disp_err(NO_RIGHTS);
	      return (-1);
	    }
	}
      else
	{
	  if (create_file(header, fd) != 0)
	    return (-1);
	}
    }
  return (0);
}
