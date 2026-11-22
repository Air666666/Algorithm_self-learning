// Ported from src/class031/Code03_Near2power.java
#include <cstdint>
#include <iostream>
#include <vector>

// 已知n是非负数
// 返回大于等于n的最小的2某次方
// 如果int范围内不存在这样的数，返回整数最小值
struct Code03_Near2power {
 static int signedBits(std::uint32_t u){return u<=0x7fffffffU?static_cast<int>(u):static_cast<int>(static_cast<std::int64_t>(u)-4294967296LL);}

	static int near2power(int n) {
		if (n <= 0) {
			return 1;
		}
		std::uint32_t u = static_cast<std::uint32_t>(n)-1;
		u |= u >> 1;
		u |= u >> 2;
		u |= u >> 4;
		u |= u >> 8;
		u |= u >> 16;
		return signedBits(u+1);
	}

	static void runDemo() {
		int number = 100;
		std::cout << near2power(number) << "\n";
	}

};

int main(){Code03_Near2power::runDemo();return 0;}
