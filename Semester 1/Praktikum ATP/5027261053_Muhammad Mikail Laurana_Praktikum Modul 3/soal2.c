#include <stdio.h>

void NamaPlayer(int i){
    int urutan = i  % 8;
    if (urutan == 0) {
        printf("Nao");
    }
    else if (urutan == 1) {
        printf("Hanazonkk");
    }
    else if (urutan == 2) {
        printf("Zynch");
    }
    else if (urutan == 3) {
    printf("ChikenCip");
    }
    else if (urutan == 4) {
        printf("Zaro");
    }
    else if (urutan == 5) {
        printf("Nanno");
    }
    else if (urutan == 6) {
        printf("Ftx");
    }
    else if (urutan == 7) {
        printf("Kokee");
    }
}

int MenentukanTotalDiamond(int totaldiamond[],int input){
    int total = 0;
    for(int i = 0; i < input; i++){
        if(totaldiamond[i]> 0){
            NamaPlayer(i);
            printf(" menemukan %d jumlah diamond di cave ke-%d \n",totaldiamond[i],i + 1);
            total += totaldiamond[i];
        }
    }

    return total;

}



int main(){
    int input;
    int totaldiamond[100000];

    scanf("%d", &input);
    for(int m = 0; m < input; m++){
        scanf("%d", &totaldiamond[m]);
    }

    int total = MenentukanTotalDiamond(totaldiamond,input);

    if (total > 0){
        printf("DIAMOND! DIAMOND! DIAMOND! DIAMOND!\n");
        printf("Total jumlah diamond yang didapat: %d\n", total);

        if (total >= 1 && total <= 64) {
            printf("Ftx sama Zynch wajib traktir GOONERS lain\n");
        } else if (total >= 65 && total <= 128) {
            printf("GOONERS tidur besok nguli lagi\n");
        } else if (total >= 129 && total <= 192) {
            printf("Para GOONERS makan-makan hari ini\n");
        }
    }else{
            printf("That's La Peace\n");
            printf("Sayang sekali Tim GOONERS pulang dengan tangan kosong\n");
    }
}