#include <stdio.h>

void CariDiamond(int lokasiDmD[],int input){
    for(int i = 0; i < input; i++){
        if(lokasiDmD[i] == 1){
            printf("DIAMOND! DIAMOND! DIAMOND! DIAMOND!\n");
            printf("Diamond ditemukan pada cave ke-%d",(i+1));
            return;
        }
    }
    printf("That's La Peace");
    return;
}
int main(){
    int input;

    scanf("%d", &input);

    int lokasiDmd[input];
    for(int m = 0; m<input; m++){
        scanf("%d", &lokasiDmd[m]);
    }
    CariDiamond(lokasiDmd,input);
}