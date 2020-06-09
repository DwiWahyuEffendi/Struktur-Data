#include <stdio.h> 
#include <stdlib.h> 
#include<string.h>
#include <stdbool.h>
#include <limits.h>
#define INFINITY 9999
#define V 10
#include<conio.h> 

struct Barang{
	int kodebarang;	
	char namabarang[20];
	int stock;
	struct Barang *next;	
}; typedef struct Barang Brg;

struct Pemesanan{
	struct Pemesanan *next;
	int kodepesanan;
	char nama[20];	
	int kodebarangpesanan;
	char namabarang[20];
	int jumlahpesanan;
	int kota_tujuan;
	int kota_asal;
	int tanggal;
	int bulan;
	int tahun;
	struct Barang Brg;	
}; typedef struct Pemesanan Pesan;

struct Login{
	struct Login *next;
	char username[50];
	char password[50];
	struct Pemesanan pesan;
}akun[50]; typedef struct Login Lg;


void lihatbarang();    
void tambahbarang();
void updatebarang();
void hapusbarang();
void detailbarang();
void tambahpemesanan();
void lihatpemesanan();
void dijkstra(int G[V][V],int n, int startnode, int targetnode);
void ubahgraph();

Lg* loginakun(Lg *);
void lihatakun(Lg *);
struct Barang *head = NULL;
struct Barang *p = NULL;
struct Pemesanan *head1 = NULL;
struct Pemesanan *p1=NULL;

int graph[V][V] =  {{0, 1, 0, 0, 0, 0, 0, 0},
				   { 0, 0, 2, 2, 3, 0, 0, 0},
				   { 1, 0, 0, 0, 0, 0, 0, 0},
				   { 0, 0, 1, 0, 0, 0, 3, 0},
				   { 0, 0, 0, 2, 0, 3, 0, 0},
				   { 0, 0, 3, 0, 0, 0, 0, 2},
				   { 0, 0, 0, 0, 1, 0, 0, 1},
				   { 0, 0, 0, 0, 0, 0, 0, 0}};

int main(){
	int pilih, fitur;
	Lg *lg;	
	lg = NULL;	
	
	system("cls"); system("color 06");
	printf("\n\t====================================================\n");
	printf("\t=          FINAL PROJECT STRUKTUR DATA A           =\n");
	printf("\t= SISTEM INFORMASI PEMESANAN BARANG DAN PENGIRIMAN =\n");
	printf("\t====================================================\n");
	printf("\t=        Dwi Wahyu Effendi    [18081010017]        =\n");
	printf("\t=        Amirah Aulia Fitri   [18081010029]        =\n");
	printf("\t====================================================\n");
	printf("\tTekan terserah untuk memulai program!!!");
	getch();
	
	system("cls"); system("color 06");
	printf("\t=================================================================== \n");	
    printf("\t=      Selamat Datang Aplikasi Pemesanan dan Pengiriman Barang     =\n");	
    printf("\t=================================================================== \n");		
    printf("\n\tSilahkan login terlebih dahulu! \n");
	getch();
	lg = loginakun(lg);
	
	do{
		menu:
		system("cls"); system("color 06");
		printf("\n\t====================================================\n");
		printf("\t=                    Menu Fitur                    =\n");
		printf("\t====================================================\n");
		printf("\t1. Informasi Barang\n");
		printf("\t2. Informasi Pemesanan\n");
		printf("\t3. Informasi Akun & Graph\n");
		printf("\t4. Keluar\n");
		printf("\t====================================================\n");
		printf("\tMasukkan Pilihan Anda : ");
		scanf("%d", &fitur);
		
		if(fitur==1){
			system("cls"); system("color 06");
			printf("\n\t====================================================\n");
			printf("\t=                    Menu Fitur                    =\n");
			printf("\t====================================================\n");
			printf("\t1. Tambah Barang\n");
			printf("\t2. Ubah Barang\n");
			printf("\t3. Lihat Barang\n");
			printf("\t4. Hapus Barang\n");
			printf("\t5. Lihat Detail Barang\n");
			printf("\t====================================================\n");
			printf("\tMasukkan Pilihan Anda : ");
			scanf("%d", &pilih);
			switch(pilih){
				case 1 :
					tambahbarang();
					break; goto menu;
				case 2 :
					updatebarang();
					break; goto menu;
				case 3 :
					lihatbarang();
					break; goto menu;
				case 4 :
					hapusbarang();
					break; goto menu;
				case 5:
					detailbarang();
					break; goto menu;
			}
		}
		else if(fitur==2){
			system("cls"); system("color 06");
			printf("\n\t====================================================\n");
			printf("\t=                    Menu Fitur                    =\n");
			printf("\t====================================================\n");
			printf("\t1.  Pemesanan Barang\n");
			printf("\t2.  Lihat Proses Pengiriman\n");
			printf("\t====================================================\n");
			printf("\tMasukkan Pilihan Anda : ");
			scanf("%d", &pilih);
			switch(pilih){
				case 1 :
					tambahpemesanan();
					break; goto menu;
				case 2 :
					lihatpemesanan(graph);
					break; goto menu;
			}
		}
		else if(fitur==3){
			system("cls"); system("color 06");
			printf("\n\t====================================================\n");
			printf("\t=                    Menu Fitur                    =\n");
			printf("\t====================================================\n");
			printf("\t1.  Lihat Akun Saya\n ");
			printf("\t2.  Ubah Data Graph\n");
			printf("\t====================================================\n");
			printf("\tMasukkan Pilihan Anda : ");
			scanf("%d", &pilih);
			switch(pilih){
				case 1 :
					lihatakun(lg);
					break; goto menu;
				case 2 :
					ubahgraph();
					break; goto menu;
			}
		}
		else if(fitur==4){
			system("cls");
			printf("\n\tTerimakasih Telah Menggunakan Program ini!!!");
			getch(); exit(0); break;
		}
		else{
			printf("\n\tMaaf Pilihan Fitur Tidak Tersedia, Silahkan Menginput Ulang!!!");
			getch(); break;	goto menu;
		}
	}

while(pilih != 10);
return 0;
akhir:
	exit(0);
}

