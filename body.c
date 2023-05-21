#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
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

address Alokasi(List L)
{
	/* Kamus Lokal */
	address P;
	int i, ukuran;
	char status;
	/* Algoritma */
	P = (address)malloc(sizeof(persediaanBarang));
	if (P != Nil) /* Alokasi berhasil */
	{
		printf("\t\t\t\t\t\t\t\tMasukkan nama barang\t: ");
	    scanf("%s", &Info(P)); 
    	printf("\t\t\t\t\t\t\t\tMasukkan jumlah stok\t: ");
    	scanf("%d", &Stok(P));
    	printf("\t\t\t\t\t\t\t\tMasukkan harga beli\t: ");
    	scanf("%d", &Beli(P));
    	do{
    		printf("\t\t\t\t\t\t\t\tMasukkan harga jual\t: ");
    		scanf("%d", &Jual(P));
    		if (Jual(P) >= Beli(P)){
	    		Keuntungan(P) = Jual(P) - Beli(P);
				Next(P) = Nil;
			}
			else{
				printf("\t\t\t\t\t Harga jual yang anda masukkan kurang dari harga beli");
				printf("\t\t\t\t\t Silakan masukkan ulang harga jual");
			}
		}while(Jual(P) < Beli(P));
	}
	return (P);
}

