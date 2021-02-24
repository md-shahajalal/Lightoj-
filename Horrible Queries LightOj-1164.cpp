#include<bits/stdc++.h>
using namespace std;
struct info
{
    long long sum=0;
    long long prop=0;

}tree[300001];
/*void init(long long arr[],int node,int b,int e)
{
    if(b==e)
    {
       tree[node].sum=arr[b];
      // tree[node].prop=0;
       return;
    }
    int left=node<<1;
    int right=left+1;
    int mid=(left+right)>>1;
    init(arr,left,b,mid);
    init(arr,right,mid+1,e);
    tree[node].sum=tree[left].sum+tree[right].sum;
    //tree[node].prop=0;
}*/
void update(int node,int b,int e,int x,int y,int v)
{
    if(e<x || b>y)return;
    if(b>=x && e<=y) {
        tree[node].sum+=((e-b+1)*v);
        tree[node].prop+=v;
        return;
    }
    int left=node<<1;
    int right=left+1;
    int mid=(b+e)>>1;
    update(left,b,mid,x,y,v);
    update(right,mid+1,e,x,y,v);
    tree[node].sum=tree[left].sum+tree[right].sum+((e-b+1)*tree[node].prop);
}
long long query(int node,int b,int e,int x,int y,long long carry)
{
    if(e<x || b>y)return 0;
    if(b>=x && e<=y)
    {
       // cout<<"carry "<<carry<<endl;
        return  tree[node].sum+(carry*(e-b+1));
    }
    int left=node<<1;
    int right=left+1;
    int mid=(b+e)>>1;
    long long p1=0,p2=0;
    p1=query(left,b,mid,x,y,carry+tree[node].prop);
    p2=query(right,mid+1,e,x,y,carry+tree[node].prop);
   // cout<<"b ="<<b<<" && "<<"e = "<<e<<" "<<p1<<" "<<p2<<endl;
    return p1+p2;
}
int main()
{
    int t,n,q,v,i,x,y;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++)
    {
        scanf("%d %d",&n,&q);
       // long long arr[n+1];
       // for(int j=1;j<=n;j++)arr[j]=0;
       // init(arr,1,1,n);
       for(int i=0;i<=3*n;i++) {
        tree[i].sum=0;
        tree[i].prop=0;
       }
        printf("Case %d:\n",tc);
        while(q--)
        {
            scanf("%d %d %d",&i,&x,&y);
            if(!i)
            {
                scanf("%d",&v);
                update(1,1,n,x+1,y+1,v);
              //  for(int i=1;i<=19;i++){
                //    cout<<tree[i].sum<<" prop="<<tree[i].prop<<endl;
               // }
            }
            else {
                  //  cout<<tree[1].prop<<endl;
              long long val=query(1,1,n,x+1,y+1,0);
              printf("%lli\n",val);
            }
        }
    }
    return 0;
}
