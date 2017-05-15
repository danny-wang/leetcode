/**
332. Reconstruct Itinerary

Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.
Note:
  1. If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
  2. All airports are represented by three capital letters (IATA code).
  3. You may assume all tickets form at least one valid itinerary.
Example 1:
tickets = [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
Return ["JFK", "MUC", "LHR", "SFO", "SJC"].
Example 2:
tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Return ["JFK","ATL","JFK","SFO","ATL","SFO"].
Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"]. But it is larger in lexical order.

思路：Hierholzer's algorithm    计算欧拉路的算法，时间复杂度O（E）。
1. 关键：directed graph & visit each path exactly once
2. 涉及的图论知识：Eulerian path
2.1 什么graph才有Eulerian Path？
1) 在无向图中，所有顶点的度数均为偶，则存在 Eularian cycle；若有且仅有两个顶点的度数为奇，其余的都为偶，则存在 Eularian path；
2) 在有向图中，所有顶点的入度数等于出度数，则存在 Eularian cycle；若有且仅有两个顶点：
	其中一个入度数比出度数大 1，另一个入度数比出度数小 1，其余的顶点入度数等于出度数，则存在 Eularian path.
3. 算法：
http://www.tuicool.com/articles/Ff2uuae
http://blog.csdn.net/stillxjy/article/details/51956183
**/
class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        map<string,multiset<string>> map;
        int t_size=tickets.size();
        for(int i=0;i<t_size;i++){
            map[tickets[i].first].insert(tickets[i].second);
        }
        vector<string> result;
        stack<string> s_stack;
        string temp="JFK";
        s_stack.push(temp);
        while(!s_stack.empty()){
            string top=s_stack.top();
            if(map[top].empty()){
                result.push_back(top);
                s_stack.pop();
            }
            else{
                string next=*(map[top].begin());
                map[top].erase(map[top].begin());
                s_stack.push(next);
            }
        }
        reverse(result.begin(),result.end());
        return result;
        
    }
};