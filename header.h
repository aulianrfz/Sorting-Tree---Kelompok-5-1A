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

typedef struct element3{
	value info[50];
	int kodeMasuk;
	int stok;
	int hargaBeli;
	int hargaJual;
	int keuntungan;
}array;

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

/* Mengecek node linked list kosong atau tidak*/
boolean IsEmpty (List L);

/* Membuat list yang menunjuk pada node linked list*/
void CreateList (List * L); 

/* Alokasi node linked list*/
address AlokasiNode ();

/* Insert node linked list */
void InsertNode(List *L);

/* Print isi linked list */
void PrintInfo(List L);

/* Menghitung jumlah node linked list */
int CountNode(List L);

/* Mengecek tree kosong atau tidak */
boolean IsEmptyTree(addressTree root);

/* Membuat node tree */
addressTree CreateTree(List *L);

/* Membagi dua node linked list */
void SeparateNode(List *L, List *bagian2);

/* Membuat node tree dari hasil pemisahan node linked list*/
void SeparateTree(addressTree *root);

#endif
