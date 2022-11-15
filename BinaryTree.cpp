#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node *createTree() {
    int temp;
    cout << "Enter data :" << endl;
    cin >> temp;
    Node *root = new Node(temp);

    if (temp == -1)
        return NULL;
    cout << "Enter data for left of " << temp << endl;
    root->left = createTree();
    cout << "Enter data for right of " << temp << endl;
    root->right = createTree();
    return root;
}

void InorderTransversal(Node *root) {
    if (root == NULL)
        return;
    InorderTransversal(root->left);
    cout << root->data << " ";
    InorderTransversal(root->right);
}

void PreorderTransversal(Node *root) {
    if (root == NULL)
        return;
    cout << root->data << " ";
    PreorderTransversal(root->left);
    PreorderTransversal(root->right);
}

void PostorderTransversal(Node *root) {
    if (root == NULL)
        return;
    PreorderTransversal(root->left);
    PreorderTransversal(root->right);
    cout << root->data << " ";
}

Node *insertNode(Node *root, int n) {
    if (root == NULL) {
        root = new Node(n);
        return root;
    }

    if (n <= root->data)
        root->left = insertNode(root->left, n);
    else
        root->right = insertNode(root->right, n);

    return root;
}
Node *createBinarySearchTree() {
    int n;
    cin >> n;
    Node *root = NULL;
    while (n != -1) {
        root = insertNode(root, n);
        cin >> n;
    }
    return root;
}
Node *searchInBST(Node *root, int val) {
    while (root && root->data != val) {
        if (root->data > val)
            root = root->left;
        else
            root = root->right;
    }
    return root;
}

Node *minVal(Node *root) {
    while (root->left)
        root = root->left;
    return root;
}
Node *deleteFromBST(Node *root, int val) {
    if (root == NULL)
        return NULL;

    if (root->data == val) {
        if (root->left && root->right) {
            Node *temp = minVal(root->right);
            root->data = temp->data;
            root->right = deleteFromBST(root->right, temp->data);
            return root;
        } else if (root->left) {
            Node *temp = root->left;
            delete root;
            return temp;
        } else if (root->right) {
            Node *temp = root->right;
            delete root;
            return temp;
        } else {
            delete root;
            return NULL;
        }
    } else if (root->data > val) {
        root->left = deleteFromBST(root->left, val);
    } else {
        root->right = deleteFromBST(root->right, val);
    }
    return root;
}

int main() {
    
}