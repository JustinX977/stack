#ifndef __STACK_H__
#define __STACK_H__

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int datatype;

typedef struct stack
{
	datatype *data;
	int top;
	int capacity;
}stack_t;

void stack_init(stack_t *ps);
void stack_destroy(stack_t *ps);
void stack_push(stack_t *ps, datatype x);
void stack_pop(stack_t *ps);
datatype stack_top(stack_t *ps);
int stack_size(stack_t *ps);
bool stack_empty(stack_t *ps);




#endif /*__STACK_H__*/
