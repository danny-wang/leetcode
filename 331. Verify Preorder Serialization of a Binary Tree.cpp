/**
331. Verify Preorder Serialization of a Binary Tree
One way to serialize a binary tree is to use pre-order traversal. When we encounter a non-null node, we record the node's value. If it is a null node, we record using a sentinel value such as #.
     _9_
    /   \
   3     2
  / \   / \
 4   1  #  6
/ \ / \   / \
# # # #   # #

For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.
Given a string of comma separated values, verify whether it is a correct preorder traversal serialization of a binary tree. Find an algorithm without reconstructing the tree.
Each comma separated value in the string must be either an integer or a character '#' representing null pointer.
You may assume that the input format is always valid, for example it could never contain two consecutive commas such as "1,,3".
Example 1:
"9,3,4,#,#,1,#,#,2,#,6,#,#"
Return true
Example 2:
"1,#"
Return false
Example 3:
"9,#,#,1"
Return false

思路：
将元素依次push到stack，遇到数字，判断stack的大小是否大于等于2，且后两个为#，如果是，则弹出他们，push一个#。
如果最后vector大小为1，且为#，则是合法的前序序列！
**/
class Solution {
public:
    bool isValidSerialization(string preorder) {
        stack<char> n_stack;
        int size=preorder.size();
        for(int i=size-1;i>=0;i--){
            //cout<<preorder[i]<<endl;
            if(preorder[i]==',')
                continue;
            else if(preorder[i]=='#')
                n_stack.push('#');
            else{
                while(preorder[i]!=','){ //处理当前数字
                    i--;
                }
                if(n_stack.size()<2)
                    return false;
                char a=n_stack.top();
                //cout<<"a="<<a<<endl;
                n_stack.pop();
                char b=n_stack.top();
                //cout<<"b="<<b<<endl;
                n_stack.pop();
                if(a=='#' && b=='#')
                    n_stack.push('#');
                else
                    return false;
            }
        }
        return (n_stack.size()==1)? true : false;
    
    }
};