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

void print(BinaryTreeNode* root){
    cout<<root->data<<" ";
    if(root->left!=NULL){
        print(root->left);
    }
    if(root->right!=NULL){
        print(root->right);
    }
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


BinaryTreeNode* takeInput(){
    cout<<"enter data"<<endl;
    int data;
    cin>>data;
    if(data==-1){
        return NULL;
    }
    BinaryTreeNode* root=new BinaryTreeNode(data);
    root->left=takeInput();
    root->right=takeInput();
    return root;

}

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
        if(leftData!=-1){
            BinaryTreeNode* rightChild=new BinaryTreeNode(rightData);
            front->left=rightChild;
            pendingNodes.push(rightChild);
        }
    }
    return root;
}


int main(){
    BinaryTreeNode* root=new BinaryTreeNode(1);
    BinaryTreeNode* node1=new BinaryTreeNode(2);
    BinaryTreeNode* node2=new BinaryTreeNode(3);
    root->left=node1;
    root->right=node2;
    print(root);
    cout<<endl;
    print2(root);

    BinaryTreeNode* root1=takeInput();
    print2(root1);
    BinaryTreeNode* root2=takeInput();
    print2(root2);
}