Lg* loginakun(Lg *lg){
	Lg *log;
	log = malloc(sizeof(Lg));
	log->next = NULL;
	
	system("cls"); system("color 06");

	printf("\n\t====================================================\n");
	printf("\t=                    LOGIN AKUN                    =\n");
	printf("\t====================================================\n");
	printf("\tUSERNAME	: ");
	gets(log->username);
	printf("\tPASSWORD	: ");
	gets(log->password);

	if(log == NULL){
		lg = log;
	}
	else{
		log->next = lg;
	}

printf("\n");
return log;
}

void lihatakun(Lg *lg){
	
	system("cls");
	printf("\n\t===================================================\n");
	printf("\t=                  Lihat Akun Saya                  =\n");
	printf("\t=====================================================");	
	
	while(lg != NULL){
		printf("\n\tUsername	: %s",lg->username);
		printf("\n\tPassword	: ******");
		lg= lg->next;
	} getch(); system("cls");
}

void masukpemesanan(int kodpes,int kodbarpes, int jumpes,int tgl,int bln,int thn,char nampes[],char nambar[],int tujuan,int asal){
	struct Pemesanan* newnode = (struct Pemesanan*)malloc(sizeof(struct Pemesanan)); 
	newnode->kodepesanan = kodpes; 
	strcpy(newnode->nama, nampes);
	newnode->kodebarangpesanan = kodbarpes; 
	strcpy(newnode->namabarang, nambar);
	newnode->jumlahpesanan = jumpes; 
	newnode->tanggal = tgl; 
	newnode->bulan = bln; 
	newnode->tahun = thn; 
	newnode->kota_asal= asal;
	newnode->kota_tujuan = tujuan; 
	newnode->next = head1; 
	head1 = newnode;
}

