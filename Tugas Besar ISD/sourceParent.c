#include "header.h"

DataParent makeDataParent(int nomorNota, int nomorMeja, string tanggal){
	DataParent data;
	
	strcpy(data.tanggal, tanggal);
	data.nomorNota = nomorNota;
	data.nomorMeja = nomorMeja;
	data.totalBelanja = 0.0;
	data.status = false;
	
	return data;
}

AddressParent alokasiParent(DataParent data){
	AddressParent ap;
	
	ap = (AddressParent) malloc(sizeof(NodeParent));
	
	ap->next = NULL;
	ap->firstChild = NULL;
	ap->dataParent = data;
	
	return ap;
}

AddressParent findParent(Multilist L, int nomorNota){
	AddressParent temp = NULL;
	
	temp = L.firstParent;
	
	while(temp != NULL){
		while(temp != NULL){
			if(temp->dataParent.nomorNota == nomorNota){
				return temp;
			}
			temp = temp->next;
		}
		return NULL;
	}
}

void insertFirstParent(Multilist *L, DataParent data){
	AddressParent temp = alokasiParent(data);
	
	temp->next = L->firstParent;
	L->firstParent = temp;
}

void insertLastParent(Multilist *L, DataParent data){
	AddressParent dataBaru = alokasiParent(data);
	
	if(isEmpty(*L)){
		insertFirstParent(L, data);
	}else{
		AddressParent temp = L->firstParent;
		
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = dataBaru;
	}
}

void deleteFirstParent(Multilist *L) {
    AddressParent temp = L->firstParent;

    if (!isEmpty(*L)) {
        deleteAllChild(temp); 
        L->firstParent = L->firstParent->next;
        free(temp); 
    }
}

void deleteAtParent(Multilist *L, int noNota) {
    AddressParent temp = L->firstParent;
    AddressParent prev = NULL;

    if (!isEmpty(*L)) {
        if (temp->dataParent.nomorNota == noNota) {
            deleteFirstParent(L);
        } else {
            while (temp != NULL && temp->dataParent.nomorNota != noNota) {
                prev = temp; 
                temp = temp->next;
            }
            
            prev->next = temp->next; 
            deleteAllChild(temp); 
            free(temp); 
        }
    }
}

void deleteAllChild(AddressParent parent){
	AddressChild temp;
	
	while(haveChild(parent)){
		temp = parent->firstChild;
		parent->firstChild = parent->firstChild->next;
		
		free(temp);
	}
}

