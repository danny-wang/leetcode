/**
数组中的逆序对

题目描述
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 即输出P%1000000007 
输入描述:
题目保证输入的数组中没有的相同的数字
数据范围：
	对于%50的数据,size<=10^4
	对于%75的数据,size<=10^5
	对于%100的数据,size<=2*10^5


输入例子:
1,2,3,4,5,6,7,0

输出例子:
7
思路：
第一反映是逐个扫描整个数组，每扫描到一个数字的时候逐个比较该数字和它之后数字的大小，时间复杂度是O(n^2)
为了降低复杂度，我们考虑先比较两个相邻的数字，具体思路：
	先把数组分割为子数组，统计子数组内部的逆序对，然或在统计两个相邻子数组之间的逆序对的数目。
不难看出这其实就是归并排续，基于归并排序写出如下代码：
**/
class Solution {
public:
	int InversePairs(vector<int> data) {
		vector<int> temp = data;
		for (auto i : temp)
			cout << i << endl;
		double result = CalculateReverse(temp, 0, temp.size() - 1);
        int a;
		a = (long long)result % 1000000007;
		return a;
	}
	double Merge(vector<int> &data, int low, int mid, int high){
		int llen = mid - low + 1;
		int rlen = high - mid;
		int* left = new int[llen];
		int* right = new int[rlen];
		for (int i = 0; i<llen; i++)
			left[i] = data[low + i];
		for (int i = 0; i<rlen; i++)
			right[i] = data[mid + 1 + i];
		int j = llen - 1;
		int k = rlen - 1;
		double count = 0;
		while (j >= 0 && k >= 0){
			if (left[j]>right[k]){
				count += (k + 1);
				data[high] = left[j];
				j--;
				high--;
			}
			else{
				data[high] = right[k];
				k--;
				high--;
			}
		}
		while (j >= 0){
			data[high] = left[j];
			high--;
			j--;
		}
		while (k >= 0){
			data[high] = right[k];
			high--;
			k--;
		}
		delete[] left;
		delete[] right;
		return count;
	}

	double CalculateReverse(vector<int> &data, int low, int high){
		int mid = (high + low) >> 1;
		double a = 0;
		double b = 0;
		double c = 0;
		if (low<high){
			a = CalculateReverse(data, low, mid);
			b = CalculateReverse(data, mid + 1, high);
			c = Merge(data, low, mid, high);
		}
		return a + b + c;
	}
};
