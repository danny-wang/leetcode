/**
字符流中第一个不重复的字符 

题目描述
请实现一个函数用来找出字符流中第一个只出现一次的字符。例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。
当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。
输出描述:
如果当前字符流没有存在出现一次的字符，返回#字符。
思路：
哈希表特殊处理
通过哈希表来统计字符流中每个字符，数组的值是这个CHAR出现的位置，哈希表初始化每个键值对应的value均为-1，
如果字符出现一次，则value等于该字符的下标，如果字符出现两次，则value等于-2；
这样遍历哈希表时，第一个value大于0的字符就是第一个出现一次的字符；时间复杂度为O(1)
**/
class Solution
{
public:
    Solution():index(0){
        for(int i=0;i<256;i++)
            occur_location[i]=-1;
    }
  //Insert one char from stringstream
    void Insert(char ch)
    {
        if(occur_location[ch]==-1)
             occur_location[ch]=index;
        else if(occur_location[ch]>=0)
            occur_location[ch]=-2;
        index++;
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
    	int res=INT_MAX;
        char temp;
        for(int i=0;i<256;i++){
            if(occur_location[i]>=0 &&occur_location[i]<res){
                temp=(char)i;
                res=occur_location[i];
            }
        }
        if(res==INT_MAX)
            return '#';
        else
            return temp;
    }
private:
    int occur_location[256];
    int index;

};