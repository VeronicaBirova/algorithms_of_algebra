#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

long double distance(long double x1, long double x2, long double y1, long double y2){
    long double a,b;
    a=x1-x2;
    b=y1-y2;
    return sqrt(a*a+b*b);
    //находим расстояние между двумя городами (с координатами (x1,y1),(x2,y2) по т.Пифагора
}

int main(){
    int N, i, j, k, t;
    cin>>N; //количество городов

    long double min, dist, a, b;
    vector<long double> x(N);
    vector<long double> y(N);
    vector<int> cities(N);
    long double route_len=0; //длина пути

    for(i=0; i<N; i++)
        cin>>x[i]>>y[i];

    for(i=0; i<N; i++)
        cities[i]=i;
    //последовательность посещения городов изначально берется из файла с входными данными

    for(i=1; i<N; i++){
        min=100000000;
        k=i;

        for(j=i; j<N; j++){
            //i-1 - номер города, в котором мы находимся, j - номер просматриваемого города
            dist=distance(x[cities[i-1]], x[cities[j]], y[cities[i-1]], y[cities[j]]);
            //просматриваем все оставшиеся города и находим, до какого от текущего города минимальное расстояние
            //(если минимальных путей несколько, берем первый попавшийся)
            if(dist<min){
                min=dist;
                k=j;
            }
        }

        //когда нашли минимальный путь, перемещаем этот город к городу, в котором мы находимся
        t=cities[i];
        cities[i]=cities[k];
        cities[k]=t;
        route_len+=min;
    }

    //возвращаемся в город, из которого стартовали
    route_len+=distance(x[cities[N-1]], x[cities[0]], y[cities[N - 1]], y[cities[0]]);

    /*for(i=0; i<N; i++)
        cout<<cities[i]<<' ';
    cout<<endl;*/

    //избавляемся от экспоненты в выводе (точность - 2 знака после запятой)
    cout<<fixed<<setprecision(2)<<route_len<<endl;

    return 0;
}
