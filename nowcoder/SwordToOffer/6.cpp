/**
旋转数组的最小数字 
题目描述
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。 
**/
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
      	if(rotateArray.size()==0)
        	return 0;
      	int left=0;
        int right=rotateArray.size()-1;
        while(left<right){
            int mid=(left+right)>>1;
            if(rotateArray[mid]>rotateArray[left] && rotateArray[mid]<rotateArray[right])
                return rotateArray[left];
            else if(rotateArray[mid]==rotateArray[left] && rotateArray[mid]==rotateArray[right])
                return search_inorder(rotateArray,left,right);
            else if(rotateArray[mid]>rotateArray[right])
                left=mid+1;
            else
                right=mid;
        }
        return rotateArray[left];
    }
    int search_inorder(vector<int> rotateArray,int left,int right){
        int min_num=INT_MAX;
        for(int i=left;i<right;i++){
            if(rotateArray[i]<min_num)
                min_num=rotateArray[i];
        }
        return min_num;
    }
};
