#include <iostream>
using namespace std;

struct node{
    int data;
    struct node *next;
};

struct node* ilk = NULL;
struct node* temp;

struct node* getNode(){
    struct node* yNode = (struct node*)malloc(sizeof(struct node));
    return yNode;
}

void insert(int eklenen){
    struct node *newNode= getNode();
    newNode->data= eklenen;
    temp= ilk;
    newNode->next=temp;
    ilk= newNode;
    cout << eklenen << " agaca eklendi\n";
    if (ilk == NULL) {
        printf("void insertion\n");
        exit(1);
    }

    
}

void remove(){
    struct node* temp2;
    
    if ((ilk==NULL) || (ilk->next==NULL) ) {
        cout << "void deletion\n";
    }
    
    if ((ilk!=NULL) || (ilk->next!=NULL) ) {
        temp2= ilk;
        ilk=ilk->next;
        cout << temp2->data << " silindi\n";
        free(temp2);
    }else{
        cout << ilk << " silindi...\n";
        free(ilk);
        ilk=NULL;
    }
}

void listele() {
    temp = ilk;
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
 
    }
}

void arama(int aranan) {
    int kontrol = 0;
    temp = ilk;
    while (temp != NULL) {
        if (aranan == temp->data) {
            kontrol = 1;
        }
        temp = temp->next;
    }
 
    if (kontrol == 1)
        printf("\n%d Sayisi Bulunmustur..\n", aranan);
    else
        printf("\nAranan Sayi Bulunamamistir...\n");
}

int main(int argc, const char * argv[]) {

    insert(12);
    insert(22);
    insert(34);
    insert(98);
    remove();
    remove();
    listele();
    arama(12);
    return 0;
}
