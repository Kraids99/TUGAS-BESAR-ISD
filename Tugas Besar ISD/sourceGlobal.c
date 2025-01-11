#include "header.h"

void createEmpty(Multilist *L){
	L->firstParent = NULL;
}

bool isEmpty(Multilist L){
	return L.firstParent == NULL;
}

bool haveChild(AddressParent ap){
	return ap->firstChild != NULL;
}

void tampilMenu(int *menu){
	int i, ch;
	int pilihan = 0;
	sembunyikanKursor();
	
	while(1){
		system("cls");
	    printf("\033[1;36m"); // biru
	    printf("\t\t\t\t\t        __           ______  \n");
	    printf("\t\t\t\t\t       /%c %c         /%c  == %c \n", 92, 92, 92, 92);
	    printf("\t\t\t\t\t       %c %c %c____    %c %c  __ %c  \n", 92, 92, 92, 92, 92, 92);
	    printf("\t\t\t\t\t        %c %c_____%c    %c %c_%c %c_%c   \n", 92, 92, 92, 92, 92, 92, 92, 92);
	    printf("\t\t\t\t\t         %c/_____/     %c/_/ /_/  \n", 92, 92);
	    printf("\033[0m\n");
	    printf("\033[1;32m"); // hijau
	    printf("\t\t\t ______        ______      ______      ___  __      _______     ______ \n");
		printf("\t\t\t/%c  ___%c      /%c  == %c    /%c  == %c    /%c  %c %c %c    /%c   _  %c   /%c  ___%c\n", 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92,92);
		printf("\t\t\t%c %c %c   ___   %c %c  __<    %c %c  __ %c   %c %c %c%c %c %c   %c %c  %c_%c %c  %c %c  __%c\n", 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92);
		printf("\t\t\t %c %c %c___%c %c   %c %c_%c %c_%c   %c %c_%c %c_%c   %c %c %c%c %c %c   %c %c_____/   %c %c_____%c\n", 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92);
		printf("\t\t\t  %c/_______/    %c/_/ /_/    %c/_/ /_/    %c/_/ %c/_/    %c/____/     %c/_____/\n", 92, 92, 92, 92, 92, 92, 92, 92);
    	printf("\033[0m\n");
		printf("\n\n");
		
		printf("\t\t\t\t\t\e[0;32m%c", 218);
		for(i = 0; i < 39; i++){
			printf("%c", 196);
		}
		printf("%c\e[0;32m", 191);
		
		printf("\n\t\t\t\t\t%c %s %s[1] Buat Nota Baru               %s  %c", 179, (pilihan == 0 ? ">>" : "  "), (pilihan == 0 ? "\e[30;42m" : ""), (pilihan == 0 ? "\e[0;32m" : ""), 179);
        printf("\n\t\t\t\t\t%c %s %s[2] Tambah Pesanan               %s  %c", 179, (pilihan == 1 ? ">>" : "  "), (pilihan == 1 ? "\e[30;42m" : ""), (pilihan == 1 ? "\e[0;32m" : ""), 179);
        printf("\n\t\t\t\t\t%c %s %s[3] Pembayaran                   %s  %c", 179, (pilihan == 2 ? ">>" : "  "), (pilihan == 2 ? "\e[30;42m" : ""), (pilihan == 2 ? "\e[0;32m" : ""), 179);
        printf("\n\t\t\t\t\t%c %s %s[4] Tampilkan Semua Transaksi    %s  %c", 179, (pilihan == 3 ? ">>" : "  "), (pilihan == 3 ? "\e[30;42m" : ""), (pilihan == 3 ? "\e[0;32m" : ""), 179);
        printf("\n\t\t\t\t\t%c %s %s[5] Laporan Transaksi            %s  %c", 179, (pilihan == 4 ? ">>" : "  "), (pilihan == 4 ? "\e[30;42m" : ""), (pilihan == 4 ? "\e[0;32m" : ""), 179);
        printf("\n\t\t\t\t\t%c %s %s[6] Hapus Save File              %s  %c", 179, (pilihan == 5 ? ">>" : "  "), (pilihan == 5 ? "\e[30;42m" : ""), (pilihan == 5 ? "\e[0;32m" : ""), 179);
        printf("\n\t\t\t\t\t%c %s %s[0] Keluar                       %s  %c\n", 179, (pilihan == 6 ? ">>" : "  "), (pilihan == 6 ? "\e[30;42m" : ""), (pilihan == 6 ? "\e[0;32m" : ""), 179);
        
        printf("\t\t\t\t\t%c", 192);
        for(i = 0; i < 39; i++){
        	printf("%c", 196);
		}
		printf("%c\e[0m", 217);
		
		ch = getch();
		if(ch == 72){
			pilihan = (pilihan - 1 + 7) % 7;
		} else if(ch == 80){
			pilihan = (pilihan + 1) % 7;
		} else if(ch == 13){
			(*menu) = pilihan;
			break;
		}
	}
}

