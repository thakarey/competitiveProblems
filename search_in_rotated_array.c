#include <stdio.h>
#include <stdlib.h>
int findpivot(int arr[],int l,int r){
     if (l <= r ) {
          int mid = l + (r-l)/2;
          if (arr[mid-1] < arr[mid] && arr[mid+1] < arr[mid]) {
               return mid;
          }else if (arr[mid] < arr[mid-1] && arr[mid+1] > arr[mid]) {
               return mid-1;
          }else if (arr[l] > arr[mid]) {
               return findpivot(arr,l,mid-1);
          }else if(arr[mid] > arr[r]){
               return findpivot(arr,mid+1,r);
          }
     }
     return 0;
}
int binary_search(int arr[],int l,int r,int k){
     // printf("%d,%d\n",l,r );
     if (l <= r) {
          int mid = l + (r-l)/2;
          if (arr[mid] == k) {
               return mid;
          }else if (arr[mid] > k) {
               return binary_search(arr,l,mid-1,k);
          }else{
               return binary_search(arr,mid+1,r,k);
          }
     }
     return -1;
}
int main(int argc, char const *argv[]) {
     int t,n,k;
     scanf("%d",&t );
     // printf("t=%d\n",t );
     while (t--) {
          scanf("%d",&n);
          // printf("n=%d\n",n );
          int arr[n];
          for (int i = 0; i < n; i++) {
               scanf("%d",&arr[i]);
          }
          scanf("%d",&k);
          int x = findpivot(arr,0,n-1);
          // printf("k= %d,x = %d\n",k,x );
          if (arr[x] == k) {
               printf("%d\n",x);
          }
          else if (x== 0) {
               printf("%d\n", binary_search(arr,0,n-1,k));
          }
          else if (arr[0] <= k) {
               printf("%d\n", binary_search(arr,0,x-1,k));
          }else{
               printf("%d\n", binary_search(arr,x+1,n-1,k));
          }
     }
     return 0;
}
