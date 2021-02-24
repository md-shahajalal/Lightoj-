#include<bits/stdc++.h>
using namespace std;
int arr[100005];
int tree[400005];
void build(int node,int b,int e)
{
    if(b==e)
    {
        tree[node]=arr[b];
        //return arr[b];
        return;
    }
   int left=node*2;
   int right=node*2+1;
   build(left,b,(b+e)/2);
   build(right,(b+e)/2+1,e);

    tree[node]=min(tree[left],tree[right]);
}
int query(int node,int b,int e,int i,int j)
{
     if(b>j || e<i){
        return INT_MAX;
    }

    if(b>=i  && j>=e)
    {
        return tree[node];
    }

    int val1=query(node*2,b,(b + e) / 2,i,j);
    int val2=query(node*2+1,(b + e) / 2+ 1,e,i,j);

    return min(val1,val2);
}
int main()
{
    int t,n,q,x,y;
    scanf("%d",&t);
    for(int i=1; i<=t; i++)
    {
        scanf("%d %d",&n,&q);
        for(int j=1; j<=n; j++)scanf("%d",&arr[j]);

       build(1,1,n);

        printf("Case %d:\n",i);
      for(int j=0;j<q;j++)
        {
            scanf("%d %d",&x,&y);

            int ans=query(1,1,n,x,y);

            //printf("%d\n",ans);
            cout<<ans<<endl;
        }

    }
    return 0;
}

