#include <cassert>
#include <algorithm>
#define main bitset_demo
#include "../src/class032/Code01_Bitset.cpp"
#undef main
#include "../src/class032/Code02_DesignBitsetTest.cpp"
#include "../src/class033/BitOperationAddMinusMultiplyDivide.cpp"
int main(){std::mt19937 rng(48);using A=BitOperationAddMinusMultiplyDivide::Solution;
 for(int n:{0,1,31,32,33,65,1000}){Code01_Bitset::Bitset a(n);Code02_DesignBitsetTest::Bitset b(n);std::vector<bool>x(n),y(n);
 for(int t=0;t<3000;++t){int op=rng()%3;if(n){int k=rng()%n;if(op==0){a.add(k);x[k]=true;b.fix(k);y[k]=true;}else if(op==1){a.remove(k);x[k]=false;b.unfix(k);y[k]=false;}else{a.reverse(k);x[k]=!x[k];}}if(op==2){b.flip();for(int k=0;k<n;++k)y[k]=!y[k];}int count=0;std::string text;for(int k=0;k<n;++k){assert(a.contains(k)==x[k]);count+=y[k];text+=y[k]?'1':'0';}assert(b.count()==count&&b.all()==(count==n)&&b.one()==(count>0)&&b.toString()==text);}}
 for(int t=0;t<100000;++t){int a=A::signedBits(rng()),b=A::signedBits(rng());assert(A::add(a,b)==A::signedBits(static_cast<std::uint32_t>(a)+static_cast<std::uint32_t>(b)));assert(A::minus(a,b)==A::signedBits(static_cast<std::uint32_t>(a)-static_cast<std::uint32_t>(b)));if(b){long long expected=static_cast<long long>(a)/b;assert(A::divide(a,b)==(expected>INT_MAX?INT_MAX:expected));}
 long long mod=(static_cast<long long>(rng())<<31)|rng();if(!mod)mod=1;long long x=static_cast<long long>(a)*123456789,y=static_cast<long long>(b)*987654321;auto norm=[mod](long long v){v%=mod;return v<0?v+mod:v;};long long expected=static_cast<long long>((static_cast<__int128>(norm(x))*norm(y))%mod);assert(BitOperationAddMinusMultiplyDivide::multiply(x,y,mod)==expected);}
 for(int a:{INT_MIN,INT_MAX,-1,0,1})for(int b:{INT_MIN,INT_MAX,-1,1}){auto e=static_cast<long long>(a)/b;assert(A::divide(a,b)==(e>INT_MAX?INT_MAX:e));}
}
