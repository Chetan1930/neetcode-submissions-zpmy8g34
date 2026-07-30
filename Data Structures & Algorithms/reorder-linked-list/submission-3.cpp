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

    ListNode* rev(ListNode* head){
        if(!head || !head->next)return head;

        ListNode* temp=rev(head->next);
        head->next->next=head;
        head->next=nullptr;
        return temp;
    }
    void reorderList(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* rhead=rev(slow->next);
        slow->next=nullptr;
        fast=head;

        while(rhead){
            ListNode* t1=fast->next;
            ListNode* t2=rhead->next;

            fast->next=rhead;
            rhead->next=t1;

            fast=t1;
            rhead=t2;
        }

        return ;
    }
};
