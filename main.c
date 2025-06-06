#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pendudukkota.h"

int main()
{
    Kota *head = NULL;

    // Menambahkan beberapa kota dan penduduk sebagai contoh
    insertKota(&head, "Bandung");
    insertPenduduk(head, "Doni");
    insertPenduduk(head, "Dani");

    insertKota(&head, "Cimahi");

    insertKota(&head, "Jakarta");

    insertKota(&head, "Surabaya");

    insertKota(&head, "Malang");

    // Tampilkan daftar kota dan penduduk
    printf("Daftar Kota dan Penduduk Awal:\n");
    tampilkanKotaPenduduk(head);

    // Tambahkan menu interaktif untuk pengelolaan kota dan penduduk
    int pilihan;
    do
    {
        printf("\nMenu:\n");
        printf("1. Tampilkan Daftar Kota dan Penduduk\n");
        printf("2. Tambah Kota\n");
        printf("3. Tambah Penduduk ke Kota\n");
        printf("4. Hapus Penduduk\n");
        printf("5. Hapus Kota\n");
        printf("6. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);

        if (pilihan == 1)
        {
            // Menampilkan daftar kota dan penduduk
            printf("Daftar Kota dan Penduduk:\n");
            tampilkanKotaPenduduk(head);
        }
        else if (pilihan == 2)
        {
            // Menambah kota
            char namaKota[50];
            printf("Masukkan nama kota: ");
            scanf("%s", namaKota);
            insertKota(&head, namaKota);
        }
        else if (pilihan == 3)
        {
            // Menambah penduduk ke kota
            char namaKota[50], namaPenduduk[50];
            printf("Masukkan nama kota: ");
            scanf("%s", namaKota);
            printf("Masukkan nama penduduk: ");
            scanf("%s", namaPenduduk);

            Kota *kota = head;
            while (kota != NULL && strcmp(kota->nama, namaKota) != 0)
            {
                kota = kota->next;
            }

            if (kota != NULL)
            {
                insertPenduduk(kota, namaPenduduk);
            }
            else
            {
                printf("Kota tidak ditemukan!\n");
            }
        }
        else if (pilihan == 4)
        {
            // Menghapus penduduk dari kota
            char namaKota[50], namaPenduduk[50];
            printf("Masukkan nama kota: ");
            scanf("%s", namaKota);
            printf("Masukkan nama penduduk yang ingin dihapus: ");
            scanf("%s", namaPenduduk);

            Kota *kota = head;
            while (kota != NULL && strcmp(kota->nama, namaKota) != 0)
            {
                kota = kota->next;
            }

            if (kota != NULL)
            {
                Penduduk *penduduk = kota->penduduk;
                while (penduduk != NULL && strcmp(penduduk->nama, namaPenduduk) != 0)
                {
                    penduduk = penduduk->next;
                }

                if (penduduk != NULL)
                {
                    // Menghapus penduduk dari kota
                    if (penduduk->prev != NULL)
                    {
                        penduduk->prev->next = penduduk->next;
                    }
                    else
                    {
                        kota->penduduk = penduduk->next;
                    }

                    if (penduduk->next != NULL)
                    {
                        penduduk->next->prev = penduduk->prev;
                    }

                    free(penduduk);
                    printf("Penduduk %s telah dihapus dari kota %s.\n", namaPenduduk, namaKota);
                }
                else
                {
                    printf("Penduduk tidak ditemukan di kota %s!\n", namaKota);
                }
            }
            else
            {
                printf("Kota tidak ditemukan!\n");
            }
        }
        else if (pilihan == 5)
        {
            // Menghapus kota
            char namaKota[50];
            printf("Masukkan nama kota yang ingin dihapus: ");
            scanf("%s", namaKota);

            Kota *kota = head;
            while (kota != NULL && strcmp(kota->nama, namaKota) != 0)
            {
                kota = kota->next;
            }

            if (kota != NULL)
            {
                // Menghapus kota
                if (kota->prev != NULL)
                {
                    kota->prev->next = kota->next;
                }
                else
                {
                    head = kota->next;
                }

                if (kota->next != NULL)
                {
                    kota->next->prev = kota->prev;
                }

                // Menghapus semua penduduk kota tersebut
                Penduduk *penduduk = kota->penduduk;
                while (penduduk != NULL)
                {
                    Penduduk *temp = penduduk;
                    penduduk = penduduk->next;
                    free(temp);
                }

                free(kota);
                printf("Kota %s telah dihapus.\n", namaKota);
            }
            else
            {
                printf("Kota tidak ditemukan!\n");
            }
        }
    } while (pilihan != 6);

    // Membersihkan memori setelah keluar
    while (head != NULL)
    {
        Kota *tempKota = head;
        head = head->next;

        Penduduk *penduduk = tempKota->penduduk;
        while (penduduk != NULL)
        {
            Penduduk *tempPenduduk = penduduk;
            penduduk = penduduk->next;
            free(tempPenduduk);
        }

        free(tempKota);
    }

    printf("Program selesai.\n");
    return 0;
}