void tambahpemesanan(){
	system("cls"); system("color 06");
    int kodpes,kodbarpes, jumpes, tgl,bln, thn,tujuan,asal;
    char nampes[50],nambar[40];
	fflush(stdin);
	printf("\t=============================================\n");
	printf("\t            Buat Pemesanan Barang            \n");
	printf("\t=============================================\n");
	printf("\tKode Pesanan	: ");
	scanf ("%d",&kodpes); fflush(stdin);
	printf("\tNama Pemesan	: ");
	scanf("%s", &nampes); 	fflush(stdin);
	printf("\tKode Barang	: ");
	scanf ("%d",&kodbarpes); fflush(stdin);
	printf("\tNama Barang	: ");
	scanf("%s", &nambar); 	fflush(stdin);
	printf("\tJumlah Pesanan	: ");
	scanf("%d", &jumpes); 	fflush(stdin);
	printf("\tTanggal     	: ");
	scanf("%d", &tgl); 	fflush(stdin);
	printf("\tBulan      	: ");
	scanf("%d", &bln); 	fflush(stdin);
	printf("\tTahun      	: ");
	scanf("%d", &thn); 	fflush(stdin);
	printf("\tKota Asal: ");
	printf("\n\t0. Surabaya");
	printf("\n\t1. Sidoarjo");
	printf("\n\t2. Gresik");
	printf("\n\t3. Situbondo");
	printf("\n\t4. Madiun ");
	printf("\n\t5. Magetan ");
	printf("\n\t6. Malang ");
	printf("\n\t7. Mojokerto ");
	printf("\n\tPilih Kota Tujuan : ");
	scanf("%d", &asal);
	printf("\tKota Tujuan");
	printf("\n\t0. Surabaya");
	printf("\n\t1. Sidoarjo");
	printf("\n\t2. Gresik");
	printf("\n\t3. Situbondo");
	printf("\n\t4. Madiun ");
	printf("\n\t5. Magetan ");
	printf("\n\t6. Malang ");
	printf("\n\t7. Mojokerto ");
	printf("\n\tPilih Kota Tujuan : ");
	scanf("%d", &tujuan);

	masukpemesanan(kodpes,kodbarpes, jumpes, tgl,bln, thn,nampes,nambar,tujuan,asal);
	getch();system("cls");
}

void lihatpemesanan(int graph[V][V]){
	struct Pemesanan* lihat;
	system("cls"); system("color 06");
	
	if (head1 == NULL){
		printf (" Tidak Ada Proses Pemesanan Barang ");
	}
	else{
		printf("\n\t=============================================\n");
		printf("\t         Lihat Proses Pemesanan Barang       \n");
		printf("\t=============================================");
		lihat = head1;
		while (lihat!= NULL){
			printf("\n\n\tKode Pesanan	: %d", lihat->kodepesanan);
			printf("\n\tNama Pemesan	: %s", lihat->nama);
			printf("\n\tKode Barang 	: %d", lihat->kodebarangpesanan);
			printf("\n\tNama Barang	: %s", lihat->namabarang);
			printf("\n\tJumlah Barang	: %d", lihat->jumlahpesanan);
			printf("\n\tTanggal Pesan   : %d", lihat->tanggal);
			printf("\n\tBulan         	: %d", lihat->bulan);
			printf("\n\tTahun         	: %d", lihat->tahun); printf("\n");
			dijkstra(graph,10,lihat->kota_asal,lihat->kota_tujuan);
			lihat = lihat->next;
		}
	}

getch(); system("cls");
}

