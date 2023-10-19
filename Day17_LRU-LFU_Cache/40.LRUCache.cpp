class Node{
    public:
    int key , val;
    Node *prev,*next;
    Node(int k,int v){
        key = k;
        val = v;
        prev = NULL;
        next = NULL;
    }
};
class LRUCache {
    int cap;
    unordered_map<int,Node*> mp;
    Node *tail = new Node(-1,-1);
    Node *head = new Node(-1,-1);
    
public:
    LRUCache(int capacity) {
        cap = capacity;
        head -> next = tail;
        tail -> prev = head;
    }

    void addnode(Node *newn){
        Node* temp = head -> next;
        newn -> next = temp;
        temp -> prev = newn;
        head -> next = newn;
        newn -> prev = head;
    }

    void deletenode(Node *deln){
        Node *delprev = deln -> prev;
        Node *delnext = deln -> next;

        delprev -> next = delnext;
        delnext -> prev = delprev;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()){
            Node* temp = mp[key];
            int ans = temp -> val;
            mp.erase(key);
            deletenode(temp);
            addnode(temp);
            mp[key] = head -> next;
            return ans;
        }

        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Node *exits = mp[key];
            mp.erase(key);
            deletenode(exits);
        }
        if(mp.size() == cap){
            mp.erase(tail -> prev -> key);
            deletenode(tail -> prev);
        }
        addnode(new Node(key,value));
        mp[key] = head -> next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */