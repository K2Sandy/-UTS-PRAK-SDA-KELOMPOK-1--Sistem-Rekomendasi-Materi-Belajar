#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Fungsi pembantu untuk membersihkan buffer input (mencegah error loop)
void bersihkanBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// ========================================================
// PROGRAM UTAMA
// ========================================================
int main() {
    bool running = true;
    
    // --- MAIN LOOP ---
    while (running) {
        int pilihanUtama;
        printf("\n======================================================\n");
        printf("         SISTEM ASISTEN BELAJAR EDUGRAPH              \n");
        printf("======================================================\n");
        printf(" 1. Katalog & Silabus Pelajaran\n");
        printf(" 2. Sistem Rekomendasi Belajar (Filter Cerdas)\n");
        printf(" 3. Lihat Daftar Belajarku\n");
        printf(" 0. Keluar Aplikasi\n");
        printf("======================================================\n");
        printf(" Pilih menu (0-3): ");
        scanf("%d", &pilihanUtama);
        bersihkanBuffer();

        switch (pilihanUtama) {
            case 1:
                printf("\n [-] Fitur Katalog masih dalam pengembangan.\n");
                break;
            case 2:
                printf("\n [-] Fitur Rekomendasi masih dalam pengembangan.\n");
                break;
            case 3:
                printf("\n [-] Fitur Daftar Belajar masih dalam pengembangan.\n");
                break;
            case 0:
                printf("\n Terima kasih telah menggunakan EduGraph. Sampai jumpa!\n");
                running = false;
                break;
            default:
                printf("\n [-] Pilihan tidak valid. Silakan coba lagi.\n");
        }
    }
    return 0;
}