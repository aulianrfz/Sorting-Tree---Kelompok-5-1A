#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

boolean IsEmpty(List L)
{
	if (First(L) == Nil)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void CreateList(List *L)
{
	First(*L) = Nil;
}

address Alokasi()
{
	/* Kamus Lokal */
	address P;
	/* Algoritma */
	P = (address)malloc(sizeof(persediaanBarang));
	if (P != Nil) /* Alokasi berhasil */
	{
		printf("Masukkan nama barang\t: ");
    	scanf("%s", &Info(P));
    	printf("Masukkan jumlah stok\t: ");
    	scanf("%d", &Stok(P));
    	printf("Masukkan harga beli\t: ");
    	scanf("%d", &Beli(P));
    	printf("Masukkan harga jual\t: ");
    	scanf("%d", &Jual(P));
    	Keuntungan(P) = Jual(P) - Beli(P);
		Next(P) = Nil;
	}
	return (P);
}

void InsertNode(List *L)
{
	/* Kamus Lokal */
	address P;
	address Last;
	/* Algoritma */
	P = Alokasi();
	if (P != Nil)
	{
		if (First(*L) != Nil){
			Last = First(*L);
			while (Next(Last) != Nil){
				Last = Next(Last);
			}
			Next(Last) = P;
		}
		else
		{
			First(*L) = P;
		}
	}
}

void PrintInfo(List L)
{
	/* Kamus Lokal */
	address P;
	int masuk = 1;
	/* Algoritma */
	if (First(L) == Nil)
	{
		printf("List Kosong .... \a\n");
	}
	else /* List memiliki elemen */
	{
		P = First(L);
		for (;;)
		{
			if (P == Nil)
			{
				printf("\n");
				break;
			}
			else /* Belum berada di akhir List */
			{
				Kode(P) = masuk;
				printf("#Kode Masuk\t: %d\n", Kode(P));
				printf("Nama barang\t: %s\n", Info(P));
				printf("Jumlah stok\t: %d\n", Stok(P));
				printf("Harga beli\t: Rp. %d\n", Beli(P));
				printf("Harga jual\t: Rp. %d\n", Jual(P));
				printf("Keuntungan\t: Rp. %d\n", Keuntungan(P));
				P = Next(P);
			}
			printf("\n");
			masuk++;
		}
	}
}

void DeleteAll(List *L)
{
    /* Kamus Lokal */
    address P, Q;
    /* Algoritma */
    P = First(*L);
    while (P != Nil)
    {
        Q = P;
        P = Next(P);
        free(Q);
    }
    First(*L) = Nil;
}

int CountNode(List L) {
    int count;
    address P;
		P = First(L);
		count = 0;
		while (P != NULL) {
        	count++;
        	P = Next(P);
    	}
    	return count;
}	

boolean IsEmptyTree(addressTree root)
{
    if (root == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void CreateTree(addressTree *root, List L){
	*root = NULL;
	*root = (address)malloc(sizeof(nbtree));
	if(IsEmpty(L) == false){
		InfoTree(*root) = L;
		Left(*root) = NULL;
		Right(*root) = NULL;
		if (IsEmptyTree(*root) == false){
			printf("\nIsi tree : \n\n");
			PrintInfo(L);
		}	
	}
	else{
		printf("Isi tree kosong...");
	}
}
