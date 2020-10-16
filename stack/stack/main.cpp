#include <iostream>
using namespace std;
#define MAXSIZE 30

struct stack {
    int top;
    int arr[MAXSIZE];
};

struct stack mystack;

void push(int eklenen){
    if (mystack.top==MAXSIZE) {
        cout << "Stack dolu\n";
    } else {
        mystack.top++;
        mystack.arr[mystack.top]= eklenen;
    }cout << mystack.arr[mystack.top] << " stacke eklendi\n";
}

int pop(){
    int tmp = 0;
    
    if (mystack.top == -1) {
        cout << "Stack bos\n";
    } else {
        tmp= mystack.arr[mystack.top];
        cout << tmp << " silindi\n";
        mystack.top= mystack.top-1;
    }
    return tmp;
}

void display(){
    
    for (int i=1; i<=mystack.top; i++) {
        cout << mystack.arr[i] << endl;
    }
}

int main() {
    
    push(15);
    push(25);
    push(35);
    push(45);
    pop();
    display();
    
    return 0;
}