//perbaikan tambah 10
void printParent(AddressParent parent) {
    int i;

    // Header
    printf("\t\t\t\t%c", 201); // Sudut kiri atas
    for (i = 0; i < 60; i++) printf("%c", 205); // Garis horizontal
    printf("%c\n", 187); // Sudut kanan atas

    printf("\t\t\t\t%c                  STRUK RESTORAN LA GRANDE                  %c\n", 186, 186);

    printf("\t\t\t\t%c", 204); // Sudut kiri bawah (persimpangan)
    for (i = 0; i < 60; i++) printf("%c", 205);
    printf("%c\n", 185); // Persimpangan kanan

    // Detail Nota
    printf("\t\t\t\t%c Nomor Nota        : %-39d%c\n", 186, parent->dataParent.nomorNota, 186);
    printf("\t\t\t\t%c Tanggal Transaksi : %-39s%c\n", 186, parent->dataParent.tanggal, 186);
    printf("\t\t\t\t%c Nomor Meja        : %-39d%c\n", 186, parent->dataParent.nomorMeja, 186);
    printf("\t\t\t\t%c Status Pembayaran : %-39s%c\n", 186, parent->dataParent.status ? "Lunas" : "Belum Lunas", 186);

    printf("\t\t\t\t%c", 204); // Persimpangan
    for (i = 0; i < 60; i++) printf("%c", 205); // Garis horizontal
    printf("%c\n", 185); // Persimpangan kanan

    // Daftar Belanjaan
    printf("\t\t\t\t%c Daftar Belanja Anda:                                       %c\n", 186, 186);
    AddressChild child = parent->firstChild;
    int no = 1;

    while (child != NULL) {
        // Format dengan penyesuaian panjang
        printf("\t\t\t\t%c %d. %-16s (x%-2d @ Rp.%11.2f) : Rp.%11.2f%c\n",
               186,
               no++,
               child->dataChild.nama,
               child->dataChild.jumlah,
               child->dataChild.harga,
               child->dataChild.jumlah * child->dataChild.harga,
               186);
        child = child->next;
    }
    if(parent->firstChild == NULL){
    	printf("\t\t\t\t%c [Kosong]                                                   %c\n", 186, 186);
	}

    printf("\t\t\t\t%c", 204); // Sudut kiri bawah
    for (i = 0; i < 60; i++) printf("%c", 205); // Garis horizontal
    printf("%c\n", 185); // Sudut kanan bawah

    // Total Harga dan Footer
    printf("\t\t\t\t%c Total Harga       : Rp. %-34.2f %c\n", 186, parent->dataParent.totalBelanja, 186);

    if (parent->dataParent.status == true) {
        printf("\t\t\t\t%c", 204); // Sudut kiri bawah
    } else {
        printf("\t\t\t\t%c", 200);
    }
    for (i = 0; i < 60; i++) printf("%c", 205); // Garis horizontal
    if (parent->dataParent.status == true) {
        printf("%c\n", 185); // Sudut kanan bawah
    } else {
        printf("%c\n\n", 188);
    }

    if (parent->dataParent.status == true) {
        printf("\t\t\t\t%c          Terima Kasih Telah Berkunjung di Restoran         %c\n", 186, 186);
        printf("\t\t\t\t%c                     *** LA GRANDE ***                      %c\n", 186, 186);

        printf("\t\t\t\t%c", 200); // Sudut kiri bawah
        for (i = 0; i < 60; i++) printf("%c", 205); // Garis horizontal
        printf("%c\n\n", 188); // Sudut kanan bawah
    }
}

void printAll(Multilist L) {
    AddressParent temp = L.firstParent;

    while (temp != NULL) {
        printParent(temp);
		

        temp = temp->next;
    }
}

void gabungNota(Multilist *L, AddressParent parent1, AddressParent parent2) {
    if (parent1->dataParent.status || parent2->dataParent.status) {
        printf("\n\t\t\t\t   [!] Gagal! Salah satu atau kedua nota sudah lunas dan tidak dapat digabungkan\n");
        return;
    }
    
    if(parent1 == parent2){
		printf("\n\t\t\t\t\t      [!] Nota 1 dan Nota 2 Sama [!]");
		return;
	}

    // Pastikan parent1 adalah nota dengan nomor terkecil
    if (parent1->dataParent.nomorNota > parent2->dataParent.nomorNota) {
        AddressParent temp = parent1;
        parent1 = parent2;
        parent2 = temp;
    }

    // Pindahkan semua child dari parent2 ke parent1
    AddressChild tempChild = parent2->firstChild;
    while (tempChild != NULL) {
        // Cari child dengan nama yang sama di parent1
        AddressChild existingChild = findChild(parent1, tempChild->dataChild.nama);

        if (existingChild != NULL) {
            // Jika ditemukan, tambahkan jumlahnya
            existingChild->dataChild.jumlah += tempChild->dataChild.jumlah;
        } else {
            // Jika tidak ditemukan, tambahkan sebagai child baru
            insertAtChild(parent1, tempChild->dataChild);
        }

        tempChild = tempChild->next;
    }

    // Perbarui total belanja parent1
    AddressChild child = parent1->firstChild;
    float totalBelanja = 0;
    while (child != NULL) {
        totalBelanja += child->dataChild.jumlah * child->dataChild.harga;
        child = child->next;
    }
    parent1->dataParent.totalBelanja = totalBelanja;

    printf("\n\t\t\t\t\t   Nota #%d berhasil digabungkan ke Nota #%d\n", parent2->dataParent.nomorNota, parent1->dataParent.nomorNota);

    // Hapus parent2 dari list menggunakan deleteAtParent
    deleteAtParent(L, parent2->dataParent.nomorNota);
}

