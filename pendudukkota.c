#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pendudukkota.h"

// Fungsi untuk membuat kota baru
Kota *createKota(const char *namaKota)
{
    Kota *newKota = (Kota *)malloc(sizeof(Kota));
    strcpy(newKota->nama, namaKota);
    newKota->penduduk = NULL;
    newKota->prev = NULL;
    newKota->next = NULL;
    return newKota;
}

// Fungsi untuk menambahkan kota ke dalam daftar kota
void insertKota(Kota **head, const char *namaKota)
{
    Kota *newKota = createKota(namaKota);
    if (*head == NULL)
    {
        *head = newKota;
    }
    else
    {
        Kota *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newKota;
        newKota->prev = temp;
    }
}

// Fungsi untuk menambahkan penduduk ke kota
void insertPenduduk(Kota *head, const char *namaPenduduk)
{
    if (head == NULL)
        return;

    Penduduk *newPenduduk = (Penduduk *)malloc(sizeof(Penduduk));
    strcpy(newPenduduk->nama, namaPenduduk);
    newPenduduk->prev = NULL;
    newPenduduk->next = NULL;

    // Menambahkan penduduk ke kota yang sesuai
    Penduduk *last = head->penduduk;
    if (last == NULL)
    {
        head->penduduk = newPenduduk;
    }
    else
    {
        while (last->next != NULL)
        {
            last = last->next;
        }
        last->next = newPenduduk;
        newPenduduk->prev = last;
    }
}

// Fungsi untuk menampilkan daftar kota dan penduduk
void tampilkanKotaPenduduk(Kota *head)
{
    Kota *kota = head;
    while (kota != NULL)
    {
        printf("prev > %s > next > ", kota->nama);

        Penduduk *penduduk = kota->penduduk;
        while (penduduk != NULL)
        {
            printf("prev > %s > next > ", penduduk->nama);
            penduduk = penduduk->next;
        }

        printf("null\n");
        kota = kota->next;
    }
}
