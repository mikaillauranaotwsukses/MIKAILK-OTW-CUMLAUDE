#include <stdio.h>

int ApakahPrime(int Angka, int i = 2){
    if(Angka == 0 || Angka == 1){
        return 0;
    }

    if(Angka % i == 0){
        return 0;
    }
    if(i * i > Angka){
        return 1;
    }
}


int main(){
    int input;

    scanf("%d", &input);

}