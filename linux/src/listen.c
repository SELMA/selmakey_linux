/*
** listen.c for selmakey in /home/alexmog/projets/SELMA/selmakey/linux/src
** 
** Made by Moghrabi Alexandre
** Login   <alexmog@epitech.net>
** 
** KeyHandling
** 
** Started on  Thu Jun 26 21:55:54 2014 Moghrabi Alexandre
** Last update Wed Jul  2 17:38:07 2014 Fabien Casoni
*/

#include <string.h>
#include <linux/input.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void			ctrl_c_handler(int sig)
{
  (void)sig;
  exit(0);
}

void			send_keycode(int code, FILE *file)
{
  fprintf(file, "%d\n", code);
}

void			start_listening(int fd)
{
  struct input_event	event;
  unsigned int		readed;
  FILE			*file;

  file = fopen("log", "w");
  signal(SIGINT, ctrl_c_handler);
  while (1337)
    {
      memset(&event, 0, sizeof(struct input_event));
      readed = read(fd, &event, sizeof(struct input_event));
      if (readed == sizeof(struct input_event)
	  && event.type == EV_KEY && event.value == 0)
	send_keycode(event.code, file);
    }
}
