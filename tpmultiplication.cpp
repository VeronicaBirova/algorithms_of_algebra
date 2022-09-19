#include <iostream>
using namespace std;
#define N 20010
int a[N], ra[N], b[N], c[N];
int main(void){
    int n, i, k;
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>a[i];
    for(i=1;i<=n;i++)
        ra[a[i]]=i;

    /*for(i=1;i<=n;i++)
        cin>>b[i];
    for(i=1;i<=n;i++){
        k=b[i];
        c[i]=a[k];
    }*/

    for(i=1;i<=n;i++)
        cout<<ra[i]<<" "; //обратная перестановка для перестановки a
    cout<<endl;
    /*for(i=1;i<=n;i++)
        cout<<c[i]<<" "; //результат перемножения перестановок a и b*/

    return 0;
}

