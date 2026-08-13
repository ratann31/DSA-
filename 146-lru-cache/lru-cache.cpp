class LRUCache {
public:

    struct Node {
        int key;
        int value;

        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;

            prev = NULL;
            next = NULL;
        }
    };


    int capacity;

    unordered_map<int, Node*> mpp;

    Node* head;
    Node* tail;


    LRUCache(int capacity) {
        this->capacity = capacity;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }


    // Node ko list se remove karo
    void removeNode(Node* node) {

        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }


    // Node ko head ke baad insert karo
    // Matlab: Most Recently Used position
    void insertFront(Node* node) {

        Node* first = head->next;

        head->next = node;
        node->prev = head;

        node->next = first;
        first->prev = node;
    }


    int get(int key) {

        // Key nahi mili
        if (mpp.find(key) == mpp.end()) {
            return -1;
        }


        // Node mil gayi
        Node* node = mpp[key];


        // Ab ye recently used hai
        removeNode(node);
        insertFront(node);


        return node->value;
    }


    void put(int key, int value) {

        // Case 1: key already exists
        if (mpp.find(key) != mpp.end()) {

            Node* node = mpp[key];

            // Value update karo
            node->value = value;

            // Isko recently used banao
            removeNode(node);
            insertFront(node);

            return;
        }


        // Case 2: key new hai
        // Aur cache full hai
        if (mpp.size() == capacity) {

            // tail ke just pehle wala
            // Least Recently Used hai
            Node* lru = tail->prev;

            // List se remove
            removeNode(lru);

            // Map se remove
            mpp.erase(lru->key);

            // Memory free
            delete lru;
        }


        // New node banao
        Node* node = new Node(key, value);

        // Map mein store
        mpp[key] = node;

        // Recently used position par daalo
        insertFront(node);
    }
};