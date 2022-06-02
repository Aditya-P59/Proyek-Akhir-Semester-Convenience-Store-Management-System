#include "PAS_binary_tree_model.h"

struct daftarbarang
{
	char namabarang[50], temp[50], dummy[50];
	int hargabarang, stokbarang;
}	inventaris[100], caribarang[100];


void inputbarang(struct node data_barang,struct daftarbarang toko, int barang, int jumlahbarang);
void bubbleshort(struct node data_barang,struct daftarbarang toko, int barang, int jumlahbarang);
void halamanpelanggan(struct node data_barang,struct daftarbarang toko, int barang, int jumlahbarang);
void orderbarang(struct node data_barang,struct daftarbarang toko, int barang, int jumlahbarang);
void helppagepelangga(struct node data_barang,struct daftarbarang toko, int barang, int jumlahbarang);
void halamanadmin(struct node data_barang,struct daftarbarang toko, int barang, int jumlahbarang);
void helppageadmin(struct node data_barang,struct daftarbarang toko, int barang, int jumlahbarang);

int login(struct node data_barang,struct daftarbarang toko, int barang, int jumlahbarang)
{
    char uid[20], pwd[20], c=' ';
    int i=0, ch, ch1; 
    system("cls");
    printf("\n\t====================================\n") ;
    printf("\t>>>>>>>>>>>  Menu Login  <<<<<<<<<<<");
    printf("\n\t====================================\n") ;
    printf("\n\t1. login admin\n");
    printf("\n\t2. kembali ke menu utama\n");
    while(1)
    {
        printf("\n\t>>") ;
        scanf("%d", &ch);
        
    //keluar program
        if(ch==2)
        {
        	return main();
        }
            
    //login
        else if (ch==1)
        {
        printf("\n\tMasukkan Username : ");
        scanf("%s", &uid);
        printf("\n\tMasukkan Password : ");
        for(i=0; i<10; i++)
     {
             ch1=getch();
             pwd[i]=ch1;
      
             if(ch1!=13)      //13 is ASCII of Enter key
                   printf("*");
             if(ch1 == 13)
                   break;
      }
      		pwd[i]='\0';
            
    //cek username sudah benar dimasukkan
        if(strcmp(uid, "admintoko")==0)
        {   
        	if(strcmp(pwd,"rahasia")==0)
        {
            printf("\n\tlogin berhasil, selamat datang\n");
            sleep(3);
            system("cls");
            halamanadmin(data_barang, toko, barang, jumlahbarang) ;
		}
		//cek password sudah benar dimasukkan
			else {
				printf("\n\tpassword salah, tekan enter untuk kembali");
				getch();
				login(data_barang, toko, barang, jumlahbarang);
			}	
   		}
   
 //ketika user menggunakan username atau password yang salah
        else
            {
            printf("\n\tpassword salah, kembali ke menu login");
			sleep(1);
            system("cls");
            login(data_barang, toko, barang, jumlahbarang);
            }
        }
        
    //ketika user memasukkan angka diluar 1,2, dan 3
        else
        {
         printf ("\n\tMasukkan pilihan yang valid");
         printf("\n\tSilahkan Kembali Menu") ;
         sleep(1);
         system("cls");
         login(data_barang, toko, barang, jumlahbarang);     
        }
    }
}

