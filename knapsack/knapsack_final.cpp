#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

long W; //ðàçìåð ðþêçàêà
vector<long> c; //ñòîèìîñòü êàæäîãî ïðåäìåòà
vector<long> v; //âåñ êàæäîãî ïðåäìåòà

int load_data(char* fn){
    int n;
    long ctemp, vtemp;
    ifstream fin(fn);
    fin>>n>>W;
    for (int i=0; i<n; i++){
        fin>>ctemp>>vtemp;
        c.push_back(ctemp);
        v.push_back(vtemp);
    }

    return 0;
}

//âîçâðàùàåò ìàêñèìàëüíóþ ñòîèìîñòü ïðåäìåòîâ, êîòîðûå ìîãóò áûòü óëîæåíû â ðþêçàê ðàçìåðîì W
int knapsack(int W, const vector<long>& v, const vector<long>& c){
    int n = v.size();
    vector<vector<long>> dp(n + 1, vector<long>(W + 1, 0));

    for (int i=1; i<=n; ++i){
        for (int w=0; w<=W; ++w){
            if (v[i-1]<=w)
                dp[i][w]=max(dp[i-1][w], dp[i-1][w-v[i-1]]+c[i-1]);
            else
                dp[i][w]=dp[i-1][w];
        }
    }

    /*îòëàäî÷íàÿ ïå÷àòü
    for(int i=1; i<=n; ++i){
        cout << endl;
        for(int j=0; j<=W; ++j)
            cout << dp[i][j]<<" ";

    }*/
    cout << endl;

    return dp[n][W];
}

int main(int argc, char** argv){
    setlocale(LC_ALL, "Russian");
    char* filename=argv[1];
    load_data(filename);

    long maxValue=knapsack(W, v, c);
    cout<<"Ìàêñèìàëüíàÿ ñòîèìîñòü ïðåäìåòîâ: "<<maxValue<<endl;
    return 0;
}
