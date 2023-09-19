/*82. Remove Duplicates from Sorted List II
Medium
7.8K
208
Companies
Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

 

Example 1:


Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]
Example 2:


Input: head = [1,1,1,2,3]
Output: [2,3]
 

Constraints:

The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.*/

/*APPROACH

*/

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

ListNode* deleteDuplicates(ListNode* head) {
    if(head==NULL || head->next==NULL){
        return head;
    }
    ListNode* smallList=deleteDuplicates(head->next);
    if(head->val == smallList->val){
        head->next=NULL;
        delete head;
        head=smallList;
    }else{
        head->next=NULL;
    }
    return head;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        ListNode* root=takeInput();
        root=deleteDuplicates(root);
        print(root);
    }

}