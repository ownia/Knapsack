#include<stdio.h>

typedef struct {
  int index;
  int data;
}datatype;

int Knapsack(int T,int n,datatype weight[]) {
  int lensize = n;
  int top = 0;
  int i,j;
  datatype stack[lensize];
  int S = T;

  for(i = 0;i < lensize;i++) {
    if(weight[i].data <= S) {
      stack[top] = weight[i];
      S = S - weight[top].data;
      top++;
      i++;
      break;
    }
  }

  j = i;
  while(S >= 0) {
    if(S == 0) {
      for(j = 0;j < top;j++) {
        printf("%d  ", stack[j].data);
      }
      printf("\n");
      return 1;
    } else {
      for(;j < lensize;j++) {
        if(weight[j].data<=S) {
          stack[top] = weight[j];
          top++;
          S = S-weight[j].data;
        }
      }
      if(S > 0) {
        top--;
        j = stack[top].index+1;
        S = S + stack[top].data;
      }
    }
  }
  if(S != 0) {
    printf("no solution\n");
  }
}

int main() {
  int T,n,i;
  printf("input T\n");
  scanf("%d", &T);
  printf("input n\n");
  scanf("%d", &n);
  int w[n];
  for (i = 0;i < n;i++) {
    printf("input %dth w\n", i + 1);
    scanf("%d", &w[i]);
  }
  datatype weight[n];
  for(i = 0;i < n;i++) {
    weight[i].index = i;
    weight[i].data = w[i];
  }
  Knapsack(T,n,weight);
}
