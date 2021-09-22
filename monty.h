#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>

#define STACK 0
#define QUEUE 1

/**
 * struct var_s - struct contains main variables of the Monty interpreter
 * @len_queue: flag 0: stack, 1: queue
 * @len_stack: length of the stack
 */
typedef struct var_s
{
int len_queue;
size_t len_stack;
} var_t;

/* global flag contains queue and stack length */
extern var_t var;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
int n;
struct stack_s *prev;
struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

stack_t *add_node(stack_t **stack, const int n);
void free_stack(int status, void *arg);
void free_lineptr(int status, void *arg);
void myfile_close(int status, void *arg);
void call_oper(stack_t **stack, char *oper, unsigned int line);

void instruct_push(stack_t **stack, unsigned int line);
void instruct_pall(stack_t **stack, unsigned int line);
void instruct_pint(stack_t **stack, unsigned int line);
void instruct_pop(stack_t **stack, unsigned int line);
void instruct_swap(stack_t **stack, unsigned int line);
void instruct_add(stack_t **stack, unsigned int line);
void instruct_nop(stack_t **stack, unsigned int line);
void instruct_sub(stack_t **stack, unsigned int line);
void instruct_div(stack_t **stack, unsigned int line);
void instruct_mul(stack_t **stack, unsigned int line);
void instruct_mod(stack_t **stack, unsigned int line);
void instruct_pchar(stack_t **stack, unsigned int line);
void instruct_pstr(stack_t **stack, unsigned int line);
void instruct_rotl(stack_t **stack, unsigned int line);
void instruct_rotr(stack_t **stack, unsigned int line);

int check_isdigit(char *str);
void set_queue(stack_t **stack, unsigned int line);
void set_stack(stack_t **stack, unsigned int line);

#endif
