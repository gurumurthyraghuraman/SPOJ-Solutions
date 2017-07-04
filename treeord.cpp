              //  1
           //   /  \
          //   2    3
          //  / \    \
          // 4   5    6

//1 2 4 5 3 6
//4 5 2 6 3 1
//4 2 5 1 3 6

#include <iostream>
#include <stdio.h>
#include <stddef.h>
#include <vector>

using namespace std;


struct node {
    int val;
    struct node *left;
    struct node *right;
};

bool isEqual(vector<int> &v1, vector<int> &v2, int vecSize){
    if(v2.size()!=vecSize) return false;
    for(int i=0;i<vecSize;i++){
        if(v1[i]!=v2[i])
            return false;
    }
    return true;
}

void buildPostOrder(struct node*root, vector<int> &postOrder) {
       if(root->left)
            buildPostOrder(root->left,postOrder);
       if(root->right)
            buildPostOrder(root->right,postOrder);
       postOrder.push_back(root->val);

}


struct node* buildTree(vector<int> &preOrder, vector<int> &inOrder, int first, int last) {
        if(preOrder.empty() || first>last) {
            return NULL;
        }
        struct node* root = new node();
        root->val=preOrder[0];
        int index;
        for(int i=first;i<=last;i++) {
            if(inOrder[i]==preOrder[0]){
                index=i;
                break;
            }
        }
        preOrder.erase(preOrder.begin());
        root->left=buildTree(preOrder,inOrder,first,index-1);
        root->right=buildTree(preOrder,inOrder,index+1, last);
        return root;
}


int main() {
    int n,tempInput;
    vector<int> preOrder,postOrder,inOrder;
    vector<int> calPostOrder;
    scanf("%d",&n);
    for(int i=0;i<3;i++)
        for(int j=0;j<n;j++) {
            if(i==0){
                scanf("%d",&tempInput);
                preOrder.push_back(tempInput);
            }
            else if(i==1) {
                scanf("%d",&tempInput);
                postOrder.push_back(tempInput);
            }
            else {
                scanf("%d",&tempInput);
                inOrder.push_back(tempInput);
            }
    }
    struct node *root = buildTree(preOrder,inOrder,0,n-1);
    buildPostOrder(root,calPostOrder);
    if(isEqual(postOrder,calPostOrder,n))
        printf("yes\n");
    else printf("no\n");

    return 0;
}
