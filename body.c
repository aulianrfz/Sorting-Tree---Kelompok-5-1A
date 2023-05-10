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
    addressTree stack[MAX_SIZE], last, still, anak1, anak2, prev, priv;
    List check, bagian, chick;


	array max[MAX_SIZE];
	int temp;
    
    address isi, izi;
    int count, top, itung;
    
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
//			priv = stack[top];
//	        chick = priv->infoTree;
//	        izi = First(chick);
//	        itung = CountNode(chick);
//	        printf("\nSTACK SAAT INI TENGAH : %d", itung);
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
//					if(top == 0)
//    				{
//    					last = still;
//					}
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
    					chick = priv->infoTree;
	        izi = First(chick);
	        itung = CountNode(chick);
	        printf("\nSTACK SAAT INI FIX 2 : %d", itung);
    				}
    				printf("\ntop %d", top);
    							priv = stack[top];
	        chick = priv->infoTree;
	        itung = CountNode(chick);
	        izi = First(chick);
	        printf("\nISI : %s", izi->info);
				}
			} else {
				printf("Isi Tree kosong");
			}
        } else {
    			prev = stack[top--];
			}
    }
//        check1 = stack[top];
//        check2 = check1->infoTree;
//        check3 = First(check2);
//        printf("stack terakhir : %s ", check3->info );
        
        if (top != -1) {
			priv = stack[top];
	        chick = priv->infoTree;
	        itung = CountNode(chick);
	        printf("\nSTACK SAAT INI BAWAH : %d", itung);
			*root = stack[top]->right;
			printf("\ntop TENGAH %d", top);
			//stack[top--];
        }
        printf("\ntop AKHIR %d", top);
        
        
    } while (top != -1);
    
//    *root = still;
//	prev = NULL;
//    do {
//        while (*root != NULL) {
//            stack[++top] = root;
//            *root = (*root)->left;
//        }
//        
//        
//        while (top != -1 && (stack[top]->right == NULL || stack[top]->right == prev)) {
//            prev = stack[top--];
//            check = prev->infoTree;
//            isi = First(check);
//            printf("%s ", isi->info);
//            
//        }
//        if (top != -1) {
//            root = stack[top]->right;
//        }
//    } while (top != -1);
    
    
    int i;
    prev = Nil;
    i = 0;
    *root = still;
    boolean stop;
    stop = true;
  //  prev = *root;
    do {	
		if(top != -1){
			top--;
			stop = false;
		}
		while (*root != NULL) 
		{
            stack[++top] = *root;
//			last = *root;
            *root = (*root)->left;
        }
        while (top != -1 && (stack[top]->right == NULL || stack[top]->right == prev)) {
			prev= stack[top--];
            check = prev->infoTree;
            isi = First(check);
			count = CountNode(check);
//			priv = stack[top];
//	        chick = priv->infoTree;
//	        itung = CountNode(chick);
//	        printf("\nSTACK SAAT INI : %d", itung);
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
        }
	} while (stop == true);

    printf("\nTOP ARRAY %d", top);	
    priv = stack[top];
	chick = priv->infoTree;
	itung = CountNode(chick);
	printf("\nSTACK ARRAY SAAT INI : %d", itung);
	
	i = 0;
	int hitungArray;
	hitungArray = 0;
	while(max[i].stok != 0)
	{
		hitungArray = hitungArray + 1;
		i++;
	}
	printf("\n\nISI ARRAY : %d", hitungArray);
	
	// BESAR KE KECIL
	for (i = 0; i <= hitungArray-1; i++) {
        if (max[i+1].stok > max[i].stok) {
            // Swap arr[j] and arr[j+1]
            temp = max[i].stok;
        	max[i].stok = max[i+1].stok;
            max[i+1].stok = temp;
        }
    }
    
    printf("\n\nISI ARRAY : %d", hitungArray);
    printf("\nArray setelah sorting: \n");
    for (i = 0; i <= hitungArray-1 ; i++) {
        printf("%d ", max[i].stok);
    }
    
    List newNode;
	address P;
	address Last;
	CreateList(&newNode);

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
	
	PrintInfo(newNode);
}

