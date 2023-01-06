#include<iostream>
using namespace std;
#define N 1010
int a[N];
int main(void){
    int n, i, s, k=0;
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>a[i];
    i=1;
    while(i<=n){
       if(a[i]==i)
          i++;
       else{
          s=a[a[i]];
          a[a[i]]=a[i];
          a[i]=s;
          k++;
        }
    }
    if(k%2==0)
        cout<<"Even"; //чётная
    else cout<<"Odd";  //нечётная
    return 0;
}
