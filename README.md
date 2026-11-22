# Algorithm_self-learning — C++17

来源：[左程云算法通关](https://github.com/algorithmzuo/algorithm-journey)。保留原课程目录与题目注释。原作者的课程、题解与代码归原作者所有；此仓库整理 C++ 学习版本，不额外授予原代码许可。

## 当前进度（尚未全部完成）

固定源版本：`8a7aa9993c3f5a8752c328831a5ddf9028ca18a1`。1,539 个 `.java` 源文件中，当前有 489 个对应的 `.cpp`：412 个恢复自原作者注释中的 C++ 实现，77 个由 Java 移植。其余 1,050 个待处理，详见 `conversion-manifest.json`。恢复原作者 C++ 与新移植代码分别记录，未将待处理文件计为完成。

## 编译与运行

每个文件是独立题解，不能将全部文件链接成一个程序。有 `main` 的题目可单独编译执行；仅有类或方法的题目需要测试驱动。

```sh
clang++ -std=c++17 -O2 src/class006/Code01_FindNumber.cpp -o find_number
./find_number
python3 tools/check_compile.py
clang++ -std=c++17 -O1 -fsanitize=address,undefined tests/intro.cpp -o test_intro
./test_intro
```

入门题保留外层课程类名；例如 `LanguageConversion::Solution`。链表节点使用指针，新增链表的内存由调用者释放。

## 验证范围

489 个文件均通过本地 Clang C++17 独立编译检查（`-fsyntax-only`）。排序、二分查找和峰值查找通过 2,000 组随机测试，链表合并、相加、分区通过基本用例，并启用 AddressSanitizer / UndefinedBehaviorSanitizer。编译通过不代表全部题目已经通过在线评测；恢复的 C++ 实现尚未全部进行运行测试。

兼容性调整：将 GNU `bits/stdc++.h` 换成标准头文件；`class164/Code04_Journey2.cpp` 的全局 `visit` 改名为 `visited`，避免 C++17 名称冲突。

新增课程 013–018、020–021 中的 9 个文件：队列、栈、最小栈、循环队列、循环双端队列、递归及迭代树遍历、递归最大值、归并排序。容器进行了 60,000 轮随机操作测试，树遍历和归并排序进行了 2,000 组随机测试，均启用 AddressSanitizer / UndefinedBehaviorSanitizer。测试代码见 `tests/containers.cpp`、`tests/trees_merge.cpp`。固定数组版本保留原课程容量约束。

新增 14 个文件：链表反转、输入输出课程全部 6 个文件、小和、翻转对、快速排序、随机选择和堆排序。`tests/sorting_matrix.cpp` 包含 2,000 组随机数组测试、500 组最大子矩阵暴力对照和 100 种链表长度测试；`tests/io.cpp` 检查 64 位整数边界、科学计数法、缓冲区切换、EOF 与溢出。均通过 ASan/UBSan。快读快写改用 C++ 字节流接口，Kattio 改用标准 C++ 流；不模拟 Java StreamTokenizer 的解析缺陷。小和中间累加值及按行求和使用 64 位整数。

新增 25 个文件（19 个 Java 移植，6 个作者 C++ 恢复），涵盖基础演示、堆、基数排序、异或与位运算，以及若干图算法示例。`tests/bits_basics.cpp` 包含 10,000 轮随机/边界测试；`tests/heap_radix.cpp` 包含 2,000 组排序、合并链表、区间覆盖和减半操作对照测试；`tests/restored_solutions.cpp` 验证新恢复题目的基本用例及保险箱全部 n=1..4、k=1..10 组合。均通过 ASan/UBSan。基数排序使用 64 位工作数组以容纳完整 int 范围；位运算显式处理 32 位补码。恢复代码修复：保险箱容量扩大至 10,002；夺回据点增加单节点处理。

新增 25 个 Java 移植文件：位图、位运算加减除和模乘、链表专题、二叉树层序/深度/宽度/构建/序列化/完全性，以及 LCA、路径和、平衡性、BST 验证与修剪、树上打家劫舍。`tests/bitset_arithmetic.cpp` 验证 21,000 轮位图操作、100,000 组算术对照与整数边界；`tests/linked_lists.cpp` 与 `tests/tree_properties.cpp` 各包含 2,000 组测试；`tests/tree_bfs_build.cpp` 覆盖 0–100 节点和深窄树；`tests/tree_codecs.cpp` 每种格式验证 1,000 棵随机树。均通过 ASan/UBSan。反序列化接受对应序列化器生成的有效格式；修剪不释放被移除节点，所有节点仍由调用者管理。
