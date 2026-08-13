class LFUCache {
public:

    // Har cache item ki information
    struct Node {
        int key;
        int value;
        int freq;

        Node(int k, int v) {
            key = k;
            value = v;
            freq = 1;       // New node ki frequency 1
        }
    };


    int capacity;

    // key -> Node
    unordered_map<int, Node*> keyMap;

    // frequency -> nodes
    unordered_map<int, list<Node*>> freqMap;

    // Sabse minimum frequency
    int minFreq;


    LFUCache(int capacity) {

        this->capacity = capacity;

        minFreq = 0;
    }


    int get(int key) {

        // Key exist nahi karti
        if (keyMap.find(key) == keyMap.end()) {
            return -1;
        }

        // Node nikalo
        Node* node = keyMap[key];

        // Purani frequency
        int oldFreq = node->freq;


        // Purani frequency wali list se remove
        freqMap[oldFreq].remove(node);


        // Agar purani frequency ki list empty ho gayi
        // aur wahi minFreq thi
        if (freqMap[oldFreq].empty() &&
            minFreq == oldFreq) {

            minFreq++;
        }


        // Frequency increase
        node->freq++;


        // New frequency wali list mein daalo
        freqMap[node->freq].push_back(node);


        return node->value;
    }


    void put(int key, int value) {

        // Capacity 0
        if (capacity == 0) {
            return;
        }


        // --------------------------------
        // CASE 1: Key already exists
        // --------------------------------

        if (keyMap.find(key) != keyMap.end()) {

            Node* node = keyMap[key];

            // Value update
            node->value = value;


            // Purani frequency
            int oldFreq = node->freq;


            // Purani list se remove
            freqMap[oldFreq].remove(node);


            // Agar ye min frequency thi
            if (freqMap[oldFreq].empty() &&
                minFreq == oldFreq) {

                minFreq++;
            }


            // Frequency increase
            node->freq++;


            // New frequency list mein daalo
            freqMap[node->freq].push_back(node);

            return;
        }


        // --------------------------------
        // CASE 2: New key
        // --------------------------------

        // Cache full hai
        if (keyMap.size() == capacity) {

            // Sabse kam frequency
            // wali list se remove karenge

            Node* lfu =
                freqMap[minFreq].front();


            // List se remove
            freqMap[minFreq].pop_front();


            // Map se remove
            keyMap.erase(lfu->key);


            // Memory free
            delete lfu;
        }


        // New node create
        Node* node = new Node(key, value);


        // keyMap mein add
        keyMap[key] = node;


        // New node ki frequency = 1
        freqMap[1].push_back(node);


        // Ab minimum frequency 1 hai
        minFreq = 1;
    }
};