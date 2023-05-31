#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <random>
#include <algorithm>

using namespace std;

#define START_LEN 29998.13//минимальный путь, полученный простым алгоритмом, который мы хотим уменьшить
#define ITER 100000 //количество итераций, на протяжении которых мы "перемешиваем" содержание и ищем лучший минимальный путь

long double distance(long double x1, long double x2, long double y1, long double y2){
    long double a,b;
    a=x1-x2;
    b=y1-y2;
    return sqrt(a*a+b*b);
}

int main(){
    unsigned seed=std::chrono::system_clock::now().time_since_epoch().count();

    int N, i, j, k, t, g;
    cin>>N;

    long double min, dist, a, b, sol;
    vector<long double> x(N);
    vector<long double> y(N);
    vector<int> cities(N);
    long double route_len, global_route_len=100000000;

    for(i=0; i<N; i++){
        cin>>x[i]>>y[i];
        //cout<<x[i]<<' '<<y[i]<<' '<<endl;
    }

    for(i=0; i<N; i++)
        cities[i]=i;

    for(g=0; g<ITER; g++){
        route_len=0;
        shuffle (cities.begin(), cities.end(), default_random_engine(seed));

        for(i=1; i<N; i++){
            min=100000000;
            k=i;

            for(j=i; j<N; j++){
                dist=distance(x[cities[i - 1]], x[cities[j]], y[cities[i - 1]], y[cities[j]]);
                if(dist<min){
                    min=dist;
                    k=j;
                }
            }

            t=cities[i];
            cities[i]=cities[k];
            cities[k]=t;
            route_len+=min;
        }

        route_len+=distance(x[cities[N-1]], x[cities[0]], y[cities[N - 1]], y[cities[0]]);

        if((route_len<START_LEN)&&(route_len<global_route_len))
            cout<<fixed<<setprecision(2)<<route_len<<endl;
        if (route_len<global_route_len)
            global_route_len=route_len;

    }
    /*for(i=0; i<N; i++)
        cout<<cities[i]<<' ';
    cout<<endl;*/

    cout<<fixed<<setprecision(2)<<global_route_len<<endl;

    return 0;
}
