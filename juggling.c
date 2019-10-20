

Skip to content
Using Gmail with screen readers
Enable desktop notifications for Gmail.
   OK  No thanks

1 of 2,184
(no subject)
Inbox
x

Pranav Thakare
Attachments
3:07 PM (8 minutes ago)
to me


Attachments area

#include <stdio.h>
int gcd(int a,int b){
     if (b == 0) {
          return a;
     }
     return gcd(b,a%b);
}
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
}
void leftRotate(int arr[], int d, int n)
{
    int i, j, k, temp;
    int g_c_d = gcd(d, n);
    for (i = 0; i < g_c_d; i++) {
        /* move i-th values of blocks */
        temp = arr[i];
        j = i;
        while (1) {
            k = j + d;
            if (k >= n)
                k = k - n;
            if (k == i)
                break;
            arr[j] = arr[k];
            j = k;
        }
        arr[j] = temp;
    }
}
int main(int argc, char const *argv[]) {
     int t,n,i,j,tmp,g_c_d,l,k;
     scanf("%d",&t );
     while (t--) {
          scanf("%d",&n );
          int arr[n];
          while (i < n) {
               scanf("%d",&arr[i++] );
          }
          scanf("%d",&k );
          leftRotate(arr,k,n);
          printArray(arr,n);
     //      g_c_d = gcd(n,k);
     //      for (i = 0; i < g_c_d; i++) {
     //           tmp = arr[i];
     //           l = i;
     //           if (k == 0) {
     //                break;
     //           }
     //           while (1) {
     //                j = i+k;
     //                if (j > n-1) {
     //                     break;
     //                }
     //                arr[l] = arr[j];
     //                l = j;
     //           }
     //           arr[j] = tmp;
     //      }
     //      for (i = 0; i < n; i++) {
     //           printf("%d,",arr[i]);
     //      }
     //
     }
     return 0;
}
juggling_rotaion_array.c
Displaying juggling_rotaion_array.c.
