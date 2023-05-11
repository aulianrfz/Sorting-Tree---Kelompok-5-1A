#include "header.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	List stokBarang, second_half, three_half, four_half;
	
	int pilih, pilihan, jumlahnode;
	addressTree root = NULL;
	addressTree anak1, anak2;

	CreateList(&stokBarang);
	
	system("color 0F");
	
	menu:
	while (true){  
	system("color 0F");
	printf("\t\t\t\t\t\t  ¦¦¦¦¦¦¦¦¦     ¦¦¦¦¦¦¦¦¦¦¦       ¦¦¦¦¦¦¦         ¦¦¦¦¦¦¦¦¦     ¦¦¦¦¦   ¦¦¦¦    ¦¦¦¦¦    ¦¦¦¦¦¦¦¦¦¦\n");
	printf("\t\t\t\t\t\t ¦¦¦¦¦¦¦¦¦¦¦   ¦¦¦¦¦¦¦¦¦¦¦¦     ¦¦¦¦¦¦¦¦¦¦¦      ¦¦¦¦¦¦¦¦¦¦¦   ¦¦¦¦¦   ¦¦¦¦    ¦¦¦¦¦    ¦¦¦¦¦¦¦¦¦¦¦\n");
	printf("\t\t\t\t\t\t¦¦¦¦           ¦   ¦¦¦¦  ¦     ¦¦¦     ¦¦¦¦¦    ¦¦¦     ¦¦¦     ¦¦¦¦  ¦¦¦       ¦¦¦¦     ¦¦¦¦  ¦ ¦\n"); 
	printf("\t\t\t\t\t\t¦¦¦¦¦¦¦¦¦¦¦        ¦¦¦¦       ¦¦¦¦      ¦¦¦¦   ¦¦¦¦             ¦¦¦¦¦¦¦¦        ¦¦¦¦     ¦¦¦¦¦¦¦\n");   
	printf("\t\t\t\t\t\t ¦¦¦¦¦¦¦¦¦¦¦       ¦¦¦¦       ¦¦¦¦      ¦¦¦¦   ¦¦¦¦             ¦¦¦¦¦¦¦¦¦       ¦¦¦¦     ¦¦¦¦¦¦¦\n");   
	printf("\t\t\t\t\t\t        ¦¦¦¦       ¦¦¦¦       ¦¦¦¦¦     ¦¦¦    ¦¦¦¦¦     ¦¦¦    ¦¦¦¦ ¦¦¦¦¦      ¦¦¦¦     ¦¦¦¦ ¦   ¦\n");
	printf("\t\t\t\t\t\t¦¦¦¦¦¦¦¦¦¦¦        ¦¦¦¦¦       ¦¦¦¦¦¦¦¦¦¦¦      ¦¦¦¦¦¦¦¦¦¦¦     ¦¦¦¦¦ ¦¦¦¦¦¦    ¦¦¦¦¦    ¦¦¦¦¦¦¦¦¦¦\n");
	printf("\t\t\t\t\t\t ¦¦¦¦¦¦¦¦¦        ¦¦¦¦¦          ¦¦¦¦¦¦¦         ¦¦¦¦¦¦¦¦¦     ¦¦¦¦¦   ¦¦¦¦    ¦¦¦¦¦    ¦¦¦¦¦¦¦¦¦¦\n");                                                                                                                                                                                                                                                                                                                                                                                                                        
		printf("\n\t\t\t\t\t\t\t\t||==============================================================||\n");
        printf("\t\t\t\t\t\t\t\t||==============|                                 |=============||\n");
        printf("\t\t\t\t\t\t\t\t||       <<<--- | Welcome To System Administrator | --->>>      ||\n");
        printf("\t\t\t\t\t\t\t\t||==============|                                 |=============||\n");
        printf("\t\t\t\t\t\t\t\t||==============================================================||\n");
        printf("\t\t\t\t\t\t\t\t||                 --->>>| Pilihan Menu |<<<---                 ||\n");
        printf("\t\t\t\t\t\t\t\t||                 ____________________________                 ||\n");
        printf("\t\t\t\t\t\t\t\t||                                                              ||\n");
        printf("\t\t\t\t\t\t\t\t|| ==>> 1. Input Barang                                         ||\n");
        printf("\t\t\t\t\t\t\t\t||______________________________________________________________||\n");
        printf("\t\t\t\t\t\t\t\t||                                                              ||\n");
        printf("\t\t\t\t\t\t\t\t|| ==>> 2. Tampilkan persediaan barang                          ||\n");
        printf("\t\t\t\t\t\t\t\t||______________________________________________________________||\n");
        printf("\t\t\t\t\t\t\t\t||                                                              ||\n");
        printf("\t\t\t\t\t\t\t\t|| ==>> 4. Sort by                                              ||\n");
        printf("\t\t\t\t\t\t\t\t||______________________________________________________________||\n");
        printf("\t\t\t\t\t\t\t\t||==============================================================||\n\n");
		printf("\n\t\t\t\t\t\t\t\tPilih Menu : ");
		printf("\n\t\t\t\t\t\t\t\t1. Input persediaan barang");
		printf("\n\t\t\t\t\t\t\t\t2. Tampilkan persediaan barang");	
		printf("\n\t\t\t\t\t\t\t\t3. Jumlah Node");	
		printf("\n\t\t\t\t\t\t\t\t4. Merge sort");
		printf("\n\t\t\t\t\t\t\t\tPilihan : ");	
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
			while (true){
				printf("\t\t\t\t\t\t\t\tHal yang akan disorting : ");
				printf("\n\t\t\t\t\t\t\t\t1. Stok Barang");
				printf("\n\t\t\t\t\t\t\t\t2. Harga Jual");
				printf("\n\t\t\t\t\t\t\t\t3. Harga Beli");
				printf("\n\t\t\t\t\t\t\t\t4. Keuntungan");
				printf("\n\t\t\t\t\t\t\t\t0. Back");
				printf("\n\t\t\t\t\t\t\t\tPilihan : ");		
				scanf("%d", &pilihan);
				getchar();
				switch (pilihan)
				{
				case 1 :
						while (true){
							printf("\t\t\t\t\t\t\t\tSorting secara : ");
							printf("\n\t\t\t\t\t\t\t\t1. Ascending");
							printf("\n\t\t\t\t\t\t\t\t2. Descending");
							printf("\n\t\t\t\t\t\t\t\t0. Back");
							printf("\n\t\t\t\t\t\t\t\tPilihan : ");		
							scanf("%d", &pilih);
							getchar();
							switch (pilih)
							{
							case 1 :
								root = CreateTree(&stokBarang);	 
								SeparateTree(&root, 1, 1);
								getchar();
								system("cls");
								break;
							case 2 :
								root = CreateTree(&stokBarang);	 
								SeparateTree(&root, 1, 2);
								getchar();
								system("cls");
								break;
							case 0:
								goto menu;
							}
						}
				case 2 :
						while (true){
							printf("\t\t\t\t\t\t\t\tSorting secara : ");
							printf("\n\t\t\t\t\t\t\t\t1. Ascending");
							printf("\n\t\t\t\t\t\t\t\t2. Descending");
							printf("\n\t\t\t\t\t\t\t\tPilihan : ");	
							printf("\n\t\t\t\t\t\t\t\t0. Back");	
							scanf("%d", &pilih);
							getchar();
							switch (pilih)
							{
							case 1 :
								root = CreateTree(&stokBarang);	 
								SeparateTree(&root, 2, 1);
								getchar();
								system("cls");
								break;
							case 2 :
								root = CreateTree(&stokBarang);	 
								SeparateTree(&root, 2, 2);
								getchar();
								system("cls");
								break;
							case 0:
								goto menu;
							}
						}
				case 3 :
						while (true){
							printf("\t\t\t\t\t\t\t\tSorting secara : ");
							printf("\n\t\t\t\t\t\t\t\t1. Ascending");
							printf("\n\t\t\t\t\t\t\t\t2. Descending");
							printf("\n\t\t\t\t\t\t\t\tPilihan : ");	
							printf("\n\t\t\t\t\t\t\t\t0. Back");	
							scanf("%d", &pilih);
							getchar();
							switch (pilih)
							{
							case 1 :
								root = CreateTree(&stokBarang);	 
								SeparateTree(&root, 3, 1);
								getchar();
								system("cls");
								break;
							case 2 :
								root = CreateTree(&stokBarang);	 
								SeparateTree(&root, 3, 2);
								getchar();
								system("cls");
								break;
							case 0:
								goto menu;
							}
						}
				case 4 :
						while (true){
							printf("Sorting secara : ");
							printf("\n\t\t\t\t\t\t\t\t1. Ascending");
							printf("\n\t\t\t\t\t\t\t\t2. Descending");
							printf("\n\t\t\t\t\t\t\t\tPilihan : ");	
							printf("\n\t\t\t\t\t\t\t\t0. Back");	
							scanf("%d", &pilih);
							getchar();
							switch (pilih)
							{
							case 1 :
								root = CreateTree(&stokBarang);	 
								SeparateTree(&root, 4, 1);
								getchar();
								system("cls");
								break;
							case 2 :
								root = CreateTree(&stokBarang);	 
								SeparateTree(&root, 4, 2);
								getchar();
								system("cls");
								break;
							case 0:
								goto menu;
							}
						}
					}
				case 0:
					goto menu;
				}
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


