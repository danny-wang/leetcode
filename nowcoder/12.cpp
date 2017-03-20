/**
数值的整数次方 
题目描述
给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。 
**/
class Solution {
public:
    double Power(double base, int exponent) {
    	if(equal_to_zero(base) && exponent<0)
            return 0;
        int abs_exponent= exponent<0 ? -exponent : exponent;
        if(exponent<0){
            double result=power_with_abs_exponent(base, abs_exponent);
            return 1.0/result;
        }
        else{
            double result=power_with_abs_exponent(base, abs_exponent);
            return result;
        }
    }
    
    double power_with_abs_exponent(double base, int exponent){
        double result=1.0;
        for(int i=1;i<=exponent;i++){
            result*=base;
        }
        return result;
    }
    
    bool equal_to_zero(double a){
        if((a-0.0)>-0.0000001 && (a-0.0)<0.0000001)
            return true;
       	else
            return false;
    }
};
