//Segment Tree Problem From kuangbin
//9.8  00:35
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int maxn = 1e5 + 5;
bool flag = 1;
typedef long long ll;
ll a[ maxn ];
struct node {
    ll sum;
    int L, R;
    bool ok;//to check whether this range is filled with " 1 "
    struct node * lchild, * rchild;
};

//" maintain "
void maintain( node * & tree){
    tree -> sum = tree -> lchild -> sum + tree -> rchild -> sum;
    if(tree -> lchild -> ok == 0 || tree -> rchild -> ok == 0)  tree -> ok = 0;
    else    tree -> ok = 1;
}

//build the tree
void build(int L, int R, node * & tree){
    tree -> L = L;
    tree -> R = R;
    if(L == R){
        tree -> sum = a[L];
        if(a[L] == 1 ||a[L] == 0 )   tree -> ok = 1;
        else  tree -> ok = 0;
        if(flag)    tree -> lchild = tree -> rchild = NULL;
        return ;
    }
    
    int mid = (L + R) >> 1;
    if(flag){
        tree -> lchild = (node *) malloc(sizeof(node));
        tree -> rchild =(node *) malloc(sizeof(node));
    }
    build(L, mid, tree -> lchild);
    build(mid + 1, R, tree -> rchild);
    maintain(tree);
}

//" update "
void update(int L, int R, node * & tree){
    if(tree -> L == tree -> R){
        tree -> sum = floor(sqrt((double)tree -> sum));
        if(tree -> sum == 1)    tree -> ok = 1;
        return ;
    }
    int mid = (tree -> L + tree -> R) >> 1;
    if(tree -> L == L && tree -> R == R){
        if(tree -> ok == 1) return ;
        if(tree -> lchild -> ok  == 0)  update(L, mid , tree -> lchild);
        if(tree -> rchild -> ok == 0)   update(mid + 1, R, tree -> rchild);
        maintain(tree);
        return ;
    }
    
    if(R <= mid)    update(L, R, tree -> lchild);
    else if( L > mid)   update(L, R, tree -> rchild);
    else    update(L, mid , tree -> lchild), update(mid + 1, R, tree -> rchild);
    maintain(tree);
}

//" query "
ll query(int L, int R, node * & tree){
    if(tree -> L == L && tree -> R == R)    return tree -> sum;
    int mid = (tree -> L + tree -> R) >> 1;
    if(R <= mid)    return query(L, R, tree -> lchild);
    else if( L > mid)   return query(L, R, tree -> rchild);
    else return query(L, mid, tree -> lchild) + query(mid + 1, R, tree -> rchild);
}

//" traverse "
void traverse(node * tree){
    if(tree -> L == tree -> R)  {
        printf("%3lld", tree -> sum);
        return ;
    }
    traverse(tree -> lchild);
    traverse(tree -> rchild);
}
//" debug "
void debug(node * root){
    for(int i = 1; i <= 10 ; i++)   printf("%3d", i);
    puts("");
    traverse(root);
    puts("");
}
int main(){
    int Case = 1, n, m;
    node * root = (node *) malloc(sizeof(node));
//    build(1, maxn, root);
//    flag = 0;
	freopen("input", "r", stdin);
	freopen("output.b", "w", stdout);
    while(scanf("%d", &n) != EOF){
        
        //initialization
        for(int i = 1; i <= n; i ++)    scanf("%lld", & a[i]);
        scanf("%d", &m);
        build(1, n, root);
        printf("Case #%d:\n", Case++);
        
        //perform the algorithm : Segment Tree
        int T, L, R;
        while(m--){
            scanf("%d%d%d", &T, &L, &R);
            if(L > R)   swap(L, R);
            if(T == 0)  {update(L, R, root);}
            else    printf("%lld\n", query(L, R, root));
        }
        puts("");
    }
    return 0;
}
