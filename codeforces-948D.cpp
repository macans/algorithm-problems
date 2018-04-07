/******************************************
*  Author : https://github.com/macans   
*  Created On : 2018-04-07
*  File : codeforces-948D.cpp

把Key存到Trie树中,每次贪心的取最小的异或值
*******************************************/
#include <cstdio>
#include <cstring>

#define maxn 300005
using namespace std;

int ans[maxn];

struct node{
    int value;
    node *child[2];
    node(){
        value = 0;
        child[0] = child[1] = NULL;
    }
};

void add_node(int x, node *cur){
    //printf("add_node %d\n", x);
    int k = 30;
    while(k>=0){
        int y = x >> k;
        //printf("x=%d, y=%d, k=%d\n", x, y, k);
        if(cur->child[y] == NULL){
            cur->child[y] = new node();
            cur = cur->child[y];
            ++cur->value;
        }
        else{
            cur = cur->child[y];
            ++cur->value;
        }
        x = x & ((1 << k--) - 1);
    }
}

int find_node(int i, int x, node *cur){
    int k = 30;
    int res = 0;
    while(k >= 0){
        int y = x >> k;        
        //printf("before:i=%d, x=%d, y=%d, k=%d\n", i, x, y, k);
        if(cur->child[y] == NULL || cur->child[y]->value == 0){
            y = y ^ 1;
            ans[i] = (ans[i] << 1) | 1;
            //printf("ans[%d]=%d\n", i, ans[i]);
        } else{
            ans[i] <<= 1;
            //printf("ans[%d]=%d\n", i, ans[i]);
        }
        //printf("after:i=%d, x=%d, y=%d, k=%d\n", i, x, y, k);
        res = (res << 1) + y;
        cur = cur->child[y];
        x = x & ((1 << k--) - 1);
    }
    return res;
}

void remove_node(int x, node *cur){
    int k = 30;
    while(k >= 0){
        int y = x >> k;
        if(cur->child[y] == NULL){
            printf("ERROR\n");
            return;
        }
        --cur->child[y]->value;
        cur = cur->child[y];
        x = x & ((1 << k--) - 1);
    }
}
int main(){
    node *root;
    int n;
    int a[maxn], b[maxn];
    while(~scanf("%d", &n)){
        memset(ans, 0, sizeof(ans));
        root = new node();
        for(int i = 0; i < n; ++i){
            scanf("%d", &a[i]);
        }
        for(int i = 0; i < n; ++i){
            scanf("%d", &b[i]);
            add_node(b[i], root);
        }
        for(int i = 0; i < n; ++i){
            int x = find_node(i, a[i], root);
            remove_node(x, root);
        }
        for(int i = 0; i < n; ++i){
            printf("%d ", ans[i]);
        }
    }
}