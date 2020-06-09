/*Stack = Tumpukan
Ciri Stack = LIFO (Last In First Out)
Stack bisa di buat dalam 2 bentuk (Array & LinkList)

Stack terdapat 2 fungsi utama yaitu:
-Push (untuk insert elemen data)
-pop (untuk delete elemen data)

Stack Array
#define max 5
ex : Stack[max] atau top 4 (karena array di mulai dari 0, jadi 0 1 2 3 4)
if(top = -1) maka underflow (kondisi stack kosong, karena jika ada data kondisi top harus bernilai / berindex 0
if(top = max-1) makaoverflow (kondisi stack penuh, karena max-1 == top 4(index))
else(maka stack bisa di tambahkan data / di hapus data)
*/

//STACK ARRAY

#include<stdio.h>
#include<stdlib.h>
#define max 5
int stack[max]; //variabel array global
int top = -1; //kondisi kosong
void push(int); //fungsi insert data
int pop(); //fungsi delete data
void display(); //fungsi menampilkan data

void push(int elemen){
	if(top==max-1){
		system("cls");
		printf("\n\tSTACK OVERFLOW\n\t");
		system("pause");
		return;
	}
	top = top+1; //Menambahkan elemen data dari bawah
	stack[top] = elemen;
}

int pop(){
	int elemen;
	if(top == -1){
		system("cls");		
		printf("\n\tSTACK UNDERFLOW\n\t");
		system("pause");
		return;
	}
	elemen = stack[top]; //Menghapus elemen data dari atas
	top = top - 1;
	system("cls");
	printf("\n\tELEMEN DATA TELAH DI HAPUS\n\t");
	system("pause");
	return elemen;
}

void display(){
	int i;
	if(top == -1){
		system("cls");
		printf("\n\tSTACK UNDERFLOW\n\t");
		system("pause");
		return;
	}
	system("cls");
	printf("\n\t TOP\n\t------");
	for(i=top;i>=0;i--){
		printf("\n\t| %d |", stack[i]);
	}
	printf("\n\t-----_");
	printf("\n\t");
	system("pause");
}

main(){
	int pilihan, data;
	
	while(1){
		system("cls");
		printf("\n\t========== STACK ARRAY ==========");
		printf("\n\t            1. PUSH");
		printf("\n\t            2. POP");
		printf("\n\t            3. DISPLAY");
		printf("\n\t            4. Exit");
		printf("\n\t==================================");
		printf("\n\tMASUKKAN PILIHAN ANDA : ");
		scanf("%d", &pilihan);
		switch(pilihan){
			case 1:
				system("cls");
				printf("\n\tMASUKKAN DATA YANG INGIN DI TAMBAHKAN : ");
				scanf("%d", &data);
				push(data);
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(1);
				break;
			default:
				printf("\n\tMAAF, ANDA SALAH MENGINPUTKAN ULANGI!!!\n\t");
				system("pause");
		}
	}
}
