/*
 * dstack.c: implementation of a double floating point stack
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
#include "data/dstack.h"

/* RESIZE(x): resize the value of x by a value of 3/2 */
#define RESIZE(x) (((x) * 3) >> 1 * sizeof((x)))

struct dstack {
	double *array;
	size_t top;
	size_t len;
};

struct dstack* dstack_create(void) {
	const size_t INITIAL_SIZE = 24;
	struct dstack *stack = malloc(sizeof(struct dstack));
	if (stack) {
		stack->array = malloc(INITIAL_SIZE * sizeof(double));
		stack->top = 0;
		stack->len = INITIAL_SIZE;
	}
	if (!stack->array)
		free(stack);
	return stack;
}

int dstack_destroy(struct dstack* stack)
{
	free(stack->array);
	free(stack);
	return 0;
}

enum stack_return dstack_push(struct dstack* stack, double x)
{
	if (!stack)
		return STACK_NULL;
	if (stack->top == stack->len - 1) {
		if (!(stack = realloc(stack, RESIZE(stack->len))))
			return STACK_OVERFLOW;
		stack->len = RESIZE(stack->len);
	}
	stack->array[++stack->top] = x;
	return STACK_OK;
}

enum stack_return dstack_pop(struct dstack* stack, double* x)
{
	if (!stack)
		return STACK_NULL;
	if (x)
		*x = stack->array[stack->top];
	stack->array[stack->top] = 0;
	stack->top--;
	return STACK_OK;
}

enum stack_return dstack_clear(struct dstack* stack)
{
	if (!stack)
		return STACK_NULL;
	while (stack->top > 0)
		stack->array[stack->top--] = 0;
	stack->array[0] = 0;
	return STACK_OK;
}

unsigned char dstack_empty(struct dstack* stack)
{
	return stack->top == 0;
}
