#include<iostream>
using namespace std;
int lastprime=1;
int isprime(int n){
    int k=2;
    while((k*k)<=n){
        if((n%k)==0)
            return 0;
        k++;
    }
    return 1;
}

int nextprime(void){
    int k=lastprime+1;
    while(lastprime!=k){
        if(k>32676)
           k=2;
        if(isprime(k)==1){
            lastprime=k;
            return k;
        }
        k++;
    }
}
int main(void){
    int t;
    t=nextprime();
    while(t<=128){
        printf("%d, ", t);
        t=nextprime();
    }
    return 0;
}
