#include"stack.h"

/*https://leetcode.cn/problems/valid-parentheses/*/
bool isValid(char* s) 
{
    stack_t st = {0};
    stack_init(&st);
    bool ret = false;

    while (*s)
    {
        if (*s == '(' || *s == '{' || *s == '[')
        {
            stack_push(&st, *s);
        }
        else
        {
            // 如果只有右括号，但是栈里面没有数据，说明不匹配
            if (stack_empty(&st) == false)
            {
                goto exit;
            }
            datatype data = stack_top(&st);
            stack_pop(&st);
            if ((*s == ')' && data != '(') ||\
                (*s == ']' && data != '[') ||\
                (*s == '}' && data != '{'))
            {
                goto exit;
            }

        }
        s++;
    }

    // 栈里面还有数据，最后都没找到匹配的左括号，说明不匹配
	if (stack_empty(&st) == false)
	{
		goto exit;
	}

    ret = true;
exit:
    stack_destroy(&st);
    return ret;
}

int main()
{
    //char *s = "([])"
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
