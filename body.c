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
	P = (address)malloc(sizeof(Barang));
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

void InsertNode(List *L) // insert node
{
	/* Kamus Lokal */
	address P;
	Barang X;
	/* Algoritma */
		
		 
	P = Alokasi();
	if (P != Nil)
	{
		InsertLast(&(*L), P);
	}
}

void InsertLast(List *L, address P)
{
	/* Kamus Lokal */
	address Last;
	/* Algoritma */
	if (First(*L) != Nil)
	{
		Last = First(*L);
		while (Next(Last) != Nil)
		{
			Last = Next(Last);
		}
		Next(Last) = P;
	}
	else
	{
		First(*L) = P;
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

