//BEYZA NUR KAYA
//1306170038

#include <iostream>
#include <stdio.h>
#include <math.h>

#define SATIR 2
#define SUTUN 2

int main(void){
    
    FILE *p = NULL;
    FILE *sp;
    int matDizi[SATIR][SUTUN];
    int matDizi2[SATIR][SUTUN];
    char *dosyaAdi = "matrisler.txt";
    int i, j;
    //int son[SATIR][SUTUN];
    
    if((p = fopen("matrisler.txt", "r")) != NULL){
        
        for(i = 0; i < SATIR; i++){
          for(j = 0; j < SUTUN; j++){
              
              fscanf(p, "%d", &matDizi[i][j]);
              //printf("%d ", matDizi[i][j]);
              
          }
          //printf("\n");
      }
        //printf("\n");
        for(i = 0; i < SATIR; i++){
                 for(j = 0; j < SUTUN; j++){
                     
                     fscanf(p, "%d", &matDizi2[j][i]);
                     //printf("%d ", matDizi2[j][i]);
                     
                 }
                 //printf("\n");
             }
    }else{
        
        printf("*** %s dosyasi bulunamadi!", dosyaAdi);
    }
    fclose(p);

    //printf("\n");
    int x;
    int A[SATIR*SUTUN];
       for(x = 0; x < SATIR*SUTUN; x++) {
           A[x]= *((int*)matDizi + x);
           //printf("%d ", tmatDizi[x]);
           
       }
    //printf("\n");
    int B[SATIR*SUTUN];
    for(x = 0; x < SATIR*SUTUN; x++) {
        B[x]= *((int*)matDizi2 + x);
        //printf("%d ", tmatDizi2[x]);
        
    }
    //printf("\n\n");
    
    int carpim[SATIR];
    int toplam[SATIR*SUTUN];
   
    for (int m=0; m<SATIR; m++) {

        carpim[m]= A[m]*B[m];
        toplam[0] += carpim[m];
        carpim[m]= 0;
        carpim[m+1]= A[m]*B[m+SATIR];
        toplam[1] += carpim[m+1];
        carpim[m]= 0;
        carpim[m+1]= A[m+SATIR]*B[m];
        toplam[2] += carpim[m+1];
        carpim[m]= 0;
        carpim[m]= A[m+SATIR]*B[m+SATIR];
        toplam[3] += carpim[m];
    }
    
    for (int j=0; j<SATIR*SUTUN; j++) {
       //printf("%d \n", toplam[j]);
    }
    
    int son[SATIR][SUTUN];
    if(SATIR*SUTUN%SATIR==0 && SATIR*SUTUN%SUTUN==0) {
        
          x=0;
          for(i=0; i<SATIR; i++) {
              for (j=0; j<SUTUN; j++) {
                  son[i][j]=toplam[x];
                  x++;
                  
              }
              
          }
          //printf("\n\nMATRIS\n");
          
          for(i=0; i<SATIR; i++) {
              for(j=0; j<SUTUN; j++) {
                  //printf("%d ", son[i][j]);
                  
              }
              //printf("\n");
          }
    }
    sp= fopen("sonuc.txt", "w");
         for(i=0; i<SATIR; i++) {
             for(j=0; j<SUTUN; j++) {
                 fprintf(sp, "%d ", son[i][j]);
                 
         }fprintf(sp, "\n");
             
         }
    
    return 0;
    
}

