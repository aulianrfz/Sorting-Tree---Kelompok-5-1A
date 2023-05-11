#include "header.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	List stokBarang;
	
	int pilih, pilihan, jumlahnode;
	addressTree root = NULL;

	CreateList(&stokBarang);
	
	menu:
	while (true){  
		header();
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
	    printf("\t\t\t\t\t\t\t\t|| ==>> 3. Sort by                                              ||\n");
	    printf("\t\t\t\t\t\t\t\t||______________________________________________________________||\n");
	    printf("\t\t\t\t\t\t\t\t||==============================================================||\n\n");
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
				printf("\t\t\t\t\t\t\t\tList Kosong...");
				getchar();
			}
			else
			{
				printf("\n\t\t\t\t\t\t\t\tList persediaan barang:\n\n");
				PrintInfo(stokBarang);
			}
			getchar();
			system("cls");
			break;
		case 3 :	
			while (true){
				printf("\n\n\t\t\t\t\t\t\t\tHal yang akan disorting : ");
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
							system("cls");
							header();
							printf("\n\t\t\t\t\t\t\t\tSorting secara : ");
							printf("\n\t\t\t\t\t\t\t\t1. Ascending");
							printf("\n\t\t\t\t\t\t\t\t2. Descending");
							printf("\n\t\t\t\t\t\t\t\t0. Back");
							printf("\n\t\t\t\t\t\t\t\tPilihan : ");		
							scanf("%d", &pilih);
							getchar();
							switch (pilih)
							{
							case 1 :
								printf("\n\n\t\t\t\t\t\t\t\tSorting Stok Ascending\n");
								root = CreateTree(&stokBarang);	 
								MergeSort(&root, 1, 1);
								getchar();
								system("cls");
								goto menu;
								break;
							case 2 :
								printf("\n\n\t\t\t\t\t\t\t\tSorting Stok Descending\n");
								root = CreateTree(&stokBarang);	 
								MergeSort(&root, 1, 2);
								getchar();
								system("cls");
								goto menu;
								break;
							case 0:
								goto menu;
							}
						}
				case 2 :
						while (true){
							system("cls");
							header();
							printf("\n\t\t\t\t\t\t\t\tSorting secara : ");
							printf("\n\t\t\t\t\t\t\t\t1. Ascending");
							printf("\n\t\t\t\t\t\t\t\t2. Descending");
							printf("\n\t\t\t\t\t\t\t\tPilihan : ");	
							printf("\n\t\t\t\t\t\t\t\t0. Back");	
							scanf("%d", &pilih);
							getchar();
							switch (pilih)
							{
							case 1 :
								printf("\n\n\t\t\t\t\t\t\t\tSorting Harga Jual Ascending\n");
								root = CreateTree(&stokBarang);	 
								MergeSort(&root, 2, 1);
								getchar();
								system("cls");
								goto menu;
								break;
							case 2 :
								printf("\n\n\t\t\t\t\t\t\t\tSorting Harga Jual Descending\n");
								root = CreateTree(&stokBarang);	 
								MergeSort(&root, 2, 2);
								getchar();
								system("cls");
								goto menu;
								break;
							case 0:
								goto menu;
							}
						}
				case 3 :
						while (true){
							system("cls");
							header();
							printf("\n\t\t\t\t\t\t\t\tSorting secara : ");
							printf("\n\t\t\t\t\t\t\t\t1. Ascending");
							printf("\n\t\t\t\t\t\t\t\t2. Descending");
							printf("\n\t\t\t\t\t\t\t\tPilihan : ");	
							printf("\n\t\t\t\t\t\t\t\t0. Back");	
							scanf("%d", &pilih);
							getchar();
							switch (pilih)
							{
							case 1 :
								printf("\n\n\t\t\t\t\t\t\t\tSorting Harga Beli Ascending\n");
								root = CreateTree(&stokBarang);	 
								MergeSort(&root, 3, 1);
								getchar();
								system("cls");
								goto menu;
								break;
							case 2 :
								printf("\n\n\t\t\t\t\t\t\t\tSorting Harga Beli Descending\n");
								root = CreateTree(&stokBarang);	 
								MergeSort(&root, 3, 2);
								getchar();
								system("cls");
								goto menu;
								break;
							case 0:
								goto menu;
							}
						}
				case 4 :
						while (true){
							system("cls");
							header();
							printf("\n\t\t\t\t\t\t\t\tSorting secara : ");
							printf("\n\t\t\t\t\t\t\t\t1. Ascending");
							printf("\n\t\t\t\t\t\t\t\t2. Descending");
							printf("\n\t\t\t\t\t\t\t\tPilihan : ");	
							printf("\n\t\t\t\t\t\t\t\t0. Back");	
							scanf("%d", &pilih);
							getchar();
							switch (pilih)
							{
							case 1 :
								printf("\n\n\t\t\t\t\t\t\t\tSorting Keuntungan Ascending\n");
								root = CreateTree(&stokBarang);	 
								MergeSort(&root, 4, 1);
								getchar();
								system("cls");
								goto menu;
								break;
							case 2 :
								printf("\n\n\t\t\t\t\t\t\t\tSorting Keuntungan Descending\n");
								root = CreateTree(&stokBarang);	 
								MergeSort(&root, 4, 2);
								getchar();
								system("cls");
								goto menu;
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


