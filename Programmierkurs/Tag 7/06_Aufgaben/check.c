#include <stdio.h>

float normalize(int value, int max){
    // float float_value = 1.0 * value;
    // float normalized_val = float_value / max;
    return 1.0 * value / max;
}
int main(){
    printf("%.1f\n", normalize(2, 4));
}