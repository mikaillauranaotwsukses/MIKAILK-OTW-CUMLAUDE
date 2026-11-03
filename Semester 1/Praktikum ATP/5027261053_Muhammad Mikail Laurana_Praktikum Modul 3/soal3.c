#include <stdio.h>

int Koordinat[10000];
int Visited[10000];


void PencarianNamexxxxxxx(int i, int Sektor, int IndeksAwal,int Langkah){
    if (i < 0 || i >= Sektor){
        printf("-1\n");
        return;
    }

    if(Koordinat[i] == 0){
        printf("%d %d %d\n", IndeksAwal, i, Langkah);
        return;
    }

    if(Visited[i] == 1){
        printf("-1\n");
        return;
    }

    Visited[i] = 1;

    if (Koordinat[i] % 2 == 0){
        PencarianNamexxxxxxx(i + Koordinat[i],Sektor,IndeksAwal,Langkah + 1);
    }else{
        PencarianNamexxxxxxx(i - Koordinat[i],Sektor,IndeksAwal,Langkah + 1);
    }
    
}

int main(){
    int Sektor,IndeksAwal;

    scanf("%d %d", &Sektor,&IndeksAwal);

    for(int i = 0; i < Sektor; i++){
        scanf("%d", &Koordinat[i]);
        Visited[i] =0;
    }

    PencarianNamexxxxxxx(IndeksAwal,Sektor,IndeksAwal,0);
    return 0;
}