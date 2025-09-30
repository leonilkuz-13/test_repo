#include <stdio.h>
#include <string.h>

/* Для решения задачи были выбраны '()' */
/* В задаче не было сказано о количестве символов в входных данных, потому пользователю будут показаны только первые 100 символов */

int main(void)
{
    int i = 0;
    char string[101];
    char g;

    while (g = getchar(), g != '\n' && g != EOF && i < sizeof(string) - 1)
    {
        if (g != '{' && g != '}' && g != '[' && g != ']' && g != '>' && g != '<')
        {
            string[i++] = g;
        }
        else
        {
            puts("Incorrect input");
            return 0;
        }
    }

    string[i] = '\0';

    int cnt = 0;
    int flag = 0;

    for (int i = 0; i < (int)sizeof(string); i++)
    {
        if (string[i] == '(')
        {
            cnt++;
            flag = 1;
        }

        if (string[i] == ')')
        {
            cnt--;
        }

        if (cnt < 0)
        {
            puts("The balance of brackets isn't maintained");
            return 0;
        }
    }

    if (flag == 1)
    {
        puts("The balance of brackets is maintained");
    }
    else
    {
        puts("No brackets were entered");
    }

    return 0;
}