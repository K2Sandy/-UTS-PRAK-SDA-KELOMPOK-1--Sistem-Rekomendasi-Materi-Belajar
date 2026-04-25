#include <stdio.h>
#include <stdbool.h>

#include "materi.h"
#include "linked_list.h"
#include "bst.h"
#include "tree.h"
#include "ui.h"

// ============================================================
// main.c — Entry point, setup data, dan main loop
// ============================================================

// ------------------------------------------------------------
// Setup General Tree (3 Level: Root -> Rumpun -> Mapel)
// ------------------------------------------------------------
static TreeNode* setupTree() {
    TreeNode* root = buatNodeTree(0, "Katalog Ilmu Pengetahuan");

    // === SAINTEK ===
    TreeNode* saintek = buatNodeTree(0, "Sains & Teknologi (SAINTEK)");
    addChild(root, saintek);
    addChild(saintek, buatNodeTree(1,  "Informatika"));
    addChild(saintek, buatNodeTree(2,  "Matematika"));
    addChild(saintek, buatNodeTree(3,  "Biologi"));
    addChild(saintek, buatNodeTree(4,  "Fisika"));
    addChild(saintek, buatNodeTree(6,  "Kimia"));

    // === SOSHUM ===
    TreeNode* soshum = buatNodeTree(0, "Sosial & Humaniora (SOSHUM)");
    addChild(root, soshum);
    addChild(soshum, buatNodeTree(5,  "Sejarah"));
    addChild(soshum, buatNodeTree(7,  "Ekonomi"));
    addChild(soshum, buatNodeTree(8,  "Sosiologi"));

    // === SENI & BUDAYA ===
    TreeNode* seniBudaya = buatNodeTree(0, "Seni & Budaya");
    addChild(root, seniBudaya);
    addChild(seniBudaya, buatNodeTree(9,  "Seni Rupa"));
    addChild(seniBudaya, buatNodeTree(10, "Musik"));

    // === OLAHRAGA & KESEHATAN ===
    TreeNode* olahragaKes = buatNodeTree(0, "Olahraga & Kesehatan");
    addChild(root, olahragaKes);
    addChild(olahragaKes, buatNodeTree(11, "Pendidikan Jasmani"));

    return root;
}

