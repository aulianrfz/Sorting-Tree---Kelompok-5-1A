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
#define Left(Q) (Q)->left
#define Right(Q) (Q)->right
#define InfoTree(Q) (Q)->infoTree
#define FirstTree(T) (T).FirstTree
#define MAX_SIZE 100

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

typedef struct element2{
	addressTree FirstTree;
}Tree;

boolean IsEmpty (List L);

void CreateList (List * L); 

address Alokasi ();

void InsertNode(List *L);

void PrintInfo(List L);

int CountNode(List L);

boolean IsEmptyTree(addressTree root);

addressTree CreateTree(List *L);

void SeparateNode(List *L, List *bagian2);

void SeparateTree(addressTree *root);

#endif