// Perbaikan tambah 10
void bayarNota(Multilist* list, AddressParent parent) {
    if (parent->dataParent.status) {
        printf("\n\t\t\t\t\t\t[!] Nota dengan nomor %d sudah lunas\n", parent->dataParent.nomorNota);
        return;
    }

    int i;
    float pembayaran, kekurangan;
    char konfirmasi;
    
    printParent(parent);
    // Konfirmasi pembayaran
    printf("\n\n\t\t\t\t\tApakah Anda ingin melanjutkan pembayaran? (y/n): ");
    konfirmasi = getche();

    if (konfirmasi == 'y' || konfirmasi == 'Y') {
        while (1) {
            printf("\n\n\t\t\t\t\tMasukkan jumlah pembayaran: Rp. ");scanf("%f", &pembayaran);

            if (pembayaran < parent->dataParent.totalBelanja) {
                kekurangan = parent->dataParent.totalBelanja - pembayaran;
                printf("\t\t\t\t\e[1;31m%c", 201); // Sudut kiri bawah
				for (i = 0; i < 60; i++) printf("%c", 205);
				printf("%c\n", 187); // Sudut kanan bawah
				printf("\t\t\t\t%c Pembayaran kurang Rp. %-36.2f %c\n", 186, kekurangan, 186);
				printf("\t\t\t\t%c", 200); // Sudut kiri bawah
				for (i = 0; i < 60; i++) printf("%c", 205);
				printf("%c\e[0m\n", 188); // Sudut kanan bawah
				pembayaran = 0;
            } else {
                parent->dataParent.status = true; // Tandai sebagai lunas
                float kembalian = pembayaran - parent->dataParent.totalBelanja;
                
                printf("\t\t\t\t\e[0;32m%c", 201); // Sudut kiri bawah
				for (i = 0; i < 60; i++) printf("%c", 205);
				printf("%c\n", 187); // Sudut kanan bawah
				printf("\t\t\t\t%c Pembayaran berhasil! Kembalian Anda: Rp. %-17.2f %c\n", 186, kembalian, 186);
				
				printf("\t\t\t\t%c", 204); // Sudut kiri bawah
				for (i = 0; i < 60; i++) printf("%c", 205);
				printf("%c\n", 185); // Sudut kanan bawah
		        printf("\t\t\t\t%c          Terima Kasih Telah Berkunjung di Restoran         %c\n", 186, 186);
		        printf("\t\t\t\t%c                     *** LA GRANDE ***                      %c\n", 186, 186);
		
		        printf("\t\t\t\t%c", 200); // Sudut kiri bawah
		        for (i = 0; i < 60; i++) printf("%c", 205); // Garis horizontal
		        printf("%c\e[0m\n\n", 188); // Sudut kanan bawah
                break;
            }
        }
    } else {
        printf("\n\n\t\t\t\t\t\t    Pembayaran dibatalkan.\n");
    }
}

void pisahkanNota(Multilist *L, AddressParent parent, AddressChild child) {
	int noNota;
	while(1){
		printf("\n\t\t\t\t\tMasukkan Nomor Nota Baru: ");scanf("%d", &noNota);
		if(findParent(*L, noNota) == NULL){
			break;
		}else{
			printf("\n\t\t\t\t\t[!] Nomor Nota %d Sudah Ada [!]\n", noNota);
		}
	}
	
	insertFirstParent(&(*L), makeDataParent(noNota, parent->dataParent.nomorMeja,parent->dataParent.tanggal));

    AddressParent newParent = (*L).firstParent;

    AddressChild prevChild = NULL;
    AddressChild currentChild = parent->firstChild;

    while (currentChild != NULL && currentChild != child) {
        prevChild = currentChild;
        currentChild = currentChild->next;
    }

    if (currentChild == child) {
        if (prevChild == NULL) {
            parent->firstChild = child->next;
        } else {
            prevChild->next = child->next;
        }
        child->next = NULL; 
        newParent->firstChild = child;

        float totalBelanjaBaru = child->dataChild.jumlah * child->dataChild.harga;
        parent->dataParent.totalBelanja -= totalBelanjaBaru;
        newParent->dataParent.totalBelanja = totalBelanjaBaru;

        printf("\n\t\t\t\tPesanan '%s' berhasil dipisahkan menjadi nota baru dengan nomor %d.\n",
               child->dataChild.nama, newParent->dataParent.nomorNota);
    }
}

