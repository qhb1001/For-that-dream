//Segment Tree Problem From Codeforces
//8.22  9:44
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 1e6 + 5;
char s[maxn];
struct node{
    int a, b, x , L , R;
    struct node * lchild, *rchild;
};
void build(int L, int R, node * & tree){
    tree -> a = tree -> b = tree -> x = 0;
    tree -> R = R; tree -> L = L;
    if(L == R){
        if(s[L] == ')') {tree -> b ++;return ;}
        else    {tree -> a ++; return ;}
    }
    int mid = (tree -> L + tree -> R) >> 1;
    
    tree -> lchild = (node *) malloc(sizeof(node));
    tree -> rchild = (node *) malloc(sizeof(node));
    build(L, mid , tree -> lchild);
    build(mid + 1, R, tree -> rchild);
    
    //another way of  " initialization "
    int t = min ( tree -> lchild -> a , tree -> rchild -> b);
    tree -> a = tree -> lchild -> a + tree -> rchild -> a - t;
    tree -> b = tree -> lchild -> b + tree -> rchild -> b - t;
    tree -> x = tree -> lchild -> x + tree -> rchild -> x + t;
    return ;
}
//int query(int L, int R, node * & tree){
//    //If here is a leaf node , then just return 0 .
//    if(tree -> L == tree -> R)  return 0;
//    
////    tree -> a = tree -> b = tree -> x =0;
//    //If the query range not across the mid
//    int mid = (tree -> L + tree -> R) >> 1;
//    if(R <= mid)    {
//        tree -> x = query(L ,R, tree -> lchild);
//        tree -> a = tree -> lchild -> a;
//        tree -> b = tree -> lchild -> b;
//        return tree -> x;
//    }
//    else if(L > mid)    {
//        tree -> x = query(L ,R, tree -> rchild);
//        tree -> a = tree -> rchild -> a;
//        tree -> b = tree -> lchild -> b;
//        return tree -> x;
//    }
//    else{
//        int x = query(L, mid, tree -> lchild) + query(mid + 1, R , tree -> rchild);
//        int t = min(tree -> lchild -> a , tree -> rchild -> b);
//        x += t;
//        tree -> a = tree -> lchild -> a + tree -> rchild -> a - t;
//        tree -> b = tree -> lchild -> b + tree -> rchild -> b - t;
//        tree -> x = x;
//        return x;
//    }
//}

node * query(int L, int R, node *  tree){
    if(tree -> L == L && R== tree -> R)  {
        return tree;
    }
    
    int mid = (tree -> L + tree -> R) >> 1;
    if(R <= mid){
        return query(L , R, tree -> lchild);
    }
    else if(L > mid){
        return  query(L, R, tree -> rchild);
    }
    else{
        node * t = (node *) malloc(sizeof(node));
        node * Left = query(L, mid , tree -> lchild), * Right = query(mid + 1, R, tree -> rchild);
        int x = min(Left -> a, Right -> b);
        t -> a = Left -> a + Right -> a - x;
        t -> b = Left -> b + Right -> b - x;
        t -> x = Left -> x + Right -> x + x;
        return t;
    }
}
int main(){
    scanf("%s", s);
    node * root = (node *) malloc(sizeof(node));
    int len = strlen(s) ;
    build(0, len - 1, root);
    int m;
    scanf("%d", &m);
    while(m--){
        int L, R;
        scanf("%d%d", &L, &R);
//        printf("%d\n", 2 * query(L - 1, R - 1, root));
        node * t = query(L - 1 ,R - 1, root);
        printf("%d\n", t -> x  * 2);
    }
    return 0;
}
