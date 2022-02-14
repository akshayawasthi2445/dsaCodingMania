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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL)return {};
        int reverseOrder = 0;
        vector<vector<int>> V;
        vector<TreeNode*> levelStore{root};
        while(!levelStore.empty()){
            vector<TreeNode*> current;
            vector<int> levelStoreData;
            for(auto i:levelStore){
                if(i->left)
                    current.push_back(i->left);
                if(i->right)
                    current.push_back(i->right);
                levelStoreData.push_back(i->val);
            }
            if(reverseOrder==0){
                V.push_back(levelStoreData);
                reverseOrder=1;
            }
            else{
                reverse(levelStoreData.begin(),levelStoreData.end());
                V.push_back(levelStoreData);
                reverseOrder=0;
            }
            swap(levelStore,current);
        }
        return V;
    }
};