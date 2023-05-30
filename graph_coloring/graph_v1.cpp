#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, m; //n - ���������� ������, m - ���������� �����
    cin>>n>>m;

    vector<vector<int>> adj(n); //���������� ������ ��������� ��� ������ �����
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v; //��� �������, ������� ����������� ������
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    vector<int> colors(n, -1); //������, �������� ����� ������ (���������� ��� ����� ����� -1)
    for(int i=0; i<n; i++) {
        //cout<<"--------i="<<i<<endl;
        vector<bool> used(n, false);
        //������, �����������, ����� ����� ��� ������������ ��� �������� ������� ������
        //(����������� ��������� ���������� ������ - n)

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
            if(used[c]!=true) //������� ������ �� �������������� ��� ������� ������ ����
                break;
        }
        colors[i]=c;

        /*cout<<"color "<<i<<" "<<c<<endl;
        cout<<"colors: ";
        for(int k=0;k<n; k++)
            cout<<colors[k]<<" ";  //� ������� ���� - ���� ����
        cout<<endl;*/
    }

    int num_colors=*max_element(colors.begin(), colors.end())+1;
    //������� ������������ ���� � ������� ������ � ��������� 1 (��� ��� �������� ���� �� 0)
    cout<<num_colors<<endl;

    return 0;
}
