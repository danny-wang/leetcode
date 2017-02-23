//You need to find the largest value in each row of a binary tree.
//思路 one：通过动态规划将每一层的所有Node指针存在一个 vector<vector<TreeNode*>>，然后计算其中每一个vector的最大值，保存起来即是解。
//better: 思路 two：这道题让我们找二叉树每行的最大的结点值，那么实际上最直接的方法就是用层序遍历，然后在每一层中找到最大值，加入结果res中即可
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> result={};
        if(root==nullptr)
            return result;
        vector<vector<TreeNode*>> nodes={};
        vector<TreeNode*> first_level_nodes;
        first_level_nodes.push_back(root);
        nodes.push_back(first_level_nodes);
        helper(0,nodes);   //生成分层的指针，存在nodes中
        for(auto i : nodes){   //选择每一层的最大值
            int value=INT_MIN;
            for(auto j : i){
                if((j->val) > value)
                    value=j->val;
            }
            result.push_back(value);
        }
        return result;
        
    }
    //level：当前是第几层
    void helper(int level, vector<vector<TreeNode*>>& nodes){
        bool signal=false;  //标识是否还会有下一层节点存在
        vector<TreeNode*> temp={};
        for(auto i : nodes[level]){
            if(i->left){
                signal=true;
                temp.push_back(i->left);
            }
            if(i->right){
                signal=true;
                temp.push_back(i->right);
            }
        }
        if(signal){
             nodes.push_back(temp);
             helper(level+1, nodes);
        }
        else
            return;
    }
};

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        if(!root)
            return result;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            int max=INT_MIN;
            int size=que.size();
            for(int i=0;i<size;i++){
                TreeNode* ptr= que.front();
                if(ptr->val> max)
                    max=ptr->val;
                if(ptr->left)
                    que.push(ptr->left);
                if(ptr->right)
                    que.push(ptr->right);
                que.pop();
            }
            result.push_back(max);
        }
        return result;
    }
};
