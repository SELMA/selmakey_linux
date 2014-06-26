/*
** init.c for selmakey in /home/alexmog/projets/SELMA/selmakey/linux/src
** 
** Made by Moghrabi Alexandre
** Login   <alexmog@epitech.net>
**
** Init functions
**
** Started on  Thu Jun 26 21:01:34 2014 Moghrabi Alexandre
** Last update Thu Jun 26 21:53:49 2014 Moghrabi Alexandre
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	init(int *fd)
{
  /** TODO PATHNME **/
  if ((*fd = open("PATHNAME", O_RDONLY)) == -1)
    return (1);
  return (0);
}
