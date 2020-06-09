#include<stdio.h>
#include<conio.h>
#define INFINITY 9999
#define V 9 
 
/*void dijkstra(int graph[V][V],int src,int a, int input);
 
int main()
{
	int graph[V][V],i,j,n,asal, tujuan;
	printf ("ingin membuat graph berapa X berapa? ");
	scanf ("%d",&n);
	printf("\nBuatlah Graph : \n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&graph[i][j]);

	printf("\n0. Surabaya");
	printf("\n1. Malang");
	printf("\n2. Magetan");
	printf("\n3. Pacitan");
	printf("\n4. Situbondo");
	printf("\nMasukkan Kota Asal :");
	scanf("%d",&asal);
	
	printf("\n0. Surabaya");
	printf("\n1. Malang");
	printf("\n2. Magetan");
	printf("\n3. Pacitan");
	printf("\n4. Situbondo");
	printf("\nMasukkan Kota Tujuan :");
	scanf("%d",&tujuan);
	
	dijkstra(graph,n,asal, tujuan);
	
	return 0;
}
 
void dijkstra(int graph[V][V], int src,int a,int input)
{
 
	int cost[V][V],distance[V],pred[V];
	int visited[V],count,mindistance,nextnode,i,j;
	char kota[25][12] = {"Surabaya","Malang","Magetan","Pacitan", "Situbondo"};
	

	for(i=0;i<src;i++)
		for(j=0;j<src;j++)
			if(graph[i][j]==0)
				cost[i][j]=INFINITY;
			else
				cost[i][j]=graph[i][j];
	
	for(i=0;i<src;i++)
	{
		distance[i]=cost[a][i];
		pred[i]=a;
		visited[i]=0;
	}
	
	distance[a]=0;
	visited[a]=1;
	count=1;
	
	while(count<src-1)
	{
		mindistance=INFINITY;
		
		//nextnode gives the node at minimum distance
		for(i=0;i<src;i++)
			if(distance[i]<mindistance&&!visited[i])
			{
				mindistance=distance[i];
				nextnode=i;
			}
			
			//check if a better path exists through nextnode			
			visited[nextnode]=1;
			for(i=0;i<src;i++)
				if(!visited[i])
					if(mindistance+cost[nextnode][i]<distance[i])
					{
						distance[i]=mindistance+cost[nextnode][i];
						pred[i]=nextnode;
					}
		count++;
	}
 
	for(i=0;i<src;i++)
		if(i==input)
		{
			printf("\nJarak dari kota %s ke kota %s adalah %d Km",kota[a],kota[i],distance[i]);
			printf("\nJalur = %s",kota[i]);
			
			j=i;
			do
			{
				j=pred[j];
				printf(" <- %s",kota[j]);
			}while(j!=a);
	}
}*/
#define x 10
#define y 10

int a,b;
int umur[x][y]= {{0, 3, 2, 0, 0},
				   {3, 0, 6, 5, 0},
				   {2, 6, 0, 8, 4},
				   {0, 5, 8, 0, 7},
				   {0, 0, 4, 7, 0}};

void cetakumur(){
	for(a=0;a<=x;a++)
		for(b=0;b<=y;b++)
		    printf("Umur = %d\n", umur[x][y]);
}

int main(){
//    cetakumur();
	for(a=0;a<=x;a++)
		for(b=0;b<=y;b++)
    		printf("Umur = %d\n", umur[x][y]);
    getchar();
    return 0;
}