void subMenu(int *menu){
	int i, ch;
	int pilihan = 0;
	sembunyikanKursor();
	
	while(1){
		system("cls");
		
		printf("\n\t\t\t\t\t   ");
		printf("\e[0m");
		for(i = 0; i < 8; i++){
			printf("\e[0;34m%c", 205);
		}
		printf("\e[0;34m[ Menu Pembayaran ]");
		for(i = 0; i < 8; i++){
			printf("\e[0;34m%c", 205);
		}
		printf("\n\n");
		
		printf("\t\t\t\t\t%c", 218);
		for (i = 0; i < 39; i++) {
			printf("\e[0;34m%c", 196); 
		}
		printf("%c\e[0;34m", 191);
		
		printf("\n\t\t\t\t\t%c %s %s[1] Gabungkan Nota               %s  %c", 179, (pilihan == 0 ? ">>" : "  "), (pilihan == 0 ? "\e[30;44m" : ""), (pilihan == 0 ? "\e[0;34m" : ""), 179);
		printf("\n\t\t\t\t\t%c %s %s[2] Pisahkan Nota                %s  %c", 179, (pilihan == 1 ? ">>" : "  "), (pilihan == 1 ? "\e[30;44m" : ""), (pilihan == 1 ? "\e[0;34m" : ""), 179);
		printf("\n\t\t\t\t\t%c %s %s[3] Bayar Nota                   %s  %c", 179, (pilihan == 2 ? ">>" : "  "), (pilihan == 2 ? "\e[30;44m" : ""), (pilihan == 2 ? "\e[0;34m" : ""), 179);
		printf("\n\t\t\t\t\t%c %s %s[0] Keluar                       %s  %c\n", 179, (pilihan == 3 ? ">>" : "  "), (pilihan == 3 ? "\e[30;44m" : ""), (pilihan == 3 ? "\e[0;34m" : ""), 179);
		
		printf("\t\t\t\t\t%c", 192);
		for (i = 0; i < 39; i++) {
			printf("%c", 196); 
		}
		printf("%c\e[0m", 217);
		
		ch = getch();
		if(ch == 72){
			pilihan = (pilihan - 1 + 4) % 4;
		} else if(ch == 80){
			pilihan = (pilihan + 1) % 4;
		} else if(ch == 13){
			(*menu) = pilihan;
			break;
		}
	}
}

void saveToFile(Multilist list, string filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("\n\n\t\t\t\t\t   \e[0;31m[!] File Gagal Disimpan [!]\e[0m\n");
        return;
    }

    AddressParent parent = list.firstParent;
    while (parent != NULL) {
        // Simpan data Parent
        fprintf(file, "%d|%s|%d|%.2f|%d\n", 
                parent->dataParent.nomorNota, 
                parent->dataParent.tanggal, 
                parent->dataParent.nomorMeja, 
                parent->dataParent.totalBelanja,
                parent->dataParent.status);

        // Simpan data Child
        AddressChild child = parent->firstChild;
        while (child != NULL) {
            fprintf(file, "  %s|%d|%.2f\n", 
                    child->dataChild.nama, 
                    child->dataChild.jumlah, 
                    child->dataChild.harga);
            child = child->next;
        }
        parent = parent->next;
    }

    fclose(file);
    printf("\n\n\t\t\t\t\e[0;32m[*] Data berhasil disimpan ke file %s [*]\e[0m\n", filename);
}

void freeMultilist(Multilist *list) {
    AddressParent parent = list->firstParent;
    while (parent != NULL) {
        AddressChild child = parent->firstChild;
        while (child != NULL) {
            AddressChild tempChild = child;
            child = child->next;
            free(tempChild);
        }
        AddressParent tempParent = parent;
        parent = parent->next;
        free(tempParent);
    }
    list->firstParent = NULL;
}

