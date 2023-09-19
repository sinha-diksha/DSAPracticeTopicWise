/*92. Reverse Linked List II
Medium
9.3K
421
Companies
Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

 

Example 1:


Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]
Example 2:

Input: head = [5], left = 1, right = 1
Output: [5]
 

Constraints:

The number of nodes in the list is n.
1 <= n <= 500
-500 <= Node.val <= 500
1 <= left <= right <= n*/

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


void print(ListNode* head){
    while(head!=NULL){
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
}


int length(ListNode* root){
    int count=0;
    while(root!=NULL){
        count++;
        root=root->next;
    }
    return count;
}

ListNode* reverse(ListNode* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    ListNode* smallHead=reverse(head->next);
    head->next->next=head;
    head->next=NULL;
    head=smallHead;
    return head;
}

ListNode* reverseBetween(ListNode* head, int left, int right) {
    if(left==right){
        return head;
    }
    int i=1;
    ListNode* temp=head;
    ListNode* prev=NULL;
    for(; i<left; i++){
        prev=head;
        head=head->next;
    }
    ListNode* root=head;
    ListNode* next=NULL;
    for(; i<right; i++){
        root=root->next;
        next=root->next;
    }
    root->next=NULL;
    if(prev!=NULL){
        prev->next=reverse(head);
    }else{
        ListNode* temp2=reverse(head);
        head->next=next;
        return temp2;
    }
    head->next=next;
    return temp;

}

int main(){
    ListNode* root=takeInput();
    int left;
    cin>>left;
    int right;
    cin>>right;
    root=reverseBetween(root, left, right);
    print(root);
}

