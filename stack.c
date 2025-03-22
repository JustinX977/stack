#include"stack.h"

void stack_init(stack_t *ps)
{
	assert(ps);

	ps->data = NULL;
	ps->top = 0;
	ps->capacity = 0;

}

void stack_destroy(stack_t *ps)
{

}

void stack_push(stack_t *ps, datatype x)
{
	assert(ps);

	if (ps->top == ps->capacity)
	{
		int newcapacity = ps->capacity;
		newcapacity = newcapacity == 0 ? 4 : ps->capacity * 2;
		datatype *temp = (datatype *)realloc(ps->data, sizeof(datatype) * newcapacity);
		if (temp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}

		ps->data = temp;
		ps->capacity = newcapacity;
	}

	ps->data[ps->top++] = x;
}

void stack_pop(stack_t *ps)
{

}

datatype stack_top(stack_t *ps)
{

}

int stack_size(stack_t *ps)
{

}

bool stack_empty(stack_t *ps)
{

}


