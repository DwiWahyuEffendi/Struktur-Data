#include <stdio.h>
#include <string.h>
#include<stdlib.h>

struct Mahasiswa
{
	struct Mahasiswa *next;
	char npm[50];
	char nama[50];
};

typedef struct Mahasiswa Mhs;

Mhs* tambahdata(Mhs *);
void lihatdata(Mhs *);

main(void)
{
int pil;
Mhs *mhs;
mhs = NULL;

	system("cls");
	printf("\n\t===========================================\n");
	printf("\t                STRUKTUR DATA A              \n");
	printf("\t                   LINKLIST                  \n");
	printf("\t===========================================\n");
	printf("\t         Nama : Dwi Wahyu Effendi\n");
	printf("\t         NPM  : 18081010017\n");
	printf("\t===========================================\n\n");
	printf("\tTekan terserah untuk memulai program!!!");
	getch();

	do
	{
	menu:
	system("cls");
	printf("\n\t==============================================\n");
	printf("\t1. Tambahkan Data\n");
	printf("\t2. Lihat Data\n");
	printf("\t3. Keluar\n\n");
	printf("\tMasukkan Pilihan Anda : ");
	scanf("%d", &pil);
	
	switch(pil)
	{
		case 1 :
			mhs = tambahdata(mhs);
			break;
			goto menu;
		case 2 :
			lihatdata(mhs);
			break;
			goto menu;
		case 3 :
			system("cls");
			printf("\n\tTerimakasih Telah Menggunakan Program ini");
			getch();
			break;
			goto akhir;
	}	
}

while(pil != 4);
return 0;

akhir:
	exit(0);
}

Mhs*tambahdata(Mhs *mhs)
{
	Mhs *mhsw;

	system("cls");

	mhsw = malloc(sizeof(Mhs));
	mhsw->next = NULL;

	fflush(stdin);
	printf("\n\t=========================================================");
	printf("\n\tMasukkan NPM   : ");
	gets(mhsw->npm);

	printf("\tMasukkan Nama  : ");
	gets(mhsw->nama);

	if(mhs == NULL)
	{
		mhs = mhsw;
	}
	else
	{
		mhsw->next = mhs;
	}

printf("\n");
system("pause");

return mhsw;
}

void lihatdata(Mhs *mhs)
{
system("cls");

printf("\n\tNpm\t\t Nama\t\t\t\t\n");

	while(mhs != NULL)
	{
		printf("\t%s\t %s\t %s\n", mhs->npm, mhs->nama);
		mhs = mhs->next;
	}

printf("\n");
system("pause");
system("cls");
}
