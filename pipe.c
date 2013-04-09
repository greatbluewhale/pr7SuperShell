// pipe() demo (needs some improvements!)
// the child is downstream from the parent

// This is written for Solaris.
// On Mac OS X, use /bin/date and /bin/cat instead.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#define STDIN  0
#define STDOUT 1
#define STDERR 2

static void oops(char *msg, int errnum)
{
  printf("%s failed: %s\n", msg, strerror(errnum));
  exit(1);
}

int main(int argc, char *argv[])
{
  int fd[2] = { -1, -1 };	/* file descriptors */

  printf("init: fd[0] = %d, fd[1] = %d\n", fd[0], fd[1]);

  if (pipe(fd) != 0)
    oops("pipe()", errno);

  printf("pipe: fd[0] = %d, fd[1] = %d\n", fd[0], fd[1]);

  pid_t ret = fork();

  if (ret == -1)
    {
      /* parent, no child */
      oops("fork()", errno);
    }
  else if (ret == 0)		/* child, downstream */
    {
      close(fd[1]);
      close(STDIN);
      dup(fd[0]);		/* maybe use dup2() instead? */
      close(fd[0]);
      execl("/usr/bin/cat", "/usr/bin/cat", NULL);
      oops("execl()", errno);
    }
  else				/* parent, upstream */
    {
      close(fd[0]);
      close(STDOUT);
      dup(fd[1]);		/* maybe use dup2() instead? */
      close(fd[1]);
      execl("/usr/bin/date", "/usr/bin/date", NULL);
      oops("execl()", errno);
    }

  return 0;
}

