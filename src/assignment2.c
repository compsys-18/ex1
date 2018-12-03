#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void sort_int_array(int *ary, int ary_size){
  /*
  int i, j, tmp;
  for(i=0; i<ary_size-1; i++){
    for(j=1; j<ary_size-i; j++){
      if(*(ary+j-1) > *(ary+j)){
        tmp = *(ary+j);
        *(ary+j) = *(ary+j-1);
        *(ary+j-1) = tmp;
      }
    }
  }
  return;
  */
  int i, j, pivot, tmp;
  pivot = *ary;
  if(ary_size<=1 || ary==NULL) return;
  for(i=j=1; i<ary_size; i++){
    if(*(ary+i) <= pivot){
      tmp = *(ary+j);
      *(ary+j) = *(ary+i);
      *(ary+i) = tmp;
      j++;
    }
  }
  *ary = *(ary+j-1);
  *(ary+j-1) = pivot;
  sort_int_array(ary, j-1);
  sort_int_array(ary+j, ary_size-j);
  return;
}

int main(){
  int n = 100;
  int *ary = malloc(sizeof(int)*n);
  printf("before\n");
  srand((unsigned int)time(NULL));
  for(int i=0; i<n; i++){
    *(ary+i) = rand() % 10000;
    printf("%d ", *(ary+i));
  }
  printf("\n");
  sort_int_array(ary, n);
  printf("after\n");
  for(int i=0; i<n; i++) printf("%d ", *(ary+i));
  printf("\n");
  free(ary);
  return 0;
}
