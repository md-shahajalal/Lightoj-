#include<bits/stdc++.h>
using namespace std;
int n;
char position[30];
bool visited[30];
int c,k;
void permutation(int x)
{
    if(x==n) {
        k--;

        for(int i=0;i<n;i++)printf("%c",position[i]);
        printf("\n");
        return;
    }

    for(int i=0;i<n;i++) {
        if(!visited[i]) {
            visited[i]=true;
            position[x]=i+65;
            if(k)permutation(x+1);
            visited[i]=false;
        }
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++) {
            c=0;
            memset(visited,false,sizeof(visited));
          scanf("%d %d",&n,&k);
        printf("Case %d:\n",i);
        permutation(0);
    }
    return 0;
}

