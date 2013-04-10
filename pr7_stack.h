/* CMPSC 311 Project 7 Command Stack Toolkit
 *
 * Author:  Nicholas Dyszel
 * Email:   nwd5069@psu.edu
 *
 * version 1.0, 9 Apr 2013
 *   definitions of stack functions for command stack
 */

#ifndef PR7_STACK_H
#define PR7_STACK_H

struct pr7_stack {
  int length;
  struct pr7_command *top;
};

struct pr7_command {
  char *command;
  struct pr7_command *next;
  struct pr7_command *prev;
};

void stack_init(struct pr7_stack *stack);
struct pr7_command *stack_push(struct pr7_stack *stack, char *command);


#endif
