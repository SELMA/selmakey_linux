/*
** main.c for selmakey in /home/alexmog/projets/SELMA/selmakey/linux/src
** 
** Made by Moghrabi Alexandre
** Login   <alexmog@epitech.net>
** 
** Started on  Thu Jun 26 20:30:48 2014 Moghrabi Alexandre
** Last update Thu Jun 26 22:24:11 2014 Moghrabi Alexandre
*/

#include <unistd.h>
#include "init.h"
#include "listen.h"

int		main(void)
{
  int		fd;

  if (init(&fd))
    return (1);
  start_listening(fd);
  close(fd);
  return (0);
}
