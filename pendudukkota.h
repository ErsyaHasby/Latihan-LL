#ifndef PENDUDUKKOTA_H
#define PENDUDUKKOTA_H

// Struktur data untuk Penduduk
typedef struct Penduduk
{
    char nama[50];
    struct Penduduk *prev;
    struct Penduduk *next;
} Penduduk;

// Struktur data untuk Kota
typedef struct Kota
{
    char nama[50];
    Penduduk *penduduk; // Penduduk terkait dengan kota
    struct Kota *prev;
    struct Kota *next;
} Kota;

// Fungsi untuk membuat kota baru
Kota *createKota(const char *namaKota);

// Fungsi untuk menambahkan kota ke dalam daftar kota
void insertKota(Kota **head, const char *namaKota);

// Fungsi untuk menambahkan penduduk ke kota
void insertPenduduk(Kota *head, const char *namaPenduduk);

// Fungsi untuk menampilkan daftar kota dan penduduk
void tampilkanKotaPenduduk(Kota *head);

#endif
