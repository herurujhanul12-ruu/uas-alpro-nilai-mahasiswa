#include <stdio.h>
#include <string.h>

#define MAX 30
#define KOMPONEN 3

char nim[MAX][20];
float nilai[MAX][KOMPONEN];
int jumlah = 0;



int faktorial(int n) {
    if (n <= 1)
        return 1;
    return n * faktorial(n - 1);
}

int fibonacci(int n) {
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int cariNIM(char cari[]) {
    for (int i = 0; i < jumlah; i++) {
        if (strcmp(nim[i], cari) == 0)
            return i;
    }
    return -1;
}



void tampilData() {
    if (jumlah == 0) {
        printf("Data kosong!\n");
        return;
    }

    printf("\nNIM\t\tTugas\tUTS\tUAS\n");
    for (int i = 0; i < jumlah; i++) {
        printf("%s\t%.2f\t%.2f\t%.2f\n",
               nim[i], nilai[i][0], nilai[i][1], nilai[i][2]);
    }
}

void tambahData() {
    if (jumlah >= MAX) {
        printf("Data sudah penuh!\n");
        return;
    }

    printf("Masukkan NIM: ");
    scanf("%s", nim[jumlah]);

    printf("Nilai Tugas: ");
    scanf("%f", &nilai[jumlah][0]);
    printf("Nilai UTS: ");
    scanf("%f", &nilai[jumlah][1]);
    printf("Nilai UAS: ");
    scanf("%f", &nilai[jumlah][2]);

    jumlah++;
    printf("Data berhasil ditambahkan.\n");
}

void ubahData() {
    char cari[20];
    printf("Masukkan NIM yang ingin diubah: ");
    scanf("%s", cari);

    int idx = cariNIM(cari);
    if (idx == -1) {
        printf("Data tidak ditemukan.\n");
        return;
    }

    printf("Nilai Tugas baru: ");
    scanf("%f", &nilai[idx][0]);
    printf("Nilai UTS baru: ");
    scanf("%f", &nilai[idx][1]);
    printf("Nilai UAS baru: ");
    scanf("%f", &nilai[idx][2]);

    printf("Data berhasil diubah.\n");
}

void hapusData() {
    char cari[20];
    printf("Masukkan NIM yang ingin dihapus: ");
    scanf("%s", cari);

    int idx = cariNIM(cari);
    if (idx == -1) {
        printf("Data tidak ditemukan.\n");
        return;
    }

    for (int i = idx; i < jumlah - 1; i++) {
        strcpy(nim[i], nim[i + 1]);
        for (int j = 0; j < KOMPONEN; j++)
            nilai[i][j] = nilai[i + 1][j];
    }

    jumlah--;
    printf("Data berhasil dihapus.\n");
}

void olahNilai() {
    float rata[MAX];
    float totalTugas = 0, totalUTS = 0, totalUAS = 0;

    for (int i = 0; i < jumlah; i++) {
        rata[i] = (nilai[i][0] + nilai[i][1] + nilai[i][2]) / 3;
        totalTugas += nilai[i][0];
        totalUTS += nilai[i][1];
        totalUAS += nilai[i][2];
    }

    int max = 0, min = 0;
    for (int i = 1; i < jumlah; i++) {
        if (rata[i] > rata[max]) max = i;
        if (rata[i] < rata[min]) min = i;
    }

    printf("\nRata-rata Tugas: %.2f\n", totalTugas / jumlah);
    printf("Rata-rata UTS: %.2f\n", totalUTS / jumlah);
    printf("Rata-rata UAS: %.2f\n", totalUAS / jumlah);

    printf("\nRata-rata tertinggi: %s (%.2f)\n", nim[max], rata[max]);
    printf("Rata-rata terendah: %s (%.2f)\n", nim[min], rata[min]);
}

void fiturRekursif() {
    printf("\nFaktorial jumlah mahasiswa (%d): %d\n",
           jumlah, faktorial(jumlah));

    printf("Deret Fibonacci (%d): ", jumlah);
    for (int i = 0; i < jumlah; i++)
        printf("%d ", fibonacci(i));
    printf("\n");
}


int main() {
    int pilihan;

    do {
        printf("\n=== MENU ===\n");
        printf("1. Tampilkan Data\n");
        printf("2. Tambah Data\n");
        printf("3. Ubah Data\n");
        printf("4. Hapus Data\n");
        printf("5. Olah Nilai\n");
        printf("6. Fitur Rekursif\n");
        printf("7. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1: tampilData(); break;
            case 2: tambahData(); break;
            case 3: ubahData(); break;
            case 4: hapusData(); break;
            case 5: olahNilai(); break;
            case 6: fiturRekursif(); break;
            case 7: printf("Program selesai.\n"); break;
            default: printf("Pilihan tidak valid!\n");
        }
    } while (pilihan != 7);

    return 0;
}
