/**
数组中重复的数字 

题目描述
在一个长度为n的数组里的所有数字都在0到n-1的范围内。 数组中某些数字是重复的，但不知道有几个数字是重复的。也不知道每个数字重复几次。请找出数组中任意一个重复的数字。 例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是重复的数字2或者3。
思路：利用哈希表来解决。每扫描到一个元素，用O(1)的时间判断是否已经在哈希表中了，时间复杂度是O(n)， 空间复杂度也是O(n).
利用 unordered_set：
**/
class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        unordered_set<int> hash_set;
        if(length<1)
            return false;
        int range=length-1;
        for(int i=0;i<length;i++){
            if(numbers[i]<=range && numbers[i]>=0){
                if(hash_set.find(numbers[i])!=hash_set.end()){
                    *duplication=numbers[i];
                    return true;
                }
                else
                    hash_set.insert(numbers[i]);
            }
            else
                return false;
        }
        return false;
    }
};
//利用数组：
bool duplicate(int numbers[], int length, int* duplication) {
        if(length<1)
            return false;
        int range=length-1;
        int *hash_set= new int[length];
        for(int i=0;i<length;i++){
            hash_set[i]=0;
        }
        for(int i=0;i<length;i++){
            if(numbers[i]<=range && numbers[i]>=0){
                if(hash_set[numbers[i]]==1){
                    *duplication=numbers[i];
                    return true;
                }
                else
                    hash_set[numbers[i]]=1;
            }
            else
                return false;
        }
        return false;
    }
//思路2：我们从头到尾扫描这个数组，首先看第i位的数字x是否等于i，不等则把x与a[x]交换，然后继续这个操作直到新的x等于i
//如果此时x与a[x]相等，那么这就是一个重复的值。时间复杂度是O(n)， 空间复杂度是O(1).
 bool duplicate(int numbers[], int length, int* duplication) {
        if(length<1)
            return false;
        int range=length-1;
        int i=0;
        while(i<length){
             if(numbers[i]<=range && numbers[i]>=0){
                 if(numbers[i]==i){
                     i++;
                     continue;
                 }
                 if(numbers[i]!=i){
                     if(numbers[i]==numbers[numbers[i]]){
                         *duplication=numbers[i];
                         return true;
                     }
                     else{
                         int temp=numbers[numbers[i]];
                         numbers[numbers[i]]=numbers[i];
                         numbers[i]=temp; 
                     }
                 
                 }
             }
            else
                return false;
        }
        return false;
    }