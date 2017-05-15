/**
207. Course Schedule
There are a total of n courses you have to take, labeled from 0 to n - 1.
Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?
For example:
2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.
2, [[1,0],[0,1]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
Note:
  1. The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
  2. You may assume that there are no duplicate edges in the input prerequisites.
思路：
很显然，这是一个有向无环图的判断问题。只要所有课程中出现了环，就不可能修满所有课程。有向无环图的判断可采用dfs或bfs，至于生成图的形式可以是邻接矩阵，也可以是邻接表。为了减小时间复杂度，本题考虑采用邻接表的方法。

就是用一个改进的DFS
    刚看到这个问题的时候，我想单纯用DFS就可以解决问题了。但细想一下，是不能够的。如果题目给出的是一个无向图，那么OK，DFS是可以解决的。但无向图得不出正确结果的。比如：A->B,A->C->B,我们用DFS来处理这个图，我们会得出它有环，但其实没有。
    我们可以对DFS稍加变化，来解决这个问题。解决的方法如下：
    图中的一个节点，根据其C[N]的值，有三种状态：
    0，此节点没有被访问过
    -1，被访问过至少1次，其后代节点正在被访问中
    1，其后代节点都被访问过。
    按照这样的假设，当按照DFS进行搜索时，碰到一个节点时有三种可能：
    1、如果C[V]=0，这是一个新的节点，不做处理
    2、如果C[V]=-1，说明是在访问该节点的后代的过程中访问到该节点本身，则图中有环。
    3、如果C[V]=1，类似于2的推导，没有环。    在程序中加上一些特殊的处理，即可以找出图中有几个环，并记录每个环的路径
**/
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        if(prerequisites.size()==0)
            return true;
        vector<vector<int>> adjac_map(numCourses,vector<int>());
        for(int i=0;i<prerequisites.size();i++)
            adjac_map[prerequisites[i].first].push_back(prerequisites[i].second);
        vector<int> sig(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(sig[i]==0){
                if(DfsFindLoop(adjac_map, sig,i))
                    return false;
            }
        }
        return true;
    }
    bool DfsFindLoop(vector<vector<int>> &adjac_map, vector<int> &sig, int i){
        if(sig[i]==0)
            sig[i]=-1;
        else if(sig[i]==-1)
            return true;
        else
            return false;
        for(auto j : adjac_map[i]){
            if(DfsFindLoop(adjac_map,sig,j))
                return true;
        }
        sig[i]=1;
        return false;
        
    }
};