/*
** ope.c for tar operations in /home/troncy_l/prog/Rush1/step_1/my_unarchive
** 
** Made by 
** Login   <troncy_l@epitech.net>
** 
** Started on  Fri Jan  8 21:13:56 2016 
** Last update Sat Jan  9 21:15:23 2016 
*/

#include "main.h"

int		my_untar(int fd)
{
  t_header	header;
  int		len;
  char		*tmp;
  int		fa;
  char		c;

  while ((len = read(fd, &header, 512)) != 0)
    {
      /*if (header.name == NULL || header.name[0] == '\0')
	return (0);*/
      if (len != 512 && (header.name == NULL || header.name[0] == '\0'))
	return (0);
      printf("Name:%s\n", header.name);
      printf("TYPE:%c\n", header.type[0]);
      printf("Size:%d\n", (int)strtol(header.size, NULL, 10));
      if (header.type[0] == '5' || header.name[strlen(header.name) - 1] == '/')
	{
	  if (mkdir(header.name, S_IRWXU | S_IRWXG | S_IRWXO) != 0)
	    printf("ERRRROOOOOOOOR\n");
	  printf("MKDIR HERE\n");
	}
      else
	{
	  fa = creat(header.name, strtol(header.mode, NULL, 8));
	  if (fa == -1)
	    printf("Failed to Create file\n");
	  tmp = malloc(sizeof(char) * (int)strtol(header.size, NULL, 10));
	  if (tmp == NULL)
	    printf("FFFFFF\n");
	  len = read(fd, tmp, (int)strtol(header.size, NULL, 10));
	  printf("READED:%d\n", len);
	  write(fa, tmp, len);
	  free(tmp);
	  close(fa);
	  if (strtol(header.size, NULL, 10) != 0)
	    read(fd, &header, 512 - (int)strtol(header.size, NULL, 10) % 512);
	  }
      read(0, &c, 1);
    }
  return (0);
}
