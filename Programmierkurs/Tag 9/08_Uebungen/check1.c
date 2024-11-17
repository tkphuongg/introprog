#include <stdio.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>

int summe(int x, int y);
int main(){
    // u_int16_t arr[4] = {1, 2, 3, 4};
    // size_t length = 2;
    // for(size_t x = 0; x < length; x++){
    //     if (check_col(arr, x, length) == false){
    //         printf("col %zu has duplicate\n", x);
    //     }
    // }

    // for(size_t y = 0; y < length; y++){
    //     if (check_row(arr, y, length) == false){
    //         printf("row %zu has duplicate\n", y);
    //     }
    // }
    
    //printf("%d\n");


    int a = summe(1, 1);

    printf("%i\n", summe(2, 3));
    printf("%i ist %c\n", summe(1, 3), 'a');

}

//bool is_latin_square(uint16_t arr[], size_t length) {
//     for(size_t x = 0; x < length; x++){
//         if (!check_col(arr, x, length)){
//             return false;
//         }
//     }

//     for(size_t y = 0; y < length; y++){
//         if (!check_row(arr, y, length)){
//             return false;
//         }
//     }
// }

int produkt(int x, int y){
    int mal = x * y;
    return mal;
}

