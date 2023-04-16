#ifndef header_H
#define header_H
#include "boolean.h"
#define Nil NULL
#define Info(P) (P)->info
#define Next(P) (P)->next
#define Kode(P) (P)->kodeMasuk
#define Stok(P) (P)->stok
#define Beli(P) (P)->hargaBeli
#define Jual(P) (P)->hargaJual
#define Keuntungan(P) (P)->keuntungan
#define Left(Q) (Q)->left
#define Right(Q) (Q)->right
#define InfoTree(Q) (Q)->infoTree
#define First(L) (L).First

// KAMUS DATA GLOBAL

typedef char* value;

typedef struct element *address;
typedef struct element{
	value info[100];
	int kodeMasuk;
	int stok;
	int hargaBeli;
	int hargaJual;
	int keuntungan;
	address next;
}Barang; 

typedef struct element1{
	address First;
}List;

typedef struct element2{
	Barang daftar;
}DaftarBarang;

typedef struct element3{
	address FirstTree;
}ListTree;

typedef struct element4 *addressTree;
typedef struct element4{
	addressTree left;
	Barang infoTree;
	addressTree right;
}Tree;

// MODUL

boolean IsEmpty (List L);

void CreateList (List * L);

address Alokasi ();

void InsertNode(List *L);

void InsertLast(List *L, address P);

void PrintInfo(List L);

#endif
