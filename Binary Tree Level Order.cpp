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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<TreeNode*> levelStore{root};
        vector<vector<int>> V;
        
        while(!levelStore.empty()){
            vector<TreeNode*> current;
            vector<int> currLevelData;
            for(auto i : levelStore){
                if(i->left)
                    current.push_back(i->left);
                if(i->right)
                    current.push_back(i->right);
                currLevelData.push_back(i->val);
            }
            V.push_back(currLevelData);
            swap(current,levelStore);
        }
        return V;
    }
};