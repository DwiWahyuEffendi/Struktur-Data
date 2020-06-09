#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct mahasiswa {
	char nama[30];
	char npm[30];
	struct mahasiswa *next, *prev;
} *head, *tail, *current;

void push(char name[],char nim[]){
	current = (struct mahasiswa *)malloc(sizeof (struct mahasiswa));
	strcpy(current -> nama, name);
	strcpy(current -> npm, nim);
	current -> next = current -> prev = NULL;
	
	if(head==NULL){
		head=tail=current;
	}
	else{
		head -> prev = current;
		current -> next = head;
		head = current;
	}
}

void pop(){
	if(head==NULL){
		printf("\n\tMasukkan data terlebih dahulu!!!");
	}
	else if(head==tail){
		current=head;
		head=tail=NULL;
		free(current);
	}
	else{
		current=head;
		head=head->next;
		head->prev=NULL;
		free(current);
	}
}

void displaystack(){
	if(head!=NULL){
		current=head;
		while(current!=NULL){
			printf("\n\t| %s \t %s |", current->nama, current->npm);
			current=current->next;
		}
	}else{
		printf("\n\t| Tidak ada data |");
	}
	printf("\n\n");
};

void enqueue(char name[], char nim[]){
	current = (struct mahasiswa *)malloc(sizeof (struct mahasiswa));
	strcpy(current -> nama, name);
	strcpy(current -> npm, nim);
	current->next = current->prev = NULL;

	if(head==NULL){
		head=tail=current;
	}else{
		head->prev=current;
		current->next=head;
		head=current;
	}
}

void dequeue(){
	if(tail==NULL){
		printf("\n\tMasukkan data terlebih dahulu!!!");
	}else if(tail==head){
		current=tail;
		head=tail=NULL;
		free(current);
	}else{
		current=tail;
		tail=tail->prev;
		tail->next=NULL;
		free(current);
	}
}

void displayqueue(){
	if(head!=NULL){
		current=head;
		printf("\n\n\t");
		while(current!=NULL){
			printf(" | %s  %s | ", current->nama,current->npm);
			current=current->next;		
		}
	}else{
		printf("\n\t| Tidak ada data |");
	}
	printf("\n\n");
};

int main() {
	int metode, menu;
	char nama[30],npm[30];

	printf("\n\t============================================\n");
	printf("\t               STRUKTUR DATA A\n");
	printf("\t             TUGAS 2 STACK QUEUE\n");
	printf("\t==============================================\n");
	printf("\t           Nama : Dwi Wahyu Effendi\n");
	printf("\t           NPM  : 18081010017\n");
	printf("\t==============================================\n");
	printf("\t     Tekan terserah untuk memulai program!!!");
	getch();
	
	do{
		system("cls");
		printf("\n\t============================================");
		printf("\n\t              Pilih Opsi Metode");    
		printf("\n\t============================================");   
		printf("\n\t                 1. Stack");
		printf("\n\t                 2. Queue");
		printf("\n\t                 3. Exit");
		printf("\n\t============================================");
		printf("\n\t          Masukkan Pilihan Anda : ");
		scanf("%d",&metode);
		
		if(metode==1){
			do{
				system("cls");
				printf("\n\t========= Pilih Menu =======");
				printf("\n\t          1. Push");
				printf("\n\t          2. Pop");
				printf("\n\t          3. Back");
				printf("\n\t============================");
				printf("\n\t       Masukkan Pilihan : ");
				scanf("%d",&menu);
				
				if(menu==1){
					system("cls");
					printf("\n\t======================================");
					printf("\n\tNama Mahasiswa		: ");
					fflush(stdin);gets(nama);
					printf("\tNPM Mahasiswa		: ");
					fflush(stdin);scanf("%s",npm);
					
					push(nama,npm);
					displaystack();
					getch();system("cls");
				}
				else if(menu==2){
					pop();
					displaystack();
					getch();system("cls");
				}
				else{
					printf("\n\tPilihan Tidak Ada, Ulangi!!!\n\n");
					getch();
				}
			}while(menu!=3);
		}
		else if(metode==2){
			do{
				system("cls");
				printf("\n\t========= Pilih Menu =======");
				printf("\n\t          1. Enqueue");
				printf("\n\t          2. Dequeue");
				printf("\n\t          3. Back");
				printf("\n\t============================");
				printf("\n\t       Masukkan Pilihan : ");
				scanf("%d",&menu);
				
				if(menu==1){
					printf("\n\t======================================");
					printf("\n\tNama Mahasiswa		: ");
					fflush(stdin);gets(nama);
					printf("\tNPM Mahasiswa		: ");
					fflush(stdin);scanf("%s",npm);
					
					enqueue(nama,npm);
					displayqueue();
					getch();system("cls");
				}
				else if(menu==2){
					dequeue();
					displayqueue();
					getch();system("cls");
				}
				else{
					printf("\n\tPilihan Tidak Ada, Ulangi!!!\n\n");
					getch();
				}

			}while(menu!=3);
		}
		else if(metode==3){
			printf("\n\n\t === Terimakasih anda telah menggunakan program ini === \n\n");
		}
		else{
			printf("\n\tPilihan Tidak Ada, Ulangi!!!\n\n");
			getch();
		}
	}
	while(metode!=3);
	return 0;
}
