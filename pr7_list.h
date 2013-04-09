/* CMPSC 311 Project 7 Linked List Toolkit
 *
 * Author:  Nicholas Dyszel
 * Email:   nwd5069@psu.edu
 *
 * version 1.0, 7 Apr 2013
 *   definitions of linked list functions for process list
 */

#ifndef PR7_LIST_H
#define PR7_LIST_H

#include <sys/types.h>

#define STATE_RUNNING 0
#define STATE_TERMINATED 1

struct pr7_list {
  int length;
  struct pr7_process *head;
  struct pr7_process *tail;
  char *name;
};

struct pr7_process {
  pid_t pid;
  int state;
  int exit_status;
  struct pr7_process *next;
  struct pr7_process *prev;
};

void list_init(struct pr7_list *list);
struct pr7_process *list_add(struct pr7_list *list, pid_t pid);
int list_remove(struct pr7_list *list, struct pr7_process *entry);
struct pr7_process *list_search(struct pr7_list *list, pid_t key);
struct pr7_process *list_add_once(struct pr7_list *list, pid_t pid, \
                                  int mode);
struct pr7_process *list_update_entry(struct pr7_list *list, pid_t pid, int status);
int list_remove_entry(struct pr7_list *list, pid_t pid);

void list_print(struct pr7_list *list);

#endif
