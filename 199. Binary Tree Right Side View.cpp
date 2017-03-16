/**
199. Binary Tree Right Side View
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---

You should return [1, 3, 4].
思路：
二叉树的层次遍历，到每一层最后一个节点，即装入result
每层最后一个节点的判断：
（1）记录当前层有几个节点
（2）当弹出到当前层最后一个节点的时候，计算目前queue中有几个节点，即可知道下一层有多少个节点，不断循环，直到队列为空
**/
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
    vector<int> rightSideView(TreeNode* root) {
        if(root==nullptr)
            return {};
        vector<int> result;  //存储最终结果
        queue<TreeNode*> layer; //分层存储所有节点
        layer.push(root);
        int num=1;
        while(!layer.empty()){
            for(int i=num; i>0;i--){
                if(i==1){ //当i==1时，说明当前节点是该层的最后一个节点
                    result.push_back(layer.front()->val);
                    if(layer.front()->left)
                        layer.push(layer.front()->left);
                    if(layer.front()->right)
                        layer.push(layer.front()->right);
                    layer.pop();
                    num=layer.size();
                }
                else{
                    if(layer.front()->left)
                        layer.push(layer.front()->left);
                    if(layer.front()->right)
                        layer.push(layer.front()->right);
                    layer.pop();
                }
            }
        }
        return result;
    }
};