#include <iostream>
using namespace std;

struct node {
    int data;
    struct node *next, *prev;
};
struct node *ilk= NULL;

struct node *newNode(int x) {
    struct node *yNode=(struct node*)malloc(sizeof(struct node));
    yNode->data=x;
    yNode->next=NULL;
    yNode->prev=NULL;
    
    return yNode;
};

void insert(int eklenen){
    struct node* ekle= newNode(eklenen);
    if (ilk==NULL) {
        ilk= ekle;
        return;
    }
    ilk->prev= ekle;
    ekle->next= ilk;
    ilk=ekle;
}

void remove(){
    if (ilk==NULL) {
        cout << "void deletion\n";
        return;
    }
    if (ilk->next==NULL) {
        free(ilk);
        ilk=NULL;
        return;
    }
    struct node* second= ilk->next;
    free(ilk);
    second->prev=NULL;
    ilk= second;
}
int main(int argc, const char * argv[]) {
   
    return 0;
}
