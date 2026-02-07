class LRUCache {
public:
    // DLL Node class
    class Node {
    public:
        int key;
        int value;
        Node* prev;
        Node* next;

        Node(int key, int value) {
            this->key = key;
            this->value = value;
            this->prev = nullptr;
            this->next = nullptr;
        }
    };

    // Create pointers for head and tail of the DLL and a hash map to store
    // key-node pairs
    Node* head = new Node(-1, -1); // Dummy head node
    Node* tail = new Node(-1, -1); // Dummy tail node
    unordered_map<int, Node*>
        cache; // Hash map to store key-node pairs - To get O(1) access to nodes
    int limit; // Variable to store the capacity of the cache

    LRUCache(int capacity) {
        limit = capacity;  // Set the capacity of the cache
        head->next = tail; // Initialize the DLL by pointing head's next to tail
        tail->prev = head; // Initialize the DLL by pointing tail's prev to head
    }

    int get(int key) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            // Move the accessed node to the front (most recently used)
            deleteNode(node);
            addNode(node);
            return node->value;
        }
        return -1;
    }

    void addNode(Node* newNode) {
        Node* oldNext = head->next; // Store the old next node of the head
        head->next = newNode;       // Point the head's next to the new node
        oldNext->prev =
            newNode; // Point the old next node's prev to the new node
        newNode->next =
            oldNext;          // Point the new node's next to the old next node
        newNode->prev = head; // Point the new node's prev to the head
    }

    void deleteNode(Node* node) {
        Node* oldPrev =
            node->prev; // Store the old previous node of the node to be deleted
        Node* oldNext =
            node->next; // Store the old next node of the node to be deleted
        oldPrev->next =
            oldNext; // Point the old previous node's next to the old next node
        oldNext->prev =
            oldPrev; // Point the old next node's prev to the old previous node
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            // Update existing key: change value and move to front
            Node* node = cache[key];
            node->value = value;
            deleteNode(node);
            addNode(node);
        } else {
            // Insert new key: evict if necessary
            if (cache.size() == limit) {
                cache.erase(tail->prev->key);
                deleteNode(tail->prev);
            }
            Node* newNode = new Node(key, value);
            addNode(newNode);
            cache[key] = newNode;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */