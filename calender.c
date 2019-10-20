#include <stdio.h>
#include <stdlib.h>
int dayofweek( int d, int m, int y);
int checkleapyear(int year);
void print( int day, int i, int year,int no_of_day);

char *week[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat"}; 

char *months[]={
	"Jan",
	"Feb",
	"March",
	"April",
	"May",
	"June",
	"July",
	"Aug",
	"Sept",
	"Oct",
	"Nov",
	"Dec"
};
// To print the calender.
void printcalender( int day,int year){

	int i = 0,l=0,j = 0,flagq = 0,start,leap,flag[20]={ 1},day1,count=1,flag1=1,k=1,col=4,m=0;
	char week_day[10];
	start = day;
	int month_day[12] = {1,1,1,1,1,1,1,1,1,1,1,1},no_of_day[12];
	leap = checkleapyear(year);
	int a[12] = { 1,1,1,1,1,1,1,1,1,1,1,1 };
	while ( col > 12 || col < 1 ){
		printf("Enter col less than 13 and greater than 1 \n");
		scanf("%d",&col);
		//exit(1);
	}
	while(i < 12){
		if( i == 0 || i == 2 || i == 4 || i == 6 || i == 7|| i == 9 || i == 11 ) 
			no_of_day[i] = 	31;
		else if( i == 1 ){
			if(leap == 0)
				no_of_day[i] = 28;			
			else
				no_of_day[i] = 29;
		}
		else 
			no_of_day [i] = 30;
		i++;
	}
	
	while(m <= 11 ){
		start = day;
		count =1;
		flag1 =1;
		k = l + col;
		i = m;
		if ( flagq == 1 )
			break;
		while( l < k && l <= 11)
			printf("\t\t month = %s\t\t%d",months[l++],m);   // prints the name of the months coloumnwise
		printf("\n");
		k = 1;
		// prints the day of the week
		// according to the given col condition
		while( k <= col  && k <= 12-m ) {
			if( i == 0 || i == 2 || i == 4 || i == 6 || i == 7|| i == 9 || i == 11 && k <= col) { 
				for(j = 0; j <= 6; j++) {
					printf("%6s",week[start % 7]);
					start++;
				}
				printf("    ");
				if( k == col ){
					printf("\n");
					break;
				}
				else 
					i++;
				k++;
			}
			else if( i == 1 && k <= col){
				for(j = 0 ; j <= 6; j++){
				 	printf("%6s",week[start%7]);
					start++;
				}
				printf("    ");
				if( k == col ){
					printf("\n");
					break;
				}
				else 
					i++;
				k++;
				
			}
			else if( i == 3 || i == 5 || i == 8 || i == 10  && k <= col){
				for(j = 0 ; j <= 6; j++){
					printf("%6s",week[start % 7]);
					start++;
				}
				printf("    ");
				if( k == col){
					printf("\n");
					break;
				}
				else 
					i++;
				k++;
			}
			//k++;
		}
		printf("\n");
		i = m;
		k = 1;
		int p = 1;
		while( p <= (6 * col )){
			flag1 = 1;
			count = 1;
			i = m + k - 1;
			if ( p <= col ){
				day1 = dayofweek(1,i+1,year);
				flag[i] = day1; 
				if( day-1 == day1)
					flag1=0;
				else
					while( ((day-1) != (day1 % 7)) && day != day1){
						count++;
						day1++;
						flag1 = 0;			
					}
				j = 0;
				while( j++ < (7-count) && flag1 == 0){
					printf("      ");		
				}
				a[i] = 1;
			}
			// prints the date 

			while( 1 ) {
				if( month_day[i] <= no_of_day[i])
					printf("%6d",month_day[i]++);
				else 
					printf("      ");
				if( day - 1 == flag[i] % 7){
					flag[i]++;			
					break;
				}
				flag[i]++;
			}
			printf("    ");
			if( p % col== 0 )
				printf("\n");				
			if( k % col== 0 )
				k = 1;
			else 
				k++;
			p++;
		}
		
		if( m <= 11 )
			if( m + col > 11 ){
				m++;
				flagq = 1;
			}
		else if ( m<= 11 && (m+col) <= 11 ) 
			m = m+ col ;
		printf("\n\n");
		
	}
}		
int checkleapyear(int year){
	if( ((year % 4 == 0 && year % 100) != 0 )||(year % 400 == 0 && year % 100 == 0 && year % 4 == 0) )
		return 1;
	else
		return 0;
}
// To get the day of week by date
// retrurn zero (0) for sunday then go on
int dayofweek( int d, int m, int y){

    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    
    y -= m < 3;
    
    return ( y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
}
int main( ) {
	int  b[10];
	int year,flag,i=0;
	printf("Enter Your Birth Date?\n");
	while(i <= 2){
		scanf("%d",&b[i]);
		if( i != 2 )
			getchar();
		i++;
	}
	flag = dayofweek(b[0],b[1],b[2]);	
	printf("Enter the year to print the calender \n ");
	scanf("%d",&year );
	printcalender(flag,year);
}
