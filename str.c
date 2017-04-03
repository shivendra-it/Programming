#include <stdio.h>

int main() {
    char arr[2005];
    int t;
    scanf("%d",&t);
   while(t--){
    scanf("%s",arr);
    int count =0;
    char *c = &arr[0];
    while(*c != '\0'){
        *c++;
        if(*c == '1'){
            while(*c == '0'){
                *c++;
            }
            if(*c == 1){
                count++;
            }
        }
        *c++;
    }
    printf("%d",count);
}
	//code
	return 0;
}