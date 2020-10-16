#include <iostream>
using namespace std;
#define MAXSIZE 30

struct queue {
    int arr[MAXSIZE-1];
    int rear=-1, front=-1;

};

struct queue myqueue{
    myqueue.rear=myqueue.front=(MAXSIZE-1)
};

void insert(int eklenen){
    
    
    if (myqueue.front > MAXSIZE) {
        cout << "queue dolu\n";
    } else {
        if (myqueue.front==-1) {
            myqueue.front=myqueue.front+1;
        }
        myqueue.rear= myqueue.rear+1;
        myqueue.arr[myqueue.rear]=eklenen;
        cout << eklenen << " yigita eklendi\n";
    }
}
int remove() {
    
    if (myqueue.front== -1 || myqueue.front > myqueue.rear) {
        cout << "yigit bos\n";
    }else {
        cout << myqueue.arr[myqueue.front] << " silindi" << endl;
        myqueue.front= myqueue.front+1;
        
    }
    
    return (myqueue.front);
}
    
void display(){
    int i;
    if (myqueue.front== -1 || myqueue.front > myqueue.rear) {
        cout << "yigit bos\n";
    }else{
        for( i = myqueue.rear; i >= myqueue.front; i--){
        cout << myqueue.arr[i] << "   ";
            
        }cout << endl;
    }
}
int main() {
    
    insert(24);
    insert(34);
    insert(44);
    remove();
    display();
    
    return 0;
}

