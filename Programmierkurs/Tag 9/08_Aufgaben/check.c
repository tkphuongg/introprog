#include <stdio.h>

u_int16_t *merge(u_int16_t left[], u_int16_t right[], size_t left_size, size_t right_size);
u_int16_t *merge_sort(u_int16_t array[], size_t len);


int main(){
    u_int16_t array_to_sort_1[8] = {1, 23, 54, 12, 1, 8, 30, 27};
    int size = sizeof(array_to_sort_1) / sizeof(u_int16_t);

    printf("Length of array: %i\n", size);
    printf("Input array: \n");
    for (int i = 0; i < size; i++){
        printf("%i ", array_to_sort_1[i]);
    }
    printf("\n");

    printf("Output array: \n");
    u_int16_t out[8] = merge_sort(array_to_sort_1, 8);
    for (int j = 0; j < size; j++){
        printf("%i ", out[j]);
    }
    printf("\n");
    return 0;
}

u_int16_t *merge(u_int16_t left[], u_int16_t right[], size_t left_size, size_t right_size){
    int left_index = 0, right_index = 0, out_index = 0;
    u_int16_t out[left_size + right_size];
    while (left_index < left_size && right_index < right_size){
        if(left[left_index] < right[right_index]){
            out[out_index] = left[left_index];
            left_index++;
        }
        else{
            out[out_index] = right[right_index];
            right_index++;
        }
        out_index++;
    }

    while (left_index < left_size){
        out[out_index] = left[left_index];
        out_index++;
        left_index++;
    }

    while (right_index < right_size){
        out[out_index] = right[right_index];
        out_index++;
        right_index++;
    }

    return out;
}

u_int16_t *merge_sort(u_int16_t array[], size_t len){
    if(len <= 1){
        return array;
    }
    else{
        size_t half_len = len / 2;
        u_int16_t left[half_len];
        left = array;
        u_int16_t right[len - half_len];
        right = &array[half_len];
        
        left = merge_sort(left, sizeof(left) / sizeof(u_int16_t));
        right = merge_sort(right, sizeof(right) / sizeof(u_int16_t));

        return merge(left, right, sizeof(left)/16, sizeof(right)/16);
    }

}

void sort_ascending(u_int16_t in[], u_int16_t out[], size_t len) {
    return;
}
