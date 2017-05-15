/**
299. Bulls and Cows
You are playing the following Bulls and Cows game with your friend: 
You write down a number and ask your friend to guess what the number is. 
Each time your friend makes a guess, you provide a hint that indicates how many digits in said 
guess match your secret number exactly in both digit and position (called "bulls") and how many 
digits match the secret number but locate in the wrong position (called "cows"). 
Your friend will use successive guesses and hints to eventually derive the secret number.
For example:
Secret number:  "1807"
Friend's guess: "7810"

Hint: 1 bull and 3 cows. (The bull is 8, the cows are 0, 1 and 7.)
Write a function to return a hint according to the secret number and friend's guess, use A to indicate the bulls and B to indicate the cows. 
In the above example, your function should return "1A3B".

Please note that both secret number and friend's guess may contain duplicate digits, for example:
Secret number:  "1123"
Friend's guess: "0111"

In this case, the 1st 1 in friend's guess is a bull, the 2nd or 3rd 1 is a cow, and your function should return "1A1B".
You may assume that the secret number and your friend's guess only contain digits, and their lengths are always equal.
问题分析：这道题看起来很唬人，其实就是遍历两个字符串，看在某个位置是否相等，如果相等，就A++；如果不相等，就把secret中的字符和guess中的字符再分别用HASH_MAP存起来；
然后再遍历第二遍，第二遍的遍历就是，如果字符在secret中出现过，就看是否在guess中出现过，如果出现过，就把B+min（map1.size(),map2.size()）
**/
class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char,vector<int>> map_a;
        unordered_map<char,vector<int>> map_b;
        int bull,cows;
        bull=cows=0;
        for(int i=0;i<secret.size();i++){
            if(secret[i]==guess[i])
                bull++;
            else{
                if(map_a.find(secret[i])==map_a.end()){ //不存在
                    vector<int> temp={i};
                    map_a[secret[i]]=temp;
                }
                else
                    map_a[secret[i]].push_back(i);
                if(map_b.find(guess[i])==map_b.end()){ //不存在
                    vector<int> temp={i};
                    map_b[guess[i]]=temp;
                }
                else
                    map_b[guess[i]].push_back(i);
            }
        }
        for(auto ite=map_a.begin();ite!=map_a.end(); ite++){
            char i=ite->first;
            int size_a=map_a[i].size();
            if(map_b.find(i)==map_b.end())
                continue;
            else{
                int size_b=map_b[i].size();
                cows+=min(size_a,size_b);
            }
        }
        stringstream ss;
        ss<<bull<<'A'<<cows<<"B";
        return ss.str();
    }
};