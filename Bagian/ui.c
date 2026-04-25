#include <stdio.h>
#include <stdbool.h>
#include "ui.h"

// ============================================================
// ui.c — Implementasi Fungsi UI/UX Bersama
// ============================================================

void prosesPilihMateri(Materi* arr[], int count, PlaylistLinkedList* playlist) {
    if (count == 0) {
        printf("\n [-] Tidak ada materi yang ditemukan/sesuai kriteria.\n");
        printf(" Tekan [Enter] untuk kembali..."); getchar();
        return;
    }

    printf("\n =========================================================================\n");
    printf(" %-4s %-25s %-12s %-10s %s\n",
           "No", "Judul Materi", "Sulit(/100)", "Waktu(m)", "Keterangan Singkat");
    printf(" -------------------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf(" %-4d %-25s %-12d %-10d %s\n",
               i + 1, arr[i]->nama,
               arr[i]->tingkatKesulitan,
               arr[i]->durasiMenit,
               arr[i]->deskripsi);
    }
    printf(" =========================================================================\n");

    while (true) {
        int pilihan;
        printf("\n Masukkan No materi untuk ditambah (0 untuk kembali): ");
        scanf("%d", &pilihan);
        bersihkanBuffer();

        if (pilihan == 0) break;

        if (pilihan >= 1 && pilihan <= count) {
            tambahMateri(playlist, *(arr[pilihan - 1]));
            printf(" [+] '%s' masuk ke Daftar Belajar!\n", arr[pilihan - 1]->nama);
        } else {
            printf(" [-] Nomor tidak valid.\n");
        }
    }
}
