#include<bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:
    

*/
#include <bits/stdc++.h>
using namespace std;

template <typename T>
class DoublyLinkedList {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;
        Node(T val) : data(val), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int sz;

public:
    // Constructor
    DoublyLinkedList() : head(nullptr), tail(nullptr), sz(0) {}


    // Insert at head
    void push_front(T val) {
        Node* node = new Node(val);
        if (!head) head = tail = node;
        else {
            node->next = head;
            head->prev = node;
            head = node;
        }
        sz++;
    }

 

    // Print forward
    void print_forward() const {
        Node* cur = head;
        while (cur) {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << "\n";
    }


};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t; 
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        
        DoublyLinkedList<int> dll;
        
        

    }
    return 0;
}
