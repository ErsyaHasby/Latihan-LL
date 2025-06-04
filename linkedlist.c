#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

void CreateNode(address *p)
{
    *p = NULL;
}

void IsiNode(infotype Nilai, address *p)
{
    *p = (address)malloc(sizeof(Node));
    if (*p != NULL)
    {
        (*p)->info = Nilai;
        (*p)->next = NULL;
    }
}

void TampilList(address p)
{
    while (p != NULL)
    {
        printf("%d -> ", p->info);
        p = p->next;
    }
    printf("NULL\n");
}

void AddAwal(address *p, int nilai)
{
    address temp;
    IsiNode(nilai, &temp);
    if (temp != NULL)
    {
        temp->next = *p;
        *p = temp;
    }
}

void AddAkhir(address *p, int nilai)
{
    address temp, last = *p;
    IsiNode(nilai, &temp);
    if (temp != NULL)
    {
        if (*p == NULL)
        {
            *p = temp;
        }
        else
        {
            while (last->next != NULL)
            {
                last = last->next;
            }
            last->next = temp;
        }
    }
}

void AddTengah(address *p, int nilai, int posisi)
{
    address temp, prev = *p;
    int i;
    IsiNode(nilai, &temp);
    if (temp != NULL)
    {
        if (posisi == 1)
        {
            AddAwal(p, nilai);
        }
        else
        {
            for (i = 1; i < posisi - 1 && prev != NULL; i++)
            {
                prev = prev->next;
            }
            if (prev != NULL)
            {
                temp->next = prev->next;
                prev->next = temp;
            }
        }
    }
}

int cariNode(address p, infotype nilai)
{
    int pos = 1;
    while (p != NULL)
    {
        if (p->info == nilai)
        {
            printf("Node dengan nilai %d ditemukan di posisi %d\n", nilai, pos);
            return 1; // ✅ Mengembalikan 1 jika ditemukan
        }
        p = p->next;
        pos++;
    }
    printf("Node dengan nilai %d tidak ditemukan\n", nilai);
    return 0; // ✅ Mengembalikan 0 jika tidak ditemukan
}

void hapusNodeAwal(address *p)
{
    if (*p != NULL)
    {
        address temp = *p;
        *p = (*p)->next;
        free(temp);
    }
}

void hapusNodeAkhir(address *p)
{
    if (*p != NULL)
    {
        address temp = *p, prev = NULL;
        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        if (prev != NULL)
        {
            prev->next = NULL;
        }
        else
        {
            *p = NULL;
        }
        free(temp);
    }
}

void hapusNode(address *p, int posisi)
{
    if (*p != NULL)
    {
        address temp = *p, prev = NULL;
        int i;
        if (posisi == 1)
        {
            *p = (*p)->next;
            free(temp);
            return;
        }
        for (i = 1; i < posisi && temp != NULL; i++)
        {
            prev = temp;
            temp = temp->next;
        }
        if (temp != NULL)
        {
            prev->next = temp->next;
            free(temp);
        }
    }
}

int jumtotNode(address p)
{
    int count = 0;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}

int nodeMax(address p)
{
    if (p == NULL)
    {
        printf("List kosong, tidak ada nilai maksimum.\n");
        return -1; // Atau nilai lain yang menunjukkan error
    }

    int max = p->info;
    while (p != NULL)
    {
        if (p->info > max)
        {
            max = p->info;
        }
        p = p->next;
    }
    return max;
}

float rata2Node(address p)
{
    int sum = 0, count = 0;
    while (p != NULL)
    {
        sum += p->info;
        count++;
        p = p->next;
    }
    return (count > 0) ? (float)sum / count : 0;
}

void tukarNode(address *p)
{
    if (*p == NULL || (*p)->next == NULL)
        return;

    address prev = NULL, curr = *p, next = NULL;
    *p = (*p)->next; // Update head ke node kedua

    while (curr != NULL && curr->next != NULL)
    {
        next = curr->next;
        curr->next = next->next;
        next->next = curr;

        if (prev != NULL)
            prev->next = next;

        prev = curr;
        curr = curr->next;
    }
}
