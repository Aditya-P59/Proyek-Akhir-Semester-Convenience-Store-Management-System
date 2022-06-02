//Proyek Akhir Semester Algoritma dan Pemrograman
//Anggota Kelompok :
//Aditya Putranto
//Muhammad Akmal Zuhdi
//Salma Azra

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include "PAS_headermarket.h"
#define BROWN_TEXT "\x1B[38;2;89;60;31m"

int main()
{
	system("cls");
	system ("Color E3");
	struct daftarbarang toko;
	struct node data_barang;
	int menuawal,jumlahbarang,barang;
	printf(BROWN_TEXT"\n\t====================================================================================\n") ;
	printf("\t>>>>>>>>>>>>>>>>>  Welcome to Convenience Store Management System  <<<<<<<<<<<<<<<<<\n") ;
	printf("\t====================================================================================\n") ;
	printf("\n\t1. Mulai Program\n") ;
	printf("\n\t2. Informasi Program\n") ;
	printf("\n\t>>") ;
	scanf("%d", &menuawal) ;
	switch(menuawal)
	{
		case 1:
			login(data_barang, toko, barang, jumlahbarang) ;
			break;
		case 2:
			informasiprogram();
			break;
		default:
			printf("\n\tAnda memasukkan pilihan yang salah!\n\n");
			system("pause");
			return main();
	}
}

