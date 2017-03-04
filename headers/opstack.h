/*
 * opstack.h: stack data structure for storing functions operating on doubles
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

#include <stddef.h>
#ifndef _STACK_RETURN
#include "stack_return.h"
#endif

struct opstack;

struct opstack* opstack_create(void);
int opstack_destroy(struct opstack*);

enum stack_return opstack_push(struct opstack*, double (*)(double, double));
enum stack_return opstack_pop(struct opstack*, double (**)(double, double));

enum stack_return opstack_clear(struct opstack*);

unsigned char opstack_empty(struct opstack*);
