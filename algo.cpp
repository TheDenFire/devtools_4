#include <iostream>
//#include <queue>
//#include <stack>

using namespace std;

struct  Node
{
    int key;
    Node *left;
    Node *right;
    int height;
};

int height(Node *N)
{
    if (N == nullptr)
        return 0;
    return N->height;
}

int max(int a, int b)
{
    return (a > b)? a : b;
}

Node* newNode(int key)
{
    Node* node = new Node();
    node->key = key;
    node->left = nullptr;
    node->right = nullptr;
    node->height = 1;
    return(node);
}

Node* insert(Node* node, int key)
{
    if (node == nullptr) {
        node = newNode(key);
        return(node);
    }
    else if (key < node->key) {
        node->left = insert(node->left, key);
//        if(key == node->key){
//            key = NULL;
//        }
    }
    else if (key > node->key) {
        node->right = insert(node->right, key);
//        if(key == node->key){
//            key = NULL;
//        }
    }
    else {
        return node;
    }

    node->height = 1 + max(height(node->left), height(node->right));
//    if(left != 0) {
//        node->left = insert(node->left, left, NULL, NULL);
//    }
//    if(right != 0){
//        node->right = insert(node->right, right, NULL, NULL);
//    }
    return node;
}
Node* InsertRL(Node * root, int key){
    if(root == nullptr){
        root = newNode(key);
        return root;
    }
    else if (key < root->key) {
        root->left = InsertRL(root->left, key);
//        if(key == node->key){
//            key = NULL;
//        }
    }
    else if (key > root->key) {
        root->right = InsertRL(root->right, key);
//        if(key == node->key){
//            key = NULL;
//        }
    }
    root->height = 1 + max(height(root->left), height(root->right));
//    else
//    if(left != 0) {
//        root->left = InsertRL(root->left, left, NULL, NULL);
//    }
//    if(right != 0){
//        root->right = InsertRL(root->right, right, NULL, NULL);

    return root;

}

Node *search(Node *node, int key){
    if( node == nullptr or key == node->key){
        return node;
    }
    if(key < node->key){
        return search(node->left, key);
    }
    else{
        return search(node->right, key);
    }
}

int main()
{
    Node *root = nullptr;

    int n;
    cin >> n;
    int k[n], l[n], r[n];

    for(int i = 0; n != i; ++i){
        cin >> k[i] >> l[i] >> r[i];
        root = InsertRL(root, k[i]);
    }


//    for( int i = 0; n != i; ++i) {
//
//        root = InsertRL(root, k[i]);
//    }
    for(int m = 0; n != m; m) {
//        cout << search(root, k[m])->key << ' ';
        cout << height(search(root, k[m])->right) - height(search(root, k[m])->left) << '\n';
        m += 1;
    }
    return 0;
}
