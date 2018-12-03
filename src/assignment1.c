#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int monte_calro(int n, double *pi){
  if(n<1 || pi==NULL) return -1;
  double c = 0.0;
  double x, y;
  srand((unsigned int)time(NULL));
  for(int i=1; i<=n; i++){
    x = (double) rand() / (double) RAND_MAX;
    y = (double) rand() / (double) RAND_MAX;
    if(x*x + y*y <= 1) c++;
  }
  *pi = c * 4 / n;
  return 0;
}

int main(){
  double pi = 0.0;
  int n = 1;
  for(int i=1; i<=4; i++){
    n *= 100;
    monte_calro(n, &pi);
    printf("for n=%d, pi=%f\n", n, pi);
  }
  return 0;
}
