/*
** my_write.c for write
** 
** Made by 
** Login   <troncy_l@epitech.net>
** 
** Started on  Sat Jan  9 00:27:31 2016 
** Last update Sat Jan  9 08:40:04 2016 marc brout
*/

#include "main.h"

void		archive_files(t_arg *arg, char *archive)
{
  int		src;
  int		dest;
  t_file	*tmp;

  if ((dest = creat(archive, O_WRONLY)) != -1)
    {
      tmp = arg->files;
      while (tmp->next != NULL)
	{
	  tmp = tmp->next;
	  if ((src = open(tmp->path, O_RDONLY)) != -1)
	    {
	      write_tar(&tmp->header, src, dest);
	      close(src);
	    }
	}
      close(dest);
    }
}

void		write_tar(t_header *header, int src, int dest)
{
  char		buff[512];
  char		zero[512];
  int		len;

  len = 0;
  while (len < 512)
    zero[len++] = 0;
  write(dest, header, 512);
  buff[512] = '\0';
  while ((len = read(src, buff, 512)) != 0)
    {
      if (len != 512)
	{
	  write(dest, buff, len);
	  write(dest, zero, 512 - len);
	}
      else
	{
	  write(dest, buff, 512);
	}
    }
}

void		calc_chksum(t_header *header)
{
  char		*str;
  int		i;
  int		a;
  int		d;
  char		c;

  i = 0;
  a = 0;
  d = 0;
  str = (char *)header;
  while (i < 500)
    {
      c = *str;
      a += c % 255;
      d += (c * (i + 1)) % 255;
      i++;
      str++;
    }
  sprintf(header->chksum, "%06o", d - a);
}
