#include<bits/stdc++.h>
using namespace std;
vector<int>v[10001];
stack<int>st;
int visited[10001];
void dfs1(int s)
{
    visited[s]=1;
    for(int i=0;i<v[s].size();i++) {
        if(!visited[v[s][i]]) {
            dfs1(v[s][i]);
        }
    }
    st.push(s);
}
void dfs2(int s)
{
    visited[s]=1;
    for(int i=0;i<v[s].size();i++) {
        if(!visited[v[s][i]]) {
            dfs2(v[s][i]);
        }
    }
}
int main()
{
    int t,n,e,a,b,c;
    scanf("%d",&t);
    for(int i=1;i<=t;i++) {
            c=0;
        scanf("%d %d",&n,&e);
        for(int j=1;j<=e;j++) {
            scanf("%d %d",&a,&b);
            v[a].push_back(b);
        }
         memset(visited,0,sizeof(visited));
        for(int i=1;i<=n;i++) {
            if(!visited[i]) {
                dfs1(i);
            }
        }
         memset(visited,0,sizeof(visited));
        while(!st.empty()) {
            int val=st.top();
            st.pop();
            if(!visited[val]) {
                    c++;
                dfs2(val);
            }
        }
    cout<<"Case "<<i<<": "<<c<<endl;
    for(int j=0;j<=n;j++)v[j].clear();
    }
    return 0;
}

