#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>

typedef char string[100];

typedef struct Child* AddressChild;
typedef struct Parent* AddressParent;

typedef struct DataChild{
	string nama;
	int jumlah;
	float harga;
}DataChild;

typedef struct DataParent{
	int nomorNota;
	string tanggal;
	bool status;
	int nomorMeja;
	float totalBelanja;
}DataParent;

typedef struct Child{
	DataChild dataChild;
	AddressChild next;
}NodeChild;

typedef struct Parent{
	DataParent dataParent;
	AddressParent next;
	
	AddressChild firstChild;
}NodeParent;

typedef struct{
	AddressParent firstParent;
}Multilist;

//Record Pembantu utk tampilkanLaporan
typedef struct{
	string nama;
	int jumlah;
} ItemCounter;

//Global
void createEmpty(Multilist *L);
bool isEmpty(Multilist L);
bool haveChild(AddressParent ap);

void tampilMenu(int *menu);
void subMenu(int *menu);

void saveToFile(Multilist list, string filename);
void freeMultilist(Multilist *list);
void loadFromFile(Multilist *list, string filename);
void deleteFile(Multilist *l, string filename);

void sembunyikanKursor();
void tampilkanKursor();
void setColor(int color);
void animateText(string text, int delay);
void loadingAnimasi();

void printDataKosong();
void printFlag();
void loadingAnimationPesanan();
void temporary(Multilist *l);
//----------------------------------------------------------------------------------

//Parent
DataParent makeDataParent(int nomorNota, int nomorMeja, string tanggal);
AddressParent alokasiParent(DataParent data);
AddressParent findParent(Multilist L, int nomorNota);

void printParent(AddressParent parent);
void printAllParent(Multilist L);
void printAll(Multilist L);

void insertFirstParent(Multilist *L, DataParent data);
void insertLastParent(Multilist *L, DataParent data);

void deleteFirstParent(Multilist *L);
void deleteAtParent(Multilist *L, int noNota);
void deleteAllChild(AddressParent parent);

void printParent(AddressParent parent);
void printAll(Multilist L);

void gabungNota(Multilist *L, AddressParent parent1, AddressParent parent2);
void bayarNota(Multilist *list, AddressParent parent);
void pisahkanNota(Multilist *L, AddressParent parent, AddressChild child);

void tampilkanLaporan(Multilist list);
void menuPembayaran(Multilist *L);

void createEmptyData(string nama, int *no_nota, string str_tanggal, int *no_meja, int *jumlah, float *harga);
					
void inputted(int unik, string nama, int no_nota, string str_tanggal, int no_meja, int jumlah, float harga);

void inputan(Multilist *L);
//----------------------------------------------------------------------------------

//Child
DataChild makeDataChild(string nama, int jumlah, float harga);
AddressChild alokasiChild(DataChild data);
AddressChild findChild(AddressParent parent, string nama);

void insertFirstChild(AddressParent parent, DataChild data);
void insertAtChild(AddressParent parent, DataChild data);
void insertLastChild(AddressParent parent, DataChild data);

void displayPesanan(string nama, int jumlah, float harga);
void menuTambahPesanan(Multilist *L);
//----------------------------------------------------------------------------------
