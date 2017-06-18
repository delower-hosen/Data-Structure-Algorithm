#include<bits/stdc++.h>
using namespace std;
struct node{
    bool endmark;
    node *next[26+1];
    node(){
        endmark=false;
        for(int i=0;i<26;i++) next[i]=NULL;
    }
}*root;
void insert(char* str,int len){
    node *cur=root;
    for(int i=0;i<len;i++){
        int id=str[i]-'a';
        if(cur->next[id]==NULL)
            cur->next[id]=new node();
            cur=cur->next[id];
    }
    cur->endmark=true;
}

bool search(char* str,int len){
    node *cur=root;
    for(int i=0;i<len;i++){
        int id=str[i]-'a';
        if(cur->next[id]==NULL) return false;
        cur=cur->next[id];
    }
    return cur->endmark;
}
void del(node* cur)
{
    for(int i= 0;i<26;i++)
        if (cur->next[i])
            del(cur->next[i]);

    delete(cur);
}

int main()
{

    printf("Enter the number of words\n");
    root = new node();
    int num_word;
    scanf("%d",&num_word);
    for(int i=1;i<=num_word;i++){
        char str[50];
        scanf("%s",str);
        insert(str,strlen(str));
    }
    printf("Enter the number of queries\n");
    int query;
    scanf("%d",&query);
    for(int i=1;i<=query;i++){
        char str[50];
        scanf("%s",str);
        if(search(str,strlen(str))) printf("Found\n");
        else printf("Not Found\n");
    }
    del(root);
    return 0;
}
