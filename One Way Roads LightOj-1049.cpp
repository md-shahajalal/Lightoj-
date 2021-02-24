#include<bits/stdc++.h>
using namespace std;
int main()
{
    int left[101];
int right[101];
    int t,a,b,c,n,leftsum,rightsum;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        leftsum=0;
        rightsum=0;
        scanf("%d",&n);
        memset(left,0,sizeof(left));
        memset(right,0,sizeof(right));
        while(n--) {
        scanf("%d %d %d",&a,&b,&c);
        if(!left[a] && !right[b]) {
            left[a]=right[b]=1;
            leftsum+=c;
        }
        else {
            right[a]=left[b]=1;
            rightsum+=c;
        }
        }
        cout<<"Case "<<i<<": "<<min(leftsum,rightsum)<<endl;
    }
    return 0;
}

