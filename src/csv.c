#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char** field;
    int fieldCnt;
} Row;

typedef struct {
    Row* rows;
    int col;
    int cnt;
} Board;

char** parse(FILE* file, size_t* num)
{
    // массив строк + их количество в строке, поскольку я их динамически выделяю
    int capacityArr = 3;
    int stringCnt = 0;
    char** array = malloc(sizeof(char*) * capacityArr);
    if (array == NULL) {
        return NULL;
    }
    size_t index = *num;
    char* line = file;
    bool flag = false;
    int fieldCnt = 0;

    int indexSTATIC = 0;
    while (line[index] != '\0') {
        if (line[index] == '"') {
            flag = !flag;
        } else if (flag == false && line[index] == ',') {
            int len = index - indexSTATIC;
            char* string = malloc(sizeof(char) * (len + 1));
            if (string == NULL) {
                return NULL;
            }
            string = memcpy(string, line + indexSTATIC, len);
            string[len] = '\0';
            if (stringCnt >= capacityArr) {
                capacityArr *= 2;
                array = realloc(array, capacityArr);
                if (array == NULL) {
                    return NULL;
                }
            }
            array[stringCnt++] = string;
            indexSTATIC = index + 1;
            fieldCnt++;
        }
        index++;
    }
}

char* read(FILE* file)
{
    size_t capacity = 100;
    size_t len = 0;
    char* Buff = malloc(capacity);
    if (Buff == NULL) {
        return NULL;
    }

    int var = 0;
    while ((var = fgetc(file)) != EOF) {
        if (len + 1 >= capacity) {
            capacity *= 2;
            char* newBuff = realloc(Buff, capacity);
            if (newBuff == NULL) {
                free(Buff);
                return NULL;
            }
            Buff = newBuff;
        }

        Buff[len++] = (char)(var);

        if (var == '\n') {
            break;
        }
    }

    if (len == 0 && var == EOF) {
        free(Buff);
        return NULL;
    }

    Buff[len] = '\0';
    return Buff;
}

int main()
{
    FILE* file = fopen("file.csv", "r");
    if (file == NULL) {
        return -1;
    }
    char* line;
    while ((line = read(file)) != NULL) {
        printf("%s", line);
        // парсинг + запись в out, после освобождение

        free(line);
    }
    fclose(file);
    return 0;
}