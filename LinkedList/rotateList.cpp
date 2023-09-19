/*61. Rotate List
Medium
8K
1.4K
Companies
Given the head of a linked list, rotate the list to the right by k places.

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
Example 2:


Input: head = [0,1,2], k = 4
Output: [2,0,1]
 

Constraints:

The number of nodes in the list is in the range [0, 500].
-100 <= Node.val <= 100
0 <= k <= 2 * 109*/
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




ListNode* rotateRight(ListNode* head, int k) {

    int len=length(head);
    if(len==0){
        return head;
    }
    ListNode* root=head;
    k=k%len;
    if(k==0){
        return head;
    }
    ListNode* prev=NULL;

    for(int i=0; i<len-k; i++){
        prev=head;
        head=head->next;
    }
    prev->next=NULL;
    ListNode* newTail=head;
    while(newTail->next!=NULL){
        newTail=newTail->next;
    }
    newTail->next=root;
    return head;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        ListNode* root=takeInput();
        int k;
        cin>>k;
        ListNode* t=rotateRight(root,k);
        print(t);

    }
}