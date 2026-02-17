#include <stdio.h>

void draw_line(int widths[], int col_count)
{
    puts("|");
    for (int i = 0; i < col_count; i++) {
        for (int j = 0; j < widths[i]; j++) {
            puts("-");
        }
        puts("|");
    }
    puts("\n");
}

int main()
{
    FILE* file = fopen("data.csv", "r");
    if (file == NULL) {
        return 1;
    }
}