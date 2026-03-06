#include <bits/stdc++.h>
using namespace std;

class AVL_Tree
{
    public:
        struct TreeNode
        {
            int val{};
            int height = 0;
            TreeNode* left{};
            TreeNode* right{};
            TreeNode() = default;
            explicit TreeNode(int x) : val(x){}
        };
        
        TreeNode* root;
}