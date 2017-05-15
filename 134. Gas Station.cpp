/**
134. Gas Station
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.
Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.
Note:
The solution is guaranteed to be unique.
思路1：暴力解法：从每个点开始看是否可以走一圈，先看后半圈是否可以成功，再看前半圈是否可以。时间复杂度O(n^2)
**/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for(int i=0;i<gas.size();i++){
            int cur_gas=0;
            bool will_break=false;
            for(int j=i;j<gas.size();j++){
                cur_gas+=gas[j];
                //cout<<"cur_gas=="<<cur_gas<<endl;
                if(cur_gas<cost[j]){
                    will_break=true;
                    break;
                }
                cur_gas-=cost[j];
            }
            if(will_break)
                continue;
            for(int j=0;j<i;j++){
                cur_gas+=gas[j];
                //cout<<cur_gas<<endl;
                if(cur_gas<cost[j]){
                    will_break=true;
                    break;
                }
                cur_gas-=cost[j];
            }
            if(will_break)
                continue;
            else
                return i;
    }
        return -1;
    }
    
};
/**
解题思路：
初始时，油箱中的油量为0，我们记tank = 0。
从第一个油站出发：
此时，油量为 tank += gas[0] - cost[0]。
如果tank > 0，说明我们可以到达下一个油站。
到达油站 i 时：
此时，油量为 tank += gas[i] - cost[i]。
  ● 如果tank >= 0，可以到达下一个油站，继续往下走。
  ● 可是，如果 tank < 0呢？
这时，我们不可能到达下一个油站（i + 1）了。
并且，假设我们是从 begin 出发的，不仅从 begin 到不了油站 i + 1，并且从 begin 到 i 之间的任何一个油站出发都不可能到达油站 i + 1。
因此，我们需要把起点设置为油站 i + 1，油箱清空，重新开始往下走。
最终，begin 总是会指向一个有可能走完一圈的开始地点。
但是，从 begin 出发，究竟能否走完一圈呢？
记录所有油站的总供油量：totalGas = gas[0] + gas[1] + ... + gas[n - 1]。
以及总耗油量：totalCost = cost[0] + cost[1] + ... + cost[n - 1]。
  ● 如果totalGas >= totalCost，那么肯定能走完一圈的。而且，begin 所在的位置就是那个起点（因为无效的起点已经在tank < 0时被排除掉了）。
  ● 如果totalGas < totalCost，那肯定是走不完一圈了。
代码如下：
**/
class Solution
{
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        int totalGas = 0;
        int totalCost = 0;
        int tank = 0;
        int begin = 0;
        for (int i = 0; i < gas.size(); i++)
        {
            totalGas += gas[i];
            totalCost += cost[i];
            tank += (gas[i] - cost[i]);
            if (tank < 0)
            {
                begin = i + 1;
                tank = 0;
            }
        }

        return (totalGas >= totalCost ? begin : -1);
    }
};