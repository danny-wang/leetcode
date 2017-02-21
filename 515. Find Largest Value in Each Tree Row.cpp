//You need to find the largest value in each row of a binary tree.
//思路：通过动态规划将每一层的所有Node指针存在一个 vector<vector<TreeNode*>>，然后计算其中每一个vector的最大值，保存起来即是解。
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
