/*
** server.c for droit du coeur in /home/alexmog/projets/SELMA/selmakey/linux/src
** 
** Made by Moghrabi Alexandre
** Login   <alexmog@epitech.net>
** 
** Started on  Thu Jul 17 18:56:14 2014 Moghrabi Alexandre
** Last update Thu Jul 17 19:06:42 2014 Moghrabi Alexandre
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "selmakey.h"

void	send_datas(int fd, int key)
{
  char	buffer[512];

  sprintf(buffer, "privmsg %s :%d\r\n", IRC_CHANNEL, key);
  write(fd, buffer, strlen(buffer));
}

void	*server_thread(void *datas)
{
  char	buffer[512];
  int	fd = *((int*)datas);
  int	readed;

  while ((readed = read(fd, buffer, 512)) != -1)
    {
      buffer[readed] = 0;
      if (strncmp("ping", buffer, 4) != NULL)
	send_datas(fd, buffer);
    }
}
