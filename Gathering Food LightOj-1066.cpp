#include<bits/stdc++.h>
using namespace std;
vector<char>v[11];
int level[11][11];
int visited[11][11];
int x,y,n;
int di[]={1,-1,0,0};
int dj[]={0,0,1,-1};
int bfs(int r,int s)
{
    memset(visited,0,sizeof(visited));
    queue<pair<int,int> >q;
    while(!q.empty())q.pop();
    q.push(make_pair(r,s));
    level[r][s]=0;
    visited[r][s]=1;
    char ch=v[r][s];
    while(!q.empty()) {
        int f1=q.front().first;
        int f2=q.front().second;
        q.pop();
        for(int i=0;i<4;i++) {
            int I=di[i]+f1;
            int J=dj[i]+f2;
            if(I>=0 && I<n && J>=0 && J<n) {
                if(!visited[I][J] && (v[I][J]=='.' || v[I][J]==ch+1 || (v[I][J]>='A' && v[I][J]<=ch+1))) {
                    visited[I][J]=1;
                    level[I][J]=level[f1][f2]+1;
                    q.push(make_pair(I,J));
                    if(ch==v[I][J]-1) {
                    x=I;
                    y=J;
                    return level[I][J];
                    }
                }
            }
        }
    }
    return 0;
}
int main()
{
    char ch;
    int t,c,sum,k,u;
    scanf("%d",&t);
    for(int i=1;i<=t;i++) {
            u=0;
            c=0;
            sum=0;
        scanf("%d",&n);
        for(int j=0;j<n;j++) {
            for(int k=0;k<n;k++) {
                cin>>ch;
                v[j].push_back(ch);
                if(ch>='A' && ch<='Z')c++;
                if(ch=='A') {
                    x=j;
                    y=k;
                }
            }
        }
    for(int j=1;j<c;j++) {
       int val=bfs(x,y);
       if(val==0) {
            cout<<"Case "<<i<<": "<<"Impossible"<<endl;
            u=1;
            break;
    }
      sum+=val;
    }
    if(!u)cout<<"Case "<<i<<": "<<sum<<endl;
    for(int j=0;j<11;j++)v[j].clear();
    }
    return 0;
}

