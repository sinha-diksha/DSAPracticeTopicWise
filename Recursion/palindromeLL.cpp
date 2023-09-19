/*234. Palindrome Linked List
Easy
14.2K
780
Companies
Given the head of a singly linked list, return true if it is a 
palindrome
 or false otherwise.

 

Example 1:


Input: head = [1,2,2,1]
Output: true
Example 2:


Input: head = [1,2]
Output: false
 

Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9
 

Follow up: Could you do it in O(n) time and O(1) space?*/

#include <bits/stdc++.h>
using namespace std;

class ListNode{
    public:
    int data;
    ListNode* next;
    
    ListNode(int data){
        this->data=data;
        next=NULL;
    }

};

void print(ListNode* root){
    while(root!=NULL){
        cout<<root->data<<" ";
        root=root->next;
    }
    cout<<endl;
}


ListNode* reverse(ListNode* head){
    if(head==NULL || head->next==NULL){
        return head;
    }

    ListNode* smallReverse=reverse(head->next);
    head->next->next=head;
    head->next=NULL;
    return smallReverse;
}

bool isPalindrome(ListNode* head) {
    ListNode* slow=head;
    ListNode* fast=head;
    ListNode* prev=NULL;
    while(slow->next!=NULL && fast->next!=NULL && fast->next->next!=NULL){
        prev=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    if(fast!=NULL && fast->next!=NULL ){
        prev=slow;
        slow=slow->next;
    }
    if(prev==NULL){
        if(head->next==NULL){
            return true;
        }
        if(head->data == head->next->data){
            return true;
        }else{
            return false;
        }
    }
    ListNode* root2=reverse(slow);
    if(prev!=NULL){
        prev->next=root2;
    }
    
    print(head);
    ListNode* root1=root2;
    while(head!=root1){
        cout<<head->data<<" "<<root2->data<<endl;
        if(head->data!=root2->data){
            return false;
        }
        head=head->next;
        root2=root2->next;
    }
    return true;
    // ListNode* root1;
    // if(prev==NULL){
    //     root1=NULL;
    // }else{
    //     prev->next=NULL;
    //     root1=head;
    // }
    // while(root1!=NULL && root2!=NULL){
    //     if(root1->data !=root2->data){
    //         return false;
    //     }
    // }
    // return true;
    

}


ListNode* takeInput(){
    ListNode* head=NULL;
    ListNode* tail=NULL;
    int data;
    cin>>data;
    while(data!=-1){
        ListNode* newNode= new ListNode(data);
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

int main(){
    ListNode* root=takeInput();
    cout<<isPalindrome(root)<<endl;
}