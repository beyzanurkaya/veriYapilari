//BEYZA NUR KAYA
//1306170038

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

struct node{
    int info;
    struct node *left;
    struct node *right;
};


struct node *root=NULL;
int arr[100];
int leaf=0;

struct node *createnode(int x)
{
    struct node *p=(struct node *)malloc(sizeof(struct node));
    p->info = x;
    p->left = NULL;
    p->right = NULL;
    return(p);
}

void setleft(struct node * p, int x)
{
    if (p == NULL)
        printf("Boş(void) ekleme! \n");
    else if (p->right != NULL)
        printf("Geçersiz ekleme! \n");
    else
        p->left = createnode(x);
}

void setright(struct node * p, int x)
{
    if (p == NULL)
        printf("Boş(void) ekleme! \n");
    else if (p->right != NULL)
        printf("Geçersiz ekleme! \n");
    else
        p->right = createnode(x);
}

void leafnodes(struct node * treeptr){
    if (treeptr != NULL) {
        if (treeptr->left == NULL && treeptr->right == NULL) {
            arr[leaf] = treeptr->info;
            leaf++;
        }
        leafnodes(treeptr->left);
        leafnodes(treeptr->right);
    }
}

int main(){
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
                    root = createnode(x);
                }
                else{
                    p=q=root;
                    
                    while ((x != p->info) && q != NULL) {
                        p = q;
                        if (x < p->info)
                            q = p->left;
                        else
                            q = p->right;
                    }
                    
                    if (x == (p->info))
                        printf("Kopya(Aynı eleman)\n");
                    else if (x < (p->info))
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