void dijkstra(int G[V][V],int n, int startnode, int targetnode)
{
	struct Pemesanan* lihat;
	int cost[V][V],distance[V],pred[V];
	int visited[V],count,mindistance,nextnode,i,j;
	char kota[25][12] = {"Surabaya","Sidoarjo","Gresik","Situbondo","Madiun","Magetan","Malang","Mojokerto"};	

	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(G[i][j]==0)
				cost[i][j]=INFINITY;
			else
				cost[i][j]=G[i][j];

	for(i=0;i<n;i++){
		distance[i]=cost[startnode][i];
		pred[i]=startnode;
		visited[i]=0;
	}
	
	distance[startnode]=0;
	visited[startnode]=1;
	count=1;
	
	while(count<n-1){
		mindistance=INFINITY;
		
		for(i=0;i<n;i++)
			if(distance[i]<mindistance&&!visited[i]){
				mindistance=distance[i];
				nextnode=i;
			}
						
			visited[nextnode]=1;
			for(i=0;i<n;i++)
				if(!visited[i])
					if(mindistance+cost[nextnode][i]<distance[i]){
						distance[i]=mindistance+cost[nextnode][i];
						pred[i]=nextnode;
					}
		count++;
	}
  	int a;
 	int u;
 	char tes[20][8] = {"Senin","Selasa","Rabu","Kamis","Jumat","Sabtu","Minggu"}; 
	for(i=0;i<n;i++)
		if(i==targetnode){
			printf("\tKota Asal	: %s", kota[startnode]);
			printf("\n\tKota Tujuan	: %s", kota[i]);
			printf("\n\tJarak Tujuan	: %d KM", distance[i]*100);
			printf("\n\tJalur		: %s", kota[i]);
			
			j=i;
			do{
				j=pred[j];
				printf(" <- %s",kota[j]);
			}while(j!=startnode);
			a=distance[i];
			if (a<=2){
				u = 1;
				printf("\n\tPengiriman\t: SENIN");
				printf("\n\tWaktu Pengiriman: 1 Hari");
				printf("\n\tWaktu Sampai\t: %s\n",tes[u]);	
			}
			else if (a<=4){
				u = 3;
				printf("\n\tPengiriman\t: SENIN");
				printf("\n\tWaktu Pengiriman: 3 Hari");
				printf("\n\tWaktu Sampai\t: %s\n",tes[u]);
			}
			else if (a<=6){
				u = 5;
				printf("\n\tPengiriman\t: SENIN");
				printf("\n\tWaktu Pengiriman: 5 Hari");
				printf("\n\tWaktu Sampai\t: %s\n",tes[u]);
			}
			else if (a>=10){
				u = 7;
				printf("\n\tPengiriman\t: SENIN");
				printf("\n\tWaktu Pengiriman: 7 Hari");
				printf("\n\tWaktu Sampai\t: %s\n",tes[u]);
			}
	}
}

void masukbarang(int kodbar,char nambar[],int stock1){
	struct Barang* newnode = (struct Barang*)malloc(sizeof(struct Barang)); 
	newnode->kodebarang = kodbar; 
	strcpy(newnode->namabarang, nambar);
	newnode->stock = stock1; 
	newnode->next = head; 
	head = newnode;
}

void tambahbarang(){
	system("cls");
    int kodbar, stock1;
    char nambar[50];

	fflush(stdin);
	printf("\t=============================================\n");
	printf("\t            	Tambah Barang 		           \n");
	printf("\t=============================================\n");
	printf("\tKode Barang		: ");
	scanf("%d", &kodbar);  fflush(stdin);
	printf("\tNama Barang		: ");
	scanf("%s", &nambar); 	fflush(stdin);
	printf("\tStock Barang     	: ");
    scanf("%d",&stock1); 	fflush(stdin);
	masukbarang(kodbar,nambar,stock1);
	getch();system("cls");
}

void updatebarang(){
	struct Barang *current;
   	char namabarang1[50];
   	int stock1, num;
	system("cls");
	
	printf("\t=============================================\n");
	printf("\t            	Update Barang 		           \n");
	printf("\t=============================================\n");
	
	printf("\tMasukkan Nilai Yang ingin di ubah : ");		
	scanf("%d", &num);
	fflush(stdin);
	
	if(head==NULL){
		printf("\tList Saat ini Masih Kosong"); getch(); system("cls"); return;
	}
	
	current = head;
	while(current!=NULL){
	 	if(num==current->kodebarang){
	 		printf("\t=============================================\n");
	 		printf("\tMasukkan Nama Barang	: ");
	      	scanf("%s", &namabarang1);
	      	strcpy(current->namabarang, namabarang1);
	      	printf("\tMasukkan Stock Baru	: ");
	      	scanf("%d", &stock1);
	      	current->stock = stock1;
			return;
		}
		current=current->next;
	}
	printf("\tKode Barang %d Tidak Berada di dalam List", num);
	getch(); system("cls");
}

void lihatbarang(){
struct Barang* lihat;
system("cls"); printf("\n");

    if(head==NULL){
        printf("\n\tData Barang Kosong\n");
    }
    else{ 
    printf("\t=============================================\n");
    printf("\t=              Lihat Barang                 =\n");
    printf("\t=============================================");
    lihat = head; 
        
		while(lihat != NULL){ 
            printf("\n\tKode Barang		: %d", lihat->kodebarang);
            printf("\n\tNama Barang		: %s", lihat->namabarang);
            printf("\n\tStock Barang		: %d", lihat->stock);
            lihat = lihat->next;
        } 
    }
    getch(); system("cls");
}