void menuPembayaran(Multilist *L) {
	int nomorNota1, nomorNota2;
    int pilihan;
    int nomorNota;
    string namaPesanan;
    AddressChild child;
    AddressParent nota1, nota2, parent;
    
    do {
    	system("cls");
        subMenu(&pilihan);
        switch(pilihan) {
        	case 0:
        		tampilkanKursor();
				printf("\n\t\t\t\t\t\t==== [ Gabung Nota ] ====\n");
						
				printf("\n\t\t\t\t\tMasukkan Nomor Nota 1 : ");scanf("%d", &nomorNota);
				nota1 = findParent((*L), nomorNota);
						
				printf("\n\t\t\t\t\tMasukkan Nomor Nota 2 : ");scanf("%d", &nomorNota);
				AddressParent nota2 = findParent((*L), nomorNota);
				if(nota1 == NULL || nota2 == NULL){
					if(nota1 == NULL){
						printf("\n\t\t\t\t\t\t[!] Nota 1 Tidak Ditemukan [!]");
					}else{
						printf("\n\t\t\t\t\t\t[!] Nota 2 Tidak Ditemukan [!]");
					}
				}else{
					gabungNota(&(*L), nota1, nota2);
				}
			break;
			
			case 1:
				tampilkanKursor();
				printf("\n\t\t\t\t\t\t==== [ Pisah Nota ] ====\n");
				
				printf("\n\t\t\t\t\tMasukkan nomor nota: ");scanf("%d", &nomorNota);
	            if(findParent(*L, nomorNota) == NULL){
	            	printf("\n\t\t\t\t\t\t[!] Nomor Nota Tidak Tersedia [!]");
	            	break;
				}
				
				parent = findParent(*L, nomorNota);
				if (parent->dataParent.status) {
			        printf("\n\t\t\t\t\t\t[!]Nota dengan nomor %d sudah lunas\n", parent->dataParent.nomorNota);
			        break;
			    }
				
	            printf("\n\t\t\t\t\tMasukkan nama pesanan yang ingin dipisahkan: ");fflush(stdin);gets(namaPesanan);
	            if(findChild(parent, namaPesanan) == NULL){
	            	printf("\n\t\t\t\t\t\t[!] Nama Menu Tidak Tersedia [!]");
	            	break;
				}
				
				child = findChild(parent, namaPesanan);
	            pisahkanNota(&(*L), parent, child);
			break;
			
			case 2:
				tampilkanKursor();
				printf("\n\t\t\t\t\t\t==== [ Bayar Nota ] ====\n");
	            printf("\n\t\t\t\t\tMasukkan nomor nota yang ingin dibayar: ");scanf("%d", &nomorNota);
	            if(findParent(*L, nomorNota) == NULL){
	            	printf("\n\t\t\t\t\t   [!] Nomor Nota Tidak Tersedia [!]");
	            	break;
				}
			
	            parent = findParent(*L, nomorNota);
	            bayarNota(&(*L), parent);
			break;
			
			case 3:
				printf("\n\n\t\t\t\t\t     \033[32m[*] Kembali Ke-Menu Utama [*]\033[0m");
			break;
        }
        getch();
    } while(pilihan != 3);
}

