# Algorithm_self-learning — C++17

[左程云《算法通关》](https://github.com/algorithmzuo/algorithm-journey) `src` 目录的 C++ 学习版本，保留课程目录、文件名和原题注释。

固定源版本：[`8a7aa9993c3f5a8752c328831a5ddf9028ca18a1`](https://github.com/algorithmzuo/algorithm-journey/tree/8a7aa9993c3f5a8752c328831a5ddf9028ca18a1/src)。全部 **1,539 个 Java 文件均有对应 C++ 文件**，待处理数为 0：

| 来源 | 文件数 |
| --- | ---: |
| 恢复原作者在 Java 注释中提供的 C++ 实现 | 414 |
| 直接移植的 C++ 实现 | 77 |
| 从 Java 语法树转换并配套公共运行库的 C++ 实现 | 1,048 |

逐文件来源、原始 Git blob SHA、转换方式和目标 SHA-256 见 [conversion-manifest.json](conversion-manifest.json)。原仓库之后新增的文件不包含在此快照中。

## 编译运行

需要支持 C++17 的 Clang/GCC，以及 **Boost 头文件**（使用 Multiprecision，无需链接 Boost 二进制库）。Linux 可安装 `libboost-dev`；macOS 可通过 `brew install boost` 安装。Boost 不在编译器默认路径时，用 `CXXFLAGS` 指定 include 路径。

```sh
# 每次编译一个题解；在本仓库根目录执行
python3 tools/build.py src/class097/Code02_LargeNumberIsPrime2.cpp -o prime
./prime

# 也可以直接使用编译器。-fwrapv 用于保留 Java 有符号整数回绕行为。
g++ -std=c++17 -O2 -fwrapv src/class097/Code02_LargeNumberIsPrime2.cpp -o prime

# macOS Homebrew 示例
CXXFLAGS="-I$(brew --prefix boost)/include" python3 tools/build.py src/class097/Code02_LargeNumberIsPrime2.cpp -o prime

# 全量独立编译检查；--pch 是 Clang 的可选加速方式
python3 tools/check_compile.py --jobs 6
python3 tools/check_compile.py --jobs 6 --pch

# 运行回归测试，启用 AddressSanitizer 和 UndefinedBehaviorSanitizer
python3 tools/test.py
```

每个文件都是独立题解，**不能把全部文件链接成一个程序**。原文件有 `main` 的版本可以直接运行；只含题解类、方法或教学片段的文件需要测试驱动。外层课程类名得到保留，例如 `Code02_PathWithMinimumEffort`。

1,048 个语法树转换文件依赖 [include/jcompat.hpp](include/jcompat.hpp)。请保留相对目录，或自行调整 include 路径。运行库使用原生 C++/STL 与 Boost，不调用 Java/JVM：`Array<T>` 保留 Java 数组的共享引用与多维数组语义；字符串保留 UTF-16 字符索引；哈希表、顺序表、堆、位集合与高精度数提供对应接口。存在同名字段和方法时，方法名加 `_method`；C++ 关键字冲突会改名。

原题的输入规模、下标和递归深度约束仍然适用。链表、树和其他节点使用指针，长期复用实例时需由调用者管理节点生命周期。提交在线评测前，需按平台要求提供入口并携带公共头文件；不同平台的依赖和内存限制可能需要调整。

## 验证结果

- **1,539 / 1,539** 个源文件通过 Apple Clang 21、C++17 独立编译检查，见 [compile-report.json](compile-report.json)。检查使用 `-fsyntax-only`，不把无入口的教学片段强行链接为程序。
- **28 项算法、861 组用例**与固定源版本的 Java 运行结果逐项一致，涵盖字符串、动态规划、滑动窗口、二分、堆、并查集和高精度运算，见 [算法对照记录](validation/algorithm-differential.json)。
- **11 类完整程序、26 组输入**与 Java 的标准输出逐字一致，包括时间格式输入、超大整数判素、树状数组、线段树、高斯消元、异或约束、欧拉路径和传递闭包，见 [输入输出对照记录](validation/stdin-differential.json)。输入和期望输出保存在 `tests/java_cpp_fixtures/`。
- **43 个回归测试程序全部通过**，启用 ASan/UBSan，见 [regression-report.json](validation/regression-report.json)。包括此前批次的随机测试、公共运行库测试、表达式求值回归，以及上述算法对照驱动。Java 对照驱动需要另行取得原 Java 源码；C++ 驱动及期望输出已包含在仓库中。
- 1,539 个源文件的 Git blob SHA 均已核对；本地副本的差异仅涉及末尾换行和 CRLF，见 [source-integrity.json](validation/source-integrity.json)。

编译和抽样运行通过**不代表所有题目均已通过在线评测**。并未对全部题目运行完整评测数据。Java 随机演示使用 C++ 随机引擎；对象默认字符串、无序集合遍历顺序和运行计时不保证与 JVM 一致。哈希函数教学示例实现 MD5，算法枚举仅列出这一实现，不模拟 Java 安全提供者的全部算法。

转换过程中修正了括号内自增/自减的解析丢失，保留需要的函数参数求值顺序，并适配了可空整数、字符串对象身份、动态位集合及 StreamTokenizer 的标点处理。恢复原作者 C++ 代码时，将 `bits/stdc++.h` 改为标准头文件；早期批次的具体修正和测试说明保存在 [previous-validation.md](validation/previous-validation.md)。

## 来源与权利

原课程、题解、注释和算法代码归原作者所有。本仓库保留来源说明，不额外授予原代码许可。Boost 为外部依赖，遵循其自身许可证。
