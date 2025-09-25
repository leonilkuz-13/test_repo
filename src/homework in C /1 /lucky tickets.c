#include <stdio.h>

int main(void) {
    long int cnt = 0;
    for (int i_1 = 0; i_1 <= 9; i_1++){
        for (int i_2 = 0; i_2 <= 9; i_2++){
            for (int i_3 = 0; i_3 <= 9;i_3++){
                for (int i_4 = 0; i_4 <= 9;i_4++){
                    for (int i_5 = 0; i_5 <= 9;i_5++){
                        for (int i_6 = 0; i_6 <= 9;i_6++){
                            if ((i_1 + i_2 + i_3) == (i_4 + i_5 + i_6))
                                cnt++;
                        }
                    }
                }
            }
        }
    }
    printf("%ld",cnt);
    return 0;
}


