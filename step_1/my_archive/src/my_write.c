/*
** my_write.c for write tar file in /home/troncy_l/prog/Rush1/step_1/my_archive/src
** 
** Made by 
** Login   <troncy_l@epitech.net>
** 
** Started on  Sat Jan  9 00:27:31 2016 
** Last update Sat Jan  9 01:12:48 2016 
*/

#include "main.h"

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
