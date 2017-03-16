/**187. Repeated DNA Sequences
All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, 
it is sometimes useful to identify repeated sequences within the DNA.
Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.
For example,
Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

Return:
["AAAAACCCCC", "CCCCCAAAAA"].

思路：找出现2次或两次以上的长度为10的字串。从头到size-10的所有长度为10的字串，依次添加到一个map中去，因为map中的key只能出现一次，所以每次判断这个字串是否已经存在了，
存在的话就把value加一，否则添加一个键值对到map中去，因为每次需要遍历map，所以时间复杂度是O（nlogn）.
代码：
**/
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.size()<10)
            return {};
        map<string,int> sequences;
        for(int i=0; i<=s.size()-10; i++){
            if(sequences.find(s.substr(i,10))==sequences.end()){
                sequences.insert(make_pair(s.substr(i,10),1));
            }
            else
                sequences[s.substr(i,10)]+=1;
        }
        vector<string> result;
        for(auto ite=sequences.begin();ite!=sequences.end();ite++){
            if(ite->second>1)
                result.push_back(ite->first);
        }
        return result;
    }
};
/**
思路2：考虑到只有4种字母，ACGT，固定10位字符，所以排列组合数是一定的，仅有4^10 = 1048576种可能。因此，可以让10位字符序列做一个Hash。
A = 00
C = 01
G = 10
T = 11

将他们拼接起来，变成一个数value。
如： AAACCC = 00 00 00 01 01 01 （二进制） = 21 （十进制）
然后遍历整个序列，每10个字符生成一个value。因为只需要判断10个字符的值，每个字符占2位，所以我们只需要20位的bit，通过掩码0xFFFFF来过滤掉10位之前的字符所对应的位。
当某value出现过一次后，就将对应的序列加入到结果中。

思路3：字符串中只包含4个字符：A, C, G, T。它们的ASCII码的二进制形式是：
  ● A : 0100 0001
  ● C : 0100 0011
  ● G : 0100 0111
  ● T : 0101 0100
这4个字符的末3位是不同的，因此，我们可以 3个bits 来表示其中的一个字符。
又因为每个子串的长度为10，因此总的位数是：10 x 3 = 30，一个int就足够存放它。
**/