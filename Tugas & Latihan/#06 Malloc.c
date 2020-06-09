#include<stdio.h>
#include<stdlib.h>

struct mahasiswa{
	char nama[10];
	int npm;
	int umur;
}mhs[10];

main(){
	int jumlahdata, n=8, i;
	
	/*int data[8] = {12, 33, 60, 13, 29, 47, 22, 21};
	
    jumlahdata = sizeof(data)/sizeof(data[0]); //sizeof(data) : menghitung byte total dimana int : 4 byte jadi 8x4 = 32, sizeof(data[0] : dimana 1 data memili 4 byte 
	printf("\n\nJumlah data : %d", jumlahdata);*/
	
	/*ptr=(int *)malloc(n*sizeof(int));	//Malloc : mengalokasikan memori secara dinamis
	
	for(i=0;i<n;i++){
		printf("Masukkan data : ");
		scanf("%d", ptr+i);
	}
	
	for(i=0;i<n;i++){
		printf(" %d ", *(ptr+i));
	}
	
	free(ptr);*/
	
	struct mahasiswa mhs1 = {"Dwi Wahyu", 17, 20};
	struct mahasiswa *ptr;
	ptr=&mhs1;
	
	printf("Nama : %s\nNPM : %d\nUmur : %d\n", (*ptr).nama, (*ptr).npm, (*ptr).umur);
	printf("Nama : %s\nNPM : %d\nUmur : %d\n", ptr->nama, ptr->npm, ptr->umur);


}
