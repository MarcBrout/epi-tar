/*
** my_write.c for write
** 
** Made by 
** Login   <troncy_l@epitech.net>
** 
** Started on  Sat Jan  9 00:27:31 2016 
** Last update Sun Jan 10 06:35:07 2016 marc brout
*/

#include "main.h"

char		pad_archive(t_arg *arg, int fd)
{
  arg->pad = arg->pad % 20;
  while (arg->pad++ < 20)
    if (write(fd, arg->zero, 512) < 0)
      {
	close(fd);
	return (1);
      }
  close(fd);
  return (0);
}

char		archive_files(t_arg *arg, char *archive)
{
  int		src;
  int		dest;
  t_file	*tmp;

  if ((dest = open(archive, O_WRONLY | O_CREAT,
		   S_IRWXU | S_IRGRP | S_IROTH)) < 0)
    return (1);
  arg->pad = 1;
  memset(arg->zero, 0, 512);
  tmp = arg->files;
  while ((tmp = tmp->next) != NULL)
    if ((src = open(tmp->path, O_RDONLY)) != -1)
      {
	if (write_tar(arg, &tmp->header, src, dest) < 0)
	  {
	    close(src);
	    close(dest);
	    return (1);
	  }
	    close(src);
      }
  if (pad_archive(arg, dest))
    return (1);
  return (0);
}

char		write_tar(t_arg *arg, t_header *header, int src, int dest)
{
  char		buff[512];
  int		len;

  len = 0;
  write(dest, header, 512);
  buff[512] = '\0';
  while (header->type[0] == '0' && (len = read(src, buff, 512)) != 0)
    {
      if (len != 512)
	{
	  if (write(dest, buff, len) < 0 ||
	      write(dest, arg->zero, 512 - len) < 0)
	    return (1);
	}
      else
	{
	  write(dest, buff, 512);
	}
      arg->pad += 1;
    }
  return (0);
}

void		calc_chksum(t_header *header)
{
  char		*str;
  int		i;
  int		d;
  char		c;

  i = 0;
  d = 0;
  str = (char *)header;
  while (i < 500)
    {
      c = *str;
      d = d + c;
      i++;
      str++;
    }
  sprintf(header->chksum, "%06o", d);
}