void loadFromFile(Multilist* list, string filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\e[0;31m[!] File tidak ditemukan [!]\e[0m\n");
        return;
    }

    char line[1000];
    AddressParent currentParent = NULL;

    while (fgets(line, sizeof(line), file)) {
        // Abaikan baris kosong
        if (strlen(line) == 0) continue;

        if (line[0] != ' ') {
            // Baris Parent
            DataParent dataParent;
            int parsed = sscanf(line, "%d|%[^|]|%d|%f|%d", 
                                &dataParent.nomorNota, 
                                dataParent.tanggal, 
                                &dataParent.nomorMeja, 
                                &dataParent.totalBelanja,
                                (int*)&dataParent.status); // Cast karena bool
            if (parsed < 5) {
                printf("Kesalahan saat membaca data Parent.\n");
                continue;
            }
            insertLastParent(list, dataParent);
            currentParent = list->firstParent;
            while (currentParent->next != NULL) {
                currentParent = currentParent->next; // Pastikan currentParent adalah Parent terbaru
            }
        } else if (currentParent != NULL) {
            // Baris Child
            DataChild dataChild;
            int parsed = sscanf(line, "  %[^|]|%d|%f", 
                                dataChild.nama, 
                                &dataChild.jumlah, 
                                &dataChild.harga);
            if (parsed < 3) {
                printf("Kesalahan saat membaca data Child.\n");
                continue;
            }
            insertLastChild(currentParent, dataChild);
        }
    }

    // Rekalkulasi total belanja setiap Parent
    AddressParent parent = list->firstParent;
    while (parent != NULL) {
        float totalBelanja = 0.0;
        AddressChild child = parent->firstChild;
        while (child != NULL) {
            totalBelanja += child->dataChild.jumlah * child->dataChild.harga;
            child = child->next;
        }
        parent->dataParent.totalBelanja = totalBelanja; // Update total belanja
        parent = parent->next;
    }

    fclose(file);
    printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\e[0;32m[*] Data berhasil dimuat dari file [*]\e[0m\n");
}

void deleteFile(Multilist *l, string filename) {
	char confirm;
	printf("\t\t\t\t\tHapus Data File (y/n): "); fflush(stdin); scanf("%c", &confirm);
	if (confirm == 'y' || confirm == 'Y') {
		if (remove(filename) == 0) {
	        printf("\n\t\t\t\t   \e[0;32m[*] File '%s' berhasil dihapus [*]\e[0m\n", filename);
	        freeMultilist(&(*l));
	    } else {
	        printf("\n\t\t\t\t   \e[0;31m[!] File '%s' tidak ditemukan [!]\e[0m\n", filename);
	    }
	} else {
		
		printf("\n\t\t\t\t\t\t\e[0;33m[-] Batal Menghapus Data [-]\e[0m");
	}
}

void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void sembunyikanKursor() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = FALSE; // Menyembunyikan kursor
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}

void tampilkanKursor() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = TRUE; // Tampilkan kursor
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}

void animateText(string text, int delay) {
	int i;
    for (i = 0; i < strlen(text); i++) {
        printf("%c", text[i]);
        fflush(stdout); 
        Sleep(delay); 
    }
    printf("\n");
}

void loadingAnimasi() {
    int totalSteps = 50; 
    int i, j, k;

    printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tLoading...\n");
    printf("\t\t\t\t[");

    // Prepare the space for the progress bar
    for (i = 0; i < totalSteps; i++) {
        printf(" ");
    }
    printf("]");

    printf("\r\t\t\t\t[");

    // Loop through each step of the loading animation
    for (i = 0; i <= totalSteps; i++) {
        fflush(stdout);
        Sleep(40); // Speed of the animation

        // Color logic for gradient effect
        if (i < totalSteps / 3) {
            setColor(12); // Red
        } else if (i < 2 * totalSteps / 3) {
            setColor(14); // Yellow
        } else {
            setColor(10); // Green
        }

        // Draw the progress bar
        for (j = 0; j <= i; j++) {
            printf("%c", 178);
        }

        // Add trailing effects (sparkles)
        for (k = 0; k < 3; k++) {
            if (i + k < totalSteps) {
                printf("*");
            }
        }

        // Reset the trailing space
        for (j = i + 3; j < totalSteps; j++) {
            printf(" ");
        }

        // Show percentage completed
        setColor(15);
        printf("] %3d%%", (i * 100) / totalSteps);

        // Reset position for next iteration
        printf("\r\t\t\t\t[");
    }

    setColor(15);
    printf("\n\t\t\t\t");
	animateText("Selesai! Memuat Konten...", 80);
    setColor(15); 
}

void printDataKosong() {
    int i;
    printf("\n");
    printf("\t\t\t\t\t\e[1;31m%c", 218); // Sudut kiri atas (ASCII 218)
    for (i = 0; i < 39; i++) printf("%c", 196); // Garis horizontal (ASCII 196)
    printf("%c\n", 191); // Sudut kanan atas (ASCII 191)

    printf("\t\t\t\t\t%c", 179); // Garis vertikal kiri dan mulai warna merah
    printf("[!]        DATA MASIH KOSONG        [!]"); // Pesan utama
    printf("%c\n", 179); // Garis vertikal kanan (ASCII 179)

    printf("\t\t\t\t\t%c", 192); // Sudut kiri bawah (ASCII 192)
    for (i = 0; i < 39; i++) printf("%c", 196); // Garis horizontal (ASCII 196)
    printf("%c\e[0m\n", 217); // Sudut kanan bawah (ASCII 217)
}

void printFlag(){
	sembunyikanKursor();
	int margin = 30;  
	int tinggi = 10, lebar = 30, lama = 35;
    int i, j, s;
    char temp[100] = "";
    char angin[4][20] = {
        "   ~~~     ~~~   ",
        "      ~~~     ~~~",
        " ~~~     ~~~     ",
        "     ~~~     ~~~ ",
    };
	for(s=0; s<lama ; s++){
		system("cls");
	    printf("\n\n\n\n\n\n");
	    for(i = 0; i < tinggi; i++)
		{
	        printf("\t\t\t\t");
	        printf("   %s", angin[(i+s) % 4]);
	        for(j = 0; j < lebar; j++)
			{
				if(i < tinggi / 2) printf("\033[38;5;88m%c\033[0m", 178);  // merah
                else printf("\033[38;5;250m%c\033[0m", 178);  // putih
	        }
	        printf("\n");
	    }
	
	    temp[s] = 178;
        printf("\n\n");
        printf("\t\t\t\t\t");
    	setColor(15); 
		printf("Mengunggah Data Nota... %d%%\033[0m\n", (s + 1)*100/ lama);
		printf("\n");
        printf("\t\t\t\t\t[",186); 
		setColor(10); 
        printf("%-35s\033[0m]", temp, 186);
        Sleep(200); 
	}
	setColor(15); 
    printf("\n\n\t\t\t\t\t   [!] Data Berhasil Diunggah [!]\n");
    printf("\n\n\t\t\t\t\t  \033[5mEnter 2 Kali Untuk Menyelesaikan\033[0m");
    getch();
}

void loadingAnimationPesanan() {
    int totalSteps = 50; 
    int i, j, k;

    printf("\n\t\t\t\tLoading...\n");
    printf("\t\t[");

    // Prepare the space for the progress bar
    for (i = 0; i < totalSteps; i++) {
        printf(" ");
    }
    printf("]");

    printf("\r\t\t[");

    // Loop through each step of the loading animation
    for (i = 0; i <= totalSteps; i++) {
        fflush(stdout);
        Sleep(40); // Speed of the animation

        // Color logic for gradient effect
        if (i < totalSteps / 3) {
            setColor(12); // Red
        } else if (i < 2 * totalSteps / 3) {
            setColor(14); // Yellow
        } else {
            setColor(10); // Green
        }

        // Draw the progress bar
        for (j = 0; j <= i; j++) {
            printf("%c", 178);
        }

        // Add trailing effects (sparkles)
        for (k = 0; k < 3; k++) {
            if (i + k < totalSteps) {
                printf("*");
            }
        }

        // Reset the trailing space
        for (j = i + 3; j < totalSteps; j++) {
            printf(" ");
        }

        // Show percentage completed
        setColor(15);
        printf("] %3d%%", (i * 100) / totalSteps);

        // Reset position for next iteration
        printf("\r\t\t[");
    }

    setColor(15);
    printf("\n\t\t\t\tCompleted!\n");
}

void temporary(Multilist *l){
	AddressParent nota1;
	AddressParent nota2;
	
	insertFirstParent(&(*l), makeDataParent(1, 27, "21-Nov-2021"));
	nota1 = findParent((*l), 1);
	insertFirstChild(nota1, makeDataChild("Burger", 10, 25000));
	insertFirstParent(&(*l), makeDataParent(2, 27, "21-Nov-2021"));
	nota1 = findParent((*l), 2);
	insertFirstChild(nota1, makeDataChild("Pizza", 2, 30000));
	insertFirstParent(&(*l), makeDataParent(3, 20, "21-Nov-2021"));
	nota1 = findParent((*l), 3);
	insertFirstChild(nota1, makeDataChild("Burger", 1, 25000));
	insertFirstChild(nota1, makeDataChild("Cola", 2, 15000));
	insertFirstChild(nota1, makeDataChild("Es krim", 2, 15000));
	insertFirstParent(&(*l), makeDataParent(4, 29, "21-Nov-2021"));
	nota2 = findParent((*l), 4);
	insertFirstChild(nota2, makeDataChild("Burger Large", 1, 40000));
	insertFirstChild(nota2, makeDataChild("Cola", 1, 40000));
}
