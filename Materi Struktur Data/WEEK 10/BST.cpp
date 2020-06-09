#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//========================================================

struct node {
	 int data;
    struct node *right;
    struct node *left;
};
typedef struct node node;

node *createNode(int bil);
void insert(node **root, node *newNode);
void inorder(node *root);
node *findLargestBST(node *root);
bool deleteNode(node **root, int key);
void deleteBST(node **root);

//========================================================

int main()
{
  node *root, *pNew;
  char pilih;
  int bil;
  bool success;

  root = NULL;
  do{
     system("cls");
     printf("masukkan pilihan\n");
     printf("1. tambah data\n");
     printf("2. hapus data\n");
     printf("3. cetak isi tree secara inorder\n");
     printf("MASUKKAN PILIHAN (tekan q untuk keluar) : ");
     fflush(stdin);
     scanf("%c", &pilih);
     if (pilih == '1'){
     		printf("nilai yang akan dimasukkan ke tree: ");
         scanf("%d", &bil);
         pNew = createNode(bil);
         if (pNew == NULL){
         	printf("insert gagal");
            getch();
         }
         else
            insert(&root, pNew);
     }
     else if (pilih == '2'){
     		printf("nilai yang akan dihapus : ");
         scanf("%d", &bil);
     		success = deleteNode(&root, bil);
         if(!success){
         	printf("\ndata gagal dihapus");
         	getch();
         }
     }
     else if (pilih == '3'){
     		inorder(root);
         getch();
     }
  } while (pilih != 'q');
  deleteBST(&root);
  return 0;
}

//========================================================

node *createNode(int bil){
   node *pNew;

   pNew = (node *)malloc(sizeof(node));

   if (pNew != NULL){
      pNew->data = bil;
      pNew->left = NULL;
      pNew->right = NULL;
   }
   return(pNew);
}

void insert(node **root, node *newNode){
	if(*root == NULL)
   	*root = newNode;
   else if (newNode->data < (*root)->data)
      insert(&((**root).left), newNode);
   else
      insert(&((**root).right), newNode);
}

void inorder(node *root){
	if (root != NULL){
   	inorder(root->left);
      printf(" %d,", root->data);
      inorder(root->right);
   }
}

node *findLargestBST(node *root){
	if (root ->right == NULL)
   	return(root);
   else
   	return(findLargestBST(root->right));
}

bool deleteNode(node **root, int key){
   node *pDel;
   node *pReplace;

	if(*root == NULL)
   	return(false);
   else if (key < (*root)->data)
      return(deleteNode(&((**root).left), key));
   else if (key > (*root)->data)
      return(deleteNode(&((**root).right), key));
   else{
   	if ((*root)->left == NULL && (*root)->right == NULL){
      	pDel = *root;
         *root = NULL;
         free(pDel);
         return(true);
      }
      else if ((*root)->left == NULL){
      	pDel = *root;
         *root = (*root)-> right;
         free(pDel);
         return(true);
      }
      else if ((*root)->right == NULL){
      	pDel = *root;
         *root = (*root)-> left;
         free(pDel);
         return(true);
      }
      else{
      	pDel = *root;
         pReplace = findLargestBST((*root)->left);
         pDel->data = pReplace->data;
         return (deleteNode(&((**root).left), pReplace->data));
      }
   }
}

void deleteBST(node **root){

	while(*root != NULL)
   	deleteNode(root, (*root)->data);
}
