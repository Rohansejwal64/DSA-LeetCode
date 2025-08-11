/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> mp; // original -> clone

    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        // If this node was already cloned, return its clone
        if (mp.find(node) != mp.end()) return mp[node];

        // Create clone
        Node* clone = new Node(node->val);
        mp[node] = clone;

        // Clone neighbors recursively
        for (auto neighbor : node->neighbors) {
            clone->neighbors.push_back(cloneGraph(neighbor));
        }

        return clone;
    }
};