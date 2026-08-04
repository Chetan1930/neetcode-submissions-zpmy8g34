class Node{
public:
    int val;
    Node* next;

    Node(int x){
        val=x;
        next=nullptr;
    }
};
class LRUCache {
public:
    
    unordered_map<int,int>mp;
    Node* head=nullptr;
    int capacity=0;
    LRUCache(int cap) {
        capacity=cap;
    }   
    void dele(int x){
        if(head && head->val==x){
            head=head->next;
            return ;
        }
        Node* curr=head;
        Node* temp=nullptr;
        while(curr){
            if(curr->val==x){
                temp->next=curr->next;
                break;
            }
            temp=curr;
            curr=curr->next;
        }

        return;
    }

    void update(int x){

        if(!head){
            head= new Node(x);
            return ;
        }

        Node* curr=head;

        while(curr->next){
            curr=curr->next;
        }

        curr->next=new Node(x);

        return ;
    }

    int get(int key) {
        if(mp.count(key)){
            dele(key);
            update(key);
            return mp[key];
            }
        else return -1;
    }
    
    void put(int key, int value) {
        mp[key]=value;
        if(mp.size()>capacity){
            int temp=head->val;
            dele(temp);
            mp.erase(temp);
        }
        update(key);
        mp[key]=value;      

    }
};
