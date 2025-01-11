#include "header.h"

int main(int argc, char *argv[]) {
	Multilist l;
	int menu;
	createEmpty(&l);
	sembunyikanKursor();
//	loadingAnimasi();Sleep(1000);system("cls");
//	loadFromFile(&l, "multilist_data.txt");Sleep(2000);
//	temporary(&l);

	do{
		system("cls");
		system("color 07");
		tampilMenu(&menu);
		switch(menu){
			case 0:
				tampilkanKursor();
				system("color E0");
				inputan(&l);
			break;
			
			case 1:
				if(isEmpty(l)){
					printDataKosong();
				}else{
					tampilkanKursor();
					menuTambahPesanan(&l);
				}
			break;
			
			case 2:
				if(isEmpty(l)){
					printDataKosong();
				}else{
					menuPembayaran(&l);
				}
			break;
			
			case 3:
				if(isEmpty(l)){
					printDataKosong();
				}else{
					system("cls");
					system("color E0");
					printf("\n\t\t\t\t\t\t==== [ Tampil Transaksi ] ====\n\n\n");
					printAll(l);
				}
			break;
			
			case 4:
				if(isEmpty(l)){
					printDataKosong();
				}else{
					system("cls");
					system("color E0");
					printf("\n\t\t\t\t\t\t==== [ Tampil Laporan ] ====\n\n\n");
					tampilkanLaporan(l);
				}
			break;
			
			case 5:
				tampilkanKursor();
				printf("\n\n\t\t\t\t\t\t  ==== [ Hapus Data ] ====\n\n\n");
				deleteFile(&l, "multilist_data.txt");
			break;
			
			case 6:
				saveToFile(l, "multilist_data.txt");
			break;
		}
		getch();
	}while(menu != 6);
	
	return 0;
}
