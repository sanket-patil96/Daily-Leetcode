class Node {
    public:
        int key;
        int val;
        Node *next, *prev;

        Node(int _key, int _val) {
            key = _key;
            val = _val;
            next = NULL;
            prev = NULL;
        }
};

// Algo:
// 1. we will create a doubly linked list, which will have head & tail pointers as "fixed" don't chanage throughout the code.
// 2. Least recently used {key,value} node will be kept after head.
// 3. Most recently used node will be before tail.
// 4. we also use a map, for mapping the keys with the actual node in the DLL
// 5. On Get operation, map will check if key is present or not, if present then, we will get the currosponding node
//    and remove the node from list and insert it before tail as it is now most recently used.
// 6. On put operation, 
//      if key already present in map, then:
//           change the node value and remove node from list and put it before tail (most recently used).
//      if key not present:
//           if full then: remove the head->next node, and then insert node
//           else:         directly insert the node at tail

class LRUCache {
private: 
    Node *head, *tail;
    unordered_map<int, Node*> m;
    int cap;

    // this is used to set the given node as least recently used
    Node* makeLRU(Node *node) {
        // remove from list
        node->next->prev = node->prev;
        node->prev->next = node->next;

        // insert at tail
        tail->prev->next = node;
        node->prev = tail->prev;
        tail->prev = node;
        node->next = tail;

        return node;
    }

public:
    LRUCache(int capacity) {
        // head & tail will remain same
        head = new Node(-1, -1);
        tail = new Node(-2, -2);
        head->next = tail;
        tail->prev = head;
        cap = capacity;
    }
    
    int get(int key) {
        if(m.count(key)) {
            Node *node = makeLRU(m[key]);
            return node->val;
        }

        return -1;
    }
    
    void put(int key, int value) {
        if(m.count(key)) {
            Node *node = makeLRU(m[key]);
            node->val = value;
            return;
        }
        
        if(m.size() == cap) {
            // remove node after head & also from map
            Node *temp = head->next;
            head->next = temp->next;
            temp->next->prev = head;
            m.erase(temp->key);

            delete temp;
        }
        
        // now insert new node at tail & add key, node in map
        Node *newNode = new Node(key, value);
        tail->prev->next = newNode;
        newNode->prev = tail->prev;
        tail->prev = newNode;
        newNode->next = tail;

        m[key] = newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */