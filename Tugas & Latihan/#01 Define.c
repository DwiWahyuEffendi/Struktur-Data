#include<stdio.h>
//Konstanta bisa menggunakan #define atau const
#define PI 3.14159 //Tanpa titikL;
#define P 4
#define add(x,y) x+y
#define banding(x, y) if(x > y)\
						printf("%d lebih besar dari %d", x, y);\
					else\
						printf("%d lebih kecil dari %d", x, y);

/*main(){
	printf("Nilai : %.4f", PI); return 0;
}*/

/*main(){
	printf("Nilai : %.2f", 5*PI); return 0;
}*/

/*main(){
	printf("Nilai : %.3f", P*PI); return 0;
}*/

/*main(){
	int p = 3;
	printf("Nilai : %.3f", P*PI+p); return 0;
}*/

/*main(){
	printf("Nilai : %d", add(2,1)); return 0;
}*/

/*main(){
	banding(2,4); return 0;
}*/

/*main()
{
	//printf("Hasil : %f", PI*2*P+add(3,4)); return 0;
	printf("Hasil : %f", PI*2+P*add(3,4)); return 0; //P*add(x,y) == P*x+y
}*/

main()
{
	printf("DATE : %s\n", __DATE__);
	printf("TIME : %s\n", __TIME__);
	return 0;
}
