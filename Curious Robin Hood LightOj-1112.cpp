#include<bits/stdc++.h>
using namespace std;
//int tree[300005];
void init(long long tree[],long long arr[],int node,int b,int e)
{
    if(b==e)
    {
        tree[node]=arr[b];
        return;
    }
    int left=node*2;
    int right=left+1;
    int mid=(b+e)>>1;
    init(tree,arr,left,b,mid);
    init(tree,arr,right,mid+1,e);
    tree[node]=tree[left]+tree[right];
}
void update(long long tree[],int node,int b,int e,int i,int newvalue)
{
    if(b>i || e<i)return;
    if(b>=i && e<=i)
    {
        tree[node]+=newvalue;
        return;
    }
    int left=node*2;
    int right=left+1;
    int mid=(b+e)>>1;
    update(tree,left,b,mid,i,newvalue);
    update(tree,right,mid+1,e,i,newvalue);
    tree[node]=tree[left]+tree[right];
}
long long query(long long tree[],int node,int b,int e,int i,int j)
{
    if(i>e || j<b)return 0;
    if(b>=i && e<=j)
    {
        return tree[node];
    }
    int left=node*2;
    int right=left+1;
    int mid=(b+e)>>1;
    long long p1=0,p2=0;
     p1=query(tree,left,b,mid,i,j);
     p2=query(tree,right,mid+1,e,i,j);
    return p1+p2;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t,n,q,a,x,p,v,r,s;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {

       scanf("%d %d",&n,&q);

        long long arr[n+1];
        long long tree[6*(n+1)];
        for(int j=1;j<=n;j++){
        scanf("%lli",&arr[j]);
        }
        init(tree,arr,1,1,n);
         printf("Case %d:\n",i);
        while(q--)
        {
            scanf("%d %d",&x,&p);
            if(x==1)
            {
            update(tree,1,1,n,p+1,(-1*arr[p+1]));
               printf("%lli\n",arr[p+1]);
                arr[p+1]=0;
            }
            else if(x==2)
            {
                scanf("%d",&v);
                update(tree,1,1,n,p+1,v);
                arr[p+1]+=v;
            }
            else {
                scanf("%d",&s);
                long long val=query(tree,1,1,n,p+1,s+1);
                printf("%lli\n",val);
            }
        }
       // tree.clear();
    }
    return 0;
}
