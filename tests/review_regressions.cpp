#include "../include/jcompat.hpp"
#include <cassert>
#include <climits>
#define main near_example_main
#include "../src/class129/Code04_FindNear.cpp"
#undef main
#include "../src/class094/Code03_MaximumAveragePassRatio.cpp"
#include "../src/class094/Code04_MinimumCostToHireWorkers.cpp"
using namespace j;
int main() {
  std::mt19937 rng(5719);
  for (int t=0;t<1000;++t) {
    int n=1+rng()%20;Code04_FindNear::n=n;std::vector<int> values(50);std::iota(values.begin(),values.end(),-25);std::shuffle(values.begin(),values.end(),rng);
    for(int i=1;i<=n;++i)Code04_FindNear::arr[i]=values[i-1];
    Code04_FindNear::near1();
    for(int i=1;i<=n;++i){std::vector<int> ids;for(int k=i+1;k<=n;++k)ids.push_back(k);std::sort(ids.begin(),ids.end(),[&](int a,int b){int da=std::abs(Code04_FindNear::arr[a]-Code04_FindNear::arr[i]),db=std::abs(Code04_FindNear::arr[b]-Code04_FindNear::arr[i]);return da!=db?da<db:Code04_FindNear::arr[a]<Code04_FindNear::arr[b];});assert(Code04_FindNear::to1[i]==(ids.empty()?0:ids[0]));assert(Code04_FindNear::to2[i]==(ids.size()<2?0:ids[1]));}
  }
  for(int t=0;t<500;++t){int n=1+rng()%8,k=1+rng()%n;Array<int> q(n),w(n);for(int i=0;i<n;++i){q[i]=1+rng()%10;w[i]=1+rng()%20;}double best=1e100;for(int mask=0;mask<(1<<n);++mask){if(__builtin_popcount(unsigned(mask))!=k)continue;double ratio=0;int sum=0;for(int i=0;i<n;++i)if(mask>>i&1){sum+=q[i];ratio=std::max(ratio,double(w[i])/q[i]);}best=std::min(best,ratio*sum);}double actual=Code04_MinimumCostToHireWorkers::mincostToHireWorkers(q,w,k);assert(std::abs(actual-best)<1e-8);}
  for(int t=0;t<300;++t){int n=1+rng()%4,m=rng()%6;auto a=make_array<int>(n,2);for(int i=0;i<n;++i){a[i][1]=1+rng()%8;a[i][0]=1+rng()%a[i][1];}double best=0;std::function<void(int,int,double)> dfs=[&](int i,int left,double sum){if(i==n){if(left==0)best=std::max(best,sum/n);return;}for(int x=0;x<=left;++x)dfs(i+1,left-x,sum+double(a[i][0]+x)/(a[i][1]+x));};dfs(0,m,0);double actual=Code03_MaximumAveragePassRatio::maxAverageRatio(a,m);assert(std::abs(actual-best)<1e-10);}
  JSet<Array<int>> set([](Array<int>a,Array<int>b){return a[0]-b[0];});Array<int> none=set.floor(Array<int>{3});assert(none==nullptr);set.add(Array<int>{4});assert(set.ceiling(Array<int>{5})==nullptr);
  assert(jround(-1.5)==-1&&jround(-0.5)==0&&jround(0.5)==1&&jround(std::nan(""))==0);assert(jround(INFINITY)==LLONG_MAX&&jround(-INFINITY)==LLONG_MIN);
  JList<Array<int>> list;for(int i=0;i<100;++i)list.add(Array<int>{i%3,i});list.sort([](Array<int>a,Array<int>b){return a[0]-b[0];});for(int i=1;i<100;++i)if(list.get(i-1)[0]==list.get(i)[0])assert(list.get(i-1)[1]<list.get(i)[1]);
  std::istringstream stream("Insert 5\n a b \n");auto*previous=std::cin.rdbuf(stream.rdbuf());TextEditorIO in;assert(in.nextString().equals(String(u"Insert")));assert(in.nextInt()==5);StringBuilder result;for(int i=0;i<5;++i)result.append(in.nextChar());assert(result.toString().equals(String(u" a b ")));std::cin.rdbuf(previous);std::cin.clear();
  std::cout<<"review regressions passed: 1000 nearest-neighbor, 500 hiring, 300 pass-ratio cases\n";
}
