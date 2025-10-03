#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int key, value, freq;
    Node(int k, int v) {
        key = k;
        value = v;
        freq = 1;
    }
};

class LFUCache {
public:
    int capacity, minFreq;
    unordered_map<int, Node*> keyNode;    // key -> Node*
    unordered_map<int, list<int>> freqList; // freq -> list of keys

    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    int get(int key) {
        if (keyNode.find(key) == keyNode.end()) return -1;

        Node* node = keyNode[key];
        int oldFreq = node->freq;

        // remove key from old freq list
        freqList[oldFreq].remove(key);
        if (freqList[oldFreq].empty()) {
            freqList.erase(oldFreq);
            if (minFreq == oldFreq) minFreq++;
        }

        // update node freq
        node->freq++;
        freqList[node->freq].push_front(key);

        return node->value;
    }

    void put(int key, int value) {
        if (capacity == 0) return;

        if (keyNode.find(key) != keyNode.end()) {
            // key already exists
            Node* node = keyNode[key];
            node->value = value;
            get(key); // reuse get to update frequency
            return;
        }

        if ((int)keyNode.size() == capacity) {
            // evict LFU key
            int evictKey = freqList[minFreq].back(); // least recent
            freqList[minFreq].pop_back();
            
            delete keyNode[evictKey];
            keyNode.erase(evictKey);
        }

        // create new node
        Node* newNode = new Node(key, value);
        keyNode[key] = newNode;
        freqList[1].push_front(key);
        minFreq = 1;
    }
};



/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */