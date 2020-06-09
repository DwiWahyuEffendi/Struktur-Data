#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>



//STRUCT DEFINITION
//-- your code here

//FUNCTION DEFINITION
//-- your code here

//========================================================

int main()
{
  
  char pilih;

  do{
    system("cls");
     
     printf("------ MENU DAFTAR HADIR MAHASISWA ---------\n");
     printf("1. TAMBAH DATA\n");
     printf("2. UPDATE DATA\n");
     printf("3. DELETE DATA\n");
     printf("4. SHOW DAFTAR HADIR\n");
     printf("MASUKKAN PILIHAN (tekan q untuk keluar) : ");
     fflush(stdin);
     scanf("%c", &pilih);
     if (pilih == '1'){
     		// call your function
	 }
     else if (pilih == '2'){
     		// call your function	
	 }
     else if (pilih == '3'){
     		// call your function	
	 }
     else if (pilih == '4'){
     		// call your function
     }
     
  } while (pilih != 'q');
}



//YOUR FUNCTIONS
// code here...

