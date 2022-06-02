struct node {
    char nama[50];
    struct node* left;
    struct node* right;
};

struct node* newNode(char nama[50])
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    strcpy(node->nama,nama);
    node->left = NULL;
    node->right = NULL;
    return (node);
}

struct node* insert(struct node* node,char nama[50])
{
    /* If the tree is empty, return a new node */
    if (node == NULL)
        return newNode(nama);
    if (strcmpi(nama, node->nama) > 0) {	
        node->left = insert(node->left,nama);
    }
    else
        node->right = insert(node->right,nama);
    return node;
}

struct node* minValueNode(struct node* node)
{
    struct node* current = node;
 
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}

struct node* deleteNode(struct node* root,char nama[50])
{
    if (root == NULL)
        return root;
    if (strcmpi(nama, root->nama) > 0)
        root->left = deleteNode(root->left,nama);
    else if (strcmpi(nama, root->nama) < 0)
        root->right = deleteNode(root->right,nama);
    else {
    	printf("%s",root->nama);
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        struct node* temp = minValueNode(root->right);
        strcpy(root->nama,temp->nama);
        root->right = deleteNode(root->right,nama);
    }
    return root;
}

struct node* updateNode(struct node* root,char nama[50],char nama_baru[50])
{
    struct node* temp = deleteNode(root,nama);
    temp = insert(temp,nama_baru);
    return temp;
}



void inorder(struct node* root)
{

    if (root != NULL) {
        inorder(root->left);
        printf("\n\t-> %s", root->nama) ;
        inorder(root->right);
    }
}

struct node* data_barang = NULL;
void menu(){
	int menuawal;
	char nama[50]="";
	char namas[50]="";
	int a = 0;
	while(a!=5){
		system("cls");
		printf("\n\t===============================================================================\n") ;
		printf("\t>>>>>>>>>>>>>>>>>  Daftar Karyawan Toko yang Bekerja Hari ini <<<<<<<<<<<<<<<<<\n") ;
		printf("\t================================================================================\n") ;
		inorder(data_barang);
		printf("\n\n\t1. Tambah karyawan\n") ;
		printf("\n\t2. Edit Karyawan \n") ;
		printf("\n\t3. Hapus Karyawan\n") ;
		printf("\n\t4. help page\n") ;
		printf("\n\t5. Halaman Pelanggan\n") ;
		printf("\n\t>>") ;
		scanf("%d", &menuawal) ;
		switch(menuawal)
		{
			case 1:
			    system("cls");
			    printf("\n\t====================================\n") ;
			    printf("\t>>>>>>>>>>>  Add Data  <<<<<<<<<<<");
			    printf("\n\t====================================\n") ;
			    printf("\n\t Masukan Nama Kategory :") ;
			    scanf("%s", nama);
			    data_barang = insert(data_barang,nama);
				break;
	
			case 2:
				system("cls");
			    printf("\n\t====================================\n") ;
			    printf("\t>>>>>>>>>>>  Edit Data  <<<<<<<<<<<");
			    printf("\n\t====================================\n") ;
			    printf("\n\t Masukan Nama Kategory yang ingin diubah:") ;
			    scanf("%s", nama);
			    printf("\n\t Masukan Nama Kategory yang Baru:") ;
			    scanf("%s", namas);
			    data_barang = updateNode(data_barang,nama,namas);
				break;
			case 3:
				system("cls");
			    printf("\n\t====================================\n") ;
			    printf("\t>>>>>>>>>>>  Delete Data  <<<<<<<<<<<");
			    printf("\n\t====================================\n") ;
			    printf("\n\t Masukan Nama Kategory yang ingin Dihapus:") ;
			    scanf("%s", nama);
			    data_barang = deleteNode(data_barang,nama);
				break;
			case 4:
			system("cls");
			printf("\n\t=================================================\n") ;
    		printf("\t>>>>>>  Help Page halaman daftar karyawan <<<<<<");
    		printf("\n\t=================================================\n") ;
			printf("\n\t1. tambah karyawan untuk menambah karyawan yg bekerja di toko ini pada hari ini\n");
			printf("\n\t2. edit karyawan untuk mengubah karyawan yg bekerja pada hari ini\n");
			printf("\n\t3. hapus karyawan untuk menghapus karyawan yg bekerja pada hari ini\n");
			printf("\n\t4. help page untuk memberikan informasi mengenai halaman\n");
			printf("\n\t5. Halaman pelanggan untuk pergi ke halaman pelanggan\n\n");
			system("pause");
			menu() ;
			case 5:
				a=5;
				break;
			default:
				printf("\n\tAnda memasukkan pilihan yang salah!\n\n");
				system("pause");
		}
	}
}

