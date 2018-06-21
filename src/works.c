#include <stdio.h>

int n;
int k;
int A[100000];

int p(int m){
    int work = 0;
    int number = 1;
    for(int i = 0; i < n; i++){
        if(A[i] > m) return 0;
        work += A[i];
        if(work > m){
            number++;
            work = A[i];
        }
    }
    return k >= number;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0;
  ub = 1000000000;
  while(ub-lb > 1){
    int mid = (lb+ub)/2;
    if(p(mid)) ub = mid;
    else lb = mid;
  }
  printf("%d \n", ub);
  return 0;
}