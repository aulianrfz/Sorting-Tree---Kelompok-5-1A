#include "header.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	/* Kamus Lokal */
	List stokBarang;
	
	int pilihan, jumlahnode;
	addressTree root = NULL;
	/* Program */
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
			CreateTree(&root, stokBarang);
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