int informasiprogram()
{
	system("cls");
	printf("\n\t============================================================================\n") ;
	printf("\t>>>>>>>>  [Informasi Program Convenience Store Management System]  <<<<<<<<\n");
	printf("\t============================================================================\n") ;
	printf("\n\tNama Program : Convenience Store Management System\n");
	printf("\n\tTujuan Program : Untuk membantu pedagang atau penjual dalam mengatur stokbarang\n") ;
	printf("\tbarang serta melakukan transaksi\n");
	printf("\n\tDeskripsi Program : ") ;
	printf("\n\tConvenience Store Management System adalah program yang menggunakan bahasa C") ;
	printf("\n\tuntuk membantu pedagang atau penjual dalam mengatur stokbarang barang serta") ;
	printf("\n\tmelakukan transaksi. Program ini dapat memasukan nama, hargabarang, serta stokbarang") ;
	printf("\n\tbarang yang akan dijual di toko. Program ini akan dilengkapi juga dengan") ;
	printf("\n\tpassword untuk dapat memulai programnya. Selain itu, pembeli dapat melihat") ;
	printf("\n\tstok barang yang tersedia dan melihat harganya untuk memesan barang ") ;
	printf("\n\ttersebut. Dengan adanya program ini, diharapkan dapat memberikan kemudahan") ;
	printf("\n\tbagi pelaku bisnis toserba dengan sebuah program manajemen yang sistematis") ;
	printf("\n\tsehingga toserba dapat bekerja dengan lebih efisien. Disini kami berencana") ;
	printf("\n\takan mengimplementasikan materi rekursi, searching, bubbleshort, array, function,") ;
	printf("\n\tserta dilengkapi dengan output program yang user friendly.\n") ;
	
	printf("\n\tPada proyek akhir semester ini, kami memodifikasi program dengan") ;
	printf("\n\tmengimplementasikan materi linked list serta binary tree dengan menambahkan");
	printf("\n\tfitur baru, yaitu “Daftar karyawan hari ini”. Fitur tersebut berfungsi untuk"); 
	printf("\n\tmencatat nama-nama karyawan yang bekerja pada hari tersebut dan juga terdapat dapat") ;
	printf("\n\tbeberapa function yang berfungsi untuk menambahkan karyawan, mencetak daftar"); 
	printf("\n\tkaryawan, mengedit daftar karyawan, sampai menghapus daftar karyawannya\n\n");
	system("pause");
	return main();
}

void halamanadmin(struct node data_barang,struct daftarbarang toko, int barang, int jumlahbarang)
{
	system("cls");
	int pilihanadmin;
	printf("\n\t====================================\n") ;
    printf("\t>>>>>>>>>>>  Menu Admin  <<<<<<<<<<<");
    printf("\n\t====================================\n\n") ;
	printf("\t1. Buka Toko\n\n");
	printf("\t2. Tutup Toko\n\n");
	printf("\t3. Help Page\n\n");
	printf("\t4. Daftar Karyawan Hari Ini\n\n");
	printf("\t5. Halaman Pelanggan\n\n");
	printf("\t>>");
	scanf("%d",&pilihanadmin);
	switch(pilihanadmin) 
	{
		case 1:
			inputbarang(data_barang, toko, barang, jumlahbarang) ;
			break;
		case 2:
			exit(0);
			break;
		case 3:
			helppageadmin(data_barang, toko, barang, jumlahbarang);
		case 4:
			menu();
		case 5:
			halamanpelanggan(data_barang, toko, barang, jumlahbarang);
		default:
			printf("\n\tAnda memasukkan pilihan yang salah!\n\n");
			system("pause");
			return halamanadmin(data_barang, toko, barang, jumlahbarang);
	}
}

void inputbarang(struct node data_barang,struct daftarbarang toko, int barang, int jumlahbarang)
{
	system("cls");
	printf("\n\t================================================\n") ;
    printf("\tSilahkan masukan daftar barang yang ingin dijual");
   	printf("\n\t================================================\n\n") ;
	printf("\tBerapa jenis barang yang ingin dijual hari ini?\n");
	printf("\t>>");
	scanf("%d",&jumlahbarang);
	for (barang = 0; barang < jumlahbarang; barang++)
   	{
   		printf("\n\tBarang ke-%d", barang+1) ;
    	printf("\n\tMasukan Nama Barang : ") ;
    	scanf("%s", inventaris[barang].namabarang) ;
    	printf("\tMasukan hargabarang Barang : Rp.") ;
    	scanf("%d", &inventaris[barang].hargabarang) ;
    	printf("\tMasukan stokbarang Barang : ") ;
    	scanf("%d", &inventaris[barang].stokbarang) ;
    }
   	system("pause");
   	bubbleshort(data_barang, toko, barang, jumlahbarang);
}

