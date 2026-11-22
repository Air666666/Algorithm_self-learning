#include <cassert>
#include <sstream>
#define main experiment_demo
#include "../src/class002/Experiment.cpp"
#undef main
#define main binary_demo
#include "../src/class003/BinarySystem.cpp"
#undef main
#define main complexity_demo
#include "../src/class007/Complexity.cpp"
#undef main
#define main swap_demo
#include "../src/class030/Code01_SwapExclusiveOr.cpp"
#undef main
#include "../src/class030/Code03_MissingNumber.cpp"
#include "../src/class030/Code04_SingleNumber.cpp"
#include "../src/class030/Code05_DoubleNumber1.cpp"
#include "../src/class030/Code06_OneKindNumberLessMtimes.cpp"
#include "../src/class031/Code01_PowerOfTwo.cpp"
#include "../src/class031/Code02_PowerOfThree.cpp"
#define main near_demo
#include "../src/class031/Code03_Near2power.cpp"
#undef main
#include "../src/class031/Code04_LeftToRightAnd.cpp"
#include "../src/class031/Code05_ReverseBits.cpp"
#include "../src/class031/Code06_CountOnesBinarySystem.cpp"
int main(){
 std::mt19937 rng(46);
 std::vector<double>w{100,100,100};assert(Experiment::calculateGini(w)==0);w={0,0,300};assert(std::abs(Experiment::calculateGini(w)-2.0/3)<1e-12);
 std::ostringstream sink;auto old=std::cout.rdbuf(sink.rdbuf());BinarySystem::printBinary(INT_MIN);assert(sink.str()=="10000000000000000000000000000000\n");sink.str("");BinarySystem::runDemo();Experiment::experiment(10,100);std::cout.rdbuf(old);
 assert(BinarySystem::negate32(INT_MIN)==INT_MIN);assert(BinarySystem::logicalRight(-1,1)==INT_MAX);assert(BinarySystem::arithmeticRight(-1,1)==-1);
 for(int t=0;t<10000;++t){
  std::uint32_t u=rng(),rev=0;int count=0;for(int i=0;i<32;++i){rev=(rev<<1)|((u>>i)&1u);count+=(u>>i)&1u;}
  assert(Code05_ReverseBits::reverseBits(u)==rev);assert(Code06_CountOnesBinarySystem::cntOnes(u)==count);
  int n=static_cast<int>(u&0x7fffffff);long long near=1;while(near<n)near*=2;
  assert(Code03_Near2power::near2power(n)==(near>INT_MAX?INT_MIN:static_cast<int>(near)));
  assert(Code01_PowerOfTwo::isPowerOfTwo(n)==(n>0&&near==n));int x=n;while(x>1&&x%3==0)x/=3;assert(Code02_PowerOfThree::isPowerOfThree(n)==(x==1));
  int l=rng()%10000,r=l+rng()%100;int ans=l;for(int i=l+1;i<=r;++i)ans&=i;assert(Code04_LeftToRightAnd::rangeBitwiseAnd(l,r)==ans);
  int len=rng()%40,missing=rng()%(len+1);std::vector<int>a;for(int i=0;i<=len;++i)if(i!=missing)a.push_back(i);std::shuffle(a.begin(),a.end(),rng);assert(Code03_MissingNumber::missingNumber(a)==missing);
  auto b=a;Complexity::bubbleSort(b);assert(std::is_sorted(b.begin(),b.end()));
  int single=t%2?INT_MIN:INT_MAX;std::vector<int> nums{single,3,3,-1,-1};assert(Code04_SingleNumber::singleNumber(nums)==single);
  nums={single,3,3,3,-1,-1,-1};assert(Code06_OneKindNumberLessMtimes::singleNumber(nums)==single);
  nums={INT_MIN,0,5,5};auto two=Code05_DoubleNumber1::singleNumber(nums);std::sort(two.begin(),two.end());assert((two==std::vector<int>{INT_MIN,0}));
 }
 std::vector<int>a{3,5};Code01_SwapExclusiveOr::swap(a,0,1);assert(a[0]==5&&a[1]==3);Code01_SwapExclusiveOr::swap(a,0,0);assert(a[0]==0); // 保留课程对别名问题的演示。
}
