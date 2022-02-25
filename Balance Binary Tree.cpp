/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int max(int a,int b){
        if(a>b)return a;
        else return b;
    }
    
    int height(TreeNode* root,int& balancestatus){
        if(root == NULL)return -1;
        int lheight = height(root->left,balancestatus);
        int rheight = height(root->right,balancestatus);
        if((lheight-rheight)>1 || (rheight-lheight)>1){
            balancestatus = 0;
        }
        return max(lheight,rheight)+1;
    }
    bool isBalanced(TreeNode* root) {
        int balancestatus = 1;
        int heightofroot=height(root,balancestatus);
        if(balancestatus == 1)return true;
        return false;
    }
};