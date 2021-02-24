
#include<bits/stdc++.h>
using namespace std;

int bfs(int s,int money[],vector<int>adj[],bool visited[])
{
    int c=1;
    int sum=money[s];
    // for(int i=1;i<=n;i++)cout<<money[i]<<" ";
    //cout<<adj[4].size()<<endl;

    queue<int>q;
    q.push(s);
    visited[s]=true;
    while(!q.empty()) {
        int f=q.front();
        q.pop();
        for(int i=0;i<adj[f].size();i++) {
            if(!visited[adj[f][i]]) {
                    c++;
                visited[adj[f][i]]=true;
                sum+=money[adj[f][i]];
            q.push(adj[f][i]);
            }
        }
    }
    if(sum%c) {
        return -1;
    }
    return (sum/c);
}
int main()
{
    int t,m,x,y,n;
    cin>>t;
    for(int i=1;i<=t;i++) {


        scanf("%d %d",&n,&m);


      vector<int>adj[n+5];
     int money[n+5];
     bool visited[n+5];


        for(int j=1;j<=n;j++) {
            scanf("%d",&money[j]);
        }
        for(int j=1;j<=m;j++) {
            scanf("%d %d",&x,&y);
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        memset(visited,false,sizeof(visited));

        int x=bfs(1,money,adj,visited);
        if(x==-1) {
             printf("Case %d: No\n",i);
        }
        else {
                int ind=0;
       for(int j=2;j<=n;j++) {
                if(!visited[j]) {
            int val=bfs(j,money,adj,visited);
            if(val!=x) {
                printf("Case %d: No\n",i);
                ind=1;
                 break;
            }
                }
        }
             if(!ind)printf("Case %d: Yes\n",i);

    }
    }
    return 0;
}
