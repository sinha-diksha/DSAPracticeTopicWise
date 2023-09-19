/*2. Add Two Numbers
Medium
26.6K
5.1K
Companies
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:


Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
 

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.*/

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

int length(ListNode* root){
    int count=0;
    while(root!=NULL){
        count++;
        root=root->next;
    }
    return count;
}

void print(ListNode* root){
    while(root!=NULL){
        cout<<root->val<<" ";
        root=root->next;
    }
    cout<<endl;
}

ListNode* findTail(ListNode* root){
    while(root->next!=NULL){
        root=root->next;
    }
    return root;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* root=l1;
    int m=length(l1);
    int n=length(l2);
    if(m<n){
        ListNode* tail1=findTail(l1);
        while(m!=n){
            ListNode* newNode=new ListNode(0);
            tail1->next=newNode;
            tail1=newNode;
            m++;
        }
    }
    else if(n<m){
        ListNode* tail1=findTail(l2);
        while(n!=m){
            ListNode* newNode=new ListNode(0);
            tail1->next=newNode;
            tail1=newNode;
            n++;
        }
    }
  
    int carry=0;

    while(l1!=NULL && l2!=NULL){
        int r=l1->val+l2->val;
        carry=r/10;
        l1->val=r%10;
        if(carry==0){
            l1=l1->next;
            l2=l2->next;
            continue;
        }
        else{
            if(carry!=0 && l1->next!=NULL){
                l1->next->val=l1->next->val+carry;
            }else{
                if(carry!=0 && l1->next==NULL){
                    ListNode* newNode=new ListNode(1);
                    l1->next=newNode;
                }
            }
        }
        l1=l1->next;
        l2=l2->next;
    }
    return root;
}

int main(){
    int t;
    cin>>t;
    while(t--){
    ListNode* root1=takeInput();
    ListNode* root2=takeInput();
    ListNode* root3=addTwoNumbers(root1, root2);
    print(root3);
    }
}