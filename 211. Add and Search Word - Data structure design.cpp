/**
Design a data structure that supports the following two operations:
void addWord(word)
bool search(word)

search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.
For example:
addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true

Note:
You may assume that all words are consist of lowercase letters a-z.
思路：与208题非常类似，这里需要考虑遇到'.'的时候，需要去递归考虑所有的子树。只要有一条为真，就返回true。
**/
struct TrieNode{
    TrieNode* next[26]; 
    bool finish;    //if this string is finished
    TrieNode(){
        for(int i=0;i<26;i++){
            next[i]=nullptr;
        }
        finish=false;
    }
};
class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
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
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
       return search_helper(word, &root); 
    }
    bool search_helper(string word, TrieNode* root){
        if(word==""&&root->finish==true)   //边界条件，是否到达字符的终点
            return true;
        if(word==""&&root->finish!=true)  //边界条件，子串为空，但是没有到达字符的终点
            return false;
        TrieNode* temp=root;
        for(int i=0; i<word.size(); i++){
            if(word[i]=='.'){
                for(int j=0; j<26; j++){  //当word[i]=='.'时，递归考虑26个字母的所有可能性
                    if(temp->next[j]){
                        bool result=search_helper(word.substr(i+1),temp->next[j]);
                        if(result==true)  //只要有一个为真，就返回true
                            return true;
                        else 
                            ;
                    }
                }
                return false;  //全部为假，返回false
            }
            else if(temp->next[word[i]-'a']==nullptr)
                return false;
            else{
                temp=temp->next[word[i]-'a'];
            }
        }
        if(temp->finish==true)
            return true;
        else 
            return false;
    }
private:
    TrieNode root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */