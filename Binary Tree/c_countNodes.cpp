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
void print2(BinaryTreeNode* root){
    cout<<root->data<<":";
    if(root->left!=NULL){
        cout<<"L"<<root->left->data<<",";
    }
    if(root->right!=NULL){
        cout<<"R"<<root->right->data;
    }
    cout<<endl;
    if(root->left!=NULL){
        print2(root->left);
    }
    if(root->right!=NULL){
        print2(root->right);
    }
}

int countNodes(BinaryTreeNode* root){
    if(root==NULL){
        return 0;
    }
    int a=countNodes(root->left);
    int b=countNodes(root->right);
    return 1+a+b;
}

int main(){
    BinaryTreeNode* root=takeInputLevelWise();
    print2(root);
    cout<<countNodes(root)<<endl;
}