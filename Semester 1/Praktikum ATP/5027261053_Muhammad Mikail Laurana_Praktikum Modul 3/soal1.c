#include <stdio.h>

long long mugenTsukoyomi(long long n){
    if(n <= 0){
        return 0;
    }

    return 1 + mugenTsukoyomi(n /2);
}


int main(){
    long long n;
    scanf("%lld", &n);

    printf("%lld", mugenTsukoyomi(n));
    return 0;
}