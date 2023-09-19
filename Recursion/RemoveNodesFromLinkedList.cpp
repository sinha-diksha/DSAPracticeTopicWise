/*2487. Remove Nodes From Linked List
Medium
877
22
Companies
You are given the head of a linked list.

Remove every node which has a node with a strictly greater value anywhere to the right side of it.

Return the head of the modified linked list.

 

Example 1:


Input: head = [5,2,13,3,8]
Output: [13,8]
Explanation: The nodes that should be removed are 5, 2 and 3.
- Node 13 is to the right of node 5.
- Node 13 is to the right of node 2.
- Node 8 is to the right of node 3.
Example 2:

Input: head = [1,1,1,1]
Output: [1,1,1,1]
Explanation: Every node has value 1, so no nodes are removed.
 

Constraints:

The number of the nodes in the given list is in the range [1, 105].
1 <= Node.val <= 105*/

#include <bits/stdc++.h>
using namespace std;

class ListNode{
    public:
    int val;
    ListNode* next;

    ListNode(int val){
        this->val=val;
        next=NULL;
    }
};

ListNode* removeNodes(ListNode* head) {
    stack<int> s;
    stack<int> q;
    ListNode* root=head;
    while(root!=NULL){
        s.push(root->val);
        root=root->next;
    }
    while(!s.empty()){
        if(q.empty()){
            q.push(s.top());
            s.pop();
        }else{
            if(q.top()>s.top()){
                s.pop();
            }else{
                q.push(s.top());
                s.pop();
            }
        }
    }
    ListNode* root2=NULL;
    ListNode* root3=NULL;
    while(!q.empty()){
        ListNode* newNode= new ListNode(q.top());
        q.pop();
        if(root2==NULL){
            root2=newNode;
            root3=newNode;
        }else{
            root3->next=newNode;
            root3=newNode;
        }
    }

    return root2;

}

ListNode* takeInput(){
    int data;
    cin>>data;
    ListNode* head=NULL;
    ListNode* tail=NULL;
    while(data!=-1){
        ListNode* newNode= new ListNode(data);
        if(head==NULL){
            head=newNode;
            tail=newNode;
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }
        cin>>data;

    }

    return head;

}

void print(ListNode* root){
    while(root!=NULL){
        cout<<root->val<<" ";
        root=root->next;
    }
    cout<<endl;
}
int main(){
    ListNode* root=takeInput();
    root=removeNodes(root);
    print(root);
}