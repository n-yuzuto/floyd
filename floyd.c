#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>  // stdbool.hヘッダーファイルをインクルード
#include <limits.h>
#include "common.h"

extern int w[N][N];                  
extern int d[N][N];
extern int p[N][N];
extern int STACK[N];


int top=0;
void Floyd(){
    int i,k,j;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            d[i][j]=w[i][j];
            p[i][j]=i;
        }
    }
    for(k=0;k<N;k++){
        for(i=0;i<N;i++){
            for(j=0;j<N;j++){
                if(i==j){
                    d[i][j]=0;
                    p[i][j]=i;
                }
                else if(d[i][k]!=M && d[k][j]!=M){
                    int can=d[i][k]+d[k][j];
                    if(can<d[i][j]||d[i][j]==M){
                        d[i][j]=can;
                        p[i][j]=p[k][j];
                    }
                }
            }
        }
    } 
}

int push(int* STACK,int d){
    if(top > N-1){
        printf("Overflow stack");
        return EXIT_FAILURE;
    }
    STACK[top]=d;
    top+=1;
}


int pop(int* STACK){
    if(top == 0){
        printf("Underflow stack");
        return EXIT_FAILURE;
    }
    top-=1;
    return STACK[top];
}



void shortest_path(int m,int n){
    if(d[m][n]==M){
        printf("there is no path.\n");
    }
    else{
        int x;
        x = n;
        push(STACK,x);
        while(x != m){
            x = p[m][x];
            push(STACK,x);
        }
        while(top > 1){
            printf("%d -> ",pop(STACK));
        }
        printf("%d\n",pop(STACK));
    }
}

void show_result(int p){
    int i,j;
    if (d[p][0] == M) printf("[M ");
    else printf("[%d ",d[p][0]);
    for(j=1;j<N-1;j++){
        if (d[p][j] == M) printf("M ");   
        else printf("%d ",d[p][j]);
    }
    if (d[p][N-1] == M) printf("M]\n");     
    else printf("%d]\n",d[p][N-1]);
    for(i=0;i<N;i++){
        printf("%d:",i);
        shortest_path(p,i);
    }
}

