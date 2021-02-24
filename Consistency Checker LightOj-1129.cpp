#include<bits/stdc++.h>
using namespace std;
bool ind;
struct node
{
    int c;
    int endmark;
    node* next[10];
    node()
    {
        c=0;
        endmark=0;
        for(int i=0;i<10;i++)
        {
            next[i]=NULL;
        }
    }
} * root;
void insert_str(string str,int l)
{
    node* curr=root;
    for(int i=0;i<l;i++)
    {
        int id=str[i]-'0';
        if(curr->next[id]==NULL)
        {
            curr->next[id]=new node();
            curr=curr->next[id];
            curr->c+=1;
        }
        else {
            curr=curr->next[id];
            curr->c+=1;
            if(curr->endmark) {
                ind=true;
               // cout<<"id "<<id<<endl;
            }
        }
    }
    curr->endmark=1;
    if(curr->c>1)ind=true;
}
void del(node*  curr)
{
    for(int i=0;i<10;i++)
    {
        if(curr->next[i]!=NULL)del(curr->next[i]);
    }
    delete(curr);
}
int main()
{
    int t,n;
    cin>>t;
    string str;
    for(int tc=1;tc<=t;tc++)
    {
        cin>>n;
        root=new node();
        ind=false;
        while(n--)
        {
            cin>>str;
            int len=str.size();
             insert_str(str,len);
            //cout<<x<<endl;
        }
        if(ind)cout<<"Case "<<tc<<": NO"<<endl;
        else cout<<"Case "<<tc<<": YES"<<endl;
        del(root);
    }
    return 0;
}
