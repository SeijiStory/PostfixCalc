/*
 * opstack.c: implementation of a double function stack
 *
 * Copyright (C) 2017  Seiji Story
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdlib.h>
#include "data/opstack.h"

/* RESIZE(x): resize the value of x by a value of 3/2 */
#define RESIZE(x) (((x) * 3) >> 1 * sizeof((x)))

struct opstack {
	double (**array)(double, double);
	size_t top;
	size_t len;
};

struct opstack* opstack_create(void) {
	const size_t INITIAL_SIZE = 24;
	struct opstack *stack = malloc(sizeof(struct opstack));
	double (*temp)(double, double);
	if (stack) {
		stack->array = malloc(INITIAL_SIZE * sizeof(temp));
		stack->top = 0;
		stack->len = INITIAL_SIZE;
	}
	if (!stack->array)
		free(stack);
	return stack;
}

int opstack_destroy(struct opstack* stack)
{
	free(stack->array);
	free(stack);
	return 0;
}

enum stack_return opstack_push(struct opstack* stack,
			       double (*f)(double, double))
{
	if (!stack)
		return STACK_NULL;
	if (stack->top == stack->len - 1) {
		if (!(stack = realloc(stack, RESIZE(stack->len))))
			return STACK_OVERFLOW;
		stack->len = RESIZE(stack->len);
	}
	stack->array[++stack->top] = f;
	return STACK_OK;
}

enum stack_return opstack_pop(struct opstack* stack,
			      double (**f)(double, double))
{
	if (!stack)
		return STACK_NULL;
	if (f)
		*f = stack->array[stack->top];
	stack->array[stack->top] = 0;
	stack->top--;
	return STACK_OK;
}

enum stack_return opstack_clear(struct opstack* stack)
{
	if (!stack)
		return STACK_NULL;
	while (stack->top > 0)
		stack->array[stack->top--] = 0;
	stack->array[0] = 0;
	return STACK_OK;
}

unsigned char opstack_empty(struct opstack* stack)
{
	return stack->top == 0;
}
