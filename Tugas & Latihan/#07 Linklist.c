#include<stdio.h>
#include<stdlib.h>

struct node{
	int info;
	struct node *link;
};

void display(struct node *start); //Fungsi Display
struct node *addatbeg(struct node *start, int num);
void addatend(struct node *start, int num);
void addafter(struct node *start, int num, int num2);
struct node *addbefore(struct node *start, int num, int num2);
struct node *del(struct node *start, int num);
void search(struct node *start, int num2);
void count(struct node *start);
struct node *reverse(struct node *start);

main(){
	struct node *start = NULL;
	int choice, num, num2;
	
	while(1){
		printf("\n1. Display\n");
		printf("2. Add at beginning\n");
		printf("3. Add node at the end\n");
		printf("4. Add after node\n");
		printf("5. Add before node\n");
		printf("6. Delete from list\n");
		printf("7. Search\n");
		printf("8. Count number of node\n");
		printf("9. Reverse list\n");
		printf("10. Exit\n\n");
		scanf("%d", &choice);
		system("cls");
			
		switch(choice){
			case 1:
				display(start);
				break;
			case 2:
				printf("Enter the number to be inserted : ");
				scanf("%d", &num);
				start = addatbeg(start, num);
				break;
			case 3:
				printf("Enter the number to be inserted : ");
				scanf("%d", &num);
				addatend(start, num);
				break;
			case 4:
				printf("Enter the number to be inserted : ");
				scanf("%d", &num);
				printf("Enter the number after which to insert : ");
				scanf("%d", &num2);
				addafter(start, num, num2);
				break;
			case 5:
				printf("Enter the number to be inserted : ");
				scanf("%d", &num);
				printf("Enter the number after which to insert : ");
				scanf("%d", &num2);
				start = addbefore(start, num, num2);
				break;
			case 6:
				printf("Enter the number to be deleted : ");
				scanf("%d", &num);
				start=del(start, num);
				break;
			case 7:
				printf("Enter the number to be searcher : ");
				scanf("%d", &num);
				search(start, num);
				break;
			case 8:
				count(start);
				break;
			case 9:
				start=reverse(start);
				break;
			case 10:
				exit(1);
			default:
				printf("Invalid input");			
	 
		}
		
	}
}

void display(struct node *start){
	struct node *p;
	if(start==NULL){
		printf("List of empty");
		getch(); system("cls");
		return;
	}
	
	p = start;
	
	while(p != NULL){
		printf("%d ", p->info);
		p=p->link;
	}
	
}

struct node *addatbeg(struct node *start, int num){
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->info = num;
	temp->link = start;
	start = temp;
	return start;
}

void addatend(struct node *start, int num){
	struct node *temp, *p;
	if(start==NULL){
		printf("This function cannot be used to add a node to an empty list\n");
		return;
	}
	temp = (struct node *)malloc(sizeof(struct node));
	temp->info=num;
	p = start;
	while(p->link!=NULL){
		p = p->link;
	}
	p->link = temp;
	temp->link = NULL;
}

struct node *del(struct node *start, int num){
	struct node *temp, *p;
	if(start==NULL){
		printf("List is empty");
	}
	
	if(start->info==num){	//Mencek list pertama
		temp = start;
		start = start->link;
		free(temp);
		return start;
	}
	
	p = start;
	while(p->link!=NULL){	//Mencek list berikutnya
		if(p->link->info==num){
			temp = p->link;
			p->link = temp->link;
			free(temp);
			return start;
		}
		p = p->link;
	}
	printf("%d not present in the list", num);
	return start;
}

void search(struct node *start, int num){
	struct node *p;
	int pos=1;
	
	if(start==NULL){
		printf("List is empty");
	}	
	
	p = start;
	while(p!=NULL){
	 	if(p->info==num){
			printf("Masukkan Nilai Baru : ");
			scanf("%d", &num);
			p->info = num;
			return;
		}
		p=p->link;
		pos++;
	}
	printf("%d not found in the list", num);
}

/*void search(struct node *start, int num){
	struct node *p;
	int pos=1;
	
	if(start==NULL){
		printf("List is empty");
	}	
	
	 p = start;
	 while(p!=NULL){
	 	if(p->info==num){
	 		printf("%d found at position %d", num, pos);
			return;
		}
		p=p->link;
		pos++;
	}
	printf("%d not found in the list", num);
}*/

void count(struct node *start){
	int count = 0;
	struct node *p;
	p = start;
	
	while(p!=NULL){
		p = p->link;
		count++;
	}
	printf("Number of nodes %d", count);
}

void addafter(struct node *start, int num, int num2){
	struct node *temp, *p;
	p = start;
	while(p!=NULL){
		if(p->info==num2){	//membandingkan
			temp = (struct node *)malloc(sizeof(struct node));
			temp->info=num;		//memasukkan list baru
			temp->link = p->link;
			p->link = temp;
			return;
		}
	p = p->link;
	}
	printf("%d not present in the list", num2);
}

struct node *addbefore(struct node *start, int num, int num2){
	struct node *temp, *p;
	
	if(start->info==num2){
		temp = (struct node *)malloc(sizeof(struct node));
		temp->info = num;
		temp->link=start;
		start=temp;
		return start;
	}
	
	p = start;
	while(p->link!=NULL){
		if(p->link->info==num2){
			temp=(struct node *)malloc(sizeof(struct node));
			temp->info=num;
			temp->link=p->link;
			p->link=temp;
			return start;
		}
		p=p->link;
	}
	printf("%d not present in the list", num2);
	return start;
}

struct node *reverse(struct node *start){
	struct node *previous, *ptr, *next;
	previous = NULL;
	ptr = start;
	
	while(ptr!=NULL){
		next=ptr->link;
		ptr->link=previous;
		previous=ptr;
		ptr=next;
	}
	start=previous;
	return start; 
}
