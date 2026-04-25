#ifndef MATERI_H
#define MATERI_H

// ============================================================
// materi.h — Struktur data utama & utilitas umum
// ============================================================

typedef struct {
    int  kategoriId; // 1:Info 2:MTK 3:Bio 4:Fis 5:Sej 6:Kim
                     // 7:Eko  8:Sos 9:SenRupa 10:Musik 11:Penjas
    char nama[50];
    char deskripsi[50];
    int  tingkatKesulitan;
    int  durasiMenit;
} Materi;

Materi buatMateri(int katId, const char* nama, const char* desk,
                  int kesulitan, int durasi);

void bersihkanBuffer();

#endif // MATERI_H
