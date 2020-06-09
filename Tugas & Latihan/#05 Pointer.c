//Pointer adalah variabel yang berfungsi untuk menyimpan alamat memori

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

main(){
	int a;
	int b = 10;
	double c =2.444;
	float d = 1.5;
	char e[5] = "Budi";
	
	printf("Alamat memori A : %u\n", &a);
	printf("Alamat memori B : %u\n", &b);
	printf("Alamat memori C : %u\n", &c);
	printf("Alamat memori D : %u\n", &d);
	printf("Alamat memori E : %u\n", &e);
	
	printf("=================================================\n");
	
	int *p1 = &a;
	int *p2 = &b;
	int *p3 = &c;
	int *p4 = &d;
	int *p5 = &e;
	
	printf(" A : %d\n", a);
	printf(" B : %d\n", b);
	printf(" C : %lf\n", c);
	printf(" D : %f\n", d);
	printf(" E : %s\n", e);
	
	printf("=================================================\n");
	
	printf("Alamat memori A : %u\n", p1);
	printf(" A : %d \n\n", *p1);
	printf("Alamat memori B : %u\n", p2);
	printf(" B : %d \n\n", *p2);
	printf("Alamat memori C : %u\n", p3);
	printf(" C : %i \n\n", *p3);
	printf("Alamat memori D : %u\n", p4);
	printf(" D : %f \n\n", *p4);
	printf("Alamat memori E : %u\n", p5);
	printf(" E : %c \n\n", *p5);
}
