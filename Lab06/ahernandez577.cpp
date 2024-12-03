#include <iostream>
#include <list>


using namespace std;


class HashTable {
    int m;
    list<int>* T;

    int h(int k){
        return k % m;
    }

public:
    // Constructor to initialize the hash table with size m
    HashTable(int size) : m(size){
        T = new list<int>[m];
    }

   ~HashTable(){
       delete[] T;
   }


    void insert(int key){ //hash insert
        int i = h(key);
        T[i].push_front(key);
    }


    void deleteKey(int k){
        int j = h(k);
        bool removed = false;

        for (auto i = T[j].begin(); i != T[j].end(); ++i){
            if(*i == k){
                T[j].erase(i); // Erase the key from the list at bucket `j`
                cout << k << ":DELETED;\n";
                removed = true;
                return;
            }
        }

        if(!removed){
            cout << k << ":DELETE_FAILED;\n";
        }
    }

    void search(int k){  //same concept as delete method
        int j = h(k);
        int pos = 0; //position in the linked list

        // Iterating through the list at index j
        for (auto i = T[j].begin(); i != T[j].end(); ++i, ++pos){
            if(*i == k){
                cout << k << ":FOUND_AT" << j << "," << pos << ";\n";
                return;
            }
        }

        cout << k << ":NOT_FOUND;\n"; 
    }

    void output(){
        for (int i = 0; i < m; ++i){ //lopping through each bucket index
            cout << i << ":";  //printing bucket index
            for(int key : T[i]){  //iterating at bucket i and printing out each key.
                cout << key << "->";
            }
            cout << ";\n";
        }
    }
};



int main(){

    int m;
    cin >> m;
    HashTable ht(m);

    char command;
    int key;

    while(true){
        cin >> command;

        switch(command){
            case 'i':
                cin >> key;
                ht.insert(key);
                break;

            case 'd':
                cin >> key;
                ht.deleteKey(key);
                break;

            case 's':
                cin >> key;
                ht.search(key);
                break;
            
            
            case 'o':
                ht.output();
                break;

            case 'e':
                return 0;
            
        }

    }

    return 0;
}
