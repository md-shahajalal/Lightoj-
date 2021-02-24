#include<bits/stdc++.h>
using namespace std;
 char ch;
 vector<char>v[20];
int visited[20][20];
int di[]={1,-1,0,0};
int dj[]={0,0,1,-1};
void bfs(int x,int y,int h,int w,int cas)
{
    memset(visited,0,sizeof(visited));
    queue<pair<int,int> >q;
    q.push(make_pair(x,y));
    visited[x][y]=1;
   int c=1,I,J;
   while(!q.empty()){
    int m=q.front().first;
    int n=q.front().second;
    q.pop();
    for(int i=0;i<4;i++) {
        I=m+di[i];
        J=n+dj[i];
        if(I>=0 && I<h && J>=0 && J<w) {
            if(!visited[I][J]) {
                visited[I][J]=1;
                if(v[I][J]=='.') {
                    q.push(make_pair(I,J));
                    c++;
                }
            }
        }
    }
   }
   cout<<"Case "<<cas<<": "<<c<<endl;
}
int main()
{
    int t,w,h,posi,posj;
    char ch;
    scanf("%d",&t);
    for(int i=1;i<=t;i++) {
        scanf("%d %d",&w,&h);
        for(int j=0;j<h;j++) {
                for(int k=0;k<w;k++) {
            cin>>ch;
            v[j].push_back(ch);
            if(ch=='@'){
                posi=j;
                posj=k;
            }
        }
        }
        bfs(posi,posj,h,w,i);
        for(int b=0;b<20;b++) {
            v[b].clear();
    }
    }
    return 0;
}

