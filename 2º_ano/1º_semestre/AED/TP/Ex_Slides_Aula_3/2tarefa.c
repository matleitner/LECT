#include <stdio.h>

int exemplo1(){
    int num = 0;
    for(int k =2; k<=9;k++){
        num++;
    }
    return num;
}

int exemplo2(int a, int b){
    int num = 0;
    for(int k= a; k<=b; k++){
        num +=5;
    }
    return num;
}

int exemplo3(int a, int b){
    int num = 0;
    for(int i= a; i<=b; i++){
        num +=i;
    }
    return num;
}

int exemplo4(int n){
    int num = 0;
    for(int i= 1; i<=n; i++){
        num +=(i*5);
    }
    return num;
}
int exemplo5(int n){
    int num = 0;
    for(int i= 1; i<=n; i++){
        num +=((i*i)*5);
    }
    return num;
}

int exemplo6(int n){
    int num = 0;
    for(int i= 1; i<=n; i++){
        for(int j= 1; j<=n;j++) {num +=15;}
    }
    return num;
}

int exemplo7(int n){
    int num = 0;
    for(int i= 1; i<=n; i++){
        for(int j= 1; j<=n;j++) {num +=j;}
    }
    return num;
}

int exemplo8(int n){
    int num = 0;
    for(int i= 1; i<=n; i++){
        for(int j= 1; j<=i;j++) {num +=(j*6);}
    }
    return num;
}

int main(void){

    int num1 = exemplo1();
    int num2 = exemplo2(1,10);

    int num3 = exemplo3(1,10);
    int num4 = exemplo4(10);

    int num5 = exemplo5(10);
    int num6 = exemplo6(10);
    int num7 = exemplo7(10);
    int num8 = exemplo8(10);

    printf("%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", num1,num2,num3,num4,num5,num6,num7,num8);


}