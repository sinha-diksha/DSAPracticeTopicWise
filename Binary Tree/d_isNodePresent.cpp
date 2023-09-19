/*Problem Level: EASY
Problem Description:
For a given Binary Tree of type integer and a number X, find whether a node exists in the tree with data X or not.
Input Format:
The first and the only line of input will contain the node data, all separated by a single space. Since -1 is used as an indication whether the left or right node data exist for root, it will not be a part of the node data.

Output Format:
The only line of output prints 'true' or 'false'.

Note:
You are not required to print anything explicitly. It has already been taken care of.

Constraints:
1 <= N <= 10^5
Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec

Sample Input 1:
8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
7

Sample Output 1:
true

Sample Input 2:
2 3 4 -1 -1 -1 -1
10

Sample Output 2:
false*/

#include <bits/stdc++.h>
using namespace std;

class BinaryTreeNode{
    public:
    int data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
     ~BinaryTreeNode(){
        delete left;
        delete right;
    }
};

BinaryTreeNode* takeInputLevelWise(){
    cout<<"enter root data"<<endl;
    int data;
    cin>>data;
    if(data==-1){
        return NULL;
    }
    BinaryTreeNode* root=new BinaryTreeNode(data);
    queue<BinaryTreeNode*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        BinaryTreeNode* front=pendingNodes.front();
        pendingNodes.pop();
        int leftData;
        int rightData;
        cout<<"enter the left child of "<<front->data<<endl;
        cin>>leftData;
        if(leftData!=-1){
            BinaryTreeNode* leftChild=new BinaryTreeNode(leftData);
            front->left=leftChild;
            pendingNodes.push(leftChild);
        }
        cout<<"enter the right child of "<<front->data<<endl;
        cin>>rightData;
        if(rightData!=-1){
            BinaryTreeNode* rightChild=new BinaryTreeNode(rightData);
            front->right=rightChild;
            pendingNodes.push(rightChild);
        }
    }
    return root;
}

bool findK(BinaryTreeNode* root, int k){
    if(root==NULL){
        return false;
    }
    if(root->data==k){
        return true;
    }
    bool a=false;
    if(root->left!=NULL){
        a=findK(root->left, k);
    }
    bool b=false;
    if(root->right!=NULL){
        b=findK(root->right, k);
    }
    return a||b;
    
}

int main(){
    BinaryTreeNode* root=takeInputLevelWise();
    int k;
    cin>>k;
    cout<<findK(root,k)<<endl;
}