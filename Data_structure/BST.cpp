#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

void print_tree(TreeNode* root)
{
    if(!root)return;
    cout<<root->val<<endl;
    print_tree(root->left);
    
    print_tree(root->right);
}

TreeNode* insert(int num,TreeNode* root)
{
    TreeNode* cur = root;
    
    if(cur == nullptr)
        return new TreeNode(num);
    
    if(num < cur->val)
        cur->left = insert(num,cur->left);
    else if(num > cur->val)
        cur->right = insert(num,cur->right);
    else return cur;
}

TreeNode* remove_node(int num,TreeNode* root)
{
    if(root==nullptr) return nullptr;
    TreeNode* parent = nullptr;
    TreeNode* cur = root;

    while(cur)
    {
        if(num > cur->val)
        {
            parent = cur;
            cur=cur->right;
        }
        else if(num < cur->val)
        {
            parent = cur;
            cur=cur->left;
        }
        else break;
    }
    if(cur == nullptr) return root;

    // 度为0或1时
    if(!(cur->left && cur->right))
    {
        TreeNode* child = cur->left != nullptr ? cur->left : cur->right;

        // 删除节点
        if(cur==root)
        {
            root = child;
        }
        else
        {
            if(cur == parent->left)
                parent->left = child;
            else 
                parent->right = child;
        }
        delete cur;
    }

    // 度为2时（这里取右子树的最小节点）
    else
    {
        //找右子树最小节点
        TreeNode* right_min = cur->right;
        while(right_min->left)
        {
            right_min = right_min->left;
        }

        //替换节点
        int tmp = right_min->val;
        remove_node(right_min->val,root);
        cur->val = tmp;
    }

    return root;
}

int main()
{
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n4 = new TreeNode(4);
    TreeNode* n5 = new TreeNode(5);
    // 构建节点之间的引用（指针）
    n4->left = n2;
    n4->right = n5;
    n2->left = n1;
    n2->right = n3;


    insert(6,n4);
    // 遍历
    print_tree(n4);

    
    return 0;

}

