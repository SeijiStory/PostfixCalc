/*
 * stack_return.h: enum for identifying errors in stack operations
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

#define _STACK_RETURN
enum stack_return {
	STACK_OK,
	STACK_OVERFLOW,
	STACK_UNDERFLOW,
	STACK_NULL,
	STACK_UNKOWNERR
};