void tampilkanLaporan(Multilist list) {
    float totalOmzet = 0;
    string makananTerbanyak = "";
    string minumanTerbanyak = "";
    int jumlahMakananTerbanyak = 0;
    int jumlahMinumanTerbanyak = 0;
    int i;

    ItemCounter makanan[100];
    ItemCounter minuman[100];
    int jumlahMakanan = 0;
    int jumlahMinuman = 0;

    AddressParent parent = list.firstParent;

    while (parent != NULL) {
        AddressChild child = parent->firstChild;

        while (child != NULL) {
            totalOmzet += child->dataChild.jumlah * child->dataChild.harga;

            // Klasifikasikan sebagai makanan atau minuman
            if (strstr(child->dataChild.nama, "Nasi") || strstr(child->dataChild.nama, "Mie") || strstr(child->dataChild.nama, "Pizza") || strstr(child->dataChild.nama, "Burger")) {
                // Makanan
                bool ditemukan = false;
                for (i = 0; i < jumlahMakanan; i++) {
                    if (strcmp(makanan[i].nama, child->dataChild.nama) == 0) {
                        makanan[i].jumlah += child->dataChild.jumlah;
                        ditemukan = true;
                        break;
                    }
                }
                if (!ditemukan) {
                    strcpy(makanan[jumlahMakanan].nama, child->dataChild.nama);
                    makanan[jumlahMakanan].jumlah = child->dataChild.jumlah;
                    jumlahMakanan++;
                }
            } else if (strstr(child->dataChild.nama, "Es") || strstr(child->dataChild.nama, "Teh") || strstr(child->dataChild.nama, "Cola")) {
                // Minuman
                bool ditemukan = false;
                for (i = 0; i < jumlahMinuman; i++) {
                    if (strcmp(minuman[i].nama, child->dataChild.nama) == 0) {
                        minuman[i].jumlah += child->dataChild.jumlah;
                        ditemukan = true;
                        break;
                    }
                }
                if (!ditemukan) {
                    strcpy(minuman[jumlahMinuman].nama, child->dataChild.nama);
                    minuman[jumlahMinuman].jumlah = child->dataChild.jumlah;
                    jumlahMinuman++;
                }
            }

            child = child->next;
        }

        parent = parent->next;
    }

    // Temukan makanan dan minuman terbanyak
    for (i = 0; i < jumlahMakanan; i++) {
        if (makanan[i].jumlah > jumlahMakananTerbanyak) {
            jumlahMakananTerbanyak = makanan[i].jumlah;
            strcpy(makananTerbanyak, makanan[i].nama);
        }
    }
    for (i = 0; i < jumlahMinuman; i++) {
        if (minuman[i].jumlah > jumlahMinumanTerbanyak) {
            jumlahMinumanTerbanyak = minuman[i].jumlah;
            strcpy(minumanTerbanyak, minuman[i].nama);
        }
    }

    // Tampilan laporan
    int j;
    printf("\n");
    printf("\t\t\t\t%c", 201); // Sudut kiri atas
    for (j = 0; j < 60; j++) printf("%c", 205); // Garis horizontal
    printf("%c\n", 187); // Sudut kanan atas

    printf("\t\t\t\t%c                 LAPORAN PENJUALAN RESTORAN                 %c\n", 186, 186);
    printf("\t\t\t\t%c                      *** LA GRANDE ***                     %c\n", 186, 186);

    printf("\t\t\t\t%c", 204); // Sudut kiri bawah (persimpangan)
    for (j = 0; j < 60; j++) printf("%c", 205);
    printf("%c\n", 185); // Persimpangan kanan

    printf("\t\t\t\t%c Total Omzet/Pendapatan : Rp. %-29.2f %c\n", 186, totalOmzet, 186);
    printf("\t\t\t\t%c Makanan Terbanyak      : %-27s (%3dx)%c\n", 186, makananTerbanyak, jumlahMakananTerbanyak, 186);
    printf("\t\t\t\t%c Minuman Terbanyak      : %-27s (%3dx)%c\n", 186, minumanTerbanyak, jumlahMinumanTerbanyak, 186);

    printf("\t\t\t\t%c", 204); // Sudut kiri bawah
	for (i = 0; i < 60; i++) printf("%c", 205);
	printf("%c\n", 185); // Sudut kanan bawah
	printf("\t\t\t\t%c          LAPORAN INI DIBUAT OTOMATIS OLEH PROGRAM          %c\n", 186, 186);
	printf("\t\t\t\t%c              MENGGUNAKAN BAHASA PEMROGRAMAN C              %c\n", 186, 186);
		
	printf("\t\t\t\t%c", 200); // Sudut kiri bawah
	for (i = 0; i < 60; i++) printf("%c", 205); // Garis horizontal
	printf("%c\n\n", 188); // Sudut kanan bawah
}

