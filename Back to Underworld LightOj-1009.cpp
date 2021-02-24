
#include<bits/stdc++.h>
using namespace std;
#define ma 20001
int color[ma];
 vector<int>v[ma];
 int visited[ma];
int bfs(int s)
{
    int x=1,y=0,k=0;
    queue<int>q;
    q.push(s);
    color[s]=1;
    visited[s]=1;
    while(!q.empty())
    {
        int t=q.front();
        q.pop();
        for(int i=0;i<v[t].size();i++)
        {
            k=1;
            if(!visited[v[t][i]]) {
                    visited[v[t][i]]=1;
                    q.push(v[t][i]);
            color[v[t][i]]=3-color[t];
            if(color[v[t][i]]==1)x++;
            else if(color[v[t][i]]==2)y++;
        }
        }
    }
    if(!k)return 0;
   return max(x,y);
}
int main()
{
    int t,n,a,b,sum,val;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        sum=0;
        val=0;
        scanf("%d",&n);
        for(int j=0;j<n;j++) {
            scanf("%d %d",&a,&b);
            v[a].push_back(b);
            v[b].push_back(a);
            val=max(val,max(a,b));
        }
        for(int j=1;j<=val;j++) {
                if(!visited[j]) {
                        int x=bfs(j);
                        sum+=x;
                }
        }
        cout<<"Case "<<i<<": "<<sum<<endl;
        for(int j=1;j<=val;j++)v[j].clear();
         memset(visited,0,sizeof(visited));
    }
    return 0;
}
