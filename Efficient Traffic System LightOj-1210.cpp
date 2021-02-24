
#include<bits/stdc++.h>
using namespace std;
stack<int>st;
int scc[20005];
void dfs(int s,vector<int>adj[],bool visited[])
{
     visited[s]=true;
    for(int i=0;i<adj[s].size();i++) {
        if(!visited[adj[s][i]]) {
          //  visited[adj[s][i]]=true;
            dfs(adj[s][i],adj,visited);
        }
    }
    st.push(s);
}
void dfs1(int s,vector<int>adj[],bool visited[],int c)
{
     visited[s]=true;
     scc[s]=c;
    for(int i=0;i<adj[s].size();i++) {
        if(!visited[adj[s][i]]) {
            //visited[adj[s][i]]=true;
            dfs1(adj[s][i],adj,visited,c);
        }
    }
}
void dfs2(int s,vector<int>adj[],bool visited[],int indeg[],int outdeg[])
{
    visited[s]=true;
    for(int i=0;i<adj[s].size();i++) {
        if(scc[s]!=scc[adj[s][i]]) {
            indeg[scc[adj[s][i]]]++;
            outdeg[scc[s]]++;
        }
        if(!visited[adj[s][i]]) {
            dfs2(adj[s][i],adj,visited,indeg,outdeg);
        }
    }
}
int main()
{
    int t,n,m,u,v;
    cin>>t;
    for(int i=1;i<=t;i++) {
        scanf("%d %d",&n,&m);
        vector<int>adj[n+5];
        vector<int>rev_adj[n+5];
        bool visited[n+5];
        for(int j=1;j<=m;j++) {
            scanf("%d %d",&u,&v);
            adj[u].push_back(v);
            rev_adj[v].push_back(u);
        }
        memset(visited,false,sizeof(visited));
        for(int j=1;j<=n;j++) {
            if(!visited[j])dfs(j,adj,visited);
        }
        memset(visited,false,sizeof(visited));
        int c=0;
        while(!st.empty()) {
             int t=st.top();
             //cout<<"t "<<t<<endl;
             st.pop();
             if(!visited[t]) {
                    c++;
             //scc[c].push_back(t);
                dfs1(t,rev_adj,visited,c);
             }
        }
        int  indeg[n+5];
        int outdeg[n+5];
        memset(indeg,0,sizeof(indeg));
        memset(outdeg,0,sizeof(outdeg));
        memset(visited,false,sizeof(visited));
        for(int j=1;j<=n;j++) {
            if(!visited[j])dfs2(j,adj,visited,indeg,outdeg);
        }
       // cout<<endl<<c<<endl;
        int in=0;
        int out=0;

        for(int j=1;j<=c && c>1;j++) {
            if(!indeg[j])in++;
            if(!outdeg[j])out++;
        }
        printf("Case %d: %d\n",i,max(in,out));
    }
    return 0;
}
