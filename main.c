#include "header.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	/* Kamus Lokal */
	List Queue;
	int pilihan;
	/* Program */
	CreateList(&Queue);

	while (true){
		printf("Pilih Menu : ");
		printf("\n1. Input persediaan barang");
		printf("\n2. Tampilkan persediaan barang");		
		printf("\nPilihan : ");	
		scanf("%d", &pilihan);
		getchar();
		switch (pilihan)
		{
		case 1:
			printf("\n");
			InsertNode(&Queue);
			system("cls");
			break;
		case 2:
			if (IsEmpty(Queue))
			{
				printf("List Kosong...");
				getchar();
			}
			else
			{
				printf("\nList persediaan barang:\n\n");
				PrintInfo(Queue);
			}
			getchar();
			system("cls");
			break;
		default:
			printf("Input Salah...");
			getchar();
			system("cls");
			break;
		}
	}
}