void bubbleshort(struct node data_barang,struct daftarbarang toko, int barang, int jumlahbarang)
{
	int sort, j, swapstok, swapharga;
		for (barang = 0; barang < jumlahbarang - 1; barang++)
		{
			for (j = 0; j < jumlahbarang - barang - 1; j++)
			{
				if(inventaris[j].stokbarang < inventaris[j+1].stokbarang)
				{
					swapstok = inventaris[j].stokbarang ;
		 			inventaris[j].stokbarang = inventaris[j+1].stokbarang ;
		 			inventaris[j+1].stokbarang = swapstok ;
		 			swapharga = inventaris[j].hargabarang ;
		 			inventaris[j].hargabarang = inventaris[j+1].hargabarang ;
		 			inventaris[j+1].hargabarang = swapharga ;
		 			strcpy(inventaris[j].temp, inventaris[j].namabarang) ;
		 			strcpy(inventaris[j].namabarang, inventaris[j+1].namabarang) ;
		 			strcpy(inventaris[j+1].namabarang, inventaris[j].temp) ;	
				}
			}
		}
		halamanpelanggan(data_barang, toko, barang, jumlahbarang);
}

void helppageadmin(struct node data_barang,struct daftarbarang toko, int barang, int jumlahbarang)
{
	system("cls");
	printf("\n\t====================================\n") ;
    printf("\t>>>>>>  Help Page Menu Admin  <<<<<<");
    printf("\n\t====================================\n") ;
	printf("\n\t1. Buka toko untuk membuka toko dan memasukan nama, hargabarang, dan stokbarang barang yang ingin dijual\n");
	printf("\n\t2. Tutup Toko untuk menutup toko dan menghapus data dagangan hari ini\n");
	printf("\n\t3. Help untuk membuka halaman bantuan menu admin\n\n");
	printf("\n\t4. daftar karyawan untuk pergi halaman yang berisi karyawan yang bekerje di toko ini\n\n");
	printf("\n\t5. Halaman pelanggan untuk pergi ke halaman pelanggan\n\n");
	system("pause");
	halamanadmin(data_barang, toko, barang, jumlahbarang) ;
}

void halamanpelanggan(struct node data_barang,struct daftarbarang toko, int barang, int jumlahbarang)
{
	system("cls");
	int menudisplay;
	printf("\n\t===========================================================\n") ;
	printf("\t>>>>>>>>>>>>>>>  Daftar Barang yang Dijual  <<<<<<<<<<<<<<<");
	printf("\n\t===========================================================\n") ;
	printf("\n\tNama Barang \t\tHarga Barang \t\tStok Barang ") ;
	for (barang = 0; barang < jumlahbarang; barang++)
	{
		printf("\n\t%s \t\t\tRp. %d \t\t%d buah ", inventaris[barang].namabarang, inventaris[barang].hargabarang, inventaris[barang].stokbarang) ;
	}
	printf("\n\n\t[Menu Pelanggan]\n\n");
	printf("\t1. Belanja\n\n");
	printf("\t2. Help Page\n\n");
	printf("\t3. Halaman Admin\n\n");
	printf("\t>>");
	scanf("%d",&menudisplay);
	switch(menudisplay)
	{
		case 1:
			orderbarang(data_barang, toko, barang, jumlahbarang);
			break;
		case 2:
			helppagepelangga(data_barang, toko, barang, jumlahbarang);
			break;
		case 3:
			halamanadmin(data_barang, toko, barang, jumlahbarang);
			break;
		default:
			printf("\n\tAnda memasukkan pilihan yang salah!\n\n");
			system("pause");
			return halamanpelanggan(data_barang, toko, barang, jumlahbarang);
	}
}

