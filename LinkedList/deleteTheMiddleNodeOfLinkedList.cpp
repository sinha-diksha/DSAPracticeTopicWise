/*2095. Delete the Middle Node of a Linked List
Medium
3.1K
54
Companies
You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.

The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start using 0-based indexing, where ⌊x⌋ denotes the largest integer less than or equal to x.

For n = 1, 2, 3, 4, and 5, the middle nodes are 0, 1, 1, 2, and 2, respectively.
 

Example 1:


Input: head = [1,3,4,7,1,2,6]
Output: [1,3,4,1,2,6]
Explanation:
The above figure represents the given linked list. The indices of the nodes are written below.
Since n = 7, node 3 with value 7 is the middle node, which is marked in red.
We return the new list after removing this node. 
Example 2:


Input: head = [1,2,3,4]
Output: [1,2,4]
Explanation:
The above figure represents the given linked list.
For n = 4, node 2 with value 3 is the middle node, which is marked in red.
Example 3:


Input: head = [2,1]
Output: [2]
Explanation:
The above figure represents the given linked list.
For n = 2, node 1 with value 1 is the middle node, which is marked in red.
Node 0 with value 2 is the only node remaining after removing node 1.
 

Constraints:

The number of nodes in the list is in the range [1, 105].
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

ListNode* deleteMiddle(ListNode* head) {
    int len=length(head);
    int k=len/2;
    ListNode* root=head;
    if(k==0){
        delete head;
        return NULL;
    }
    ListNode* prev=NULL;
    ListNode* next1=NULL;
    for(int i=0; i<k; i++){
        prev=head;
        head=head->next;
        next1=head->next;
    }
    head->next=NULL;
    prev->next=next1;
    delete head;
    return root;
        
}

int main(){
    int t;
    cin>>t;
    while(t--){
        ListNode* root=takeInput();
        root=deleteMiddle(root);
        print(root);
    }

}