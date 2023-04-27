#include "header.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	/* Kamus Lokal */
	List stokBarang, second_half, three_half, four_half;
	
	int pilihan, jumlahnode;
	addressTree root = NULL;
	addressTree anak1, anak2;
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
			// Masih bisa dilakukan jika inputan 4 barang, belum dijadikan modul
			
			root = CreateTree(&stokBarang);
			
			printf("\nSebelum di pisah: \n");
			PrintInfo(stokBarang);
			
			jumlahnode = CountNode(stokBarang);
    			
			First(second_half) = Nil;
			SeparateNode(&stokBarang, &second_half);
			anak1 = CreateTree(&stokBarang);
			anak2 = CreateTree(&second_half);
    		root->left = anak1;
    		root->right = anak2;
    		
    		jumlahnode = CountNode(stokBarang);
    		
    		First(three_half) = Nil;
			SeparateNode(&stokBarang, &three_half);
			
    		anak1 = CreateTree(&stokBarang);
    		anak2 = CreateTree(&three_half);
    		root->left->left = anak1;
    		root->left->right = anak2;
    		
    		First(four_half) = Nil;
			SeparateNode(&second_half, &four_half);
			
    		anak1 = CreateTree(&second_half);
    		anak2 = CreateTree(&four_half);
    		root->right->left = anak1;
    		root->right->right = anak2;
    		
    		printf("\nSetelah di pisah: \n");
    		printf("kesatu: ");
    		PrintInfo(stokBarang);

    		printf("kedua: ");
    		PrintInfo(three_half);
    		
    		printf("ketiga: ");
    		PrintInfo(second_half);

    		printf("keempat: ");
    		PrintInfo(four_half);
				
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

