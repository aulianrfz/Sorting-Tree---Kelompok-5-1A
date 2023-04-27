#ifndef header_H
#define header_H
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>
#define Nil NULL
#define Info(P) (P)->info
#define Next(P) (P)->next
#define Kode(P) (P)->kodeMasuk
#define Stok(P) (P)->stok
#define Beli(P) (P)->hargaBeli
#define Jual(P) (P)->hargaJual
#define Keuntungan(P) (P)->keuntungan
#define First(L) (L).First
#define Left(P) (P)->left
#define Right(P) (P)->right
#define InfoTree(P) (P)->infoTree

typedef char* value;
typedef struct element *address;

// LIST PERSEDIAAN BARANG
typedef struct element{
	value info[50];
	int kodeMasuk;
	int stok;
	int hargaBeli;
	int hargaJual;
	int keuntungan;
	address next;
}persediaanBarang;

typedef struct element1{
	address First;
}List;

typedef struct NBtree *addressTree;
typedef struct NBtree
{ 
	List infoTree;
	addressTree left, right;
}nbtree;

boolean IsEmpty (List L);

void CreateList (List * L);

address Alokasi ();

void InsertNode(List *L);

void PrintInfo(List L);

void DeleteAll(List *L);

int CountNode(List L);

boolean IsEmptyTree(addressTree root);

void CreateTree(addressTree *root, List L);


#endif
