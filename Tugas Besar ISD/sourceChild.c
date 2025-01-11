#include "header.h"

DataChild makeDataChild(string nama, int jumlah, float harga){
	DataChild data;
	
	strcpy(data.nama, nama);
	data.jumlah = jumlah;
	data.harga = harga;
	
	return data;
}

AddressChild alokasiChild(DataChild data){
	AddressChild ac;
	
	ac = (AddressChild) malloc(sizeof(NodeChild));
	
	ac->next = NULL;
	ac->dataChild = data;
	
	return ac;
}

AddressChild findChild(AddressParent parent, string nama) {
    AddressChild tempChild = parent->firstChild;
    while (tempChild != NULL) {
        if (strcmp(tempChild->dataChild.nama, nama) == 0) {
            return tempChild; 
        }
        tempChild = tempChild->next;
    }

    return NULL; 
}

void insertFirstChild(AddressParent parent, DataChild data) {
    if (parent != NULL) {
        AddressChild newChild = alokasiChild(data);
        newChild->next = parent->firstChild;

        parent->firstChild = newChild;

        parent->dataParent.totalBelanja += newChild->dataChild.jumlah * newChild->dataChild.harga;
    }
}

void insertAtChild(AddressParent parent, DataChild data) {
    AddressChild newChild = alokasiChild(data);

    if (parent->firstChild == NULL) {
        insertFirstChild(parent, data);
    } else {
        AddressChild temp = parent->firstChild;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newChild;
    }

    parent->dataParent.totalBelanja += newChild->dataChild.jumlah * newChild->dataChild.harga;
}

void insertLastChild(AddressParent parent, DataChild data) {
    if (parent != NULL) {
        AddressChild newChild = alokasiChild(data);
        if (!haveChild(parent)) {
            parent->firstChild = newChild;
        } else {
            AddressChild temp = parent->firstChild;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newChild;
        }
        
        parent->dataParent.totalBelanja += newChild->dataChild.jumlah * newChild->dataChild.harga;
    }
}

void displayPesanan(string nama, int jumlah, float harga) {
	int i;
	
    // Top border
    printf("\n\n\t\t\t\t\t%c", 201);
    for (i = 0; i < 46; i++) {
        printf("%c", 205);
    }
    printf("%c\n", 187);

    // Title
    printf("\t\t\t\t\t%c [+]%-38s[+] %c\n", 186, " Masukkan Pesanan Anda", 186);

    // Middle border
    printf("\t\t\t\t\t%c", 204);
    for (i = 0; i < 46; i++) {
        printf("%c", 205);
    }
    printf("%c\n", 185);
    
    printf("\t\t\t\t\t%c", 186);
    for (i = 0; i < 46; i++) {
        printf(" ");
    }
    printf("%c\n", 186);

    // Nama Pesanan
    printf("\t\t\t\t\t%c Nama Pesanan   : ", 186);
    if (strcmp(nama, "") == 0 || strcmp(nama, "-") == 0) {
        printf("%-27s %c\n", "[Belum Diisi]", 186);
    } else {
        printf("%-27s %c\n", nama, 186);
    }

    // Jumlah Pesanan
    printf("\t\t\t\t\t%c Jumlah Pesanan : ", 186);
    if (jumlah < 1) {
        printf("%-27s %c\n", "[Belum Diisi]", 186);
    } else {
        printf("%-27d %c\n", jumlah, 186);
    }

    // Harga Pesanan
    printf("\t\t\t\t\t%c Harga Pesanan  : ", 186);
    if (harga < 1) {
        printf("%-27s %c\n", "[Belum Diisi]", 186);
    } else {
        printf("Rp. %-23.2f %c\n", harga, 186);
    }
    
    printf("\t\t\t\t\t%c", 186);
    for (i = 0; i < 46; i++) {
        printf(" ");
    }
    printf("%c\n", 186);

    // Bottom border
    printf("\t\t\t\t\t%c", 200);
    for (i = 0; i < 46; i++) {
        printf("%c", 205);
    }
    printf("%c\n", 188);
}

void menuTambahPesanan(Multilist *L) {
	string nama="";
	int jumlah=0, nomorNota=0;
	float harga=0.0;
	char confirm;
	AddressParent parent;

	system("cls");	
	printf("\n\n\t\t\t\t\t\t=== Cari Nota ===");		
	printf("\n\t\t\t\t\tMasukkan Nomor Nota: "); scanf("%d", &nomorNota);
		
	if (findParent(*L, nomorNota) == NULL) {
		printf("\n\n\t\t\t\t\t[!] Nota Tidak Ditemukan [!]");
		getch();
		return;
	}
	parent = findParent(*L, nomorNota);
	if (parent->dataParent.status) {
		printf("\n\n\t\t\t\t\t[!]Nota dengan nomor %d sudah lunas\n", parent->dataParent.nomorNota);
		getch();
		return;
	}
	printParent(parent); getch();
	
	do {
		system("cls");
		displayPesanan(nama, jumlah, harga);
		printf("\n\t\t\t\t\t\tMasukkan Nama: "); fflush(stdin); gets(nama);
		
		if (strcmp(nama, "") == 0 || strcmp(nama, "-") == 0) {
	        printf("\n\t\t\t\t\t\t[!] Nama Pesanan Tidak Boleh Kosong [!]");
	        getch();
	    }
		
	} while(strcmp(nama, "") == 0);
	
	do {
		system("cls");
		displayPesanan(nama, jumlah, harga);
		printf("\n\t\t\t\t\t\tMasukkan Jumlah Pesanan: "); scanf("%d", &jumlah);
		
		if (jumlah < 1) {
	        printf("\n\t\t\t\t\t\t[!] Jumlah Pesanan Tidak Boleh Kurang Dari 1 [!]");
	        getch();
	    }
		
	} while(jumlah < 1);
	
	do {
		system("cls");
		displayPesanan(nama, jumlah, harga);
		printf("\n\t\t\t\t\t\tMasukkan Harga Pesanan: Rp. "); scanf("%f", &harga);
		
		if (harga < 1) {
	        printf("\n\t\t\t\t\t\t[!] Harga Pesanan Tidak Boleh Kurang Dari 1 [!]");
	        getch();
	    }
		
	} while(harga < 1);
	
	system("cls");
	
	displayPesanan(nama, jumlah, harga);
	
	printf("\n\t\t\t\t\t\tSimpan Pesanan (y/n): "); confirm = getche();
	
	if (confirm == 'y' || confirm == 'Y') {
		insertFirstChild(findParent(*L, nomorNota), makeDataChild(nama, jumlah, harga));
		
		loadingAnimationPesanan();
		
		printf("\n\n\t\t\t\t\t\t[+] Berhasil Memasukkan Pesanan [+]");
		
		getch();
	} else {
		printf("\n\n\t\t\t\t\t\t[-] Batal Memasukkan Pesanan [-]");
		getch();
	}
}
