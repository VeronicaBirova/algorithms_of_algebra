#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, m; //n - êîëè÷åñòâî âåðøèí, m - êîëè÷åñòâî ðåáåð
    cin>>n>>m;

    vector<vector<int>> adj(n); //ñîñòàâëÿåì ñïèñîê ñìåæíîñòè äëÿ íàøåãî ãðàôà
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v; //äâå âåðøèíû, êîòîðûå ñîåäèíÿþòñÿ ðåáðîì
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    vector<int> colors(n, -1); //âåêòîð, õðàíÿùèé öâåòà âåðøèí (èçíà÷àëüíî âñå öâåòû ðàâíû -1)
    for(int i=0; i<n; i++) {
        //cout<<"--------i="<<i<<endl;
        vector<bool> used(n, false);
        //âåêòîð, îïèñûâàþùèé, êàêèå öâåòà óæå èñïîëüçîâàíû äëÿ ïîêðàñêè ñìåæíûõ âåðøèí
        //(ìàêñèìàëüíî âîçìîæíîå êîëè÷åñòâî öâåòîâ - n)

        /*cout<<"colors: ";
        for (int k=0;k<n;k++)
            cout<<colors[k]<<" ";
        cout<<endl;*/

        /*cout<<"used: ";
        for(int k=0;k<n;k++)
            cout<<used[k]<<" ";
        cout<<endl;*/

        for(int j:adj[i]){
            if(colors[j]!=-1)
                used[colors[j]]=true;
            /*cout<<"j="<<j<<endl;
            cout<<"used: ";
            for(int k=0;k<n;k++)
                cout<<used[k]<<" ";
            cout<<endl;*/
        }
        int c;
        for(c=0; c<n; c++){
            if(used[c]!=true) //íàõîäèì ïåðâûé íå èñïîëüçîâàííûé äëÿ ñìåæíûõ âåðøèí öâåò
                break;
        }
        colors[i]=c;

        /*cout<<"color "<<i<<" "<<c<<endl;
        cout<<"colors: ";
        for(int k=0;k<n; k++)
            cout<<colors[k]<<" ";  //ó êàæäîãî óçëà - ñâîé öâåò
        cout<<endl;*/
    }

    int num_colors=*max_element(colors.begin(), colors.end())+1;
    //íàõîäèì ìàêñèìàëüíûé öâåò â âåêòîðå öâåòîâ è äîáàâëÿåì 1 (òàê êàê ñ÷åò÷èêè èäóò îò 0)
    cout<<num_colors<<endl;

    return 0;
}
