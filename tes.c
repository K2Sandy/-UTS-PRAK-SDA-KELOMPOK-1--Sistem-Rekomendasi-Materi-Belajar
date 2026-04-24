#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CHILDREN 10

// ========================================================
// 0. STRUKTUR DATA UTAMA
// ========================================================
typedef struct {
    int kategoriId; // 1: Info, 2: MTK, 3: Bio, 4: Fis, 5: Sej, 6: Kim
    char nama[50];
    char deskripsi[50];
    int tingkatKesulitan; 
    int durasiMenit;      
} Materi;

Materi buatMateri(int katId, const char* nama, const char* desk, int kesulitan, int durasi) {
    Materi m;
    m.kategoriId = katId;
    strcpy(m.nama, nama);
    strcpy(m.deskripsi, desk);
    m.tingkatKesulitan = kesulitan;
    m.durasiMenit = durasi;
    return m;
}

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