
#include<bits/stdc++.h>
using namespace std;
#define maxi 100001
struct data
{
    int maxx;
    int minn;
}tree[3*maxi];
int n,ans;
void init(int arr[],int node,int b,int e)
{
    if(b==e)
    {
        tree[node].maxx=arr[b];
        tree[node].minn=arr[b];
        return;
    }
    int left=node<<1;
    int right=left+1;
    int mid=(b+e)>>1;
    init(arr,left,b,mid);
    init(arr,right,mid+1,e);
    tree[node].maxx=max(tree[left].maxx,tree[right].maxx);
    tree[node].minn=min(tree[left].minn,tree[right].minn);
}
data query(int node,int b,int e,int i,int j)
{
    if(b>=i && e<=j)return tree[node];
    if(b>j || e<i)
    {
        data temp;
        temp.maxx=0;
        temp.minn=INT_MAX;
        return temp;
    }
    int left=node<<1;
    int right=left+1;
    int mid=(b+e)>>1;
    data x1=query(left,b,mid,i,j);
    data x2=query(right,mid+1,e,i,j);
    int maxim=max(x1.maxx,x2.maxx);
    int minim=min(x1.minn,x2.minn);
    data temp;
    temp.maxx=maxim;
    temp.minn=minim;
    return temp;
}
int search_ans(int s,int e)
{
    data temp=query(1,1,n,s,e);
    ans=max(ans,temp.maxx-temp.minn);
    if(e+1<=n) search_ans(s+1,e+1);
    return ans;
}
int main()
{
    int t,d;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++)
    {
        ans=0;
        scanf("%d %d",&n,&d);
        int arr[n+1];
        for(int i=1;i<=n;i++)scanf("%d",&arr[i]);
        init(arr,1,1,n);
        int ans1=search_ans(1,d);
        printf("Case %d: %d\n",tc,ans1);
    }
}
