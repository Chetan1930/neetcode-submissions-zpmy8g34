/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        

        Node* curr=head;
        unordered_map<Node* , Node* > mp;
        Node* prev=nullptr;

        while(curr){
            mp[curr] = new Node(curr->val);
            curr=curr->next;
        }

        Node* newhead= mp[head];
        curr= head;


        while(newhead){
            newhead->next=mp[curr->next];
            newhead->random=mp[curr->random];
            newhead=newhead->next;
            curr=curr->next;
        }



        return mp[head];



    }
};
