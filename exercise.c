#include"stack.h"

/*https://leetcode.cn/problems/valid-parentheses/*/
bool isValid(char* s) 
{
    stack_t st = {0};
    stack_init(&st);

    while (*s)
    {
        if (*s == '(' || *s == '{' || *s == '[')
        {
            stack_push(&st, *s);
        }
        else
        {
            datatype data = stack_top(&st);
            stack_pop(&st);
            if ((*s == ')' && data != '(') ||\
                (*s == ']' && data != '[') ||\
                (*s == '}' && data != '{'))
            {
                stack_destroy(&st);
                return false;
            }

        }
        s++;
    }
	if (stack_empty(&st) == true)
	{
		stack_destroy(&st);
		return false;
	}

    stack_destroy(&st);
    return true;
}

int main()
{
    //char *s = {'(', ')', '[', ']'};
	
    char *s = "([]){";
    bool ret = isValid(s);
    if (ret == true)
    {
        printf("It is ture\n");
    }
    else
    {
        printf("It is false\n");
    }

    return 0;
}
