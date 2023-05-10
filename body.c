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

address Alokasi(List *L)
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
	P = Alokasi(L);
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
		printf("List Kosong .... \a\n");
	}
	else /* List memiliki elemen */
	{
		still = P;
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
				printf("\nNama barang\t: %s\n", Info(P));
				printf("Jumlah stok\t: %d\n", Stok(P));
				printf("Harga beli\t: Rp. %d\n", Beli(P));
				printf("Harga jual\t: Rp. %d\n", Jual(P));
				printf("Keuntungan\t: Rp. %d\n", Keuntungan(P));\
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
//			PrintInfo(InfoTree(root));
//		}	
	}
	else{
		printf("Isi tree kosong...");
	}
	return(root);
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

void SeparateTree(addressTree *root) {
	//kamus data
    addressTree stack[MAX_SIZE], last, still, anak1, anak2, prev, priv;
    List check, bagian, chick;
    addressTree daun, tempDaun;
	int lewat;
	lewat = 0;

	array max[MAX_SIZE];
	array temp;
    
    address isi, izi;
    int count, top, itung;
    
    //membagi root menjadi berisi satu node saja setiap bagiannya
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
		while (*root != NULL) 
		{
	        stack[++top] = *root;
            stack[++top] = *root;
			last = *root;
            *root = (*root)->left;
        }
	        priv = stack[top];
		    chick = priv->infoTree;
		    itung = CountNode(chick);
		    printf("\nSTACK SAAT INI ATAS : %d", itung);
	        while (top != -1 && (stack[top]->right == NULL || stack[top]->right == prev)) {
	        	if(stack[top]->right != prev){
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
	    				printf("\nitungan : %d", count);
	    				printf("\nISI : %s", izi->info);
	    				if(count != 1)
						{
	    					stack[++top] = anak1;
	    					stack[++top] = anak1;
	    				}
					}
				} 
				else {
					printf("Isi Tree kosong");
				}
	        } 
			else {
	    		prev = stack[top--];
			}
    	}    
    } while (top != -1);
    
    //memasukkan setiap ujung node yang berjumlah satu kedalam array yang berbeda
    int i;
    prev = Nil;
    i = 0;
    *root = still;
    boolean stop;
    stop = true;
	do{
		do {	
			if(top == 0 && last == *root)
			{
				top--;
			}
			if(last == still){
				top--;
				stop = false;
			} 
			while (*root != NULL) 
			{
	            stack[++top] = *root;
	            *root = (*root)->left;
	        }
	        while (top != -1 && (stack[top]->right == NULL || stack[top]->right == prev)) {
				prev= stack[top--];
	            check = prev->infoTree;
	            isi = First(check);
				count = CountNode(check);
				if (count == 1){
	//				max[i].info = isi->info;
	//				printf("\ninfo : %s ", max[i].info);
					max[i].stok = isi->stok;
					printf("\ninfo : %d ", max[i].stok);
					max[i].hargaBeli = isi->hargaBeli;
					max[i].hargaJual = isi->hargaJual;
					max[i].keuntungan = isi->keuntungan;
					i++;
				}
			}
			if (top != -1) {
				*root = stack[top]->right;
				last = still;
	        }
		} while (stop == true);
	
		i = 0;
		int hitungArray;
		hitungArray = 0;
		while(max[i].stok != 0)
		{
			hitungArray = hitungArray + 1;
			i++;
		}
		printf("\n\nISI ARRAY : %d", hitungArray);
		
		//sorting pada array
		// BESAR KE KECIL
		for (i = 0; i <= hitungArray-1; i++) {
	        if (max[i+1].stok > max[i].stok) {
	            temp = max[i];
	        	max[i] = max[i+1];
	            max[i+1] = temp;
	        }
	    }
	    
	    printf("\n\nISI ARRAY : %d", hitungArray);
	    printf("\nArray setelah sorting: \n");
	    for (i = 0; i <= hitungArray-1 ; i++) {
	        printf("%d ", max[i].stok);
	    }
	    
	    //membuat list berdasarkan array yang sudah disorting
	    List newNode;
		address P;
		address Last;
		CreateList(&newNode);
		//memasukkan setiap ellemen array ke list
		i = 0;
		for (i = 0; i <= hitungArray-1 ; i++) {
			P = (address)malloc(sizeof(persediaanBarang));
			if (P != Nil)
			{
		    	//Info(P) = max[i].info;
		    	Stok(P) = max[i].stok;
		    	Beli(P) = max[i].hargaBeli;
		    	Jual(P) = max[i].hargaJual;
		    	Keuntungan(P) = max[i].keuntungan;
				Next(P) = Nil;
			}
			if (P != Nil)
			{
				if (First(newNode) != Nil){
					Last = First(newNode);
					while (Next(Last) != Nil){
						Last = Next(Last);
					}
					Next(Last) = P;
				}
				else
				{
					First(newNode) = P;
				}
			}
		}
		printf("isi list :::");
		PrintInfo(newNode);
		i = 0;
		stop = true;
		last = *root;
		
		//membuat node tree berisi list yang sudah disorting
		if(daun != Nil){
			tempDaun = daun;
		}
		daun = CreateTree(&newNode);
		printf("isi tree ::");
		PrintInfo(InfoTree(daun));
	} while(top != -1);
	
	//menyambungkan node tree ke tree
	*root = still;
	stop = true;
	prev = Nil;
	top = -1;
	printf("\n\n\nMASUK\n\n\n ");
	do { 
		while (*root != NULL) 
		{
	        stack[++top] = *root;
	    	*root = (*root)->left;
	    }
		while (top != -1 && (stack[top]->right == NULL || stack[top]->right == prev)) {
			prev = stack[top--];
	    	if (Left(prev) == Nil){
				if(lewat < 2){
					Right(prev) = tempDaun;
	            	Left(prev) = tempDaun;
	            	lewat++;	
				} 
				else {
					Right(prev) = daun;
	            	Left(prev) = daun;
	            	lewat++;
				}
	            printf("berhasil tambahkan \n\n\n ");
	            PrintInfo(InfoTree(Right(prev)));
			}
		}
		if (top != -1) {
			*root = stack[top]->right;
			top--;
			last = still;
	    }  
		printf("HI");    
	} while (lewat < 4);
	fflush(stdin);
	
	//memasukkan setiap node tree yang telah diurutkan sebelumnya ke dalam array
	top = -1;
	*root = awalan;
	last = Nil;
	stop = true;
	do{
		do {
				if(top == 0 && last == *root)
			{
				top--;
			}	
			if(last == still){
				top--;
				stop = false;
			} 
			while (*root != NULL) 
			{
	            stack[++top] = *root;
	            *root = (*root)->left;
	        }
	        while (top != -1 && ((stack[top]->right == NULL) || (stack[top]->right == prev))) {
				prev= stack[top--];
	            check = prev->infoTree;
	            isi = First(check);
				count = CountNode(check);
					while(isi !=Nil){
	//				max[i].info = isi->info;
	//				printf("\ninfo : %s ", max[i].info);
					max[i].stok = isi->stok;
					printf("\ninfo : %d ", max[i].stok);
					max[i].hargaBeli = isi->hargaBeli;
					max[i].hargaJual = isi->hargaJual;
					max[i].keuntungan = isi->keuntungan;
					i++;
					isi = isi->next;
				}
				top--;
				top--;
			}
			if (top != -1) {
				*root = stack[top]->right;
				last = still;
	        }
		} while (stop == true);
	
		i = 0;
		int hitungArray;
		hitungArray = 0;
		while(max[i].stok != 0)
		{
			hitungArray = hitungArray + 1;
			i++;
		}
		printf("\n\nISI ARRAY : %d", hitungArray);
		
		//sorting pada array
		// BESAR KE KECIL
		int j;
		for (i = 0; i < hitungArray-1; i++) {
		    for (j = 0; j < hitungArray-i-1; j++) {
		        if (max[j].stok < max[j+1].stok) {
		            // Swap the elements
		            temp = max[j];
		            max[j] = max[j+1];
		            max[j+1] = temp;
		        }
		    }
		}
	    printf("\n\nISI ARRAY : %d", hitungArray);
	    printf("\nArray setelah sorting: \n");
	    for (i = 0; i <= hitungArray-1 ; i++) {
	        printf("%d ", max[i].stok);
	    }
	    
	    //membuat list dari array yang telahh disorting
	    List newNode;
		address P;
		address Last;
		CreateList(&newNode);
	
		//memasukkan setiap elemen array ke list baru
		i = 0;
		for (i = 0; i <= hitungArray-1 ; i++) {
		P = (address)malloc(sizeof(persediaanBarang));
			if (P != Nil)
			{
		    	//Info(P) = max[i].info;
		    	Stok(P) = max[i].stok;
		    	Beli(P) = max[i].hargaBeli;
		    	Jual(P) = max[i].hargaJual;
		    	Keuntungan(P) = max[i].keuntungan;
				Next(P) = Nil;
			}
		if (P != Nil)
		{
			if (First(newNode) != Nil){
				Last = First(newNode);
				while (Next(Last) != Nil){
					Last = Next(Last);
				}
				Next(Last) = P;
			}
			else
			{
				First(newNode) = P;
			}
		}
		}
		printf("isi list :::");
		PrintInfo(newNode);
		i = 0;
		stop = true;
		last = *root;
		
		//membuat node tree untuk list yang telah disorting
		if(daun != Nil){
			tempDaun = daun;
		}
		daun = CreateTree(&newNode);
		printf("isi tree ::");
		PrintInfo(InfoTree(daun));
	} while(top != -1);
	
	//menyambungkan node tree ke tree
	*root = still;
	stop = true;
	prev = Nil;
	top = -1;
	printf("\n\n\nMASUK\n\n\n ");
	do { 
		while (*root != NULL) 
		{
	        stack[++top] = *root;
	    	*root = (*root)->left;
	    }
		while (top != -1 && (stack[top]->right == NULL || stack[top]->right == prev)) {
			prev = stack[top--];
	    	if (Left(prev) == Nil){
					Right(prev) = daun;
	            	Left(prev) = daun;
	            	lewat++;	
	            printf("berhasil tambhkan \n\n\n ");
	            PrintInfo(InfoTree(Right(prev)));
			}
		}
		top--;
		top--;
		top--;
		if (top != -1) {
			*root = stack[top]->right;
			last = still;
	    }  
		printf("HI");    
	} while (lewat < 4);
	fflush(stdin);
}
}

