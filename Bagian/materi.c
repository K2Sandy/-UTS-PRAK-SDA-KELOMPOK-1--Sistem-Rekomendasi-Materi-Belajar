#include <stdio.h>
#include <string.h>
#include "materi.h"

// ============================================================
// materi.c — Implementasi struct Materi & utilitas umum
// ============================================================

Materi buatMateri(int katId, const char* nama, const char* desk,
                  int kesulitan, int durasi) {
    Materi m;
    m.kategoriId       = katId;
    m.tingkatKesulitan = kesulitan;
    m.durasiMenit      = durasi;
    strcpy(m.nama,      nama);
    strcpy(m.deskripsi, desk);
    return m;
}

void bersihkanBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
