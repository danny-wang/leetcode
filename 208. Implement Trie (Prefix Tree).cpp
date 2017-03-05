/**
Implement a trie with insert, search, and startsWith methods.
Note:
You may assume that all inputs are consist of lowercase letters a-z.
思路：
Trie树，又称字典树，单词查找树或者前缀树，是一种用于快速检索的多叉树结构，如英文字母的字典树是一个26叉树，数字的字典树是一个10叉树。
Trie一词来自retrieve，发音为/tri:/ “tree”，也有人读为/traɪ/ “try”。
Trie树可以利用字符串的公共前缀来节约存储空间。
Trie树的基本性质可以归纳为：
（1）根节点不包含字符，除根节点意外每个节点只包含一个字符。
（2）从根节点到某一个节点，路径上经过的字符连接起来，为该节点对应的字符串。
（3）每个节点的所有子节点包含的字符串不相同。
**/
struct TrieNode{
    TrieNode* next[26];
    bool finish;
    TrieNode(){
        for(int i=0;i<26;i++){
            next[i]=nullptr;
        }
        finish=false;
    }
};
class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
       // memset(root->next, 0, sizeof(root->next))
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        if(word=="")
            return;
        TrieNode* head = &root;
        for(auto i : word){
            if(head->next[i-'a']==nullptr){
                head->next[i-'a']=new TrieNode();
                head=head->next[i-'a'];
            }
            else{
                head=head->next[i-'a'];
            }
        }
        head->finish=true;
            
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        if(word=="")
            return true;
        TrieNode* head = &root;
        for(auto i:word){
            if(head->next[i-'a']==nullptr){
                return false;
            }
            else{
                head=head->next[i-'a'];
            }
        }
        if(head->finish==true)
            return true;
        else 
            return false;
        
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        if(prefix=="")
            return true;
        TrieNode* head = &root;
        for(auto i:prefix){
            if(head->next[i-'a']==nullptr){
                return false;
            }
            else{
                head=head->next[i-'a'];
            }
        }
        return true;
    }
private:
    TrieNode root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */