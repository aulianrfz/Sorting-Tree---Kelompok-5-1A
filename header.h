#ifndef header_H
#define header_H
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>
#define Nil NULL
#define Info(P) (P)->info
#define Next(P) (P)->next
#define Stok(P) (P)->stok
#define Beli(P) (P)->hargaBeli
#define Jual(P) (P)->hargaJual
#define Keuntungan(P) (P)->keuntungan
#define First(L) (L).First
#define Left(P) (P)->left
#define Right(P) (P)->right
#define InfoTree(P) (P)->infoTree
#define FirstTree(T) (T).FirstTree
#define MAX_SIZE 100

typedef const char* value;
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

typedef struct Item{
	value namaBarang[50];
	int stok;
	int hargaBeli;
	int hargaJual;
	int keuntungan;
}Item;
typedef Item array[MAX_SIZE];

boolean IsEmpty (List L);

void CreateList (List * L);

address Alokasi (List L);

void InsertNode(List *L);

void PrintInfo(List L);

int CountNode(List L);

boolean IsEmptyTree(addressTree root);

addressTree CreateTree(List L);

void CopyList(List L, List *copy);

void SeparateNode(List *L, List *bagian1, List *bagian2);

void SeparateTree(addressTree *root);

void MergeTree(addressTree root, array *arr, int *index,int pilihan, int pilih);

List MergeList(array arr, int index, int pilihan, int pilih);

void MergeSort(addressTree root, int pilih, int pilihan);

void SortArray(struct Item arr[], int index, int pilihan, int pilih);

void SwapItems(struct Item arr[], int j);

#endif
