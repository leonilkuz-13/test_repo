#include "test.h"

int calc_rect(int w, int h, int type) {
    if (type == 1) return (w * h);
    else return (w + h) * 2 ;
}