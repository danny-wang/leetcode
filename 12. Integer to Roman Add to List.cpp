/**
12. Integer to Roman Add to List
Given an integer, convert it to a roman numeral.
Input is guaranteed to be within the range from 1 to 3999.

解题思路：
其中每两个阶段的之间有一个减法的表示，比如 900=CM， C 写在 M 前面表示 M-C。
所以映射关系应该是
string symbol[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};    
int value[]=    {1000,900,500,400, 100, 90,  50, 40,  10, 9,   5,  4,   1};   

然后就是贪心的做法，每次选择能表示的最大值，把对应的字符串连起来。
**/
class Solution {
public:
    string intToRoman(int num) {
        const int radix[] = { 1000, 900, 500, 400, 100, 90,
			50, 40, 10, 9, 5, 4, 1 };
		const string symbol[] = { "M", "CM", "D", "CD", "C", "XC",
			"L", "XL", "X", "IX", "V", "IV", "I" };
		string roman;
		for (size_t i = 0; num > 0; ++i)
		{
			int count = num / radix[i];
			num %= radix[i];
			for (; count > 0; --count) roman += symbol[i];
		}
		return roman;
	
    }
};