void createEmptyData(string nama, int *no_nota, string str_tanggal, int *no_meja, int *jumlah, float *harga){
	strcpy(nama, "-");
	strcpy(str_tanggal, "-");
	*no_meja = 0;
	*no_nota = 0;
	*jumlah = 0;
	*harga = 0;
}

void inputted(int unik, string nama, int no_nota, string str_tanggal, int no_meja, int jumlah, float harga) {
    int lebar = 50;
    int i;
    system("cls");
    
    // Top border
    printf("\n\n\n\n");
    printf("\t\t\t%c", 201);
    for (i = 0; i < lebar; i++) printf("%c", 205);
    printf("%c\n", 187);
    
    // Title
    printf("\t\t\t%c\t\t==== [ Data Nota ] ====\t\t   %c\n", 186, 186);
    printf("\t\t\t%c\t\t\t\t\t\t   %c\n", 186, 186);
    
    // Nomor Nota
    printf("\t\t\t%c\tNomor Nota         : ", 186);
    if (no_nota > 0 && unik == 0) 
        printf("%-22d", no_nota);
    else 
        printf("%-22s", "[Belum Diisi]");
    printf("%c\n", 186);
    
    // Tanggal Hari
    printf("\t\t\t%c\tTanggal Hari       : ", 186);
    if (strcmpi(str_tanggal, "-") != 0) 
        printf("%-22s", str_tanggal);
    else 
        printf("%-22s", "[Belum Diisi]");
    printf("%c\n", 186);
    
    // Nomor Meja
    printf("\t\t\t%c\tNomor Meja         : ", 186);
    if (no_meja > 0 && no_meja < 21) 
        printf("%-22d", no_meja);
    else 
        printf("%-22s", "[Belum Diisi]");
    printf("%c\n", 186);
    
    // Middle border
    printf("\t\t\t%c", 204);
    for (i = 0; i < lebar; i++) printf("%c", 205);
    printf("%c\n", 185);
    
    // Nama Pesanan
    printf("\t\t\t%c\tNama Pesanan       : ", 186);
    if (strcmpi(nama, "-") != 0) 
        printf("%-22s", nama);
    else 
        printf("%-22s", "[Belum Diisi]");
    printf("%c\n", 186);
    
    // Jumlah Pesanan
    printf("\t\t\t%c\tJumlah Pesanan     : ", 186);
    if (jumlah > 0) 
        printf("%-22d", jumlah);
    else 
        printf("%-22s", "[Belum Diisi]");
    printf("%c\n", 186);
    
    // Harga Pesanan
    printf("\t\t\t%c\tHarga Pesanan      : ", 186);
    if (harga > 0) 
        printf("%-19.2f   ", harga);
    else 
        printf("%-22s", "[Belum Diisi]");
    printf("%c\n", 186);
    
    // Bottom border
    printf("\t\t\t%c\t\t\t\t\t\t   %c\n", 186, 186);
    printf("\t\t\t%c", 200);
    for (i = 0; i < lebar; i++) printf("%c", 205);
    printf("%c\n", 188);
}