// ------------------------------------------------------------
// Setup BST (55 Materi)
// ------------------------------------------------------------
static BSTNode* setupBST() {
    BSTNode* root = NULL;

    // --- 1: Informatika ---
    root = insertBST(root, buatMateri(1, "Logika Dasar",      "Fondasi algoritma IF-ELSE.",       10, 30));
    root = insertBST(root, buatMateri(1, "Array 1 Dimensi",   "Penyimpanan memori sekuensial.",   20, 25));
    root = insertBST(root, buatMateri(1, "Linked List",       "Pointer data dinamis.",            30, 60));
    root = insertBST(root, buatMateri(1, "Tree & BST",        "Hirarki data non-linear.",         50, 45));
    root = insertBST(root, buatMateri(1, "Graph Theory",      "Rute terpendek Dijkstra.",         80, 90));

    // --- 2: Matematika ---
    root = insertBST(root, buatMateri(2, "Aritmatika Dasar",  "Penjumlahan & Pengurangan.",       15, 20));
    root = insertBST(root, buatMateri(2, "Aljabar Linear",    "Matriks dan Vektor.",              35, 60));
    root = insertBST(root, buatMateri(2, "Trigonometri",      "Sin, Cos, Tan.",                   45, 40));
    root = insertBST(root, buatMateri(2, "Kalkulus Lanjut",   "Limit dan Integral.",              60, 90));
    root = insertBST(root, buatMateri(2, "Probabilitas",      "Peluang & Statistik.",             70, 75));

    // --- 3: Biologi ---
    root = insertBST(root, buatMateri(3, "Anatomi Sel",       "Bagian-bagian sel.",               15, 30));
    root = insertBST(root, buatMateri(3, "Ekosistem",         "Rantai makanan.",                  30, 40));
    root = insertBST(root, buatMateri(3, "Genetika Kromosom", "Pewarisan sifat gen.",             45, 50));
    root = insertBST(root, buatMateri(3, "Evolusi Manusia",   "Teori asal usul.",                 75, 60));
    root = insertBST(root, buatMateri(3, "Sistem Saraf",      "Otak dan impuls.",                 85, 80));

    // --- 4: Fisika ---
    root = insertBST(root, buatMateri(4, "Hukum Newton",      "Gaya dan gerak lurus.",            25, 45));
    root = insertBST(root, buatMateri(4, "Kinematika",        "Kecepatan & Percepatan.",          35, 50));
    root = insertBST(root, buatMateri(4, "Optik Geometri",    "Cermin dan Lensa.",                55, 60));
    root = insertBST(root, buatMateri(4, "Termodinamika",     "Suhu dan Kalor.",                  65, 80));
    root = insertBST(root, buatMateri(4, "Fisika Kuantum",    "Partikel sub-atomik.",             95, 120));

    // --- 5: Sejarah ---
    root = insertBST(root, buatMateri(5, "Manusia Purba",     "Zaman batu dan logam.",            15, 25));
    root = insertBST(root, buatMateri(5, "Perang Dunia II",   "Sejarah eropa 1940an.",            20, 30));
    root = insertBST(root, buatMateri(5, "Kemerdekaan RI",    "Proklamasi 1945.",                 30, 35));
    root = insertBST(root, buatMateri(5, "Revolusi Industri", "Eropa abad ke-18.",                40, 45));
    root = insertBST(root, buatMateri(5, "Perang Dingin",     "Blok Barat vs Timur.",             50, 40));

    // --- 6: Kimia ---
    root = insertBST(root, buatMateri(6, "Tabel Periodik",    "Unsur-unsur dasar.",               20, 30));
    root = insertBST(root, buatMateri(6, "Ikatan Kimia",      "Kovalen dan Ionik.",               40, 40));
    root = insertBST(root, buatMateri(6, "Asam & Basa",       "Skala pH dan titrasi.",            50, 45));
    root = insertBST(root, buatMateri(6, "Stoikiometri",      "Perhitungan mol.",                 60, 70));
    root = insertBST(root, buatMateri(6, "Kimia Organik",     "Rantai Karbon.",                   80, 90));

    // --- 7: Ekonomi ---
    root = insertBST(root, buatMateri(7, "Permintaan & Penawaran", "Hukum dasar pasar.",          20, 30));
    root = insertBST(root, buatMateri(7, "Inflasi & Deflasi",      "Perubahan nilai uang.",       35, 40));
    root = insertBST(root, buatMateri(7, "Sistem Ekonomi",         "Kapitalisme vs Sosialisme.",  40, 45));
    root = insertBST(root, buatMateri(7, "Neraca Pembayaran",      "Ekspor impor nasional.",      60, 60));
    root = insertBST(root, buatMateri(7, "Ekonomi Makro",          "GDP, GNP, dan indikator.",    75, 80));

    // --- 8: Sosiologi ---
    root = insertBST(root, buatMateri(8, "Interaksi Sosial",    "Kontak dan komunikasi.",         15, 25));
    root = insertBST(root, buatMateri(8, "Stratifikasi Sosial", "Lapisan kelas masyarakat.",      30, 35));
    root = insertBST(root, buatMateri(8, "Konflik Sosial",      "Teori konflik Marx.",            45, 40));
    root = insertBST(root, buatMateri(8, "Lembaga Sosial",      "Keluarga, sekolah, agama.",      50, 50));
    root = insertBST(root, buatMateri(8, "Perubahan Sosial",    "Modernisasi & globalisasi.",     65, 60));

    // --- 9: Seni Rupa ---
    root = insertBST(root, buatMateri(9, "Unsur Seni Rupa",   "Garis, warna, bentuk.",            10, 20));
    root = insertBST(root, buatMateri(9, "Aliran Realisme",   "Menggambar objek nyata.",          25, 35));
    root = insertBST(root, buatMateri(9, "Desain Grafis",     "Komposisi visual.",                40, 50));
    root = insertBST(root, buatMateri(9, "Seni Kontemporer",  "Seni modern & instalasi.",         55, 60));
    root = insertBST(root, buatMateri(9, "Sejarah Seni Dunia","Dari renaisans ke modern.",        70, 75));

    // --- 10: Musik ---
    root = insertBST(root, buatMateri(10, "Not & Melodi",     "Dasar membaca not.",               10, 25));
    root = insertBST(root, buatMateri(10, "Harmoni & Akord",  "Kombinasi nada.",                  35, 40));
    root = insertBST(root, buatMateri(10, "Teori Musik",      "Tangga nada & interval.",          45, 50));
    root = insertBST(root, buatMateri(10, "Komposisi Lagu",   "Struktur verse & chorus.",         60, 65));
    root = insertBST(root, buatMateri(10, "Musik Elektronik", "Produksi digital DAW.",            75, 80));

    // --- 11: Pendidikan Jasmani ---
    root = insertBST(root, buatMateri(11, "Kebugaran Dasar",  "Lari, push-up, sit-up.",           10, 30));
    root = insertBST(root, buatMateri(11, "Atletik",          "Lompat jauh & lempar.",            25, 40));
    root = insertBST(root, buatMateri(11, "Gizi & Nutrisi",   "Kalori dan metabolisme.",          40, 35));
    root = insertBST(root, buatMateri(11, "Renang",           "Gaya bebas & dada.",               35, 45));
    root = insertBST(root, buatMateri(11, "Bela Diri",        "Teknik dasar silat.",              50, 50));

    return root;
}