//void SeparateTree(addressTree *root) {
//    addressTree stack[MAX_SIZE], last, still, anak1, anak2, prev ,priv;
//    List check, bagian, chick;
//
//	array temp[MAX_SIZE], max[MAX_SIZE];
//    
//    address isi, izi;
//    int count, top, itung;
//    
//    int i;
//    
//    if (*root == Nil) {
//        return;
//    }
//    
//	top = -1;
//    prev = Nil;
//    still = *root;
//    do {	
//		while (*root != NULL) 
//		{
//            stack[++top] = *root;
//            stack[++top] = *root;
//			last = *root;
//            *root = (*root)->left;
//        }
//        
//        while (top != -1 && (stack[top]->right == NULL || stack[top]->right == prev)) {
//			if(stack[top]->right != prev){
//				prev = stack[top--];
//	            count = CountNode(check);
//	            isi = First(check);
//	            if(isi != Nil){
//	            	count = CountNode(check);
//	            	if (count != 1)
//	            	{
//	            		CreateList(&bagian);
//						SeparateNode(&check, &bagian);
//						anak1 = CreateTree(&check);
//						anak2 = CreateTree(&bagian);
//						if(top == 0)
//	    				{
//	    					last = still;
//						}
//	    				last->left = anak1;
//	    				addressTree tunjuk;
//	    				List coba;
//	    				address nama;
//	    				tunjuk = last->left;
//	            		coba = tunjuk->infoTree;
//	            		nama = First(coba);
//	            		while(nama!= Nil){
//	            			printf("\nKIRI isi node : %s", nama->info);
//	            			nama = nama->next;
//						}
//	            		//printf("\nisi node : %s", nama->info);
//	    				last->right = anak2;
//	    					    				tunjuk = last->right;
//	            		coba = tunjuk->infoTree;
//	            		nama = First(coba);
//	            		while(nama!= Nil){
//	            			printf("\nKANAN isi node : %s", nama->info);
//	            			nama = nama->next;
//						}
//	    				*root = last;
//	    				last = last->left;
//	    				printf("\n===================================\n");
//	    				printf("First half: ");
//	    				PrintInfo(check);
//	    				printf("\n------------------------------------\n");
//						printf("Second half: ");
//	    				PrintInfo(bagian);
//	    				printf("\n===================================\n");
////	    				priv = stack[top];
////	            		chick = priv->infoTree;
////	            		itung = CountNode(chick);
////	            		printf("STACK SAAT INI : %d", itung);
//	    				count = CountNode(check);
//	    				if(count !=1)
//						{
//	    					stack[++top] = anak1;
//	    					stack[++top] = anak1;
//	    				}
//					}
//				} else {
//					printf("Isi Tree kosong");
//				}
//	        }else {
//    			prev = stack[top--];
//			}
//    	}
//        
//        if (top != -1) {
//			*root = stack[top]->right;
//        }
//    } while (top != -1);
//    
//    i = 0;
//    *root = still;
//    do {	
//		while (*root != NULL) 
//		{
//            stack[++top] = *root;
//			last = *root;
//            *root = (*root)->left;
//        }
//        while (top != -1 && (stack[top]->right == NULL || stack[top]->right == prev)) {
//			prev= stack[top--];
//            check = prev->infoTree;
//            isi = First(check);
//			count = CountNode(check);
//			while(isi != Nil){
//				printf("\nisi(%d) : %d ", i, isi->stok);
//				isi = isi->next;
//			} 
//			i++;
////			if (count == 1){
//////				max[i].info = isi->info;
//////				printf("\ninfo : %s ", max[i].info);
////				max[i].stok = isi->stok;
////				printf("\ninfo : %d ", max[i].stok);
////				max[i].hargaBeli = isi->hargaBeli;
////				max[i].hargaJual = isi->hargaJual;
////				max[i].keuntungan = isi->keuntungan;
////				i++;
////			}
//		}
//		if (top != -1) {
//			*root = stack[top]->right;
//        }
//	} while (top != -1);
//}

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
