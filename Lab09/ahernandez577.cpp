#include <iostream>
#include <vector>
#include <queue>
#include <string>


// Credit to yt video help, textbook, and g4g

using namespace std;

string HuffmanEncodings[6];


struct Node {
    Node *left;
    Node *right;
    string letter; 
    int frequency;
    int unique_id;

    Node(string l, int frequency){
        left = nullptr;
        right = nullptr;
        this->letter = l;
        this->frequency = frequency;
        this->unique_id = 0;
    }

    Node(string letter, int frequency, int unique_id){
        left = nullptr;
        right = nullptr;
        this->letter = letter;
        this->frequency = frequency;
        this->unique_id = unique_id; // Specific unique ID
    }
};

struct compare {

    bool operator()(Node* left, Node* right) {
        if (left->frequency == right->frequency) {
            return left->unique_id > right->unique_id;
        }
        return left->frequency > right->frequency;
    }
};

void generateHuffmanCodes(Node* root, string encoding, string alphabet[], int size) {
    if(!root) return;

    if(root->letter != "!") {
        for (int j = 0; j < size; j++){
            if(root->letter == alphabet[j]) {
                HuffmanEncodings[j] = encoding;
            }
        }
    } else {
        generateHuffmanCodes(root->left, encoding + "0", alphabet, size);
        generateHuffmanCodes(root->right, encoding + "1", alphabet, size);
    }
}

void Huffman(int size, string A[], vector<int>& C){
    priority_queue<Node *, vector<Node *>, compare> Huffmanheap; // Priority queue ensures the smallest frequencies are processed first

    for (int i = 0; i < size; i++){
        Node *temp = new Node(A[i], C[i], i + 1);
        Huffmanheap.push(temp);
    }

    //building huffman tree
    while (Huffmanheap.size() > 1){

        Node *left = Huffmanheap.top();
        Huffmanheap.pop();
        Node *right = Huffmanheap.top();
        Huffmanheap.pop();

        // Create a new parent node
        Node *newParent = new Node("!", left->frequency + right->frequency);
        if (left->frequency == right->frequency && left->unique_id > right->unique_id)
        {
            newParent->left = right;
            newParent->right = left;
            newParent->unique_id = right->unique_id;
        }
        else
        {
            newParent->left = left;
            newParent->right = right;
            newParent->unique_id = left->unique_id;
        }

        Huffmanheap.push(newParent);
    }

    generateHuffmanCodes(Huffmanheap.top(), "", A, size);

    char f = 'A';
    for (int i = 0; i < 6; i++, f++) {
        cout << f << ":" << HuffmanEncodings[i] << endl;
    }
}

int main(){

    int s = 6;
    vector<int> C;
    string A[s];
    A[0] = "A";
    A[1] = "B";
    A[2] = "C";
    A[3] = "D";
    A[4] = "E";
    A[5] = "F";

    for (int i = 0; i < s; i++){
        int v;
        cin >> v;
        C.push_back(v);
    }

    Huffman(s, A, C);

    return 0;
}
