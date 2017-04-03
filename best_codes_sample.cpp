//----------------------------------------------------------------------------\\

// Intro- Multiply and add efficiently.
#include <stdio.h>

main(){
    printf("%d %d", add(4, 5), multiply(4, 5));
}
 
int multiply(int a, int b){
    return b==0?0:add(((b&1) ==1?a:0),multiply(a<<1,b>>1));
}

int add(int a, int b){
    return b==0?a:add(a^b, (a&b)<<1);
}






//----------------------------------------------------------------------------\\

// Intro- Prints current time in text-art.

main(_){_^448&&main(-~_);putchar(--_%64?32|-~7[__TIME__-_/8%8][">'txiZ^(~z?"-48]>>";;;====~$::199"[_*2&8|_/64]/(_&2?1:8)%8&1:10);}



//----------------------------------------------------------------------------\\

// Intro- Computes day of the week for given date.

#include <stdio.h>

main(){
    printf("%d %d %d", dow(2011, 7, 19), dow(1993, 5, 23), dow(2016, 12, 16)); //output- 2 0 5
}

int dow(int y, int m, int d) {
    return ((y-=m<3)+y/4-y/100+y/400+" bed=pen+mad."[m]+d)%7;
}


//----------------------------------------------------------------------------\\

// Strange one-liners that swaps value of two variables.
 
#include <stdio.h>

main(){
    int a=5, b=7;

    a-=b=(a+=b)-b;
    printf("%d %d\n", a, b);
 
    a=(int[]){b, b=a}[0];
    printf("%d %d\n", a, b);
    
    a^=b^=a^=b;
    printf("%d %d\n", a, b);
    
    a=b+a-(b=a);
    printf("%d %d\n", a, b);
}


//----------------------------------------------------------------------------\\

// Intro- Calculates the first 15000 digits of PI.
 
a[52514],b,c=52514,d,e,f=1e4,g,h;main(){for(;b=c-=14;h=printf("%04d",e+d/f))for(e=d%=f;g=--b*2;d/=g)d=d*b+f*(h?a[b]:f/5),a[b]=d%--g;}


//----------------------------------------------------------------------------\\

// Intro- Shortest C code that prints itself.
 
main(a){printf(a="main(a){printf(a=%c%s%c,34,a,34);}",34,a,34);}



//----------------------------------------------------------------------------\\

// Intro- Keeps printing prime number (theoretically) forever. Number of characters- 80.
//      Can be made even shorter (69 bytes)- main($,_){for(;$++;)for(_=2;_&(_<$?_:!printf("%i|",$));_=$%_?_+1:0);}

main($,_){for($=3;;$+=2)for(_=3;_&(_<=sqrt($)?_:!printf("%i|",$));_=$%_?_+2:0);}




//----------------------------------------------------------------------------\\






//----------------------------------------------------------------------------\\






//----------------------------------------------------------------------------\\

