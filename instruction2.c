#include "monty.h"

/**
 * instruct_add - adds the top two elements of the stack
 * @stack: pointer to the top node of stack
 * @line: the current file line number calling instruction
 */
void instruct_add(stack_t **stack, unsigned int line)
{
int n = 0;
if (var.len_stack < 2)
{
fprintf(stderr, "L%u: can't add, stack too short\n", line);
exit(EXIT_FAILURE);
}
n += (*stack)->n;
instruct_pop(stack, line);
(*stack)->n += n;
}

/**
 * instruct_nop - nop doesn’t do anything
 * @stack: pointer to the top node of stack
 * @line: the current file line number calling instruction
 */
void instruct_nop(stack_t **stack __attribute__ ((unused)), unsigned int line)
{
(void) line;
}

/**
 * instruct_sub - sub subtracts the top from the second top element
 * @stack: pointer to the top node of stack
 * @line: the current file line number calling instruction
 */
void instruct_sub(stack_t **stack, unsigned int line)
{
int n;
if (var.len_stack < 2)
{
fprintf(stderr, "L%u: can't sub, stack too short\n", line);
exit(EXIT_FAILURE);
}
n = (*stack)->n;
instruct_pop(stack, line);
(*stack)->n -= n;
}

/**
 * instruct_div - divides the second top by the top element of the stack
 * @stack: pointer to the top node of stack
 * @line: the current file line number calling instruction
 */
void instruct_div(stack_t **stack, unsigned int line)
{
int n;
if (var.len_stack < 2)
{
fprintf(stderr, "L%u: can't div, stack too short\n", line);
exit(EXIT_FAILURE);
}
n = (*stack)->n;
instruct_pop(stack, line);
if (n == 0)
{
fprintf(stderr, "L%u: division by zero\n", line);
exit(EXIT_FAILURE);
}
(*stack)->n /= n;
}

/**
 * instruct_mul - multiplies the second top with the top element
 * @stack: pointer to the top node of stack
 * @line: the current file line number calling instruction
 */
void instruct_mul(stack_t **stack, unsigned int line)
{
int n;
if (var.len_stack < 2)
{
fprintf(stderr, "L%u: can't mul, stack too short\n", line);
exit(EXIT_FAILURE);
}
n = (*stack)->n;
instruct_pop(stack, line);
(*stack)->n *= n;
}
