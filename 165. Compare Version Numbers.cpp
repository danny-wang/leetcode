/**165. Compare Version Numbers
Compare two version numbers version1 and version2.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.
You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.
Here is an example of version numbers ordering:
0.1 < 1.1 < 1.2 < 13.37
思路：
将每一位的版本号存入一个vector中，然后分别比较大小。如果有一位大，则返回1，如果有一位小，则返回-1.
注意：有可能出现1.0 和1 这两个版本是一样的。需要考虑到

**/
class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> version_a;//存储version1的每一个版本号
        vector<int> version_b;//存储version2的每一个版本号
        stringstream ss;
        //将version1的每一个版本号存入
        for(int i=0;i<version1.size();i++){
            if(version1[i]!='.'){
                ss<<version1[i];
            }
            else{
                int temp=0;
                ss>>temp;
                version_a.push_back(temp);
                ss.clear();ss.str("");
            }
        }
        int temp=0;
        ss>>temp;
        version_a.push_back(temp);
        ss.clear();ss.str("");
        //将version2的每一个版本号存入
        for(int i=0;i<version2.size();i++){
            if(version2[i]!='.'){
                ss<<version2[i];
            }
            else{
                int temp=0;
                ss>>temp;
                version_b.push_back(temp);
                ss.clear();ss.str("");
            }
        }
        temp=0;
        ss>>temp;
        version_b.push_back(temp);
        ss.clear();ss.str("");
        int a_size=version_a.size();//version1的版本号数量
        int b_size=version_b.size();//version2的版本号数量
        int a_index=0; int b_index=0;
        while(a_size!=0 && b_size!=0){//对于每一位比较大小
            if(version_a[a_index]>version_b[b_index])
                return 1;
            else if(version_a[a_index]<version_b[b_index])
                return -1;
            else{
                a_size--;
                b_size--;
                a_index++;
                b_index++;
            }
        }
        if(a_size!=0){//如果之后的版本全为0，则相等，否则大
            for(int i=a_index; i<version_a.size();i++){
                if(version_a[i]==0)
                    continue;
                else
                    return 1;
            }
            return 0;
        }
        else if(b_size!=0){//如果之后的版本全为0，则相等，否则小
            for(int i=b_index; i<version_b.size();i++){
                if(version_b[i]==0)
                    continue;
                else
                    return -1;
            }
            return 0;
        }
        else
            return 0;
    }
};
//更简单的做法：
int compareVersion(string version1, string version2) {
    int i = 0; 
    int j = 0;
    int n1 = version1.size(); 
    int n2 = version2.size();
    
    int num1 = 0;
    int num2 = 0;
    while(i<n1 || j<n2)
    {
        while(i<n1 && version1[i]!='.'){
            num1 = num1*10+(version1[i]-'0');
            i++;
        }
        
        while(j<n2 && version2[j]!='.'){
            num2 = num2*10+(version2[j]-'0');;
            j++;
        }
        
        if(num1>num2) return 1;
        else if(num1 < num2) return -1;
        
        num1 = 0;
        num2 = 0;
        i++;
        j++;
    }
    
    return 0;
}