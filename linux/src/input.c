/*
** test.c for test in /home/casoni_f/test/input
** 
** Made by Fabien Casoni
** Login   <casoni_f@epitech.net>
** 
** Started on  Thu Jun 26 20:51:59 2014 Fabien Casoni
** Last update Wed Jul  2 18:05:19 2014 Fabien Casoni
*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <linux/input.h>
#include <string.h>

#define EV_RELEASED 0

int			main()
{
  int			fd;
  char			*device = "/dev/input/event3";
  struct input_event	event;
  unsigned int		scan_code = 0;
  int			num_bytes;
  FILE			*f;

  fd = open(device, O_RDWR);
  f = fopen("log", "w");
  while (1)
    {
      memset(&event, 0, sizeof(struct input_event));
      num_bytes = read(fd, &event, sizeof(struct input_event));
      printf("%d\n", event.value);
      /* if (event.type == EV_KEY && event.value == EV_RELEASED) */
      /* 	{ */
      /* 	  scan_code = event.code; */
      /* 	  fprintf(f, "%d\n", scan_code); */
      /* 	} */
    }
}
