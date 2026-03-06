#include <iostream>
#include <algorithm>

using namespace std;

class AVLTree {
public:
    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;
        int height;
        TreeNode(int v) : val(v), left(nullptr), right(nullptr), height(1) {}
    };

private:
    TreeNode* root;

    int height(TreeNode* node) {
        return node ? node->height : 0;
    }

    void updateHeight(TreeNode* node) {
        if (node) {
            node->height = 1 + max(height(node->left), height(node->right));
        }
    }

    TreeNode* rightRotate(TreeNode* y) {
        TreeNode* x = y->left;
        TreeNode* T2 = x->right;

        x->right = y;
        y->left = T2;

        updateHeight(y);
        updateHeight(x);

        return x;
    }

    TreeNode* leftRotate(TreeNode* x) {
        TreeNode* y = x->right;
        TreeNode* T2 = y->left;

        y->left = x;
        x->right = T2;

        updateHeight(x);
        updateHeight(y);

        return y;
    }

    int getBalance(TreeNode* node) {
        return height(node->left) - height(node->right);
    }

    TreeNode* insert(TreeNode* node, int val) {
        if (!node) return new TreeNode(val);

        if (val < node->val) {
            node->left = insert(node->left, val);
        } else if (val > node->val) {
            node->right = insert(node->right, val);
        } else {
            return node; // Duplicate values not allowed
        }

        updateHeight(node);

        int balance = getBalance(node);

        // Left Left Case
        if (balance > 1 && val < node->left->val) {
            return rightRotate(node);
        }

        // Right Right Case
        if (balance < -1 && val > node->right->val) {
            return leftRotate(node);
        }

        // Left Right Case
        if (balance > 1 && val > node->left->val) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case
        if (balance < -1 && val < node->right->val) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    TreeNode* minValueNode(TreeNode* node) {
        TreeNode* current = node;
        while (current->left) {
            current = current->left;
        }
        return current;
    }

    TreeNode* remove(TreeNode* node, int val) {
        if (!node) return node;

        if (val < node->val) {
            node->left = remove(node->left, val);
        } else if (val > node->val) {
            node->right = remove(node->right, val);
        } else {
            if (!node->left || !node->right) {
                TreeNode* temp = node->left ? node->left : node->right;
                if (!temp) {
                    temp = node;
                    node = nullptr;
                } else {
                    *node = *temp;
                }
                delete temp;
            } else {
                TreeNode* temp = minValueNode(node->right);
                node->val = temp->val;
                node->right = remove(node->right, temp->val);
            }
        }

        if (!node) return node;

        updateHeight(node);

        int balance = getBalance(node);

        // Left Left Case
        if (balance > 1 && getBalance(node->left) >= 0) {
            return rightRotate(node);
        }

        // Left Right Case
        if (balance > 1 && getBalance(node->left) < 0) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Right Case
        if (balance < -1 && getBalance(node->right) <= 0) {
            return leftRotate(node);
        }

        // Right Left Case
        if (balance < -1 && getBalance(node->right) > 0) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    TreeNode* find(TreeNode* node, int val) {
        if (!node || node->val == val) return node;
        if (val < node->val) return find(node->left, val);
        return find(node->right, val);
    }

public:
    AVLTree() : root(nullptr) {}

    void insert_node(int val) {
        root = insert(root, val);
    }

    void remove_node(int val) {
        root = remove(root, val);
    }

    TreeNode* find_node(int val) {
        return find(root, val);
    }
};

int main() {
    AVLTree tree;
    tree.insert_node(10);
    tree.insert_node(20);
    tree.insert_node(30);
    tree.insert_node(40);
    tree.insert_node(50);
    tree.insert_node(25);

    AVLTree::TreeNode* found = tree.find_node(30);
    if (found) {
        cout << "Found: " << found->val << endl;
    } else {
        cout << "Not found" << endl;
    }

    tree.remove_node(30);
    found = tree.find_node(30);
    if (found) {
        cout << "Found: " << found->val << endl;
    } else {
        cout << "Not found" << endl;
    }

    return 0;
}
