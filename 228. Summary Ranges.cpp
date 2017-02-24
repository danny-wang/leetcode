/**
Given a sorted integer array without duplicates, return the summary of its ranges.
For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
思路：分情况讨论，一次处理一个范围
**/
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        if(nums.size()==0)
            return result;
        int l=nums[0]; //当前范围的左值
        int r=0;  //当前范围的右值
        stringstream ss;  //生成范围
        ss<<l;
        bool sig=false; //标识当前范围内是否大于等于两个数，如果大于，则为true
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]+1){
                r=nums[i];
                sig=true;
            }
            else{  //与前一个元素不同，需要输出之前的范围。
                string s;
                if(!sig){
                    ;
                }
                else{  //当前范围内大于一个数，则需要->和右值
                    ss<<"->";
                    ss<<r;
                }
                ss>>s;
                result.push_back(s);
                ss.clear(); //重置ss状态
                ss.str("");
                ss<<nums[i]; //当前范围的左值
                sig=false;
            }
        }
        if(sig){  //最后一个范围，包含多个数
            string s;
            ss<<"->";
            ss<<nums[nums.size()-1];
            ss>>s;
            result.push_back(s);
        }
        if(!sig){  //最后一个范围，只包含一个数
            string s;
           ss>>s;
           cout<<"s="<<s<<endl;
           result.push_back(s); 
        }
        return result;
        
    }
};