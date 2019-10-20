#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SET_ZERO memset(carr,0,sizeof(carr))
int main(int argc, char const *argv[]) {
     int t,carr[26];
     int i=0,j=0,k=0,count=0,max = -1,flag=1,index;
     char arr[10000];
     scanf("%d\n",&t );
     while (t--) {
          scanf("%s", arr);
          i=0;count=0;flag=1;max=-1;
          SET_ZERO;
          while (arr[i] != '\0') {
               if (carr[arr[i] -'a'] == 0) {
                    carr[arr[i] -'a']++;
                    if (flag) {
                         index = i;
                    }flag=0;
                    count++;
                    i++;
               }else{
                    SET_ZERO;
                    flag=1;
                    if (max < count) {
                         max = count;
                    }
                    count = 0;
                    i = index +1;
               }

          }
          if (count > max)
               printf("%d\n",count );
          else
               printf("%d\n",max );
     }
     return 0;
}
