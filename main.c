#include "header.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	List stokBarang, second_half, three_half, four_half;
	
	int pilihan, jumlahnode;
	addressTree root = NULL;
	addressTree anak1, anak2;

	CreateList(&stokBarang);

	while (true){                                                                                                              
		printf("Pilih Menu : ");
		printf("\n1. Input persediaan barang");
		printf("\n2. Tampilkan persediaan barang");	
		printf("\n3. Jumlah Node");	
		printf("\n4. Merge sort");
		printf("\nPilihan : ");	
		scanf("%d", &pilihan);
		getchar();
		switch (pilihan)
		{
		case 1:
			printf("\n");
			InsertNode(&stokBarang);
			system("cls");
			break;
		case 2:
			if (IsEmpty(stokBarang))
			{
				printf("List Kosong...");
				getchar();
			}
			else
			{
				printf("\nList persediaan barang:\n\n");
				PrintInfo(stokBarang);
			}
			getchar();
			system("cls");
			break;
		case 3 :
			if (First(stokBarang) == Nil)
			{
				printf("List Kosong .... \a\n");
			}
			else /* List memiliki elemen */
			{
				jumlahnode = CountNode(stokBarang);
				printf("%d", jumlahnode);
			}
			getchar();
			system("cls");
			break;
		case 4 :
			root = CreateTree(&stokBarang);		
			SeparateTree(&root);	
//			while (true){
//				printf("Hal yang akan disorting : ");
//				printf("\n1. Stok Barang");
//				printf("\n2. Harga Jual");
//				printf("\n3. Harga Beli");
//				printf("\nPilihan : ");		
//				scanf("%d", &pilihan);
//				getchar();
//				switch (pilihan)
//				{
//					case 1 : 
//						Merge(root, stokBarang, 1);
//						while (true){
//						printf("Sorting secara : ");
//						printf("\n1. Ascending");
//						printf("\n2. Descending");
//						printf("\nPilihan : ");		
//						scanf("%d", &pilihan);
//						getchar();
//						system("cls");
//						break;
//					case 2 :
//						while (true){
//						printf("Sorting secara : ");
//						printf("\n1. Ascending");
//						printf("\n2. Descending");
//						printf("\nPilihan : ");		
//						scanf("%d", &pilihan);
//						getchar();
//						system("cls");
//						break;
//				}
//			}
			getchar();
			system("cls");
			break;
		default:
			printf("Input Salah...");
			
			system("cls");
			break;
		}
	}
}

