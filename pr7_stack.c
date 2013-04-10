/* CMPSC 311 Project 7 Command Stack Toolkit
 *
 * Author:  Nicholas Dyszel
 * Email:   nwd5069@psu.edu
 *
 * version 1.0, 7 Apr 2013
 *   implementation of command stack
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pr7_stack.h"

char *strdup(const char *s1);

// Initializes stack
void stack_init(struct pr7_stack *stack)
{
  stack->length = 0;
  stack->top = NULL;
}

// Pushes new command to the top of the stack
// Returns pointer to the new top, NULL if error
struct pr7_command *stack_push(struct pr7_stack *stack, char *command)
{
  struct pr7_command *new = malloc(sizeof(struct pr7_command));
  if (new == NULL)
  {
    fprintf(stderr, "%s: %s: %d: malloc() failed\n", __FILE__, __FUNCTION__, \
            __LINE__);
    return NULL;
  }
  new->command = strdup(command);
  int len = strlen(new->command);
  if (new->command[len-1] == '\n')
  {
    if (new->command[len-2] == '\r') new->command[len-2] = '\0';
    else new->command[len-1] = '\0';
  }
  else if (new->command[len-1] == '\r') new->command[len-1] = '\0';
  new->next = stack->top;
  new->prev = NULL;
  stack->top = new;
  if (new->next != NULL) new->next->prev = new;
  return new;
}