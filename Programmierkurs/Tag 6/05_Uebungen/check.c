#include <stdio.h>
#include <math.h>

int check_digit(int n);
int check_consecutive_seven(int n);
int tricky_numbers(int n);

int main(){
    tricky_numbers(2);
    // tricky_numbers(5);
    // tricky_numbers(6);
}

int check_digit(int n){
    if (n == 7 || n == 4) 
    {
        return 1;
    }
    else if ((n % 10 != 7 && n % 10 != 4)){
        return 0;
    }
    else{
        n /= 10;
        return check_digit(n);
    }
}

int check_consecutive_seven(int n){
    if ((n % 100) / 11 == 7 && (n % 100) % 11 == 0){
        return 0;
    }
    else if (n < 10)
    {
        return 1;
    }
    
    else{
        n /= 10;
        return check_consecutive_seven(n);
    }
}

int tricky_numbers(int n) {
    static int iterate = -1;
    iterate++;
    printf("iterate: %i\n", iterate);
    printf("compare result case 1: %i < %f = %i\n", iterate, pow(10, n - 1), iterate < pow(10, n - 1));
    if (iterate == 0 && n == 0){
        return 1;
    }
    else if (iterate < pow(10, n - 1)){
        // printf("lower limit: %i\n", pow(10, n - 1));
        // printf("Case 1 fulfilled\n");
        return tricky_numbers(n);
    }
    else if (iterate <= pow(10, n)){
        printf("higher limit: %f\n", pow(10, n));
        if (check_digit(iterate) && check_consecutive_seven(iterate)){
            printf("Case 2 fulfilled\n");
            printf("compare result case 2: %i && %i = %i\n", check_digit(iterate), check_consecutive_seven(iterate), check_digit(iterate) && check_consecutive_seven(iterate));
            return 1 + tricky_numbers(n);
        }
        else {
            return tricky_numbers(n);
        }
    }
    else {
        return 0;
    }
}