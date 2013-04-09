/* CMPSC 311 Project 7, demo program for pr7.h
 *
 * See try_pr7.h.sh for a command script to compile and run.
 * See try_pr7.h.out for output and commentary.
 */


/* Symbols defined in pr7.h, with _POSIX_C_SOURCE defined or not
 *  MAX_LINE            input line length
 *  MAX_PATH            directory name length
 *  MAX_CHILDREN        number of child processes
 */


#include  <stdio.h>
#include  "pr7.h"

int main(void)
{
#if defined(_POSIX_C_SOURCE)
  #if (_POSIX_C_SOURCE + 0) == 0
    printf("  _POSIX_C_SOURCE is defined\n");
  #else
    printf("  _POSIX_C_SOURCE is defined as %ld\n", (long int) _POSIX_C_SOURCE);
  #endif
#else
  printf("  _POSIX_C_SOURCE is not defined\n");
#endif

  printf("  MAX_LINE        %d\n", MAX_LINE);
  printf("  MAX_PATH        %d\n", MAX_PATH);
  printf("  MAX_CHILDREN    %d\n", MAX_CHILDREN);

  return 0;
}

