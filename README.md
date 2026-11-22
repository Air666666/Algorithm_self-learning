# Algorithm_self-learning — C++17

来源：[左程云算法通关](https://github.com/algorithmzuo/algorithm-journey)。保留原课程目录与题目注释。原作者的课程、题解与代码归原作者所有；此仓库整理 C++ 学习版本，不额外授予原代码许可。

## 当前进度（尚未全部完成）

固定源版本：`8a7aa9993c3f5a8752c328831a5ddf9028ca18a1`。1,539 个 `.java` 源文件中，当前有 425 个对应的 `.cpp`：406 个恢复自原作者注释中的 C++ 实现，19 个由 Java 移植。其余 1,114 个待处理，详见 `conversion-manifest.json`。恢复原作者 C++ 与新移植代码分别记录，未将待处理文件计为完成。

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

425 个文件均通过本地 Clang C++17 独立编译检查（`-fsyntax-only`）。排序、二分查找和峰值查找通过 2,000 组随机测试，链表合并、相加、分区通过基本用例，并启用 AddressSanitizer / UndefinedBehaviorSanitizer。编译通过不代表全部题目已经通过在线评测；恢复的 C++ 实现尚未全部进行运行测试。

兼容性调整：将 GNU `bits/stdc++.h` 换成标准头文件；`class164/Code04_Journey2.cpp` 的全局 `visit` 改名为 `visited`，避免 C++17 名称冲突。

新增课程 013–018、020–021 中的 9 个文件：队列、栈、最小栈、循环队列、循环双端队列、递归及迭代树遍历、递归最大值、归并排序。容器进行了 60,000 轮随机操作测试，树遍历和归并排序进行了 2,000 组随机测试，均启用 AddressSanitizer / UndefinedBehaviorSanitizer。测试代码见 `tests/containers.cpp`、`tests/trees_merge.cpp`。固定数组版本保留原课程容量约束。