// ------------------------------------------------------------
// Main Loop
// ------------------------------------------------------------
int main() {
    PlaylistLinkedList daftarBelajar;
    initLinkedList(&daftarBelajar);

    TreeNode* menuRoot = setupTree();
    BSTNode*  rootBST  = setupBST();

    bool running = true;
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

            // ================================================
            case 1: {
                bool inKatalog = true;
                while (inKatalog) {
                    printf("\n=== KATALOG PELAJARAN ===\n");
                    printf(" Pilih Rumpun Ilmu:\n");
                    for (int i = 0; i < menuRoot->numChildren; i++)
                        printf(" %d. %s\n", i + 1, menuRoot->children[i]->namaKategori);
                    printf(" %d. Lihat Peta Silabus Lengkap (Preorder BST)\n",
                           menuRoot->numChildren + 1);
                    printf(" 0. Kembali ke menu utama\n");
                    printf(" Pilih (0-%d): ", menuRoot->numChildren + 1);

                    int pilRumpun;
                    scanf("%d", &pilRumpun);
                    bersihkanBuffer();

                    if (pilRumpun == 0) {
                        inKatalog = false;
                    }
                    else if (pilRumpun == menuRoot->numChildren + 1) {
                        printf("\n=== PETA SILABUS HIERARKI MATERI ===\n");
                        preorderTraversalBST(rootBST, "");
                        printf("\n Tekan [Enter] untuk kembali..."); getchar();
                    }
                    else if (pilRumpun >= 1 && pilRumpun <= menuRoot->numChildren) {
                        TreeNode* rumpun = menuRoot->children[pilRumpun - 1];

                        bool inMapel = true;
                        while (inMapel) {
                            printf("\n=== %s ===\n", rumpun->namaKategori);
                            printf(" Pilih Mata Pelajaran:\n");
                            for (int j = 0; j < rumpun->numChildren; j++)
                                printf(" %d. %s\n", j + 1, rumpun->children[j]->namaKategori);
                            printf(" 0. Kembali ke pilih rumpun\n");
                            printf(" Pilih (0-%d): ", rumpun->numChildren);

                            int pilMapel;
                            scanf("%d", &pilMapel);
                            bersihkanBuffer();

                            if (pilMapel == 0) {
                                inMapel = false;
                            }
                            else if (pilMapel >= 1 && pilMapel <= rumpun->numChildren) {
                                TreeNode* mapel = rumpun->children[pilMapel - 1];
                                Materi*   arr[50];
                                int       count = 0;
                                kumpulkanMateriInorder(rootBST, mapel->idKategori,
                                                       9999, 9999, arr, &count);
                                printf("\n Menampilkan semua materi %s:", mapel->namaKategori);
                                prosesPilihMateri(arr, count, &daftarBelajar);
                            } else {
                                printf(" [-] Pilihan tidak valid!\n");
                            }
                        }
                    } else {
                        printf(" [-] Pilihan tidak valid!\n");
                    }
                }
                break;
            }

            // ================================================
            case 2: {
                bool inRekomendasi = true;
                while (inRekomendasi) {
                    printf("\n=== SISTEM REKOMENDASI ===\n");
                    printf(" Pilih Rumpun Ilmu:\n");
                    for (int i = 0; i < menuRoot->numChildren; i++)
                        printf(" %d. %s\n", i + 1, menuRoot->children[i]->namaKategori);
                    printf(" 0. Kembali ke menu utama\n");
                    printf(" Pilih (0-%d): ", menuRoot->numChildren);

                    int pilRumpun;
                    scanf("%d", &pilRumpun);
                    bersihkanBuffer();

                    if (pilRumpun == 0) {
                        inRekomendasi = false;
                    }
                    else if (pilRumpun >= 1 && pilRumpun <= menuRoot->numChildren) {
                        TreeNode* rumpun = menuRoot->children[pilRumpun - 1];

                        printf("\n=== %s ===\n", rumpun->namaKategori);
                        printf(" Pilih Mata Pelajaran:\n");
                        for (int j = 0; j < rumpun->numChildren; j++)
                            printf(" %d. %s\n", j + 1, rumpun->children[j]->namaKategori);
                        printf(" 0. Kembali\n");
                        printf(" Pilih (0-%d): ", rumpun->numChildren);

                        int pilMapel;
                        scanf("%d", &pilMapel);
                        bersihkanBuffer();

                        if (pilMapel == 0) {
                            // kembali ke loop pilih rumpun
                        }
                        else if (pilMapel >= 1 && pilMapel <= rumpun->numChildren) {
                            TreeNode* mapel = rumpun->children[pilMapel - 1];

                            int batasWaktu, batasSulit;
                            printf("\n --- Filter Rekomendasi: %s ---\n", mapel->namaKategori);
                            printf(" Maksimal waktu belajar (menit) : ");
                            scanf("%d", &batasWaktu);
                            printf(" Maksimal kesulitan (1-100)     : ");
                            scanf("%d", &batasSulit);
                            bersihkanBuffer();

                            Materi* arr[50];
                            int     count = 0;
                            kumpulkanMateriInorder(rootBST, mapel->idKategori,
                                                   batasWaktu, batasSulit, arr, &count);
                            printf("\n Rekomendasi materi %s untukmu:", mapel->namaKategori);
                            prosesPilihMateri(arr, count, &daftarBelajar);
                        } else {
                            printf(" [-] Pilihan tidak valid!\n");
                        }
                    } else {
                        printf(" [-] Pilihan tidak valid!\n");
                    }
                }
                break;
            }

            // ================================================
            case 3: {
                bool inDaftar = true;
                while (inDaftar) {
                    printf("\n=== DAFTAR BELAJARKU ===\n");
                    tampilkanPlaylist(&daftarBelajar);

                    if (daftarBelajar.head == NULL) {
                        printf("\n Tekan [Enter] untuk kembali..."); getchar();
                        inDaftar = false;
                        break;
                    }

                    printf("\n Aksi:\n");
                    printf(" 1. Urutkan berdasarkan waktu tercepat (Insertion Sort)\n");
                    printf(" 2. Urutkan berdasarkan tingkat kesulitan (Termudah ke Tersulit)\n");
                    printf(" 0. Kembali ke menu sebelumnya\n");
                    printf(" Pilih (0-2): ");

                    int aksi;
                    scanf("%d", &aksi);
                    bersihkanBuffer();

                    if (aksi == 0) {
                        inDaftar = false;
                    } else if (aksi == 1) {
                        insertionSortByDurasi(&daftarBelajar);
                        printf("\n [+] Daftar belajar diurutkan berdasarkan WAKTU!\n");
                    } else if (aksi == 2) {
                        insertionSortByKesulitan(&daftarBelajar);
                        printf("\n [+] Daftar belajar diurutkan berdasarkan KESULITAN!\n");
                    } else {
                        printf(" [-] Pilihan tidak valid!\n");
                    }
                }
                break;
            }

            // ================================================
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
