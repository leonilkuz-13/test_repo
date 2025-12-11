#include <stdio.h>
#include <string.h>

/*в условии задачи не было указано количество символов во входном потоке, потому
 * пользователь сможет ввести только 100 символов*/

int main(void)
{
    char str[101];
    char substr[100];
    int count = 0;

    fgets(str, sizeof(str) - 1, stdin);
    fgets(substr, sizeof(substr) - 1, stdin);

    char *g = strchr(str, '\n'), *g1 = strchr(substr, '\n');

    if (g != NULL && g1 != NULL) {
        *g = '\0';
        *g1 = '\0';
    }

    char* ptr = str;
    ptr = strstr(ptr, substr);
    while (ptr != NULL) {
        count++;
        ptr++;
        ptr = strstr(ptr, substr);
    }
    if (count > 0) {
        printf("count substr in str = %d", count);
    } else {
        puts("The substr isn't in str");
    }
    return 0;
}