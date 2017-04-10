/**
序列化二叉树
题目描述
请实现两个函数，分别用来序列化和反序列化二叉树
思路
二叉树的遍历应该也做了不少了，所以递归实现前序遍历和由前序遍历得到的串重新构树应该不难，这道题主要的问题是我们对于输入流的控制。
遇到节点为空的时候，用‘#‘代替
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
    char* Serialize(TreeNode *root) {    
        if(!root)
            return nullptr;
        stringstream ss;
        SerializeHelper(root,ss);
        string str=ss.str();
        char* temp=new char[str.size()+1];
        for(int i=0;i<str.size();i++)
            temp[i]=str[i];
        temp[str.size()]='\0';
        return temp;
        
    }
    TreeNode* Deserialize(char *str) {
        if(!str)
            return nullptr;
    	string temp=str;
        stringstream ss;
        ss.str(temp);
        TreeNode* temp2=new TreeNode(1);
        TreeNode **root=&temp2;
        DeserializeHelper(root,ss);
        return *root;
    }
    void SerializeHelper(TreeNode *root, stringstream &ss){
        if(root==nullptr){
            ss<<"# ";
            return;
        }
        ss<<root->val<<" ";
        SerializeHelper(root->left,ss);
        SerializeHelper(root->right,ss);
            
    }
    void DeserializeHelper(TreeNode **pRoot,stringstream &ss){
        int num;
        if(GetNum(ss,num)){
            *pRoot=new TreeNode(num);
            DeserializeHelper((&((*pRoot)->left)),ss);
            DeserializeHelper((&((*pRoot)->right)),ss);
        }
    }
    bool GetNum(stringstream& ss, int& num){
        char temp[32];
        ss>>temp;
        if(temp[0]=='#')
            return false;
        else{
            num=atoi(temp);
            return true;
        }
 
    }
};