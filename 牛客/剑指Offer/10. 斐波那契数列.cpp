/*
题目描述

大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项。
*/

class Solution {
public:
    int Fibonacci(int n) {
 
        int res = 0, next = 1;
         
        while(n--) {
            int temp = res;
            res = next;
            next += temp;
        }
         
        return res;
    }
};

