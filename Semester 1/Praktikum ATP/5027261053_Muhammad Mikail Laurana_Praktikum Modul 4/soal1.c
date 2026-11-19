#include <stdio.h>

int main(){
    int Input;
    scanf ("%d", &Input);

    for (int i = 1; i <= Input; i++)
    {
        int TotalLoop;
        scanf("%d", &TotalLoop);

        //Angka 1 diluar loop untuk mencari max min
        int AngkaLohYa;
        scanf("%d", &AngkaLohYa);

        int Total;
        int Max;
        int Min;


        Total = AngkaLohYa;
        Max = AngkaLohYa;
        Min = AngkaLohYa;

        for (int x = 1; x < TotalLoop; x++)
        {
            scanf("%d", &AngkaLohYa);
            Total += AngkaLohYa;

            if (AngkaLohYa > Max)
            {
                Max = AngkaLohYa;
            }

            if (AngkaLohYa < Min)
            {
                Min = AngkaLohYa;
            }
        }

        

        printf("---Siklus %d---\n", i);
        printf("Total: %d\n", Total);
        printf("Rata-rata: %.2f\n", (double) Total / TotalLoop);
        printf("Tertinggi: %d\n", Max);
        printf("Terendah: %d\n", Min);        
    }

    return 0;
    
}