// Dibuat oleh :
// Ersya Hasby Satria
// 241511072

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef int infotype;

typedef struct tNode *address;

typedef struct tNode
{
    infotype info;
    address next;
} Node;

// Prototipe fungsi
void CreateNode(address *p);
void IsiNode(infotype Nilai, address *p);
void TampilList(address p);
void AddAwal(address *p, int nilai);
void AddAkhir(address *p, int nilai);
void AddTengah(address *p, int nilai, int posisi);
int cariNode(address p, infotype nilai);
void hapusNodeAwal(address *p);
void hapusNodeAkhir(address *p);
void hapusNode(address *p, int posisi);
int jumtotNode(address p);
int nodeMax(address p);
float rata2Node(address p);
void tukarNode(address *p);

#endif
