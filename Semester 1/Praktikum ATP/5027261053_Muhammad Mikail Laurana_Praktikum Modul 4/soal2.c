#include <stdio.h>

struct DataTim
{
    char NamaTim[100];
    int Menang;
    int Seri;
    int Kalah;
    int GolMasuk;
    int GolKebobolan;
    int TotalPoin;
};

int main(){
    int Input;

    scanf("%d", &Input);

    struct DataTim Klasemen[100];
    
    for (int i = 0; i < Input; i++)
    {
        scanf("%s %d %d %d %d %d", Klasemen[i].NamaTim, &Klasemen[i].Menang, &Klasemen[i].Seri, 
            &Klasemen[i].Kalah, &Klasemen[i].GolMasuk, &Klasemen[i].GolKebobolan);

        Klasemen[i].TotalPoin = (Klasemen[i].Menang * 3) + (Klasemen[i].Seri * 1);
    }

    int Juaranya = 0;
    for (int i = 1; i < Input; i++)
    {
        int SelisihTim = Klasemen[i].GolMasuk - Klasemen[i].GolKebobolan;
        int SelisihJuara = Klasemen[Juaranya].GolMasuk - Klasemen[Juaranya].GolKebobolan;

        if (Klasemen[i].TotalPoin > Klasemen[Juaranya].TotalPoin || 
            (Klasemen[i].TotalPoin == Klasemen[Juaranya].TotalPoin && SelisihTim > SelisihJuara)){
            Juaranya = i;
        }
    }

    printf("Juara: %s\n",Klasemen[Juaranya].NamaTim);
    printf("Poin: %d\n",Klasemen[Juaranya].TotalPoin);
    printf("Selisih gol: %d\n", (Klasemen[Juaranya].GolMasuk - Klasemen[Juaranya].GolKebobolan));
    return 0;
}
