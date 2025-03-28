#include"stack.h"

void stack_test1(void)
{
	stack_t st = {0};
	stack_init(&st);
	stack_push(&st, 1);
	stack_push(&st, 2);
	stack_push(&st, 3);
	stack_push(&st, 4);
	stack_push(&st, 5);
	stack_push(&st, 6);
	stack_push(&st, 7);

	datatype ret = stack_top(&st);
	printf("ret = %d\n", ret);

	stack_print(&st);

	stack_destroy(&st);
}

int main(void)
{
	//stack_test1();
	
	return 0;
}

void stack_print(stack_t *ps)
{
	while (!stack_empty(ps))
	{
		printf("%d\t", stack_top(ps));
		stack_pop(ps);
	}
}

void stack_init(stack_t *ps)
{
	assert(ps);

	ps->data = NULL;
	ps->top = 0;
	ps->capacity = 0;

}

void stack_destroy(stack_t *ps)
{
	assert(ps);

	free(ps->data);

	ps->data = NULL;
	ps->top = ps->capacity = 0;
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
	assert(ps);

	ps->top = (ps->top == 0 ? 0 : ps->top - 1);
}

datatype stack_top(stack_t *ps)
{
	assert(ps);
	assert(ps->top > 0);
	return ps->data[ps->top - 1];
}

int stack_size(stack_t *ps)
{
	assert(ps);
	return ps->top;
}

bool stack_empty(stack_t *ps)
{
	return ps->top == 0;
}


