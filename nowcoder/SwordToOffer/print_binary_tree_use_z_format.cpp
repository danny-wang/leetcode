/**]
按之字形顺序打印二叉树 
题目描述
请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。
思路：记录每层的大小，用队列去存，偶数层需要逆序。
**/
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        if(pRoot==nullptr)
            return {};
        vector<vector<int>> res;
        bool left_to_right=true;
        int num_of_node_in_cur_level=1;
        queue<TreeNode*> node_queue;
        node_queue.push(pRoot);
        while(!node_queue.empty()){
            vector<int> temp;
            for(int i=0;i<num_of_node_in_cur_level;i++){
                TreeNode* cur=node_queue.front();
                temp.push_back(cur->val);
                if(cur->left)
                    node_queue.push(cur->left);
                if(cur->right)
                    node_queue.push(cur->right);
                node_queue.pop();
            }
            num_of_node_in_cur_level=node_queue.size();
            if(left_to_right){
                res.push_back(temp);
                left_to_right=false;
            }
            else{
                reverse(temp.begin(),temp.end());
                res.push_back(temp);
                left_to_right=true;
            }
            
        }
        return res;
    }
    
};