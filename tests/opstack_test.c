#include <math.h>
#include <stdio.h>
#include "../data/opstack.h"

double add(double a, double b);
double sub(double a, double b);
double mul(double a, double b);
double div(double a, double b);

int main(int argc, char **argv)
{
	struct opstack *stack = NULL;
	stack = opstack_create();
	opstack_push(stack, add);
	opstack_push(stack, sub);
	opstack_push(stack, mul);
	opstack_push(stack, div);
	opstack_push(stack, pow);
	opstack_push(stack, fmod);
	double a = 5.5;
	double b = 3;
	double (*f)(double, double);
	while (!opstack_empty(stack)) {
		opstack_pop(stack, &f);
		printf("%0.3f\n", f(a,b));
	}
	opstack_destroy(stack);
	return 0;
}

double add(double a, double b) { return a + b; }
double sub(double a, double b) { return a - b; }
double mul(double a, double b) { return a * b; }
double div(double a, double b) { return a / b; }
