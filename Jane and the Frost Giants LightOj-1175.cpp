#include<bits/stdc++.h>
using namespace std;
int r,c;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
char maze[201][201];
int dis[201][201];
bool visited[201][201];
int level[201][201];
int give_ans(int x,int y)
{
    visited[x][y]=true;
    queue<pair<int,int> >q;
    q.push(make_pair(x,y));
    level[x][y]=0;
    while(!q.empty())
    {
         int f1=q.front().first;
         int f2=q.front().second;
         q.pop();
         int fx;
         int fy;
         if(f1==1 || f1==r || f2==1 || f2==c)return level[f1][f2];
         for(int i=0;i<4;i++)
         {
             fx=f1+dx[i];
             fy=f2+dy[i];
             if(fx>=1 && fx<=r && fy>=1 && fy<=c && maze[fx][fy]!='#' && !visited[fx][fy])
             {
                 level[fx][fy]=level[f1][f2]+1;

                 if(level[fx][fy]<dis[fx][fy]){
                    q.push(make_pair(fx,fy));
                    visited[fx][fy]=true;
                 }
             }
         }
    }
    return -1;
}
void bfs(int x,int y)
{
     visited[x][y]=true;
     queue<pair<int,int> >q;
     q.push(make_pair(x,y));
     while(!q.empty())
     {
         int f1=q.front().first;
         int f2=q.front().second;
         q.pop();
         int fx;
         int fy;
         for(int i=0;i<4;i++)
         {
             fx=f1+dx[i];
             fy=f2+dy[i];
             if(fx>=1 && fx<=r && fy>=1 && fy<=c && maze[fx][fy]!='#' && !visited[fx][fy])
             {
                  if(min(dis[fx][fy],1+dis[f1][f2])<dis[fx][fy]) {
                 q.push(make_pair(fx,fy));
                 dis[fx][fy]=min(dis[fx][fy],1+dis[f1][f2]);
                 visited[fx][fy]=true;
                 }
             }
             }
         }
     }
int main()
{
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++)
    {
        scanf("%d %d",&r,&c);
        int x, y;
        for(int i=1;i<=r;i++)
        {
            for(int j=1;j<=c;j++){
                scanf(" %c",&maze[i][j]);
                if(maze[i][j]=='J')
                {
                    x=i;
                    y=j;
                }
            }
        }
        for(int i=1;i<=r;i++)
        {
            for(int j=1;j<=c;j++){
               dis[i][j]=INT_MAX;
              }
        }
        for(int i=1;i<=r;i++)
        {
            for(int j=1;j<=c;j++){
              if(maze[i][j]=='F'){
                memset(visited,false,sizeof(visited));
                dis[i][j]=0;
                bfs(i,j);
              //  cout<<"here"<<endl;
              }
            }
        }
       /* for(int i=1;i<=r;i++)
        {
            for(int j=1;j<=c;j++){
              cout<<dis[i][j]<<" ";
            }
            cout<<endl;
        }
        */
    memset(visited,false,sizeof(visited));
    int ans= give_ans(x,y);

    if(ans==-1) printf("Case %d: IMPOSSIBLE\n",tc);
    else printf("Case %d: %d\n",tc,ans+1);
    }
    return 0;
}
