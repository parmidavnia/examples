#include <stdio.h>

// simple branch

int func1(int a, int b){
    int res = 0;
    if( a < b ){
        res = a * b;
    } else {
        res = a/b;
    }
    return res;
}

int main(){
    // if a<b a*b, else a/b
    int a = 10;
    int b = 5;
    int res = func1(a,b);
    return 0;
}