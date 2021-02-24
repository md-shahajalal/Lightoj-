#include<bits/stdc++.h>
using namespace std;
map<string,int>mp;
vector<int>v[10001];
int indeg[10001];
int topological_sort(int s)
{
    int val=0;
    queue<int>q;
    for(int i=1;i<=s;i++) {
        if(!indeg[i]) {
            q.push(i);
            val++;
        }
    }
    while(!q.empty()) {
        int f=q.front();
        q.pop();
        for(int i=0;i<v[f].size();i++) {
            indeg[v[f][i]]--;
            if(!indeg[v[f][i]]) {
                    val++;
                q.push(v[f][i]);
            }
        }
    }
    return val;
}
int main()
{
    string str,str1;
    int t,m,c;
    scanf("%d",&t);
    for(int i=1;i<=t;i++) {
        cin>>m;
        c=0;
    while(m--) {
        cin>>str>>str1;
        if(!mp[str])mp[str]=++c;
        if(!mp[str1])mp[str1]=++c;
        v[mp[str]].push_back(mp[str1]);
        indeg[mp[str1]]++;
    }
    int x=topological_sort(c);
    if(x==c)cout<<"Case "<<i<<": "<<"Yes"<<endl;
    else  cout<<"Case "<<i<<": "<<"No"<<endl;
    mp.clear();
    memset(indeg,0,sizeof(indeg));
    for(int j=0;j<=c;j++)v[j].clear();
    }
    return 0;
}

