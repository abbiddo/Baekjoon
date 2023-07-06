#include<stdio.h>
int main(){
    int a,b,c,sum;
    char str[80];
    scanf("%d ",&a);
    for(int i=0;i<a;i++){
        scanf("%s",&str);
        c=0;
        sum=0;
        for(int j=0; str[j]!='\0'; j++){
        	if (str[j]=='O'){
        		c++;
        		sum+=c;
			}
			else c=0;	
        }
        printf("%d\n",sum);
    }
}