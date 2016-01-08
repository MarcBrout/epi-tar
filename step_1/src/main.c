/*
** main.c for main function in /home/troncy_l/prog/Rush1/step_1
** 
** Made by 
** Login   <troncy_l@epitech.net>
** 
** Started on  Fri Jan  8 20:23:09 2016 
** Last update Fri Jan  8 21:04:52 2016 
*/

#include "main.h"

int		main(int argc, char **argv)
{
  int		fd;
  int		len;
  t_header	header;

  if (argc != 2)
    {
      printf("wrong Usage\n");
      return (0);
    }
  fd = open(argv[1], O_RDONLY);
  len = read(fd, &header, 512);
  printf("READED:%d\n", len);
  printf("FileName:%s\n", header.name);
  printf("La taille du 1er fichier est:%s", header.size);
  return (0);
}
