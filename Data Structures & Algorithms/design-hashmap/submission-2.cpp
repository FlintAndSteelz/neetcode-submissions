class MyHashMap {
private:
    struct ListNode{
        int key, val;
        ListNode *next;
        ListNode(int key = -1, int val = -1, ListNode *next =   nullptr): key(key), val(val), next(next){}
    };

    vector<ListNode*> map;
    int hash(int key){
        return key % map.size();
    }



public:
    MyHashMap() {
        map.resize(1000);
        for (auto &buckets: map)
            //create dummy node, để khỏi phải chia th list rỗng, hay list có 1 con
            buckets = new ListNode(0);
    }
    
    void put(int key, int value) {
        ListNode *curr = map[hash(key)];
        while (curr->next != nullptr){
            //Tìm xem 
            if (curr->next-> key == key){
                curr->next->val = value;
                return;
            }
            curr = curr->next;
        }
        curr->next = new ListNode(key, value, nullptr);
        //
    }
    
    int get(int key) {
        ListNode *curr = map[hash(key)];
        while (curr->next != nullptr){
            if (curr->next->key == key)
                return curr->next->val;
            curr = curr->next;
        }

        return -1;
    }
        
    void remove(int key) {
        ListNode *curr = map[hash(key)];
        while (curr->next != nullptr){
            if (curr->next-> key == key){
                ListNode *temp = curr->next;
                curr->next = temp->next;
                delete temp;
                return;
            }
            curr = curr->next;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */