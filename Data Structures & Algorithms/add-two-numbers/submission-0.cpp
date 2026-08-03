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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        

        ListNode* f=l1;
        ListNode* s=l2;

        int carry=0;
        ListNode* newhead=nullptr;
        ListNode* temp=nullptr;

        while(f || s ){
            int sum = 0;
            if(f){
                sum+=f->val;
                f=f->next;
            }

            if(s){
                sum+=s->val;
                s=s->next;
            }

            sum+=carry;

            if(sum/10){
                carry=sum/10;
            }   

            int val=sum%10;

            if(!newhead){
                newhead= new ListNode(val);
                temp=newhead;
            }

            else{
                temp->next=new ListNode(val);
                temp=temp->next;
            }
        }

        if(carry){
            temp->next=new ListNode(carry);
                temp=temp->next;
        }

        return newhead;
    }
};
