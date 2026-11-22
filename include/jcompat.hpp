#ifndef ALGORITHM_JAVA_COMPAT_HPP
#define ALGORITHM_JAVA_COMPAT_HPP
#include <algorithm>
#include <array>
#include <bitset>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/miller_rabin.hpp>
#include <chrono>
#include <cmath>
#include <codecvt>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <locale>
#include <map>
#include <memory>
#include <numeric>
#include <optional>
#include <queue>
#include <random>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
namespace j {
template <class C, class A, class B> auto compare_call(C c, A a, B b) {
  if constexpr (std::is_pointer_v<C>)
    return c->compare(a, b);
  else
    return c(a, b);
}
using i64 = long long;
using u64 = unsigned long long;
using jchar = char16_t;
template <class T> struct Array {
  std::shared_ptr<std::vector<T>> p;
  int length = 0;
  Array() = default;
  Array(std::nullptr_t) {}
  explicit Array(int n) : p(std::make_shared<std::vector<T>>(n)), length(n) {
    if (n < 0)
      throw std::length_error("negative array size");
  }
  Array(int n, const T &value) : Array(n) {
    std::fill(p->begin(), p->end(), value);
  }
  Array(std::initializer_list<T> a)
      : p(std::make_shared<std::vector<T>>(a)), length(a.size()) {}
  template <class It>
  Array(It a, It b)
      : p(std::make_shared<std::vector<T>>(a, b)), length(p->size()) {}
  decltype(auto) operator[](int i) { return (*p)[i]; }
  decltype(auto) operator[](int i) const { return (*p)[i]; }
  auto begin() const { return p->begin(); }
  auto end() const { return p->end(); }
  bool operator==(std::nullptr_t) const { return !p; }
  bool operator!=(std::nullptr_t) const { return bool(p); }
  bool operator==(const Array &o) const { return p == o.p; }
  bool operator!=(const Array &o) const { return p != o.p; }
  Array clone() const { return Array(begin(), end()); }
};
template <class T> Array<T> make_array(int n) { return Array<T>(n); }
template <class T, class... D> auto make_array(int n, int m, D... d) {
  using A = decltype(make_array<T>(m, d...));
  Array<A> a(n);
  for (int i = 0; i < n; ++i)
    a[i] = make_array<T>(m, d...);
  return a;
}
inline std::string utf8(const std::u16string &s) {
  return std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t>{}
      .to_bytes(s);
}
inline std::u16string utf16(const std::string &s) {
  return std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t>{}
      .from_bytes(s);
}
struct String {
  std::shared_ptr<std::u16string> p;
  String() = default;
  String(std::nullptr_t) {}
  String(const char16_t *s) {
    static std::map<std::u16string, std::shared_ptr<std::u16string>> pool;
    auto &v = pool[s];
    if (!v)
      v = std::make_shared<std::u16string>(s);
    p = v;
  }
  explicit String(std::u16string s)
      : p(std::make_shared<std::u16string>(std::move(s))) {}
  explicit String(const std::string &s) : String(utf16(s)) {}
  explicit String(Array<jchar> a)
      : String(std::u16string(a.begin(), a.end())) {}
  String(Array<jchar> a, int off, int len)
      : String(std::u16string(a.begin() + off, a.begin() + off + len)) {}
  template <class... A> static String format(String fmt, A... a) {
    auto f = utf8(*fmt.p);
    int n = std::snprintf(nullptr, 0, f.c_str(), a...);
    std::vector<char> b(n + 1);
    std::snprintf(b.data(), b.size(), f.c_str(), a...);
    return String(std::string(b.data(), n));
  }
  Array<signed char> getBytes(int = 0) const {
    auto s = utf8(*p);
    return Array<signed char>(s.begin(), s.end());
  }
  int length() const { return p->size(); }
  bool isEmpty() const { return p->empty(); }
  jchar charAt(int i) const { return p->at(i); }
  Array<jchar> toCharArray() const {
    return Array<jchar>(p->begin(), p->end());
  }
  String substring(int a) const { return String(p->substr(a)); }
  String substring(int a, int b) const { return String(p->substr(a, b - a)); }
  bool equals(const String &s) const {
    return p && s.p ? *p == *s.p : p == s.p;
  }
  int compareTo(const String &s) const {
    return *p < *s.p ? -1 : *p > *s.p ? 1 : 0;
  }
  bool operator==(const String &s) const { return p == s.p; }
  bool operator!=(const String &s) const { return p != s.p; }
  bool operator==(std::nullptr_t) const { return !p; }
  bool operator!=(std::nullptr_t) const { return bool(p); }
  bool operator<(const String &s) const { return *p < *s.p; }
  int indexOf(const String &s) const {
    auto i = p->find(*s.p);
    return i == p->npos ? -1 : int(i);
  }
  String trim() const {
    int a = 0, b = length();
    while (a < b && (*p)[a] <= 32)
      ++a;
    while (b > a && (*p)[b - 1] <= 32)
      --b;
    return substring(a, b);
  }
  Array<String> split(const String &pattern) const {
    std::string s = utf8(*p), pat = utf8(*pattern.p);
    std::regex re(pat);
    std::sregex_token_iterator it(s.begin(), s.end(), re, -1), end;
    std::vector<String> v;
    for (; it != end; ++it)
      v.emplace_back(it->str());
    while (!v.empty() && v.back().isEmpty())
      v.pop_back();
    return Array<String>(v.begin(), v.end());
  }
  String toString() const { return *this; }
};
inline std::string text(const String &s) { return s.p ? utf8(*s.p) : "null"; }
inline std::string text(jchar c) { return utf8(std::u16string(1, c)); }
inline std::string text(bool b) { return b ? "true" : "false"; }
inline std::string text(const std::string &s) { return s; }
inline std::string text(const char *s) { return s; }
template <class T> std::string text(T v) {
  std::ostringstream o;
  o << std::setprecision(16) << v;
  return o.str();
}
inline String newString(String s) { return String(std::u16string(*s.p)); }
inline String str(Array<jchar> a, int off, int len) {
  return String(a, off, len);
}
inline std::string text(Array<jchar> a) {
  return utf8(std::u16string(a.begin(), a.end()));
}
template <class T> String str(T v) { return String(utf16(text(v))); }
inline String operator+(const String &a, const String &b) {
  return String(utf16(text(a) + text(b)));
}
template <class T> String operator+(const String &a, const T &b) {
  return String(utf16(text(a) + text(b)));
}
template <class T> String operator+(const T &a, const String &b) {
  return String(utf16(text(a) + text(b)));
}
struct StringBuilder {
  std::shared_ptr<std::u16string> p = std::make_shared<std::u16string>();
  StringBuilder() = default;
  explicit StringBuilder(int) {}
  explicit StringBuilder(String s)
      : p(std::make_shared<std::u16string>(*s.p)) {}
  template <class T> StringBuilder &append(T v) {
    *p += utf16(text(v));
    return *this;
  }
  int length() const { return p->size(); }
  void setLength(int n) { p->resize(n); }
  void deleteCharAt(int n) { p->erase(n, 1); }
  String toString() const { return String(*p); }
  jchar charAt(int i) const { return p->at(i); }
};
inline std::string text(const StringBuilder &b) { return text(b.toString()); }
template <class T> struct Box {
  std::optional<T> v;
  Box() = default;
  Box(std::nullptr_t) {}
  Box(T x) : v(x) {}
  operator T() const {
    if (!v)
      throw std::runtime_error("null unboxing");
    return *v;
  }
  template <class U, std::enable_if_t<std::is_arithmetic_v<U>, int> = 0>
  bool operator==(U x) const {
    return T(*this) == x;
  }
  template <class U, std::enable_if_t<std::is_arithmetic_v<U>, int> = 0>
  bool operator!=(U x) const {
    return T(*this) != x;
  }
  bool operator==(std::nullptr_t) const { return !v; }
  bool operator!=(std::nullptr_t) const { return bool(v); }
};
template <class T> std::string text(Box<T> x) {
  return x.v ? text(*x.v) : "null";
}
template <class T> T unbox(T x) { return x; }
template <class T> T unbox(Box<T> x) { return T(x); }
template <class A, class B> auto jmin(A a, B b) {
  using T = std::common_type_t<decltype(unbox(a)), decltype(unbox(b))>;
  return std::min<T>(unbox(a), unbox(b));
}
template <class A, class B> auto jmax(A a, B b) {
  using T = std::common_type_t<decltype(unbox(a)), decltype(unbox(b))>;
  return std::max<T>(unbox(a), unbox(b));
}
inline int jcompare(String a, String b) { return a.compareTo(b); }
template <class A, class B> auto jcompare(A a, B b) {
  return a < b ? -1 : a > b ? 1 : 0;
}
inline int signed32(std::uint32_t u) {
  return u <= 0x7fffffffU ? int(u) : int(i64(u) - 4294967296LL);
}
inline i64 signed64(u64 u) {
  i64 x;
  std::memcpy(&x, &u, 8);
  return x;
}
template <class T> auto jshl(T x, int n) {
  if constexpr (sizeof(T) > 4)
    return signed64(u64(x) << (n & 63));
  else
    return signed32(std::uint32_t(x) << (n & 31));
}
template <class T> auto jushr(T x, int n) {
  if constexpr (sizeof(T) > 4)
    return signed64(u64(x) >> (n & 63));
  else
    return signed32(std::uint32_t(x) >> (n & 31));
}
template <class T> auto jshr(T x, int n) {
  if constexpr (sizeof(T) > 4) {
    n &= 63;
    if (!n)
      return i64(x);
    u64 u = u64(x) >> n;
    if (x < 0)
      u |= ~u64(0) << (64 - n);
    return signed64(u);
  } else {
    n &= 31;
    if (!n)
      return int(x);
    std::uint32_t u = std::uint32_t(x) >> n;
    if (x < 0)
      u |= ~std::uint32_t(0) << (32 - n);
    return signed32(u);
  }
}
inline int highestOneBit(int x) {
  unsigned u = static_cast<unsigned>(x);
  return u ? signed32(1u << (31 - __builtin_clz(u))) : 0;
}
inline String binaryString(int x) {
  unsigned u = x;
  std::string s;
  do {
    s.push_back(char('0' + (u & 1)));
    u >>= 1;
  } while (u);
  std::reverse(s.begin(), s.end());
  return String(s);
}
template <class A, class B> auto jdiv(A a, B b) {
  using T = std::common_type_t<decltype(unbox(a)), decltype(unbox(b))>;
  T x = unbox(a), y = unbox(b);
  if constexpr (std::is_integral_v<T>) {
    if (y == 0)
      throw std::domain_error("division by zero");
    if (x == std::numeric_limits<T>::min() && y == -1)
      return x;
  }
  return T(x / y);
}
template <class A, class B> auto jrem(A a, B b) {
  using T = std::common_type_t<decltype(unbox(a)), decltype(unbox(b))>;
  T x = unbox(a), y = unbox(b);
  if constexpr (std::is_integral_v<T>) {
    if (y == 0)
      throw std::domain_error("division by zero");
    if (x == std::numeric_limits<T>::min() && y == -1)
      return T(0);
    return T(x % y);
  } else
    return std::fmod(x, y);
}
inline double random() {
  static std::mt19937_64 g(20261122);
  return std::generate_canonical<double, 53>(g);
}
inline i64 millis() {
  return std::chrono::duration_cast<std::chrono::milliseconds>(
             std::chrono::steady_clock::now().time_since_epoch())
      .count();
}
struct StandardCharsets {
  static constexpr int UTF_8 = 0;
};
struct Security {
  static Array<String> getAlgorithms(String) {
    return Array<String>{String(u"MD5")};
  }
};
struct MessageDigest {
  String algorithm;
  static MessageDigest getInstance(String s) {
    if (!s.equals(String(u"MD5")))
      throw std::invalid_argument(
          "Only MD5 is implemented by this teaching example");
    MessageDigest m;
    m.algorithm = s;
    return m;
  }
  Array<signed char> digest(Array<signed char> input) {
    std::vector<std::uint8_t> b;
    for (auto c : input)
      b.push_back(static_cast<std::uint8_t>(c));
    std::uint64_t bits = std::uint64_t(b.size()) * 8;
    b.push_back(0x80);
    while (b.size() % 64 != 56)
      b.push_back(0);
    for (int i = 0; i < 8; ++i)
      b.push_back(bits >> (8 * i));
    static constexpr int shifts[64] = {
        7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
        5, 9,  14, 20, 5, 9,  14, 20, 5, 9,  14, 20, 5, 9,  14, 20,
        4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
        6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21};
    static const std::array<std::uint32_t, 64> k = []() {
      std::array<std::uint32_t, 64> a{};
      for (int i = 0; i < 64; ++i)
        a[i] = static_cast<std::uint32_t>(
            std::floor(std::abs(std::sin(i + 1)) * 4294967296.0));
      return a;
    }();
    std::uint32_t h[4] = {0x67452301, 0xefcdab89, 0x98badcfe, 0x10325476};
    for (size_t off = 0; off < b.size(); off += 64) {
      std::uint32_t w[16];
      for (int i = 0; i < 16; ++i) {
        w[i] = 0;
        for (int j = 0; j < 4; ++j)
          w[i] |= std::uint32_t(b[off + 4 * i + j]) << (8 * j);
      }
      auto a = h[0], bb = h[1], c = h[2], d = h[3];
      for (int i = 0; i < 64; ++i) {
        std::uint32_t f, g;
        if (i < 16) {
          f = (bb & c) | (~bb & d);
          g = i;
        } else if (i < 32) {
          f = (d & bb) | (~d & c);
          g = (5 * i + 1) % 16;
        } else if (i < 48) {
          f = bb ^ c ^ d;
          g = (3 * i + 5) % 16;
        } else {
          f = c ^ (bb | ~d);
          g = (7 * i) % 16;
        }
        std::uint32_t x = a + f + k[i] + w[g];
        a = d;
        d = c;
        c = bb;
        bb += (x << shifts[i]) | (x >> (32 - shifts[i]));
      }
      h[0] += a;
      h[1] += bb;
      h[2] += c;
      h[3] += d;
    }
    Array<signed char> ans(16);
    for (int i = 0; i < 16; ++i)
      ans[i] = static_cast<signed char>((h[i / 4] >> (8 * (i % 4))) & 255);
    return ans;
  }
};
struct BigInteger {
  boost::multiprecision::cpp_int v = 0;
  BigInteger() = default;
  BigInteger(std::nullptr_t) {}
  explicit BigInteger(boost::multiprecision::cpp_int n) : v(std::move(n)) {}
  explicit BigInteger(String s, int radix = 10) {
    auto a = text(s);
    bool neg = a.size() && a[0] == '-';
    for (size_t i = neg; i < a.size(); ++i) {
      char c = a[i];
      int d = c >= '0' && c <= '9' ? c - '0' : std::tolower(c) - 'a' + 10;
      if (d < 0 || d >= radix)
        throw std::invalid_argument("digit");
      v = v * radix + d;
    }
    if (neg)
      v = -v;
  }
  BigInteger(int sign, Array<signed char> b) {
    for (auto c : b)
      v = (v << 8) + static_cast<unsigned char>(c);
    if (sign < 0)
      v = -v;
  }
  static BigInteger valueOf(i64 x) {
    return BigInteger(boost::multiprecision::cpp_int(x));
  }
  static const BigInteger ZERO, ONE;
  BigInteger add(BigInteger b) const { return BigInteger(v + b.v); }
  BigInteger subtract(BigInteger b) const { return BigInteger(v - b.v); }
  BigInteger multiply(BigInteger b) const { return BigInteger(v * b.v); }
  BigInteger divide(BigInteger b) const { return BigInteger(v / b.v); }
  BigInteger mod(BigInteger b) const {
    auto r = boost::multiprecision::cpp_int(v % b.v);
    if (r < 0)
      r += b.v;
    return BigInteger(r);
  }
  int intValue() const {
    return signed32(static_cast<std::uint32_t>(v & 0xffffffff));
  }
  i64 longValue() const {
    return signed64(static_cast<u64>(v & 0xffffffffffffffffULL));
  }
  int signum() const { return v < 0 ? -1 : v > 0 ? 1 : 0; }
  String toString(int radix = 10) const {
    if (radix == 10)
      return String(v.convert_to<std::string>());
    auto n = v;
    bool neg = n < 0;
    if (neg)
      n = -n;
    std::string s;
    do {
      int d = (n % radix).convert_to<int>();
      s.push_back("0123456789abcdefghijklmnopqrstuvwxyz"[d]);
      n /= radix;
    } while (n != 0);
    if (neg)
      s += '-';
    std::reverse(s.begin(), s.end());
    return String(s);
  }
  bool isProbablePrime(int certainty) const {
    if (certainty <= 0)
      return true;
    auto n = v < 0 ? -v : v;
    if (n < 2)
      return false;
    static std::mt19937 gen(5489);
    return boost::multiprecision::miller_rabin_test(
        n, std::max(1, (certainty + 1) / 2), gen);
  }
};
inline const BigInteger BigInteger::ZERO = BigInteger::valueOf(0),
                        BigInteger::ONE = BigInteger::valueOf(1);
inline std::string text(const BigInteger &b) { return text(b.toString()); }
struct BigDecimal {
  boost::multiprecision::cpp_dec_float_50 v = 0;
  BigDecimal() = default;
  explicit BigDecimal(String s) : v(text(s)) {}
  explicit BigDecimal(int x) : v(x) {}
  BigDecimal multiply(BigDecimal b) const {
    BigDecimal r;
    r.v = v * b.v;
    return r;
  }
  int intValue() const { return v.convert_to<int>(); }
};
struct BitSet {
  std::shared_ptr<std::vector<u64>> p;
  BitSet() : p(std::make_shared<std::vector<u64>>()) {}
  BitSet(std::nullptr_t) {}
  explicit BitSet(int n)
      : p(std::make_shared<std::vector<u64>>((n + 63) / 64)) {}
  bool get(int i) const {
    return i / 64 < int(p->size()) && ((*p)[i / 64] >> (i % 64) & 1);
  }
  void set(int i, bool b = true) {
    if (i / 64 >= int(p->size()))
      p->resize(i / 64 + 1);
    u64 m = 1ULL << (i % 64);
    if (b)
      (*p)[i / 64] |= m;
    else
      (*p)[i / 64] &= ~m;
  }
  void or_java(BitSet b) {
    p->resize(std::max(p->size(), b.p->size()));
    for (size_t i = 0; i < b.p->size(); ++i)
      (*p)[i] |= (*b.p)[i];
  }
  int cardinality() const {
    int n = 0;
    for (auto x : *p)
      n += __builtin_popcountll(x);
    return n;
  }
};

template <class T> bool value_equal(const T &a, const T &b) { return a == b; }
inline bool value_equal(const String &a, const String &b) {
  return a.equals(b);
}
struct ValueHash {
  template <class T> size_t operator()(const T &x) const {
    return std::hash<T>{}(x);
  }
  size_t operator()(const String &s) const {
    return s.p ? std::hash<std::u16string>{}(*s.p) : 0;
  }
  template <class T> size_t operator()(const Array<T> &a) const {
    return std::hash<const void *>{}(a.p.get());
  }
};
struct ValueEqual {
  template <class T> bool operator()(const T &a, const T &b) const {
    return value_equal(a, b);
  }
};
template <class T> struct JList {
  std::shared_ptr<std::vector<T>> p;
  JList() : p(std::make_shared<std::vector<T>>()) {}
  JList(std::nullptr_t) {}
  explicit JList(int n) : JList() { p->reserve(n); }
  explicit JList(Array<T> a)
      : p(std::make_shared<std::vector<T>>(a.begin(), a.end())) {}
  template <class C>
  explicit JList(const C &c)
      : p(std::make_shared<std::vector<T>>(c.begin(), c.end())) {}
  int size() const { return p->size(); }
  bool isEmpty() const { return p->empty(); }
  bool empty() const { return p->empty(); }
  bool add(T x) {
    p->push_back(x);
    return true;
  }
  void add(int i, T x) { p->insert(p->begin() + i, x); }
  void push(T x) { p->push_back(x); }
  T pop() {
    T x = p->back();
    p->pop_back();
    return x;
  }
  T peek() { return p->back(); }
  T &get(int i) { return (*p)[i]; }
  T set(int i, T x) {
    T old = (*p)[i];
    (*p)[i] = x;
    return old;
  }
  T remove(int i) {
    T x = (*p)[i];
    p->erase(p->begin() + i);
    return x;
  }
  void clear() { p->clear(); }
  auto begin() const { return p->begin(); }
  auto end() const { return p->end(); }
  template <class C> void sort(C cmp) {
    std::sort(p->begin(), p->end(), [&](const T &a, const T &b) {
      return compare_call(cmp, a, b) < 0;
    });
  }
  bool contains(T x) const {
    return std::find_if(begin(), end(),
                        [&](const T &v) { return value_equal(v, x); }) != end();
  }
  bool equals(const JList &b) const {
    return p->size() == b.p->size() &&
           std::equal(begin(), end(), b.begin(),
                      [](const T &a, const T &b) { return value_equal(a, b); });
  }
  bool operator==(std::nullptr_t) const { return !p; }
  bool operator!=(std::nullptr_t) const { return bool(p); }
  bool operator==(const JList &b) const { return p == b.p; }
};
template <class T> struct JDeque {
  std::shared_ptr<std::deque<T>> p = std::make_shared<std::deque<T>>();
  JDeque() = default;
  JDeque(std::nullptr_t) : p(nullptr) {}
  int size() const { return p->size(); }
  bool isEmpty() const { return p->empty(); }
  bool empty() const { return p->empty(); }
  void clear() { p->clear(); }
  bool add(T x) {
    p->push_back(x);
    return true;
  }
  bool offer(T x) { return add(x); }
  void addLast(T x) { p->push_back(x); }
  void offerLast(T x) { addLast(x); }
  void addFirst(T x) { p->push_front(x); }
  void offerFirst(T x) { addFirst(x); }
  void push(T x) { addFirst(x); }
  T poll() { return pollFirst(); }
  T pollFirst() {
    T x = p->front();
    p->pop_front();
    return x;
  }
  T pollLast() {
    T x = p->back();
    p->pop_back();
    return x;
  }
  T pop() { return pollFirst(); }
  T removeFirst() { return pollFirst(); }
  T removeLast() { return pollLast(); }
  T peek() { return p->front(); }
  T peekFirst() { return p->front(); }
  T peekLast() { return p->back(); }
  auto begin() const { return p->begin(); }
  auto end() const { return p->end(); }
};
template <class T> struct JHeap {
  struct Data {
    std::vector<T> v;
    std::function<int(T, T)> cmp;
  };
  std::shared_ptr<Data> p;
  JHeap() : p(std::make_shared<Data>()) {
    p->cmp = [](T a, T b) { return jcompare(a, b); };
  }
  JHeap(std::nullptr_t) {}
  template <class C> explicit JHeap(C cmp) : p(std::make_shared<Data>()) {
    p->cmp = [cmp](T a, T b) { return compare_call(cmp, a, b); };
  }
  template <class C> JHeap(int, C cmp) : JHeap(cmp) {}
  explicit JHeap(int) : JHeap() {}
  bool isEmpty() const { return p->v.empty(); }
  int size() const { return p->v.size(); }
  auto cmp() {
    return [this](T a, T b) { return p->cmp(a, b) > 0; };
  }
  bool add(T x) {
    p->v.push_back(x);
    std::push_heap(p->v.begin(), p->v.end(), cmp());
    return true;
  }
  bool offer(T x) { return add(x); }
  T poll() {
    std::pop_heap(p->v.begin(), p->v.end(), cmp());
    auto x = p->v.back();
    p->v.pop_back();
    return x;
  }
  T peek() { return p->v.front(); }
  void clear() { p->v.clear(); }
};
template <class T> struct JSet {
  struct Data {
    std::set<T, std::function<bool(T, T)>> s;
    Data(std::function<bool(T, T)> c) : s(c) {}
  };
  std::shared_ptr<Data> p;
  JSet() : p(std::make_shared<Data>([](T a, T b) { return a < b; })) {}
  JSet(std::nullptr_t) {}
  template <class C>
  explicit JSet(C cmp)
      : p(std::make_shared<Data>(
            [cmp](T a, T b) { return compare_call(cmp, a, b) < 0; })) {}
  explicit JSet(JList<T> a) : JSet() {
    for (auto x : a)
      add(x);
  }
  explicit JSet(Array<T> a) : JSet() {
    for (auto x : a)
      add(x);
  }
  bool add(T x) { return p->s.insert(x).second; }
  bool contains(T x) const { return p->s.count(x); }
  bool remove(T x) { return p->s.erase(x); }
  int size() const { return p->s.size(); }
  bool isEmpty() const { return p->s.empty(); }
  void clear() { p->s.clear(); }
  T first() { return *p->s.begin(); }
  T last() { return *p->s.rbegin(); }
  T pollFirst() {
    auto x = first();
    remove(x);
    return x;
  }
  Box<T> lower(T x) {
    auto it = p->s.lower_bound(x);
    return it == p->s.begin() ? Box<T>{} : Box<T>(*--it);
  }
  Box<T> higher(T x) {
    auto it = p->s.upper_bound(x);
    return it == p->s.end() ? Box<T>{} : Box<T>(*it);
  }
  Box<T> floor(T x) {
    auto it = p->s.upper_bound(x);
    return it == p->s.begin() ? Box<T>{} : Box<T>(*--it);
  }
  Box<T> ceiling(T x) {
    auto it = p->s.lower_bound(x);
    return it == p->s.end() ? Box<T>{} : Box<T>(*it);
  }
  auto begin() const { return p->s.begin(); }
  auto end() const { return p->s.end(); }
  template <class C> void removeAll(C c) {
    for (auto x : c)
      remove(x);
  }
  struct Iterator {
    typename std::set<T, std::function<bool(T, T)>>::iterator it;
    T next() { return *it++; }
  };
  Iterator iterator() { return {p->s.begin()}; }
  bool operator==(std::nullptr_t) const { return !p; }
  bool operator!=(std::nullptr_t) const { return bool(p); }
};
template <class K, class V, bool Ordered = false> struct JMap {
  using Storage =
      std::conditional_t<Ordered, std::map<K, V>,
                         std::unordered_map<K, V, ValueHash, ValueEqual>>;
  std::shared_ptr<Storage> p = std::make_shared<Storage>();
  JMap() = default;
  JMap(std::nullptr_t) : p(nullptr) {}
  auto get(K k) {
    using R = std::conditional_t<std::is_arithmetic_v<V>, Box<V>, V>;
    auto it = p->find(k);
    return it == p->end() ? R{} : R(it->second);
  }
  V getOrDefault(K k, V v) {
    auto it = p->find(k);
    return it == p->end() ? v : it->second;
  }
  V put(K k, V v) {
    V old = p->count(k) ? p->at(k) : V{};
    (*p)[k] = v;
    return old;
  }
  void putIfAbsent(K k, V v) { p->emplace(k, v); }
  bool containsKey(K k) const { return p->count(k); }
  bool contains(K k) const { return containsKey(k); }
  V remove(K k) {
    V old = p->count(k) ? p->at(k) : V{};
    p->erase(k);
    return old;
  }
  void clear() { p->clear(); }
  int size() const { return p->size(); }
  bool isEmpty() const { return p->empty(); }
  JList<K> keySet() {
    JList<K> a;
    for (auto &x : *p)
      a.add(x.first);
    return a;
  }
  JList<V> values() {
    JList<V> a;
    for (auto &x : *p)
      a.add(x.second);
    return a;
  }
  K firstKey() { return p->begin()->first; }
  K lastKey() { return p->rbegin()->first; }
  Box<K> floorKey(K k) {
    auto it = p->upper_bound(k);
    return it == p->begin() ? Box<K>{} : Box<K>((--it)->first);
  }
  Box<K> ceilingKey(K k) {
    auto it = p->lower_bound(k);
    return it == p->end() ? Box<K>{} : Box<K>(it->first);
  }
  bool operator==(std::nullptr_t) const { return !p; }
  bool operator!=(std::nullptr_t) const { return bool(p); }
};
template <class K, class V> using JTreeMap = JMap<K, V, true>;
template <class T> struct JHashSet {
  std::shared_ptr<std::unordered_set<T, ValueHash, ValueEqual>> p =
      std::make_shared<std::unordered_set<T, ValueHash, ValueEqual>>();
  JHashSet() = default;
  JHashSet(std::nullptr_t) : p(nullptr) {}
  template <class C> explicit JHashSet(C c) : JHashSet() {
    for (auto x : c)
      add(x);
  }
  bool add(T x) { return p->insert(x).second; }
  bool remove(T x) { return p->erase(x); }
  bool contains(T x) const { return p->count(x); }
  int size() const { return p->size(); }
  bool isEmpty() const { return p->empty(); }
  void clear() { p->clear(); }
  auto begin() const { return p->begin(); }
  auto end() const { return p->end(); }
  template <class C> void removeAll(C c) {
    for (auto x : c)
      remove(x);
  }
  struct Iterator {
    typename std::unordered_set<T, ValueHash, ValueEqual>::iterator it;
    T next() { return *it++; }
  };
  Iterator iterator() { return {p->begin()}; }
};
template <class T, class V> void fill(Array<T> a, V v) {
  std::fill(a.begin(), a.end(), v);
}
template <class T, class V> void fill(Array<T> a, int l, int r, V v) {
  std::fill(a.begin() + l, a.begin() + r, v);
}
template <class T> void sort(Array<T> a) { std::sort(a.begin(), a.end()); }
template <class T> void sort(Array<T> a, int l, int r) {
  std::sort(a.begin() + l, a.begin() + r);
}
template <class T, class C> void sort(Array<T> a, C c) {
  std::stable_sort(a.begin(), a.end(),
                   [&](T x, T y) { return compare_call(c, x, y) < 0; });
}
template <class T, class C> void sort(Array<T> a, int l, int r, C c) {
  std::stable_sort(a.begin() + l, a.begin() + r,
                   [&](T x, T y) { return compare_call(c, x, y) < 0; });
}
template <class T> Array<T> copyOf(Array<T> a, int n) {
  Array<T> b(n);
  std::copy_n(a.begin(), std::min(n, a.length), b.begin());
  return b;
}
template <class T> void arraycopy(Array<T> a, int x, Array<T> b, int y, int n) {
  std::vector<T> temp(a.begin() + x, a.begin() + x + n);
  std::copy(temp.begin(), temp.end(), b.begin() + y);
}
template <class T, class... U> JList<T> asList(T a, U... rest) {
  return JList<T>(Array<T>{a, static_cast<T>(rest)...});
}
template <class T> JList<T> asList(Array<T> a) { return JList<T>(a); }
struct IO {
  IO() = default;
  template <class... A> IO(A...) {}
  String next() {
    std::string s;
    if (!(std::cin >> s))
      return nullptr;
    return String(s);
  }
  int nextInt() { return std::stoi(text(next())); }
  i64 nextLong() { return std::stoll(text(next())); }
  double nextDouble() { return std::stod(text(next())); }
  String nextString() { return next(); }
  String readString() { return next(); }
  jchar nextChar() {
    char c;
    std::cin >> c;
    return static_cast<unsigned char>(c);
  }
  jchar nextLowerCase() {
    int c;
    do {
      c = std::cin.get();
    } while (c != EOF && (c < 'a' || c > 'z'));
    return c;
  }
  jchar nextUpperCase() {
    int c;
    do {
      c = std::cin.get();
    } while (c != EOF && (c < 'A' || c > 'Z'));
    return c;
  }
  template <class... A> void printf(String fmt, A... a) {
    print(String::format(fmt, a...));
  }
  int size = 0, a = 0, b = 0, c = 0;
  void numbers() {
    std::string line;
    std::getline(std::cin >> std::ws, line);
    std::istringstream in(line);
    size = 0;
    a = b = c = 0;
    if (in >> a)
      ++size;
    if (in >> b)
      ++size;
    if (in >> c)
      ++size;
  }
  int readInt() { return nextInt(); }
  i64 readLong() { return nextLong(); }
  double readDouble() { return nextDouble(); }
  int readByte() { return std::cin.get(); }
  int read() { return readByte(); }
  template <class T> int read(Array<T> a) {
    int n = 0;
    for (; n < a.length; ++n) {
      int c = std::cin.get();
      if (c == EOF)
        break;
      a[n] = static_cast<T>(c);
    }
    return n ? n : -1;
  }
  template <class T> void write(Array<T> a, int off, int len) {
    for (int i = 0; i < len; ++i)
      std::cout.put(static_cast<char>(a[off + i]));
  }
  String readLine() {
    std::string s;
    if (!std::getline(std::cin, s))
      return nullptr;
    if (!s.empty() && s.back() == '\r')
      s.pop_back();
    return String(s);
  }
  template <class T> IO &print(T x) {
    std::cout << text(x);
    return *this;
  }
  template <class T> IO &println(T x) {
    print(x);
    std::cout << '\n';
    return *this;
  }
  IO &println() {
    std::cout << '\n';
    return *this;
  }
  template <class T> IO &writeInt(T x) { return print(x); }
  template <class T> IO &write(T x) { return print(x); }
  template <class T> IO &write(Array<T> x) {
    write(x, 0, x.length);
    return *this;
  }
  template <class T> IO &writeln(T x) { return println(x); }
  IO &writeln() { return println(); }
  void flush() { std::cout.flush(); }
  void close() { flush(); }
};
inline IO jout;
inline IO jin;
struct Tokenizer : IO {
  double nval = 0;
  String sval;
  int ttype = 0;
  static constexpr int TT_EOF = -1;
  template <class... A> Tokenizer(A... a) : IO(a...) {}
  void parseNumbers() {}
  int nextToken() {
    sval = nullptr;
    int c;
    while (true) {
      c = std::cin.peek();
      if (c == EOF)
        return ttype = -1;
      if (c <= 32) {
        std::cin.get();
        continue;
      }
      if (c == '/') {
        std::string skip;
        std::getline(std::cin, skip);
        continue;
      }
      break;
    }
    bool neg = false;
    if (c == '-') {
      std::cin.get();
      int d = std::cin.peek();
      if (d != '.' && (d < '0' || d > '9'))
        return ttype = '-';
      neg = true;
      c = d;
    }
    if (c == '.' || (c >= '0' && c <= '9')) {
      long double value = 0, scale = 1;
      bool dot = false;
      while (true) {
        c = std::cin.peek();
        if (c == '.' && !dot) {
          dot = true;
          std::cin.get();
        } else if (c >= '0' && c <= '9') {
          std::cin.get();
          value = value * 10 + (c - '0');
          if (dot)
            scale *= 10;
        } else
          break;
      }
      nval = static_cast<double>((neg ? -value : value) / scale);
      return ttype = -2;
    }
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c >= 160) {
      std::string word;
      do {
        word.push_back(std::cin.get());
        c = std::cin.peek();
      } while ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
               (c >= '0' && c <= '9') || c == '-' || c == '.' || c >= 160);
      sval = String(word);
      return ttype = -3;
    }
    std::cin.get();
    return ttype = c;
  }
};
struct StringTokenizer {
  std::istringstream in;
  explicit StringTokenizer(String s) : in(text(s)) {}
  bool hasMoreTokens() {
    in >> std::ws;
    return !in.eof();
  }
  String nextToken() {
    std::string s;
    in >> s;
    return String(s);
  }
};
struct Exception : std::runtime_error {
  Exception() : std::runtime_error("Java exception") {}
  explicit Exception(const std::exception &e) : std::runtime_error(e.what()) {}
  explicit Exception(String s) : std::runtime_error(text(s)) {}
  void printStackTrace() { std::cerr << what() << '\n'; }
};
} // namespace j
#endif
