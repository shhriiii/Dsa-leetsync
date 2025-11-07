class LRUCache {
public:
    class node{
        public:
        int key , val;
        node* next ;
        node* prev ;
        node(int _key , int _val){
            key=_key;
            val=_val;
        }
    };
    int cap;
    node* head = new node(-1,-1);
    node * tail = new node(-1,-1);
    unordered_map<int , node*> mp;
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head; 
    }
    void addNode(node* newNode){
        node* temp = head->next;
        newNode->next = temp;
        newNode->prev=head;
        head->next=newNode;
        temp->prev=newNode;

    }
    void deleteNode(node* delNode){
        node* delprev = delNode->prev;
        node* delNext = delNode->next;
        delprev->next=delNext;
        delNext->prev = delprev;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            node* resNode = mp[key];
            int val = resNode->val;
            mp.erase(key);
            deleteNode(resNode);
            addNode(resNode);
            mp[key]=head->next;



            return val;

        }
        return -1;
        
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            node* exist = mp[key];
            mp.erase(key);
            deleteNode(exist);

        }
        if(mp.size()==cap){
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        node* newNode = new node(key,value);
        addNode(newNode);
        mp[key]=newNode;
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */