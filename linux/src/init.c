/*
** init.c for init in /home/alexmog/projets/SELMA/selmakey/linux/src
** 
** Made by Moghrabi Alexandre
** Login   <alexmog@epitech.net>
** 
** Started on  Thu Jul 17 18:16:08 2014 Moghrabi Alexandre
** Last update Thu Jul 17 19:12:05 2014 Moghrabi Alexandre
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <linux/input.h>
#include <string.h>
#include <sys/epoll.h>
#include <signal.h>
#include "selmakey.h"

void	find_kbd(char *path)
{
  FILE	*fd;
  int	found;
  char	buff[412];
  char	buff2[412];
  int	i;
  char	tmp[412];

  memset(buff, 0, sizeof(buff));
  found = 0;
  fd = fopen("/proc/bus/input/devices", "r");
  sprintf(path, "/dev/input/event");
  while (!found)
    {
      i = -1;
      while (++i < 10)
	{
	  memset(tmp, 0, sizeof(tmp));
	  if (fgets(tmp, 412, fd) == NULL)
	    break;
	  if (i == 1)
	    memcpy(buff, tmp, sizeof(tmp));
	  else if (i == 5)
	    memcpy(buff2, tmp, sizeof(tmp));
	}
      // WTF??
      /*      while (i < 10
      (fgets(buff[0], 412, fd) != NULL
       && fgets(buff[1], 412, fd) != NULL
       && fgets(buff[2], 412, fd) != NULL
       && fgets(buff[3], 412, fd) != NULL
       && fgets(buff[4], 412, fd) != NULL
       && fgets(buff[5], 412, fd) != NULL
       && fgets(buff[6], 412, fd) != NULL
       && fgets(buff[7], 412, fd) != NULL
       && fgets(buff[8], 412, fd) != NULL
       && fgets(buff[9], 412, fd) != NULL)*/
      if (strstr(buff, "keyboard") != NULL
	  || strstr(buff, "Keyboard") != NULL)
	{
	  sprintf(path, "%s%c", path, buff2[strlen(buff2) - 3]);
	  found = 1;
	}
    }
  fclose(fd);
}

int	init_server(t_kl *kl)
{
  (void)kl;
  return (0);
}

int	init(t_kl *kl)
{
  char	path[4096];

  memset(kl, 0, sizeof(t_kl));
  find_kbd(path);
  if ((kl->fd = open(path, O_RDONLY)) == -1)
    {
      printf("Need sudo to be installed.\n");
      return (1);
    }
  kl->file = fopen("test.log", "w");
  kl->epoll_fd = epoll_create(sizeof(kl->fd));
  kl->epoll_event.events = EPOLLIN;
  kl->ctrl = epoll_ctl(kl->epoll_fd, EPOLL_CTL_ADD, kl->fd,
		       &kl->epoll_event);
  return (0);
}
