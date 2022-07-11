class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> ans;
        if(!root) return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int k= q.size();
            for(int i=0; i<k; i++){
                root=q.front(); q.pop();
                if(i== 0) ans.push_back(root->val);
                if(root->right) q.push(root->right);
                if(root->left) q.push(root->left);
            }
        }
        return ans;
    }
};