void orderbarang(struct node data_barang,struct daftarbarang toko, int barang, int jumlahbarang)
{
	system("cls");
	int menudisplay, uang;
	printf("\n\t===========================================================\n") ;
	printf("\t>>>>>>>>>>>>>>>  Daftar Barang yang Dijual  <<<<<<<<<<<<<<<");
	printf("\n\t===========================================================\n") ;
	printf("\n\tNama Barang \t\tHarga Barang \t\tStok Barang ") ;
	for (barang = 0; barang < jumlahbarang; barang++)
	{
		printf("\n\t%s \t\t\tRp. %d \t\t%d buah ", inventaris[barang].namabarang, inventaris[barang].hargabarang, inventaris[barang].stokbarang) ;
	}
	
	int kantongbelanja ;
	int biaya=0;
	int q ;
	printf("\n\n\t[Keranjang Belanja]\n\n") ;
	for (barang=0;barang<jumlahbarang;barang++)
	{
    	strcpy(caribarang[barang].namabarang, caribarang[barang].dummy) ;
    	caribarang[barang].stokbarang = 0 ;
	}
	
	printf("\tBerapa jenis barang yang ingin anda beli?\n");
	printf("\t>>");
	scanf("%d",&kantongbelanja);
	for (barang=0;barang<kantongbelanja;barang++)
	{
		printf("\n\tMasukan Nama Barang ke-%d : ", barang+1) ;
    	scanf("%s", caribarang[barang].namabarang) ;
   		printf("\tMasukan jumlah pembelian ke-%d : ", barang+1) ;
    	scanf("%d", &caribarang[barang].stokbarang) ;
	}
	system ("cls");
	printf("\n\t===========================================================\n") ;
    printf("\t>>>>>>>>>>>>>>>>>>>  Ringkasan Belanja  <<<<<<<<<<<<<<<<<<<");
    printf("\n\t===========================================================\n") ;
    printf("\n\tNama Barang \t\tHarga Barang \t\tStok Pembelian ") ;
     for(barang=0;barang<jumlahbarang;barang++)
    {
    	for(q = 0; q < jumlahbarang; q++)
		{
        	if(strcmp(inventaris[q].namabarang,caribarang[barang].namabarang)==0)
        	{
            	if(caribarang[barang].stokbarang <= inventaris[q].stokbarang)
				{
        				biaya+=(inventaris[q].hargabarang*caribarang[barang].stokbarang);
        				printf("\n\t%s \t\t\tRp. %d \t\t%d buah ", inventaris[q].namabarang, inventaris[q].hargabarang, caribarang[barang].stokbarang);
        				inventaris[q].stokbarang=inventaris[q].stokbarang-caribarang[barang].stokbarang;
				}
				else{
					printf("\n\t%s tidak dapat dibeli karena stokbarang yang dipesan melebihi stokbarang yang tersedia", caribarang[barang].namabarang) ;
				}
        	}
		}
    }
    
    printf("\n\t___________________________________________________________\n") ;
    pembayaran:
    printf("\n\t>>>Pembayaran<<<\n");
    printf("\n\tTotal hargabarang: Rp.%d\n",biaya);
    printf("\n\tMasukkan jumlah uang anda: Rp.");
    scanf("%d", &uang);
    if(uang>=biaya){
    	printf("\n\tsisa uang anda: Rp.%d", uang-biaya);
	}
	else {
		printf("\n\t!!!maaf uang ada tidak cukup!!!");
		printf("\n\t!!!silahkan masukan jumlah uang dengan benar!!!\n");
		system("pause");
		goto pembayaran;
	}
    printf("\n\n\t!!!Terima Kasih Telah berbelanja!!!\n");
	system ("pause");
	bubbleshort(data_barang, toko, barang, jumlahbarang);
	
}

void helppagepelangga(struct node data_barang,struct daftarbarang toko, int barang, int jumlahbarang)
{
	system("cls");
	printf("\n\t====================================\n") ;
    printf("\t>>> Help Page Menu Pelanggan <<<");
    printf("\n\t====================================\n") ;
	printf("\n\t1. Belanja untuk memilih nama dan jumlah barang yang ingin dibeli\n");
	printf("\n\t2. Help untuk membuka halaman bantuan menu pelanggan\n");
	printf("\n\t3. Halaman Admin untuk login dan mengatur nama, hargabarang, dan stokbarang barang di toko\n\n");
	system("pause");
	return halamanpelanggan(data_barang, toko, barang, jumlahbarang) ;
}
