#include<bits/stdc++.h>
using namespace std;
char maze[501][501];
int result[501][501];
bool visited[501][501];
int parentx[501][501];
int parenty[501][501];
int m,n;
int c;
void dfs(int x,int y,int px,int py)
{
    if(visited[x][y])return;
    visited[x][y]=true;
    if(x>m || x<1 || y>n || y<1 || maze[x][y]=='#')
    {
        return;
    }
    if(maze[x][y]=='C')c++;
   // cout<<"(x,y) "<<"("<<x<<","<<y<<") "<<c<<endl;
    parentx[x][y]=px;
    parenty[x][y]=py;
    dfs(x,y+1,px,py);
    dfs(x,y-1,px,py);
    dfs(x+1,y,px,py);
    dfs(x-1,y,px,py);
}
int main()
{
    int t,q,x,y;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++)
    {
       scanf("%d %d %d",&m,&n,&q);
       for(int i=1;i<=m;i++)
       {
           for(int j=1;j<=n;j++)
           {
               scanf(" %c",&maze[i][j]);
               if(maze[i][j]=='#')result[i][j]=0;
           }
       }
       memset(visited,false,sizeof(visited));
      // memset(result,0,sizeof(result));
       for(int i=1;i<=m;i++)
       {
           for(int j=1;j<=n;j++)
           {
               c=0;

                if(!visited[i][j]) {
               // cout<<"i,j"<<i <<" "<<j<<endl;
                parentx[i][j]=i;
                parenty[i][j]=j;
                    dfs(i,j,i,j);
                    result[i][j]=c;
                }
           }
       }

       printf("Case %d:\n",tc);
       while(q--)
       {
           scanf("%d %d",&x,&y);
           printf("%d\n",result[parentx[x][y]][parenty[x][y]]);
       }
    }
    return 0;
}
