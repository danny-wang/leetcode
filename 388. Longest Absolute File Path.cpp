/**
388. Longest Absolute File Path 
Suppose we abstract our file system by a string in the following manner:
The string "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext" represents:
dir
    subdir1
    subdir2
        file.ext

The directory dir contains an empty sub-directory subdir1 and a sub-directory subdir2 containing a file file.ext.
The string "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext" represents:
dir
    subdir1
        file1.ext
        subsubdir1
    subdir2
        subsubdir2
            file2.ext

The directory dir contains two sub-directories subdir1 and subdir2. subdir1 contains a file file1.ext and an empty second-level sub-directory subsubdir1. subdir2 contains a second-level sub-directory subsubdir2 containing a file file2.ext.
We are interested in finding the longest (number of characters) absolute path to a file within our file system. For example, in the second example above, the longest absolute path is "dir/subdir2/subsubdir2/file2.ext", and its length is 32 (not including the double quotes).
Given a string representing the file system in the above format, return the length of the longest absolute path to file in the abstracted file system. If there is no file in the system, return 0.
Note:
  ● The name of a file contains at least a . and an extension.
  ● The name of a directory or sub-directory will not contain a ..
Time complexity required: O(n) where n is the size of the input string.
Notice that a/aa/aaa/file1.txt is not the longest file path, if there is another path aaaaaaaaaaaaaaaaaaaaa/sth.png.
几个基础知识，关于string的
1. '\n','\t'这种都算作一个char，长度都是1
思路：
通过使用unordered_map将深度和总长度相互映射，通过更新map就能得到最长绝对文件路径。
找到'\n'时判断当前深度是否是文件还是文件夹，找到‘\t’深度自增一(每次遍历到'\n',要level=0,因为'\t'就是相对应深度)。
**/
class Solution {
public:
    int lengthLongestPath(string input) {
        int res=0;
        unordered_map<int,int> map;  //层数和当前路径长度的对应关系
        map[0]=0;
        int size=input.size();
        int level=1;
        for(int i=0;i<size;i++){
            int start=i;
            while(i<size && input[i]!='\n' && input[i]!='\t')
                i++;
            if(i==size || input[i]=='\n'){
                string temp=input.substr(start,i-start);
                if(temp.find('.')!=string::npos){
                    res=max(res,map[level-1]+(int)temp.size());
                    level=1;
                }
                else{
                    map[level]=map[level-1]+(int)temp.size()+1;
                    //cout<<"map["<<level<<"]"<<map[level]<<endl;
                    level=1;
                }
            }
            else
                level++;
        }
        return res;
    }
};