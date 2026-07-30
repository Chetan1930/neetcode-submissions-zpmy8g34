/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:

    int listlen(ListNode* head){
        int l=0;
        while(head){
            head=head->next;
            l++;
        }
        return l;        
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int l=listlen(head);
        int ep=l-n+1;
        if(ep<=0 || ep>l)return head;
        if(ep==1)return head->next;
        ListNode* prev=nullptr;
        ListNode* curr=head;
        while(ep>1){
            prev=curr;
            curr=curr->next;
            ep--;
        }
        prev->next=curr->next;
        return head;
    }
};
