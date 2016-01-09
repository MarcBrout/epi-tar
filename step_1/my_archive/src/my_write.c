/*
** my_write.c for write
** 
** Made by 
** Login   <troncy_l@epitech.net>
** 
** Started on  Sat Jan  9 00:27:31 2016 
** Last update Sat Jan  9 05:27:12 2016 marc brout
*/

#include "main.h"

void		archive_files(t_arg *arg, char *archive)
{
  int		src;
  int		dest;
  t_file	*tmp;

  printf("lol\n");
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
  char		buff[513];
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
