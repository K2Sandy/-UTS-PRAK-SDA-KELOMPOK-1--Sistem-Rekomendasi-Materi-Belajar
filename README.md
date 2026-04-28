<div align="center">

# 🎓 EduGraph
### Sistem Rekomendasi Alur Belajar Berbasis Struktur Data Hibrida

<br>

![C](https://img.shields.io/badge/Language-C11-00599C?style=for-the-badge&logo=c&logoColor=white)
![Status](https://img.shields.io/badge/Status-UTS%20Project-success?style=for-the-badge)
![License](https://img.shields.io/badge/License-Academic-orange?style=for-the-badge)
![Universitas](https://img.shields.io/badge/Universitas-Syiah%20Kuala-blueviolet?style=for-the-badge)

<br>

> **EduGraph** adalah aplikasi CLI (*Command-Line Interface*) berbahasa C yang membantu mahasiswa mengelola alur belajar secara cerdas menggunakan **Arsitektur Struktur Data Hibrida** — menggabungkan General Tree, Binary Search Tree, dan Linked List dalam satu sistem yang terintegrasi.

<br>

</div>

---


## ✨ Fitur Utama

| # | Fitur | Deskripsi |
|:---:|---|---|
| 1 | 📚 **Katalog Silabus Bertingkat** | Navigasi hirarki 3 level: Rumpun Ilmu → Mata Pelajaran → Materi |
| 2 | 🤖 **Rekomendasi Cerdas** | Filter materi berdasarkan batas waktu & tingkat kesulitan secara otomatis |
| 3 | 📋 **Daftar Belajarku** | Antrean dinamis (*queue*) untuk menampung materi pilihan pengguna |
| 4 | ⚡ **Smart Sorting** | Urutkan playlist berdasarkan durasi tercepat atau kesulitan termudah |
| 5 | 🗺️ **Mode Peta Silabus** | Visualisasi seluruh pohon materi BST secara *real-time* (Preorder) |

---

## 🛠 Arsitektur Sistem

Sistem menghindari array statis dan mengintegrasikan **3 struktur data** serta **3 algoritma utama**:

### 🌳 Struktur Data

| Struktur | Peran | Kompleksitas |
|---|---|:---:|
| **General Tree** | Mengelola kategori berjenjang (Root → Rumpun → Mapel) | O(n) |
| **Binary Search Tree** | Menyimpan & mencari materi berdasarkan tingkat kesulitan | O(log n) |
| **Linked List** | Wadah Daftar Belajar dengan alokasi memori dinamis | O(1) |

### ⚙️ Algoritma

| Algoritma | Implementasi | Kegunaan |
|---|---|---|
| **Inorder Traversal** | BST → kiri, root, kanan | Ekstrak materi otomatis dari termudah ke tersulit |
| **Insertion Sort** | Langsung pada pointer Linked List | Sorting playlist tanpa memori tambahan |
| **Preorder Traversal** | BST → root, kiri, kanan | Visualisasi peta silabus (Mode Admin) |

---

## 💻 Cara Menjalankan

### Prasyarat

Pastikan *compiler* GCC telah terinstal: Windows (MinGW-w64), Linux (`build-essential`), atau macOS (`xcode-select --install`).

### Langkah Instalasi & Kompilasi

Proyek ini menyediakan dua versi kode: **allinone** (seluruh kode dalam satu file) dan **bagian** (kode modular yang dipisah dengan *header*). 

Jalankan perintah berikut di terminal secara berurutan:

```bash
# 1. Clone repositori
git clone https://github.com/username/UTS-PRAK-SDA-KELOMPOK-1.git
cd UTS-PRAK-SDA-KELOMPOK-1

# 2. Kompilasi (Pilih salah satu versi kode yang ingin digunakan)

# ---> Opsi A: Versi All-in-One (satu file)
cd code/allinone
gcc -Wall -std=c11 main.c -o edugraph

# ---> Opsi B: Versi Modular (banyak file)
cd code/bagian
gcc -Wall -std=c11 main.c materi.c linked_list.c bst.c tree.c ui.c -o edugraph

# 3. Jalankan program
./edugraph      # Untuk Linux / macOS
.\edugraph.exe  # Untuk Windows
```

---

## 👥 Tim Pengembang

EduGraph dikembangkan secara kolaboratif oleh Mahasiswa **S1 Informatika**, Fakultas Matematika dan Ilmu Pengetahuan Alam, **Universitas Syiah Kuala** sebagai proyek UTS Praktikum Struktur Data dan Algoritma.

<div align="center">

| No | Nama | NPM |
|:---:|---|:---:|
| 1 | **Muhammad Albharaka** | 250810701100022 |
| 2 | **Putroe Zalfa** | 250810701100024 |
| 3 | **Al Aul Tsaqif** | 250810701100034 |
| 4 | **Imam As-Shadiq** | 250810701100079 |
| 5 | **Hally Lubbaba** | 250810701100110 |

</div>

---

## 📄 Hak Cipta & Lisensi

Proyek ini diajukan untuk memenuhi penilaian **Ujian Tengah Semester (UTS)**
mata kuliah **Praktikum Struktur Data dan Algoritma**.

```text
© 2026 Tim EduGraph — Universitas Syiah Kuala
Seluruh kode bersifat akademis dan tidak untuk keperluan komersial.
```

---

<div align="center">

*Dibuat dengan ❤️ oleh Kelompok 1 — Informatika, Universitas Syiah Kuala*

</div>