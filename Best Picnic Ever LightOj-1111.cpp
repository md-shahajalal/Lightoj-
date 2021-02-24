#include<bits/stdc++.h>
using namespace std;
bool visited[1001];
int bfs(vector<int>adj[],int x)
{
    memset(visited,false,sizeof(visited));
    queue<int>q;
    q.push(x);
    visited[x]=true;
    int counter=1;
    while(!q.empty()) {
        int f=q.front();
        q.pop();
        for(int i=0;i<adj[f].size();i++) {
                if(!visited[adj[f][i]]) {
            q.push(adj[f][i]);
            visited[adj[f][i]]=true;
            counter++;
                }
        }
    }
    return counter;
}
int main()
{
    int t,k,n,m,a,b;
    scanf("%d",&t);
    int arr[100];
    for(int i=1;i<=t;i++) {
        vector<int>adj[1001];
        scanf("%d %d %d",&k,&n,&m);
        for(int j=0;j<k;j++)scanf("%d",&arr[j]);
        for(int j=0;j<m;j++) {
            scanf("%d %d",&a,&b);
            adj[a].push_back(b);
        }
        int c=INT_MAX;
        for(int j=0;j<k;j++) {
            c=min(c,bfs(adj,arr[j]));
        }
        printf("Case %d: %d\n",i,c);
    }
    return 0;
}

