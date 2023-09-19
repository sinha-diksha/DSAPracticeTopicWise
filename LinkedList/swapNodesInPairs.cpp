/*24. Swap Nodes in Pairs
Medium
10.7K
388
Companies
Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

 

Example 1:


Input: head = [1,2,3,4]
Output: [2,1,4,3]
Example 2:

Input: head = []
Output: []
Example 3:

Input: head = [1]
Output: [1]
 

Constraints:

The number of nodes in the list is in the range [0, 100].
0 <= Node.val <= 100*/


/* APPROACH
*/

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


ListNode* swapPairs(ListNode* head) {
    if(head==NULL || head->next==NULL){
        return head;
    }
    ListNode* smallHead=swapPairs(head->next->next);
    ListNode* a=head;
    ListNode* b=head->next;
    b->next=a;
    a->next=smallHead;
    head=b;
    return head;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        ListNode* root=takeInput();
        root=swapPairs(root);
        print(root);
    }
}