// Ported from class033/BitOperationAddMinusMultiplyDivide.java
#include <climits>
#include <cstdint>
#include <stdexcept>

// 不用任何算术运算，只用位运算实现加减乘除
// 代码实现中你找不到任何一个算术运算符
// 测试链接 : https://leetcode.cn/problems/divide-two-integers/
// 提交Solution类即可，注意multiply方法不要提交

struct BitOperationAddMinusMultiplyDivide {

	// 只提交Solution类
	struct Solution {

		inline static int MIN = INT_MIN;

		static int divide(int a, int b) {
 if(b==0)throw std::invalid_argument("division by zero");
			if (a == MIN && b == MIN) {
				// a和b都是整数最小
				return 1;
			}
			if (a != MIN && b != MIN) {
				// a和b都不是整数最小，那么正常去除
				return div(a, b);
			}
			if (b == MIN) {
				// a不是整数最小，b是整数最小
				return 0;
			}
			// a是整数最小，b是-1，返回整数最大，因为题目里明确这么说了
			if (b == neg(1)) {
				return INT_MAX;
			}
			// a是整数最小，b不是整数最小，b也不是-1
			a = add(a, b > 0 ? b : neg(b));
			int ans = div(a, b);
			int offset = b > 0 ? neg(1) : 1;
			return add(ans, offset);
		}

		// 必须保证a和b都不是整数最小值，返回a除以b的结果
		static int div(int a, int b) {
			int x = a < 0 ? neg(a) : a;
			int y = b < 0 ? neg(b) : b;
			int ans = 0;
			for (int i = 30; i >= 0; i = minus(i, 1)) {
				if ((x >> i) >= y) {
					ans |= (1 << i);
					x = minus(x, y << i);
				}
			}
			return a < 0 ^ b < 0 ? neg(ans) : ans;
		}

		static int signedBits(std::uint32_t u){return u<=0x7fffffffU?static_cast<int>(u):static_cast<int>(static_cast<std::int64_t>(u)-4294967296LL);}
        static int add(int a,int b){
            std::uint32_t x=static_cast<std::uint32_t>(a),y=static_cast<std::uint32_t>(b);
            while(y){auto carry=(x&y)<<1;x^=y;y=carry;}
            return signedBits(x);
        }

		static int minus(int a, int b) {
			return add(a, neg(b));
		}

		static int neg(int n) {
			return add(~n, 1);
		}

	};

	// 如下的multiply方法，也叫龟速乘，后面的课程有大用处
	// 很多时候，题目要求计算a * b，然后 % mod的结果
	// 过程就是课上讲的，每一步取模即可，后续的课程还会见到
	// 正模数下的龟速乘，避免 long long 加法溢出。
 static long long multiply(long long a,long long b,long long mod){
  if(mod<=0)throw std::invalid_argument("mod must be positive");
  a%=mod;if(a<0)a+=mod;b%=mod;if(b<0)b+=mod;
  auto plus=[mod](long long x,long long y){return x>=mod-y?x-(mod-y):x+y;};
  long long ans=0;
  while(b){if(b&1)ans=plus(ans,a);a=plus(a,a);b>>=1;}
  return ans;
 }
};