void inputan(Multilist *L){
	string nama, status, str_tanggal, nama_pembeli;
	int D, M, Y, no_nota, no_meja, jumlah, unik=1;
	AddressParent parent;
	float harga;
	createEmptyData(nama, &no_nota, str_tanggal, &no_meja, &jumlah, &harga);
	
	while(1)
	{
		inputted(unik, nama, no_nota, str_tanggal, no_meja, jumlah, harga);
		printf("\n\t\t\tMasukkan Nomor Nota: ");
		printf("\n\t\t\t%c>>> ",192);scanf("%d", &no_nota);
		
		if(no_nota < 1)
		{
			printf("\n\t\t\t[!] No nota tidak boleh kurang dari 1 [!]"); getch();
		}else if(findParent(*L, no_nota) != NULL){
			printf("\n\t\t\t[!] No nota harus unik [!]"); getch();
		}else{
			unik = 0;
			break;
		}
	}
	
	while(1)
	{
		inputted(unik, nama, no_nota, str_tanggal, no_meja, jumlah, harga);
		printf("\n\t\t\tMasukkan Tanggal Hari ini [D-M-Y]: ");
		printf("\n\t\t\t%c>>> ",192);scanf("%d-%d-%d", &D, &M, &Y);
		if(D < 1 || D > 31)
		{
			printf("\n\t\t\t[!] Tanggal tidak boleh kurang dari 1 atau lebih dari 31 [!]"); getch();
		}
		else if(M < 1 || M > 12) 
		{
			printf("\n\t\t\t[!] Bulan tidak boleh kurang dari 1 atau lebih dari 12 [!]"); getch();
		}
		else if(Y < 1)
		{
			printf("\n\t\t\t[!] Tahun tidak boleh kurang dari 1 [!]"); getch();
		} 
		else if((M == 2 && ((Y % 4 == 0 && Y % 100 != 0) || (Y % 400 == 0))) && D > 29)
		{
			printf("\n\t\t\t[!] Bulan 2 pada tahun %d hanya memiliki 29 hari [!]", Y); getch();
		} 	
		else if(M == 2 && D > 28)
		{
			printf("\n\t\t\t[!] Bulan 2 hanya memiliki 28 hari, karena bukan tahun kabisat [!]"); getch();
		}
		else if((M%2==0 && M<8) && D > 30)
		{
			printf("\n\t\t\t[!] Bulan %d hanya memiliki 30 hari [!]", M); getch();
		}
		else if((M>=8 && M<=12 && M%2!=0) && D > 30)
		{
			printf("\n\t\t\t[!] Bulan %d hanya memiliki 30 hari [!]", M); getch();
		}
		else
		{
			sprintf(str_tanggal, "%02d-%02d-%04d", D, M, Y);
			break;	
		}
	}
	
	while(1)
	{
		inputted(unik, nama, no_nota, str_tanggal, no_meja, jumlah, harga);
		printf("\n\t\t\tMasukkan Nomor Meja: ");
		printf("\n\t\t\t%c>>> ",192);scanf("%d", &no_meja);
		if(no_meja < 1 || no_meja > 20)
		{
			printf("\n\t\t\t[!] No meja tidak boleh kurang dari 1 dan tidak boleh lebih dari 20 [!]"); getch();
		} 
		else break;
	}
	
	insertFirstParent(&(*L), makeDataParent(no_nota, no_meja, str_tanggal));
	parent = findParent(*L, no_nota);
	while(1){
		inputted(unik, nama, no_nota, str_tanggal, no_meja, jumlah, harga);
		printf("\n\t\t\tMasukkan Nama Pesanan: ");
		printf("\n\t\t\t%c>>> ",192);fflush(stdin);gets(nama);
		if(strlen(nama)==0 || strcmpi(nama,"-")==0)
		{
			printf("\n\t\t\t[!] Nama Pesanan tidak boleh kosong atau - [!]"); getch();
		} 
		else break;
	}
	while(1)
	{
		inputted(unik, nama, no_nota, str_tanggal, no_meja, jumlah, harga);
		printf("\n\t\t\tMasukkan Jumlah Pesanan: ");
		printf("\n\t\t\t%c>>> ",192);scanf("%d", &jumlah);
		if(jumlah < 1)
		{
	        printf("\n\t\t\t[!] Jumlah Pesanan Tidak Boleh Kurang Dari 1 [!]"); getch();
	    }
		else break;
	}
	while(1)
	{
		inputted(unik, nama, no_nota, str_tanggal, no_meja, jumlah, harga);
		printf("\n\t\t\tMasukkan Harga Pesanan: Rp. ");
		printf("\n\t\t\t%c>>> ",192);scanf("%f", &harga);
		if(harga < 1)
		{
	        printf("\n\t\t\t[!] Harga Pesanan Tidak Boleh Kurang Dari 1 [!]"); getch();
	    } 
		else break;
	}
	inputted(unik, nama, no_nota, str_tanggal, no_meja, jumlah, harga);
	insertFirstChild(parent, makeDataChild(nama, jumlah, harga));
	printf("\n\n\t\t\t\t\t   \033[5mLoading");
    printf(".");sleep(2);printf(".");sleep(2);printf(".");sleep(2);printf("\033[0m\n");
	printFlag();
}
