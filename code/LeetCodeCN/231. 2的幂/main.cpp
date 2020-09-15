/************************************************
 * Author        : jumpingfrog0
 * Created Time  : 2020/05/03
 * File Name     : main.cpp
 *************************************************/

/************************************************
 * 题目描述:
 *
 * 给定一个整数，编写一个函数来判断它是否是 2 的幂次方。
 *
 * 示例 1:
 *      输入: 1
 *      输出: true
 *      解释: 2^0 = 1
 *
 * 示例 2:
 *      输入: 16
 *      输出: true
 *      解释: 2^4 = 16
 *
 * 示例 3:
 *      输入: 218
 *      输出: false
 *************************************************/

#include <cstdio>

bool isPowerOfTwo(int n) {
    if (n == 0) {
        return false;
    } else if (n == 1) {
        return true;
    } else {
        if (n % 2 != 0) {
            return false;
        }

        while (n % 2 == 0) {
            if (n / 2 == 1) {
                return true;
            } else {
                n = n / 2;
            }
        }
        return false;
    }
}

int main()
{
    int n;
    while(scanf("%d", &n) != EOF) {
        bool res = isPowerOfTwo(n);
        if (res) {
                printf("true\n");
        } else {
                printf("false\n");
        }
    }

    return 0;
}
