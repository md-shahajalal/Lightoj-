#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,a,ans;
    cin>>t;
    for(int tc=1;tc<=t;tc++)
    {
        int arr[7]={0,0,0,0,INT_MAX,INT_MAX,INT_MAX};
        cin>>n;
        while(n--)
        {
            for(int i=1;i<=3;i++)
            {
                cin>>a;
                if(a>arr[i])arr[i]=a;
            }
            for(int i=4;i<=6;i++)
            {
                cin>>a;
                if(a<arr[i])arr[i]=a;
            }
        }
        if(arr[4]>arr[1] && arr[5]>arr[2] && arr[6]>arr[3])
        {
            ans=(arr[4]-arr[1])*(arr[5]-arr[2])*(arr[6]-arr[3]);
            printf("Case %d: %d\n",tc,ans);
        }
        else printf("Case %d: 0\n",tc);
    }
    return 0;
}
