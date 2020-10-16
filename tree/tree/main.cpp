#include <iostream>
using namespace std;

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int data){
    struct node *yNode= (struct node*)malloc(sizeof(struct node));
    yNode->data=data;
    yNode->left= NULL;
    yNode->right= NULL;
    
    return yNode;
}
struct node *root=NULL;
int arr[100];
int leaf=0;

void setleft(struct node * p, int x)
{
    if (p == NULL)
        printf("Boş(void) ekleme! \n");
    else if (p->right != NULL)
        printf("Geçersiz ekleme! \n");
    else
        p->left = newNode(x);
}

void setright(struct node * p, int x)
{
    if (p == NULL)
        printf("Boş(void) ekleme! \n");
    else if (p->right != NULL)
        printf("Geçersiz ekleme! \n");
    else
        p->right = newNode(x);
}

void leafnodes(struct node * treeptr){
    if (treeptr != NULL) {
        if (treeptr->left == NULL && treeptr->right == NULL) {
            arr[leaf] = treeptr->data;
            leaf++;
        }
        leafnodes(treeptr->left);
        leafnodes(treeptr->right);
    }
}

void LDR(struct node* node){
    if (node==NULL) {
        return ;
    }
    LDR(node->left);
    cout << node->data;
    LDR(node->right);
}

void LRD(struct node* node){
    if (node==NULL) {
        return ;
    }
    LRD(node->left);
    LRD(node->right);
    cout << node->data;
}

void DLR(struct node* node){
    if (node==NULL) {
        return ;
    }
    cout << node->data;
    DLR(node->left);
    DLR(node->right);
    
}

int main() {
    struct node * p, *q;
       int selection, x;
       
       while (1)
       {
           printf("*** *** ***\n");
           printf("1    -->    Eleman ekle                 \n");
           printf("2    -->    Yaprak düğümü görüntüle     \n");
           printf("3    -->    EXIT                        \n");
           printf("*** *** ***\n");
           
           printf("Seçiminizi giriniz: ");
           scanf("%d", &selection);
           switch(selection){
               case 1:
                   printf("Eklemek istediğiniz sayıyı giriniz: ");
                   scanf("%d", &x);
                   
                   if(root==NULL)
                   {
                       printf("Agaç oluşturuldu, ilk eleman ekleniyor!\n");
                       root = newNode(x);
                   }
                   else{
                       p=q=root;
                       
                       while ((x != p->data) && q != NULL) {
                           p = q;
                           if (x < p->data)
                               q = p->left;
                           else
                               q = p->right;
                       }
                       
                       if (x == (p->data))
                           printf("Kopya(Aynı eleman)\n");
                       else if (x < (p->data))
                           setleft(p, x);
                       else
                           setright(p, x);
                   }
                   break;
               case 2:
                   if (root == NULL) {
                       printf("Ağaçta görüntülenecek eleman yok!\n");
                       break;
                   }
                   leafnodes(root);
                   printf("Yaprak düğümlerinin sayısı: %d\n", leaf);
                   printf("Yaprak düğümler:\n");
                   for (int i = 0; i<leaf; i++) {
                       printf("%d          ", arr[i]);
                   }printf("\n");
                   break;
               case 3:
                   return 0;
           }
       }
    return 0;
}
