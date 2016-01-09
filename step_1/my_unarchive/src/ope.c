/*
** ope.c for tar operations in /home/troncy_l/prog/Rush1/step_1/my_unarchive
** 
** Made by 
** Login   <troncy_l@epitech.net>
** 
** Started on  Fri Jan  8 21:13:56 2016 
** Last update Sat Jan  9 02:59:48 2016 
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
      /*if (header.name == NULL || header.name[0] == '\0')
	return (0);*/
      if (len != 512)
	return (0);
      printf("Name:%s\n", header.name);
      if (header.name[strlen(header.name) - 1] == '/')
	{
	  mkdir(header.name, S_IRWXU | S_IRWXG | S_IRWXO);
	}
      else
	{
	  printf("Size:%d\n", (int)strtol(header.size, NULL, 10));
	  fa = creat(header.name, strtol(header.mode, NULL, 8));
	  tmp = malloc(sizeof(char) * (int)strtol(header.size, NULL, 10));
	  if (tmp == NULL)
	    printf("FFFFFF\n");
	  len = read(fd, tmp, (int)strtol(header.size, NULL, 10));
	  write(fa, tmp, len);
	  printf("CheckSum:%d\n", (int)strtol(header.chksum, NULL, 10));
	  free(tmp);
	  close(fa);
	  read(fd, &header, 512 - (int)strtol(header.size, NULL, 10) % 512);
	  }
    }
  return (0);
}
