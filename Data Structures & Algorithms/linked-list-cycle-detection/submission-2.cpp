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
    bool hasCycle(ListNode* head) {
        if(head==nullptr || head->next==nullptr)return  false;

        ListNode* slow=head;
        ListNode* fast=head->next;

        while(fast){
            if(fast->next==nullptr)fast=nullptr;
            else fast=fast->next->next;
            slow=slow->next;

            if(fast==slow)return true;
        }


        return false;
    }
};
