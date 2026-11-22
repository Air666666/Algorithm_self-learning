#include <cassert>
#include <memory>
#include <set>
#define Solution DoubleNumberSolution
#include "../src/class030/Code05_DoubleNumber2.cpp"
#undef Solution
#define Solution WidthSolution
#include "../src/class036/Code03_WidthOfBinaryTree2.cpp"
#undef Solution
#define Solution ArrangementSolution
#include "../src/class188/Code03_Arrangement2.cpp"
#undef Solution
#define Solution SafeSolution
#include "../src/class188/Code06_CrackingTheSafe2.cpp"
#undef Solution
#define Solution CutEdgeSolution
#include "../src/class191/Code02_CutEdge2.cpp"
#undef Solution
#define Solution RecaptureSolution
#include "../src/class193/Code06_Recapture2.cpp"
#undef Solution
int main(){
 std::vector<int>a{INT_MIN,0,5,5};auto d=DoubleNumberSolution().singleNumber(a);std::sort(d.begin(),d.end());assert((d==std::vector<int>{INT_MIN,0}));
 TreeNode n1(1),n2(2),n3(3),n4(4),n5(5);n1.left=&n2;n1.right=&n3;n2.left=&n4;n3.right=&n5;auto width=std::make_unique<WidthSolution>();assert(width->widthOfBinaryTree(&n1)==4);
 auto ar=std::make_unique<ArrangementSolution>();std::vector<std::vector<int>>pairs{{5,1},{4,5},{11,9},{9,4}};auto v=ar->validArrangement(pairs);assert(v.size()==pairs.size());for(size_t i=1;i<v.size();++i)assert(v[i-1][1]==v[i][0]);auto expected=pairs;std::sort(expected.begin(),expected.end());std::sort(v.begin(),v.end());assert(v==expected);
 auto safe=std::make_unique<SafeSolution>();for(int n=1;n<=4;++n)for(int k=1;k<=10;++k){int count=1;for(int i=0;i<n;++i)count*=k;auto s=safe->crackSafe(n,k);assert(s.size()==static_cast<size_t>(count+n-1));std::set<std::string>seen;for(size_t i=0;i+n<=s.size();++i)seen.insert(s.substr(i,n));assert(seen.size()==static_cast<size_t>(count));for(char c:s)assert(c>='0'&&c<'0'+k);}
 auto cuts=std::make_unique<CutEdgeSolution>();std::vector<std::vector<int>>edges{{0,1},{1,2},{2,0},{1,3}};assert((cuts->criticalConnections(4,edges)==std::vector<std::vector<int>>{{1,3}}));edges={{0,1},{0,1},{1,1}};assert(cuts->criticalConnections(2,edges).empty());
 auto rec=std::make_unique<RecaptureSolution>();std::vector<int>cost{7};edges.clear();assert(rec->minimumCost(cost,edges)==7);cost={5,2,7};edges={{0,1},{1,2},{2,0}};assert(rec->minimumCost(cost,edges)==2);edges={{0,1},{1,2}};assert(rec->minimumCost(cost,edges)==5);
}
