/**
210. Course Schedule II
There are a total of n courses you have to take, labeled from 0 to n - 1.
Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.
There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.
For example:
2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1]
4, [[1,0],[2,0],[3,1],[3,2]]
There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. So one correct course order is [0,1,2,3]. Another correct ordering is[0,2,1,3].
Note:
  1. The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
  2. You may assume that there are no duplicate edges in the input prerequisites.
思路：求出拓扑排序后的顺序。我们依然是用Kahn's Algorithm和Tarjan's Algorithm（207用的这个方法，DFS）。

Kahn's Algorithm: 需要注意输出的先后顺序，edge [0，1]表示假如要take 0，必须先take 1，那么edge[0]也就是0其实inDegree = 1，而edge[1]也就是1的indegree = 0。这个edge等价于"1 -> 0"。
步骤：
　　（1）初始化一个大小为numCourses的数组indegree；
　　（2）将图中个节点的入度保存到数组中，将数组中第一个入度为0的节点找出，并将该节点在数组中的值设为-1，将数组中所有以该顶点为入度的顶点入度减一，将其push到vector中；
　　（3）重复（2）numCourses次，若期间在indegree数组中没有找到入度为0的顶点，则返回空;
**/
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        if(numCourses==1){
            vector<int> result={0};
            return result;
        }
        vector<vector<int>> map(numCourses,vector<int>());
        vector<int> indegree(numCourses,0);
        for(int i=0;i<prerequisites.size();i++){
            map[prerequisites[i].second].push_back(prerequisites[i].first);
            indegree[prerequisites[i].first]=indegree[prerequisites[i].first]+1;
        }
        vector<int> path;
        queue<int> zero_indegree;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                zero_indegree.push(i);
                indegree[i]=-1;   //will not be process again
            }
        }
        while(!zero_indegree.empty()){
            int num=zero_indegree.size();
            for(int i=0;i<num;i++){
                int index=zero_indegree.front();
                path.push_back(index);
                for(int i=0;i<map[index].size();i++){
                    indegree[map[index][i]]--;
                    if(indegree[map[index][i]]==0){
                        zero_indegree.push(map[index][i]);
                        indegree[map[index][i]]=-1;
                    }
                }
                zero_indegree.pop();
            }
            
        }
        if(path.size()==numCourses)
            return path;
        else
            return {};
        
    }
};