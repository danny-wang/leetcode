/**
数字在排序数组中出现的次数
题目描述
统计一个数字在排序数组中出现的次数。
思路：
用二分查找的办法，首先找第一个k，然后在找最后一个k,计算中间有多少个元素即可。
**/
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        int first=first_k(data,k);
        int last=last_k(data,k);
        if(first==-1)
            return 0;
        else
            return last-first+1;
    }
    int first_k(vector<int>& data, int k){
    	if(data.empty())
            return -1;
    	int low=0;
    	int high=data.size()-1;
    	while(low<=high){
            int mid=(high+low)>>1;
            if(data[mid]==k && ((mid>1 && data[mid-1]!=k)  || mid==0))
                return mid;
            else if(data[mid]==k){
                high=mid-1;
            }
            else if(data[mid]>k){
                high=mid-1;
            }
            else
                low=mid+1;
        }
    	return -1;
	}
 	int last_k(vector<int>& data, int k){
    	if(data.empty())
            return -1;
    	int low=0;
    	int high=data.size()-1;
    	while(low<=high){
            int mid=(high+low)>>1;
            if(data[mid]==k && ((mid<data.size()-1 && data[mid+1]!=k ) ||mid==data.size()-1))
                return mid;
            else if(data[mid]==k){
                low=mid+1;
            }
            else if(data[mid]>k){
                high=mid-1;
            }
            else
                low=mid+1;
        }
    	return -1;
	}
};