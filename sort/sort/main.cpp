#include<iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctime>
using namespace std;

int randm[17000];
int d1[17000];
int d2[17000];
int d3[17000];

void selection(int);
void insertion(int);
void bubble(int );

int main() {
    
    return 0;
}

void bubble(int n){
    
    for (int i = n; i > 1; --i) {
        for (int j = 0; j < i - 1; j++) {
            if (d1[j] > d1[j + 1]) {
                int ata;
                ata = d1[j];
                d1[j] = d1[j + 1];
                d1[j + 1]=ata;
            }
        }
    }
}

void insertion(int n){
    for (int i = 1; i < n; i++) {
        for (int j = i; j >= 0; j--) {
            if (d3[j] < d3[j - 1]) {
                int ata;
                ata = d3[j];
                d3[j] = d3[j + 1];
                d3[j + 1] = ata;
            }
        }
    }
}

void selection(int n) {
    for (int i = 0; i < n; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (d2[j] < d2[min]) {
                int ata;
                ata = d2[min];
                d2[min] = d2[j];
                d2[j] = ata;
            }
        }
    }
}
