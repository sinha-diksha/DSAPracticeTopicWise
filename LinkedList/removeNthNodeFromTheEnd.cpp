/*
19. Remove Nth Node From End of List
Medium
16.1K
671
Companies
Given the head of a linked list, remove the nth node from the end of the list and return its head.

 

Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]
 

Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz*/
#include<bits/stdc++.h>
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

ListNode* removeNthFromEnd(ListNode* head, int n) {
    int len=length(head);
    if(n==len){
        ListNode* a=head;
        head=head->next;
        a->next=NULL;
        delete a;
        return head;
    }
    int r=len-n;
    ListNode* prev=NULL;
    ListNode* next1=NULL;
    ListNode* root=head;
    for(int i=0; i<r; i++){
        prev=head;
        head=head->next;
        next1=head->next;

    }
    head->next=NULL;
    delete head;
    prev->next=next1;
    return root;
}

int main(){
    int t;
    cin>>t;
    while(t--){
    ListNode* root=takeInput();
    int n;
    cin>>n;
    root=removeNthFromEnd(root,n);
    print(root);
    }

}
