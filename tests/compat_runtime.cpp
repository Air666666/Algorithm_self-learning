#include "../include/jcompat.hpp"
#include <cassert>
using namespace j;
struct Desc {
  int compare(int a, int b) { return b - a; }
};
int main() {
  Array<int> a{1, 2, 3};
  auto b = a;
  b[1] = 9;
  assert(a[1] == 9);
  auto c = a.clone();
  c[1] = 4;
  assert(a[1] == 9);
  auto m = make_array<int>(3, 4);
  m[0][0] = 2;
  assert(m[1][0] == 0);
  auto mb = make_array<bool>(3, 4);
  mb[2][1] = true;
  assert(mb[2][1] && !mb[1][1]);
  String x(u"你好a");
  auto y = newString(x);
  assert(x != y && x.equals(y) && x.length() == 3);
  JList<String> ls;
  ls.add(x);
  assert(ls.contains(y));
  JHashSet<String> ss;
  ss.add(x);
  ss.add(y);
  assert(ss.size() == 1);
  JMap<String, int> sm;
  sm.put(x, 7);
  assert(sm.get(y) == 7);
  assert(sm.get(String(u"missing")) == nullptr);
  JTreeMap<int, int> tm;
  tm.put(5, 7);
  tm.put(9, 8);
  assert(tm.floorKey(4) == nullptr && tm.ceilingKey(10) == nullptr);
  assert(int(tm.floorKey(8)) == 5);
  JSet<int> ts;
  ts.add(4);
  ts.add(10);
  assert(ts.lower(4) == nullptr && int(ts.higher(4)) == 10);
  Desc d;
  JHeap<int> hp(&d);
  for (int v : {3, 7, 2, 9})
    hp.add(v);
  assert(hp.poll() == 9 && hp.poll() == 7);
  Array<int> sorted{3, 7, 2, 9};
  j::sort(sorted, &d);
  assert(sorted[0] == 9 && sorted[3] == 2);
  std::mt19937 rng(1729);
  JMap<int, int> hm;
  std::unordered_map<int, int> ref;
  BitSet bits(150);
  std::vector<bool> expected(150);
  for (int i = 0; i < 10000; ++i) {
    int k = rng() % 150, v = rng() % 100000;
    hm.put(k, v);
    ref[k] = v;
    assert(int(hm.get(k)) == ref[k]);
    bits.set(k, v % 2);
    expected[k] = v % 2;
    int count = 0;
    for (int q = 0; q < 150; ++q) {
      assert(bits.get(q) == expected[q]);
      count += expected[q];
    }
    assert(bits.cardinality() == count);
    int n = rng();
    int shift = rng() % 32;
    assert(jshl(n, shift) == signed32(std::uint32_t(n) << shift));
    assert(jushr(n, shift) == signed32(std::uint32_t(n) >> shift));
  }
  assert(jushr(-1, 1) == 2147483647);
  assert(jshr(-1, 31) == -1);
  assert(jshl(1, 32) == 1);
  BigInteger big(String(u"123456789012345678901234567890"));
  assert(big.multiply(big).divide(big).toString().equals(big.toString()));
  assert(big.mod(BigInteger::valueOf(97)).intValue() == 52);
  assert(BigInteger(String(u"170141183460469231731687303715884105727"))
             .isProbablePrime(50));
  assert(!BigInteger::valueOf(561).isProbablePrime(50));
  auto md = MessageDigest::getInstance(String(u"MD5"));
  assert(BigInteger(1, md.digest(String(u"abc").getBytes()))
             .toString(16)
             .equals(String(u"900150983cd24fb0d6963f7d28e17f72")));
  assert(BigInteger(1, md.digest(String(u"").getBytes()))
             .toString(16)
             .equals(String(u"d41d8cd98f00b204e9800998ecf8427e")));
  std::istringstream input("8:05 -12.5 abc 42\n");
  auto *old = std::cin.rdbuf(input.rdbuf());
  Tokenizer t;
  assert(t.nextToken() == -2 && t.nval == 8);
  assert(t.nextToken() == ':');
  assert(t.nextToken() == -2 && t.nval == 5);
  assert(t.nextToken() == -2 && t.nval == -12.5);
  assert(t.nextToken() == -3 && t.sval.equals(String(u"abc")));
  assert(t.nextToken() == -2 && t.nval == 42);
  assert(t.nextToken() == -1);
  std::cin.rdbuf(old);
  std::cin.clear();
  std::cout << "compatibility runtime checks passed\n";
}
