#include <stdio.h>
#include <string.h>

struct Mahasiswa
{
    char Nama[100];
    int Matematika;
    int Ipa;
    int BahasaIndonesia;
    int BahasaInggris;
};

int main(){
    struct Mahasiswa mhs[100];
    int totalMhs;

    printf("Masukan total mahasiswa yang diinput : ");
    scanf("%d", &totalMhs);

    for (int i = 0; i < totalMhs; i++) {
        scanf("%s", mhs[i].Nama);
        scanf("%d", &mhs[i].Matematika);
        scanf("%d", &mhs[i].Ipa);
        scanf("%d", &mhs[i].BahasaIndonesia);
        scanf("%d", &mhs[i].BahasaInggris);
    }

    int mencari;
    printf("Masukan total mahasiswa yang ingin dicari : ");
    scanf("%d", &mencari);

    for (int j = 0; j < mencari; j++)
    {
        char cari[100];
        printf("Masukan Nama yang ingin dicari : ");
        scanf("%s", cari);              // FIX #1: pakai %s, bukan &s

        for (int i = 0; i < totalMhs; i++)
        {
            if (strcmp(mhs[i].Nama, cari) == 0)
            {
                printf("Nilai %s\n", mhs[i].Nama);        // FIX #2: pakai i, bukan j
                printf("Matematika : %d\n", mhs[i].Matematika);
                printf("IPA : %d\n", mhs[i].Ipa);
                printf("Bahasa Indonesia : %d\n", mhs[i].BahasaIndonesia);
                printf("Bahasa Inggris : %d\n", mhs[i].BahasaInggris);
                break;
            }
            else{
                printf("Data tidak ditemukan\n");
            }
        }
    }

    return 0;
}
