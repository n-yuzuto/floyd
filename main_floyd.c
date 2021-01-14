#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "common.h"

int w[N][N] = {
  { 0, M,  M, 10, 20, M},
  {15, 0, 34, M,  13, M},
  { M, M,  0, M,  M, 6},
  { M, M,  M, 0,  10, M},
  { 30, M, 17, M,  0, 12},
  { 40, M,  8, M,  M, 0}};

               
int d[N][N];
int p[N][N];
int STACK[N];

void push(int* STACK,int d);
int pop(int* STACK);
void Floyd();
void shortest_path(int m,int n);
void show_result(int p);

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: ./main <node ID>\n");
    return 1;
  }

  int p = atoi(argv[1]);
  if (p < 0 || N <= p) {
    fprintf(stderr, "Node ID %d is out of range: [0, %d].\n", p, N);
    return 1;
  }

  Floyd();
  show_result(p);
  
  return 0;
}