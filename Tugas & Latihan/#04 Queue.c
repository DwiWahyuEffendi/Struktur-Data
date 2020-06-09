/*Queue = Antrian
Ciri Queue = FIFO (First In First Out)
Queue bisa di buat dalam 2 bentuk yaitu Array & Linklist

Queue terdapat 2 fungsi utama yaitu:
-Enqueue (untuk insert elemen data)
-Dequeue (untuk delete elemen data)

Queue menggunakan 2 variabel utama yaitu:
-rear/belakang (untuk insert data)
-front/depan (untuk delete data)

Queue Array
#define max 5
ex:Queue[max]
if(rear=max-1) atau max=4 makan queue overflow
if(front=-1 || front=rear+1) maka queue underflow

Rear untuk insert data rear=rear+1;
Front untuk delete data front=front+1
*/

#include<stdio.h>
#include<stdlib.h>
#define max 3
int front=-1;
int rear=-1;
int queue[max];
void enqueue();
int dequeue();
void display();

/*void enqueue(int elemen){
	if(rear==max-1){
		system("cls");
		printf("\n\tQUEUE OVERFLOW\n\t");
		system("pause");
		return;
	}
	
	if(front==-1){
		front=0;	//Hanya untuk kondisis awal
	}
	
	rear=rear+1;
	queue[rear]=elemen;
	return;
}

int dequeue(){
	int elemen;
	
	if(front==-1||front==rear+1){
		system("cls");		
		printf("\n\tQUEUE UNDERFLOW\n\t");
		system("pause");
		return;
	}
	
	front=front+1;
	elemen=queue[front];
	system("cls");
	printf("\n\tELEMEN DATA TELAH DI HAPUS\n\t");
	system("pause");
	return elemen;
}

void display(){
	int i;
	if(front==-1||front==rear+1){
		system("cls");		
		printf("\n\tQUEUE UNDERFLOW\n\t");
		system("pause");
		return;
	}
	system("cls");printf("\n\tFront |");
	for(i=front;i<=rear;i++){
		printf(" %d |", queue[i]);
	}
	printf(" Rear");
	printf("\n\t");
	system("pause");
}

main(){
	int pilihan, data;
	
	while(1){
		system("cls");
		printf("\n\t========== QUEUE ARRAY ==========");
		printf("\n\t           1. ENQUEUE");
		printf("\n\t           2. DEQUEUE");
		printf("\n\t           3. DISPLAY");
		printf("\n\t           4. Exit");
		printf("\n\t==================================");
		printf("\n\tMASUKKAN PILIHAN ANDA : ");
		scanf("%d", &pilihan);
		
		switch(pilihan){
			case 1:
				system("cls");
				printf("\n\tMASUKKAN DATA YANG INGIN DI TAMBAHKAN : ");
				scanf("%d", &data);
				enqueue(data);
				break;
			case 2:
				dequeue();
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
}*/

//Circular Queue
void enqueue(int elemen){
	if(front==0 && rear==max-1 || front==rear+1){	//2 Kondisi (kondisi 1 overflow sebelum di pop, kondisi 2 untuk overflow setelah di pop / mengisi elemen yang di pop)
		system("cls");
		printf("\n\tQUEUE OVERFLOW\n\t");
		system("pause");
		return;
	}
	
	if(front==-1){
		front=0;	//Hanya untuk kondisis awal
	}
	
	if(rear==max-1){
		rear=0;
	}
	else{
		rear=rear+1;
	}
	queue[rear]=elemen;
	return;
}

int dequeue(){
	int elemen;
	
	if(front==-1){
		system("cls");
		printf("\n\tQUEUE UNDERFLOW");
		system("pause");
		return;
	}
	elemen = queue[front];
	
	if(front==rear){	//berarti data hanya terdiri dari 1
		front=-1;
		rear=-1;
	}
	else if(front==max-1){
		front=0;
	}
	else{
		front=front+1;
	}
	
	system("cls");
	printf("\n\tELEMEN DATA TELAH DI HAPUS\n\t");
	system("pause");
	return elemen;
}

void display(){
	if(front==-1){
		system("cls");
		printf("\n\tQUEUE UNDERFLOW");
		system("pause");
		return;
	}
	
	int i=front;
	system("cls");printf("\n\tFront |");
	
	if(front<=rear){
		while(i<=rear){
		printf(" %d |", queue[i++]);			
		}
	}
	else{
		while(i<=max-1){
		printf(" %d |", queue[i++]);			
		}
		i=0;
		while(i<=rear){
		printf(" %d |", queue[i++]);	
		}
	}
	
	printf(" Rear");
	printf("\n\t");
	system("pause");
}

main(){
	int pilihan, data;
	
	while(1){
		system("cls");
		printf("\n\t========== QUEUE ARRAY ==========");
		printf("\n\t           1. ENQUEUE");
		printf("\n\t           2. DEQUEUE");
		printf("\n\t           3. DISPLAY");
		printf("\n\t           4. Exit");
		printf("\n\t==================================");
		printf("\n\tMASUKKAN PILIHAN ANDA : ");
		scanf("%d", &pilihan);
		
		switch(pilihan){
			case 1:
				system("cls");
				printf("\n\tMASUKKAN DATA YANG INGIN DI TAMBAHKAN : ");
				scanf("%d", &data);
				enqueue(data);
				break;
			case 2:
				dequeue();
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
