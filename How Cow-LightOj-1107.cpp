#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,x1,y1,x2,y2,n,x,y;
    scanf("%d",&t);
    for(int i=1;i<=t;i++) {
        scanf("%d %d %d %d %d",&x1,&y1,&x2,&y2,&n);
        cout<<"Case "<<i<<":"<<endl;
        for(int j=1;j<=n;j++) {
                int c1=0,c2=0;
            scanf("%d %d",&x,&y);
            if(x>=x1 && x<=x2)c1=1;
           if(y>=y1 && y<=y2)c2=1;
           if(c1 && c2)cout<<"Yes"<<endl;
           else cout<<"No"<<endl;
        }
    }
    return 0;
}
