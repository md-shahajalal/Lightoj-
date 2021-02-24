#include<bits/stdc++.h>
using namespace std;
vector<char>v[21];
int di[]={1,-1,0,0};
int dj[]={0,0,1,-1};
int r,c;
int bfs(int x,int y)
{
    int level[21][21];
    queue<pair<int,int> >q;
    int visited[21][21],val;
    memset(visited,0,sizeof(visited));
     memset(level,0,sizeof(level));
    visited[x][y]=1;
    q.push(make_pair(x,y));
    while(!q.empty()) {
        int f1=q.front().first;
        int f2=q.front().second;
        q.pop();
        for(int i=0;i<4;i++) {
            int I=f1+di[i];
            int J=f2+dj[i];
            if(I>=0 && I<r && J>=0 && J<c) {
                char ch=v[I][J];
                if(ch!='#' && ch!='m') {
                    if(!visited[I][J]) {
                        visited[I][J]=1;
                        level[I][J]=level[f1][f2]+1;
                        q.push(make_pair(I,J));
                        if(ch=='h')val=level[I][J];
                    }
                }
            }
        }
    }
    return val;
}
int main()
{
    char ch;
    int t,pos_ai,pos_aj,pos_bi,pos_bj,pos_ci,pos_cj;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        scanf("%d %d",&r,&c);
        for(int j=0;j<r;j++) {
                for(int k=0;k<c;k++) {
            cin>>ch;
            v[j].push_back(ch);
            if(ch=='a'){
                pos_ai=j;
                pos_aj=k;
            }
            else if(ch=='b') {
                  pos_bi=j;
                pos_bj=k;
            }
            else if(ch=='c') {
                  pos_ci=j;
                pos_cj=k;
            }
        }
    }
    int val=bfs(pos_ai,pos_aj);
    int val1=bfs(pos_bi,pos_bj);
    int val2=bfs(pos_ci,pos_cj);
    cout<<"Case "<<i<<": "<<max(val2,max(val,val1))<<endl;
    for(int j=0;j<r;j++)v[j].clear();
    }
    return 0;
}
