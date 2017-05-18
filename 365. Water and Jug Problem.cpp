/**
365. Water and Jug Problem 
You are given two jugs with capacities x and y litres. There is an infinite amount of water supply available. 
You need to determine whether it is possible to measure exactly z litres using these two jugs.
If z liters of water is measurable, you must have z liters of water contained within one or both buckets by the end.
Operations allowed:
  ● Fill any of the jugs completely with water.
  ● Empty any of the jugs.
  ● Pour water from one jug into another till the other jug is completely full or the first jug itself is empty.
Example 1: (From the famous "Die Hard" example)
Input: x = 3, y = 5, z = 4
Output: True

Example 2:
Input: x = 2, y = 6, z = 5
Output: False

思路：
求最大公约数GCD（Greatest Common Divisor)。
如果x与y互质（最大公约数为1），则容量范围[1, max(x, y)]之内的任意整数体积均可以通过适当的操作得到。
否则，记x与y的最大公约数为gcd，则可以获得的容量z只能为gcd的整数倍，且z <= max(x, y)。
代码：0ms
注意：两个瓶子可能量出的水是两个瓶子容量最大公约数的倍数。所以只要判断z是否可以被x，y的最大公约数整除即可。
**/
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        //最后可量的水可以装在一个或者两个罐子内
        if(x+y<z)
            return false;
        //x或者y为0的情况
        if(x==z || y==z ||x+y==z)
            return true;
        //利用得到的最大公约数
        return (z%gcd(x,y))==0;
    }
    //得到最大公约数
    static int gcd(int x,int y){
        while(y!=0){
            int temp=y;
            y=x%y;
            x=temp;
        }
        return x;
    }
};