void InsertNode(List *L)
{
	/* Kamus Lokal */
	address P;
	address Last;
	/* Algoritma */
	P = Alokasi(*L);
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

void PrintInfo(List L){
	address P, still;

	if (First(L) == Nil)
	{
		printf("\t\t\t\t\t\t\t\tList Kosong .... \a\n");
	}
	else /* List memiliki elemen */
	{
		still = P;
		P = First(L);
		printf("\t\t\t\t\t\t|:-----------:|:-----------:|:----------:|:----------:|:---------:|\n");
		printf("\t\t\t\t\t\t| Nama Barang | Jumlah Stok | Harga Beli | Harga Jual | Keuntungan |\n");
		printf("\t\t\t\t\t\t|:-----------:|:-----------:|:----------:|:----------:|:---------:|\n");
		while (P != Nil)
		{
			if (P == Nil)
			{
				printf("\n");
				break;
			}
			else /* Belum berada di akhir List */
			{
				printf("\t\t\t\t\t\t|%12s |%12d |%11d |%11d |%10d |\n", Info(P), Stok(P), Beli(P), Jual(P), Keuntungan(P));
				P = Next(P);
			}
			printf("\n");
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

addressTree CreateTree(List L)
{
	addressTree root;

	root = (addressTree)malloc(sizeof(nbtree));
	if(IsEmpty(L) == false)
	{
		InfoTree(root) = L;
		Left(root) = NULL;
		Right(root) = NULL;
		Parent(root) = NULL;
		Status(root) = false;
		if (IsEmptyTree(root) == false){
//			printf("\nIsi tree : \n\n");
//			PrintInfo(InfoTree(root));
		}	
	}
	else{
		printf("\t\t\t\t\t\t\t\tIsi tree kosong...");
	}
	
	return(root);
}

void CopyList(List L, List *copy)
{
    address current = First(L);
    address prev = NULL;
    address newNode;

    while (current != NULL) {
        //address newNode = Alokasi(current->info);
        newNode = (address)malloc(sizeof(persediaanBarang));
        if (newNode != Nil) /* Alokasi berhasil */
		{
			strcpy(newNode->info, current->info);
			newNode->stok= current->stok;
			newNode->hargaBeli = current->hargaBeli;
			newNode->hargaJual = current->hargaJual;
			newNode->keuntungan = current->keuntungan;
			newNode->next = Nil;
		}
        if (prev == NULL) {
            First(*copy) = newNode;
        } else {
            prev->next = newNode;
        }
        newNode->next = NULL;
        prev = newNode;
        current = current->next;
    }
}


void SeparateNode(List *L, List *bagian1, List *bagian2)
{
	List copy;
    CreateList(&copy);
    CopyList(*L, &copy);

    // Separate nodes
    address slow, fast;
    
    slow = First(copy);
    fast = First(copy)->next;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    
    First(*bagian1) = First(copy);
    First(*bagian2) = slow->next;
    slow->next = NULL;	
}

<<<<<<< HEAD
=======
void SeparateTree(addressTree *root, int pilihan, int pilih) {
	//kamus data
    addressTree stack[MAX_SIZE], last, still, anak1, anak2, prev, priv, awalan;
    List check, bagian, chick;
    addressTree daun, tempDaun;
	int lewat;
	lewat = 0;
>>>>>>> 76c1952ac048cfaf55950a19da84431443230330


void SeparateTree(addressTree *root) {
	//kamus data
    addressTree stack[MAX_SIZE], last, still, anak1, anak2, prev;
    List check, bagian1, bagian2;
    address isi;
    int i, j, count, top;
    
    //membagi roor menjadi satu node pada setiap anaknya
    if (*root == Nil) {
        return;
    }
    
	top = -1;
    prev = *root;
    still = *root;
    
    do {	
		if(top != -1){
			top--;
		}
		while (still != NULL) 
		{
	        stack[++top] = still;
            stack[++top] = still;
			last = still;
            still = (still)->left;
        }
        while (top != -1 && (stack[top]->right == NULL || stack[top]->right == prev)) {
        	if(stack[top]->right != prev){
				prev = stack[top--];
	            check = prev->infoTree;
	            isi = First(check);
	            if(isi != Nil){
	            	count = CountNode(check);
	            	if (count != 1)
	            	{
						CreateList(&bagian1);
						CreateList(&bagian2);
						SeparateNode(&check, &bagian1, &bagian2);
						anak1 = CreateTree(bagian1);
						anak2 = CreateTree(bagian2);
	    				last->left = anak1;
	    				last->right = anak2;
	    				Parent(anak1) = last;
	    				Parent(anak2) = last;
	    				still = last;
	    				last = last->left;
	    				printf("\\t\t\t\t\t\t\t\tn===================================\n");
	    				printf("First half: ");
	    				PrintInfo(bagian1);
	    				printf("\\t\t\t\t\t\t\t\tn------------------------------------\n");
						printf("Second half: ");
	    				PrintInfo(bagian2);
	    				printf("\n\t\t\t\t\t\t\t\t===================================\n");
	    				count = CountNode(bagian1);
	    				if(count != 1)
						{
	    					stack[++top] = anak1;
	    					stack[++top] = anak1;
	    				}
					}
				} 
				else {
					printf("\n\t\t\t\t\t\t\t\tIsi Tree kosong");
				}
        	} 
			else {
    			prev = stack[top--];
			}
   		}
        if (top != -1) {
			still = stack[top]->right;
        }  
    }while(top != -1);
}

boolean IsLeaf(addressTree node) {
	if (node != NULL && node->left == NULL && node->right == NULL){
		return true;
	}
	else {
		return false;
	}
}

void InsertLeavesToArray(addressTree root, array *arr, int *index) {
    if (root == NULL) {
        return;
    }
    
    addressTree stack[MAX_SIZE];
    int top = -1;
    
	int count = 0;
    address itung;
    addressTree node;
    address isi;
    List check, link;
    addressTree newTree;
    newTree = Nil;
    
    *index = Nil;
    
    stack[++top] = root;
    
    do{
        node = stack[top--];
            	
    	check = node->infoTree;
        isi = First(check);
        
        if (IsLeaf(node)) {
            strcpy((*arr)[*index].namaBarang, isi->info);
            (*arr)[*index].stok = isi->stok;
            (*arr)[*index].hargaBeli = isi->hargaBeli;
            (*arr)[*index].hargaJual = isi->hargaJual;
            (*arr)[*index].keuntungan = isi->keuntungan;
            (*index)++;	 
        }
        
        count = 0;        
        itung = isi;
        while (itung != NULL) {
        	count++;
        	itung = itung->next;
    	}
    	
    	printf("COUNT %d", count);
    	printf("INDEX %d", *index);
    	
    	addressTree sibling;
    	
    	if(count == 1 && newTree == Nil)
        {
           	sibling = node;
		}
        
        if (node->right != NULL) {
            stack[++top] = node->right;
        }
        
        if (node->left != NULL) {
            stack[++top] = node->left;
        }
    
    	if(count == 1 && *index != 1)
    	{
    		node->status = true;
    		link = Merge(*arr, *index);
			newTree = CreateTree(link);	
			sibling->right = newTree;
			node->left = newTree;	
			newTree = Nil;
			*index = 0;	
		}else {
		node->status = false; }
		
			printf("\niyah %d", *index);
			printf("\ntop %d", top);
			if(node->status == true)
			{
				printf("IYA TRUE");
			} else {printf("bukan true");
			}
		
    } while ((node->status == false) || (top != -1 ));
    
}

List Merge(array arr, int index)
{
	List newNode;
	address P;
	address Last;
	CreateList(&newNode);
	int i;
	
    //memasukkan setiap elemen pada array ke dalam list
	for (i = 0; i < index ; i++) {
		P = (address)malloc(sizeof(persediaanBarang));
		if (P != Nil)
		{
		//	strcpy(Info(P), arr[i].namaBarang);
	    	Stok(P) = (arr)[i].stok;
	    	Beli(P) = (arr)[i].hargaBeli;
	    	Jual(P) = (arr)[i].hargaJual;
	    	Keuntungan(P) = (arr)[i].keuntungan;
			Next(P) = Nil;
		}
			if (P != Nil){
				if (First(newNode) != Nil){
					Last = First(newNode);
					while (Next(Last) != Nil){
						Last = Next(Last);
					}
						Next(Last) = P;
			}
			else{
				First(newNode) = P;
				}
			}
	}
	
	printf("BERHASIL");
	PrintInfo(newNode);
	
	return(newNode);
}
<<<<<<< HEAD

=======
>>>>>>> 76c1952ac048cfaf55950a19da84431443230330