void hapusbarang(){
system("cls");	
struct Barang *temp = NULL;
int num;
	
	printf("\t=============================================\n");
	printf("\t            	HAPUS Barang 		           \n");
	printf("\t=============================================\n");
	printf("\tMasukkan List Barang Yang ingin di Hapus : ");		
	scanf("%d", &num);
	
	if(head==NULL){
		printf("\n\tList Saat ini Masih Kosong");
		getch(); system("cls"); return;
	}
	
	if(num==head->kodebarang){	//Mencek list pertama
		temp = head;
		head = head->next;
		free(temp);
		return;
	}
	
	p = head;
	while(p->next!=NULL){	//Mencek list berikutnya
		if(p->next->kodebarang==num){
			temp = p->next;
			p->next = temp->next;
			free(temp);
			getch(); system("CLS");
			return;
		}
		p = p->next;
	}
	printf("\n\tKode Barang %d Tidak Berada di dalam List", num);
	getch(); system("cls");
}

void detailbarang(){
system("cls"); printf("\n");
int search_detail;
int kembali;
struct Barang* detail;
struct Barang* letak;
struct Pemesanan* lihat;

    if(head==NULL){
        printf("\n\tDetail Barang Kosong\n");
    }
	else{
	 	printf("\t=============================================\n");
    	printf("\t=            Lihat Detail Barang            =\n");
    	printf("\t=============================================\n");
    	detail = head; 
        
		while(detail != NULL){ 
        	printf("\n\t[%d]\t[%s] \n", detail->kodebarang, detail->namabarang);
			detail = detail->next; 
		}
		printf("\tSilahkan Masukkan kode barang yang ingin dilihat : ");
		scanf("%d", &search_detail);
		
		letak = head;
		lihat = head1;
		while(letak!=NULL){
			if(search_detail==letak->kodebarang){
				printf("\n\tKode Barang		: %d", letak->kodebarang);
        		printf("\n\tNama Barang		: %s", letak->namabarang);
        		printf("\n\tStock Barang		: %d", letak->stock);
				while (lihat != NULL){
					if(letak->kodebarang == lihat->kodebarangpesanan){
						printf("\n\tNama Pemesan 		: %s \n", lihat->nama);
						lihat = lihat->next;
						kembali =1;
					}
					else{
						lihat = lihat->next;
						kembali =0;
					}
				}
				if (kembali == 0){
					printf("\n\tBarang belum di pesan");
				}
			}
			letak = letak->next;
		}
    }
    getch();
    system("cls");
}

void ubahgraph(){
	int kota_awal, kota_tujuan, jarak_baru;
	char kota[25][12] = {"Surabaya","Malang","Magetan","Pacitan", "Situbondo"};
	system("cls");
	
	printf("\t=============================================\n");
    printf("\t=             Update Data Barang            =\n");
    printf("\t=============================================\n");
	printf("\tPilih Kota Yang ingin di rubah\n");
	printf("\n\t0. Surabaya");
	printf("\n\t1. Sidoarjo");
	printf("\n\t2. Gresik");
	printf("\n\t3. Situbondo");
	printf("\n\t4. Madiun ");
	printf("\n\t5. Magetan ");
	printf("\n\t6. Malang ");
	printf("\n\t7. Mojokerto ");
	printf("\tMasukkan Kota : ");
	scanf("%d", &kota_awal);
	fflush(stdin);

	printf("\tKota %s Ke Kota? : \n", kota[kota_awal]);
	printf("\n\t0. Surabaya");
	printf("\n\t1. Sidoarjo");
	printf("\n\t2. Gresik");
	printf("\n\t3. Situbondo");
	printf("\n\t4. Madiun ");
	printf("\n\t5. Magetan ");
	printf("\n\t6. Malang ");
	printf("\n\t7. Mojokerto ");
	printf("\tMasukkan Kota : ");
	scanf("%d", &kota_tujuan);
	fflush(stdin);
	printf("\tMasukkan jarak yang Baru : ");
	scanf("%d", &jarak_baru);
	fflush(stdin);

	graph[kota_awal][kota_tujuan] = jarak_baru;
	printf("\tJarak %s ke %s yang baru adalah %d Km", kota[kota_awal], kota[kota_tujuan], jarak_baru*100);
	
	getch();
   	system("cls");	
}
