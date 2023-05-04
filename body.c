#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

boolean IsEmpty(List L){
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

void CreateListTree(Tree *T)
{
	FirstTree(*T) = Nil;
}

address AlokasiNode()
{
	address P;

	P = (address)malloc(sizeof(persediaanBarang));
	if (P != Nil)
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
	address P;
	address Last;

	P = AlokasiNode();
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

void InsertLast(List *L, address P)
{
	address Last;

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
	address P;
	int masuk = 1;

	if (First(L) == Nil)
	{
		printf("List Kosong .... \a\n");
	}
	else /* List memiliki elemen */
	{
		P = First(L);
		while (P != Nil)
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
				printf("Keuntungan\t: Rp. %d\n", Keuntungan(P));\
				P = Next(P);
			}
			printf("\n");
			masuk++;
		}
	}
}

void PrintInfoTree(addressTree *root, List L)
{

	address P;
	int masuk = 1;

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
/* Mengirimkan true jika Isi_Tree KOSONG */
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

addressTree CreateTree(List *L)
{

	addressTree root;

	root = (addressTree)malloc(sizeof(nbtree));
	if(IsEmpty(*L) == false)
	{
		InfoTree(root) = *L;
		Left(root) = NULL;
		Right(root) = NULL;
//		if (IsEmptyTree(root) == false){
//			printf("\nIsi tree : \n\n");
//			PrintInfo(*L);
//		}	
	}
	else{
		printf("Isi tree kosong...");
	}
	return(root);
}

void SeparateTree(addressTree *root) {
    addressTree stack[MAX_SIZE], last, still, anak1, anak2, prev;
    List check, bagian;
    address isi;
    int count, top;
    
    if (*root == Nil) {
        return;
    }
    
	top = -1;
    prev = Nil;
    still = *root;
    do {
		while (*root != NULL) 
		{
            stack[++top] = *root;
            stack[++top] = *root;
			last = *root;
            *root = (*root)->left;
        }
        while (top != -1 && (stack[top]->right == NULL || stack[top]->right == prev)) {
			prev = stack[top--];
            check = prev->infoTree;
            isi = First(check);
            if(isi != Nil){
            	count = CountNode(check);
            	if (count != 1)
            	{
            		CreateList(&bagian);
					SeparateNode(&check, &bagian);
					anak1 = CreateTree(&check);
					anak2 = CreateTree(&bagian);
					if(top = 0)
    				{
    					last = still;
					}
    				last->left = anak1;
    				last->right = anak2;
    				*root = last;
    				last = last->left;
    				printf("\n===================================\n");
    				printf("First half: ");
    				PrintInfo(check);
    				printf("\n------------------------------------\n");
					printf("Second half: ");
    				PrintInfo(bagian);
    				printf("\n===================================\n");
    				count = CountNode(check);
    				if(count !=1)
					{
    					stack[++top] = anak1;
    					stack[++top] = anak1;
    				}
				}
			} else {
				printf("Isi Tree kosong");
			}
        }
        if (top != -1) {
            *root = stack[top]->right;
        }
    } while (top != -1);
}

void SeparateNode(List *L, List *bagian2)
{
	address slow, fast;
	
	slow = First(*L);
    fast = First(*L)->next;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
	
    First(*bagian2) = slow->next;
    slow->next = NULL; 		
}

