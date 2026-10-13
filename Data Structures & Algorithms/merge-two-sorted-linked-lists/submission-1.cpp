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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* f=list1;
        ListNode* s=list2;
        ListNode* res=nullptr;
        ListNode* ans=res;
        while(f && s){
            if(f->val <= s->val){
                if(res==nullptr){
                    res=f;
                    ans=res;
                }
                else{
                    res->next=f;
                    res=res->next;
                }
                f=f->next;
            }
            else{
                if(res==nullptr){
                    res=s;
                    ans=res;
                }
                else{
                    res->next=s;
                    res=res->next;

                }
                s=s->next;
            }
        }

        while(f){
            if(res==nullptr){
                    res=f;
                    ans=res;
                }
                else{
                    res->next=f;
                    res=res->next;
                }
                f=f->next;
        }

        while(s){
            if(res==nullptr){
                    res=s;
                    ans=res;
                }
                else{
                    res->next=s;
                    res=res->next;

                }
                s=s->next;
        }
        if(res)res->next=nullptr;

        return ans;
    }
};
