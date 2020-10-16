//BEYZA NUR KAYA
//1306170038

#include<iostream>
#include <stdio.h>
#define MAXSIZE 10

int pop();
struct stack{
    int arr[MAXSIZE];
    int top;
};

struct stack mystack;

struct nodetype{
    int info;
    struct nodetype *left;
    struct nodetype *right;
    
};

typedef struct nodetype *NODEPTR;

NODEPTR getnode(void)
{
    NODEPTR p;
    p = (NODEPTR)malloc(sizeof(struct nodetype));
    return(p);
}

NODEPTR maketree(int x)
{
    NODEPTR p;
    
    p = getnode();
    p->info = x;
    p->left = NULL;
    p->right = NULL;
    return(p);
}

NODEPTR ptree;
NODEPTR p, q;
void ldragac(){
    
    int number;
    
    number = pop();
    ptree = maketree(number);
    while (number != NULL) {
        number = pop();
        if (number == NULL) {
            return;
        }
        p = q = ptree;
        while (number != p->info && q != NULL){
            p = q;
            if (number < p->info)
                q = p->left;
            else
                q = p->right;
        }
        if (number == p->info)
            printf("%d",number);
        else if (number < p->info){
            if (p == NULL)
                printf("Boş(void) ekleme!");
            else if (p->left != NULL)
                printf("Geçersiz ekleme!");
            else
                p->left = maketree(number);
            
        }else{
            if (p == NULL)
                printf("Boş(void) ekleme!");
            else if (p->right != NULL)
                printf("Geçersiz ekleme!");
            else
                p->right = maketree(number);
        }
    }
}

void intrav(NODEPTR tree){
    if (tree != NULL) {
        intrav(tree->left);
        printf("%d ", tree->info);
        intrav(tree->right);
    }
}

void push(int);
int  pop(void);
void display(void);

int main() {
    
    int choose;
    int tmp;
    mystack.top = -1;
    
    while (1) {
        printf ("1    -->   Yığıta eleman ekle.                              \n");
        printf ("2    -->   Yığıttan eleman silme.                           \n");
        printf ("3    -->   Yığıttaki elemanları yazdır.                     \n");
        printf ("4    -->   Elemanları ikili ağaca taşı ve ağacı yazdır.     \n\n");
        
        printf ("Seçiminizi giriniz: ");
        scanf    ("%d", &choose);
        switch (choose){
            case 1:
                tmp=0;
                printf ("Eklenecek eleman:");
                scanf ("%d", &tmp);
                push(tmp);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                ldragac();
                printf("\n--- LDR Formundaki Agaç ---\n");
                intrav(ptree);
                printf("\n--- ---\n");
        }
    }
    return 0;
}

void push(int x){
    if (mystack.top == (MAXSIZE - 1)){
        printf("Stack dolu!\n");
        return;
    }else{
        (mystack.top)++;
        mystack.arr[mystack.top] = x;
    }
    return;
}

int pop(){
    int tmp;
    if (mystack.top == -1){
        printf("Stack boş.\n");
        return NULL;
    }else{
        tmp = mystack.arr[mystack.top];
        printf("%d stackten çıkarıldı.\n", tmp);
        mystack.top = mystack.top - 1;
    }
    return(tmp);
}

void display(){
    int i;
    if (mystack.top == -1){
        printf("Stackte gösterilecek eleman yok!\n");
        return;
    }else{
        printf("\n * STACK * \n");
        for (i = mystack.top; i >= 0; i--)
            printf("%d\n", mystack.arr[i]);
    }
    printf("\n");
}



