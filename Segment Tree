#include<bits/stdc++.h>
using namespace std;
#define mx 100005
#define inf 0x3f3f3f3f
int arr[mx];
int tree[3*mx]; //why? ;)

void build_tree(int node,int a,int b){  //node=current node, b-e=current range
        if(a>b) return;  //out of range
        if(a==b){   //Leaf node
            tree[node]=arr[a];  //initialize value
            return;
        }
        int mid=(a+b)/2;
        int left=node*2;
        int right=(node*2)+1;
        build_tree(left,a,mid);   //Init left child
        build_tree(right,mid+1,b); //Init right child
        tree[node]=max(tree[left],tree[right]);  //Init root value
}

void update_tree(int node,int a,int b,int i,int j,int value){ //[a,b]=current range [i,j]=to be updated
        if(a>b or a>j or b<i)  //current segment is not within range [i,j]
            return;
        if(a==b){    //Leaf node
            tree[node]+=value;
            return;
        }
        int mid=(a+b)/2;
        int left=node*2;
        int right=(node*2)+1;
        update_tree(left,a,mid,i,j,value);   //updating left child
        update_tree(right,mid+1,b,i,j,value); //updating right child
        tree[node]=max(tree[left],tree[right]);  //updating root with max value

}

int query_tree(int node,int a,int b,int i,int j){
     if(a>b or a>j or b<i) return -inf; //out of range

     if(a>=i and b<=j) //current segment is totally in range [i,j]
        return tree[node];

    int left=node*2;
    int right=node*2+1;
    int mid =(a+b)/2;
    int q1=query_tree(left,a,mid,i,j);
    int q2=query_tree(right,mid+1,b,i,j);
    int res=max(q1,q2);
    return res;
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    build_tree(1,0,n-1);

    update_tree(1,0,n-1,0,6,5);  //increment range [0,6] by 5
    update_tree(1,0,n-1,7,10,12); // Incremenet range [7, 10] by 12
	update_tree(1,0,n-1, 10,n-1,100); // Increment range [10, N-1] by 100
    int ans=query_tree(1,0,n-1,0,n-1);  //Get max value in range [0,n-1]
    cout<<ans<<endl;
    return 0;
}
