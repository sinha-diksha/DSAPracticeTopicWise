
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



ListNode* reverse(ListNode* head, ListNode* tail){
        if(head==tail){
            return head;
        }
        if(head->next==NULL){
            return head;
        }
        if(head==NULL){
            return head;
        }
        ListNode* smallAns=reverse(head->next,tail);
        head->next->next=head;
        head->next=NULL;
        head=tail;
        return tail;
    }

    int length(ListNode* head, ListNode* tail){
        if(head==NULL){
            return 0;
        }
        int count=1;
        while(head!=tail){
            count++;
            head=head->next;
        }
        return count;
    }
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        if(head==NULL || head->next==NULL || head->next->next==NULL){
            return head;
        }
        ListNode* prev=head;
        ListNode* next=head->next->next->next;
        ListNode* left=head->next;;
        ListNode* right=head->next->next;
        ListNode* root=head;
        int i=2;
        while(left!=NULL){
            int r=length(left, right);
            if(r%2==0){
                ListNode* smallHead=reverse(left, right);
                i++;
                prev->next=smallHead;
                left->next=next;
                prev=left;
                left=next;
                if(left==NULL){
                    break;
                }
                ListNode* root=left;
                int j=1;
                while(root!=NULL && root->next!=NULL && (j<i)){
                    root=root->next;
                    j++;
                }
                
                right=root;
                if(right!=NULL){
                    next=root->next;
                }else{
                    next=NULL;
                }
                print(head);
            }
            else{
                prev=right;
                left=next;
                if(left==NULL){
                    break;
                }
                i++;
                ListNode* root=left;
                int j=1;
                while(root!=NULL && (j<i) && root->next!=NULL){
                    root=root->next;
                    j++;
                }
                right=root;
                if(root!=NULL){
                    next=root->next;
                }else{
                    next=NULL;
                }
                print(head);
                
            }
        }
    
        return head;
    }

int main(){
    ListNode* root=takeInput();
    root=reverseEvenLengthGroups(root);
    print(root);
}


