// 原题测试 / 参考链接（保留上游原始地址）
// https://leetcode.cn/problems/power-of-three/

// Ported from src/class031/Code02_PowerOfThree.java
#include <cstdint>
#include <iostream>
#include <vector>

// 判断一个整数是不是3的幂
// 测试链接 : https://leetcode.cn/problems/power-of-three/
struct Code02_PowerOfThree {

	// 如果一个数字是3的某次幂，那么这个数一定只含有3这个质数因子
	// 1162261467是int型范围内，最大的3的幂，它是3的19次方
	// 这个1162261467只含有3这个质数因子，如果n也是只含有3这个质数因子，那么
	// 1162261467 % n == 0
	// 反之如果1162261467 % n != 0 说明n一定含有其他因子
	static bool isPowerOfThree(int n) {
		return n > 0 && 1162261467 % n == 0;
	}

};
