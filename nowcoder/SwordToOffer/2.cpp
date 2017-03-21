/**
题目描述
请实现一个函数，将一个字符串中的空格替换成“%20”。
例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。 
**/
class Solution {
public:
	void replaceSpace(char *str,int length) {
		string temp(str);
        stringstream ss;
        for(int i=0;i<temp.size();i++){
            if(temp[i]==' '){
                ss<<"%20";
            }
            else
                ss<<temp[i];
        }
        ss>>str;
	}
};
