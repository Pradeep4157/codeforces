#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    i think that this can be solved using the idea of tree where or trie where first node will have

    two children and each one of them will have two child left denoting how many of the current suffix

    set bit numbers have next bit as 0 and right will denote how many of this suffix bits have 1 set bit

    as the next bit . each node is going to have pointer to right and left child and a vector

    to store the indices with this suffix bits lets try to see whether this works or not

    how are we creating a tree


    after insertion we will do BFS for each arr[i] to get the values that will give arr[i]^thatvalue >= k 

    how will the BFS go ?

    at a bit : 
        if that bit is not set in k then we will push both the left and right pointer of all the current nodes if they exist !!

        else:
            if that bit is already set in k : 
                
                if the current bit is also set in arr[i] then we only need 
*/
// this is what each node is going to store
struct Node
{
    Node *left = nullptr;
    Node *right = nullptr;
    vector<int> indices;
};

void insert(int value, int index, Node *temp)
{
    while (value)
    {
        // we will keep inserting the value in the nodes it belongs
        if (value & 1)
        {
            // that means we are going right side
            if (temp->right == NULL)
            {

                // then we need to create a new right node
                temp->right = new Node();
            }

            // now also push the index in that node
            temp->right->indices.push_back(index);
            temp = temp->right;
        }
        else
        {
            // that means we are going to the left side
            if (temp->left == NULL)
            {
                temp->left = new Node();
            }
            // now we push the index
            temp->left->indices.push_back(index);
            temp = temp->left;
        }
        value >>= 1;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        // now first we create root node
        Node *root = new Node();

        // now we will insert all the indices in the tree

        for (int i = 0; i < n; i++)
        {
            Node *temp = root;
            insert(arr[i], i, temp);
        }

        // now insertion is done !! now we find the values

        // now for each node we will do BFS traversal to find the indices 
    }
    return 0;
}
