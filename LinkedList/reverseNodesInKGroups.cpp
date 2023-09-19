/*
25. Reverse Nodes in k-Group
Hard
11.5K
587
Companies
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
Example 2:


Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]
 

Constraints:

The number of nodes in the list is n.
1 <= k <= n <= 5000
0 <= Node.val <= 1000*/

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

ListNode* takeInput(){
    int data;
    cin>>data;
    ListNode* head=NULL;
    ListNode* tail=NULL;
    while(data!=-1){
        ListNode* newNode=new ListNode(data);
        if(head==NULL){
            head=newNode;
            tail=newNode;
        }else{
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

int length(ListNode* head){
    int count=0;
    while(head!=NULL){
        count++;
        head=head->next;
    }
    return count;
}

ListNode* reverse(ListNode* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    ListNode* smallNode=reverse(head->next);
    head->next->next=head;
    head->next=NULL;
    return smallNode;
}


ListNode* reverseKGroup(ListNode* head, int k) {
    int len=length(head);
        if(head==NULL || head->next==NULL || len<k){
            return head;
        }
    ListNode* root=head;
    ListNode* prev=NULL;
    
    for(int i=0; i<k; i++){
        prev=root;
        root=root->next;
    }
    prev->next=NULL;
    ListNode* newHead=reverse(head);
    head->next=reverseKGroup(root, k);
    return newHead;

}

int main(){
    int t;
    cin>>t;
    while(t--){
        ListNode* root=takeInput();
        int k; 
        cin>>k;
        root=reverseKGroup(root,k);
        print(root);
    }
}