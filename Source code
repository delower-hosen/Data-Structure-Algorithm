#include<bits/stdc++.h>
using namespace std;
#define mx 100005
int arr[mx];
int tree[mx*3];

void init(int node,int b,int e)
{
    if (b==e) {
        tree[node]=arr[b];
        return;
    }
    int Left=node*2;
    int Right=node*2+1;
    int mid =(b+e)/2;
    init(Left,b,mid);
    init(Right,mid+1,e);
    tree[node]=tree[Left]+tree[Right];
}

void update(int node,int b,int e,int i,int newvalue)
{
    if (i>e || i<b)
        return; //out of range
    if (b==e) { //Relevant segment
        tree[node]=newvalue;
        return;
    }
    int Left=node*2; //need to split
    int Right=node*2+1;
    int mid =(b+e)/2;
    update(Left,b,mid,i,newvalue);
    update(Right,mid+1,e,i,newvalue);
    tree[node]=tree[Left]+tree[Right];
}

int query(int node, int b, int e, int i, int j)
{
    if (i > e || j < b)
        return 0; //Out of range
    if (b >= i && e <= j)
        return tree[node]; //Relevant Segment
    int Left = node * 2; //need to split
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    int p1 = query(Left, b, mid, i, j);
    int p2 = query(Right, mid + 1, e, i, j);
    return p1 + p2; //sum of left and right side
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
    init(1,1,n);
    update(1,1,n,2,0); //updating value of index 2 by 0
    printf("%d\n",query(1,1,n,1,3));
    update(1,1,n,2,2);  //updating value of index 2 by 2
    printf("%d\n",query(1,1,n,2,2));
    return 0;
}

/*
7
4 -9 3 7 1 0 2
*/
