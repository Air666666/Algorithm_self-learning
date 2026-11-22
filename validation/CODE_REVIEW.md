# 转换代码复查与修复

此前版本存在能够复现的转换错误。下面记录已修复的问题与实际验证范围，不以编译成功替代算法正确性结论。

## 测试链接逐文件核验

重新扫描固定源版本的全部 1,539 个 Java 文件，并逐项核对对应 C++ 的文件开头：1,441 个原文件含 1,662 条测试/参考链接记录，遗漏为 **0**。98 个原文件没有提供链接。全部地址保留在代码开头和 [课程链接索引](../PROBLEM_LINKS.md)；未把参考资料伪称为在线评测地址，也未补造未知地址。

## 已修复的问题

| 问题 | 影响与修复 | 验证 |
| --- | --- | --- |
| 插入文本时空格被跳过 | `class152/Code03_TextEditor1`、`class172/Code06_TextEditor1` 原先使用跳过空白的读入，导致文本错位，甚至把下一条命令读进文本后崩溃。增加专用 `TextEditorIO`，保留 ASCII 32–126 的字符，并按原读入器消费参数后的一个分隔符。 | 前后空格、内部空格及后续命令的 Java/C++ 对照；修复前失败、修复后通过。 |
| 有序集合查不到引用类型元素时抛异常 | 公共 `JSet` 把数组等引用类型也包装成数值装箱对象；`class129/Code04_FindNear::near1()` 第一次查询空集合就抛出 `null unboxing`。现在仅数值类型使用 `Box`，数组和节点等引用类型返回对应空值。 | 原 Java 用例对照，以及 1,000 组随机最近/次近结果与暴力枚举比较。 |
| 比较器的相等情况不符合 C++ 排序要求 | 8 个文件沿用了上游 `a <= b ? -1 : 1` 等写法，相等时返回 -1。改成三路比较，使相等元素返回 0，满足 STL 严格弱序的要求。涉及雇佣工人、最大平均通过率、元素、购买装备、Dropping Tests 及副本、电梯、Momo 方程。 | 雇佣工人 500 组子集穷举、通过率分配 300 组分配方案穷举；ASan/UBSan 通过。 |
| 其他字符读入语义丢失 | 对照原 `FastReader.nextChar()` 的实现，区分“读完整个词并返回末字符”“跳过非字母”和“保留可打印空格”，恢复对应调用。默认读字符遇到 EOF 返回 0，避免使用未初始化变量。 | 全部自定义 `nextChar` 实现已扫描；修改后的各题重新编译；公共接口回归。 |
| 四舍五入与稳定排序不一致 | Java `Math.round(-1.5)` 返回 -1，C++ `llround` 返回 -2。新增饱和、NaN 与负半值处理，并修正 Camera Relocation 的调用；`JList.sort` 改为稳定排序。 | 半值、NaN、无穷值与等键元素顺序回归。 |

修复前的失败输出见 [review-before-fixes.json](review-before-fixes.json)。原始算法中有关输入范围、递归深度和内存规模的限制仍然适用。

## 验证结果与复现

- **1,539 / 1,539** 个文件重新通过 C++17 编译检查，见 [compile-report.json](../compile-report.json)。
- **44 / 44** 个回归程序通过 ASan/UBSan，包含新增的 1,800 组暴力对照，见 [regression-report.json](regression-report.json)。
- **38 / 38** 个上游随机对数器与 Java 对照通过。仅在测试副本中限制 `main` 的测试规模，并将两端随机源替换为相同种子的 LCG；算法函数未更改。两端输出完全一致，且没有“出错”等失败提示，见 [review-selfchecks.json](review-selfchecks.json)。
- **22 / 22** 个程序、**51 / 51** 组输入与 Java 对照通过，见 [review-programs.json](review-programs.json)。原文件仅含注释形式 C++ 的版本，使用同一道题的 Java 实现作参照；64 位判素版本仅使用其范围内的输入，不拿任意精度输入测试它。
- 保存的 **59 / 59** 项复现任务通过：38 项有界对数器及 21 个完整程序的输入测试；最近邻的单独方法用例另由暴力回归覆盖，见 [review-replay.json](review-replay.json)。

```sh
python3 tools/check_compile.py --jobs 6 --pch  # Clang；可去掉 --pch
python3 tools/test.py                        # ASan/UBSan 回归
python3 tools/test_review.py                 # 保存的 Java 结果复现
```

上述脚本沿用 README 中的 `CXX` / `CXXFLAGS` 配置。Java 对照产生的期望结果、输入以及对数器参数已保存在 `tests/review_programs/`、`tests/review_selfchecks.json`。

## 覆盖边界

对 1,048 个语法树转换文件进行了全量结构扫描，检查输入封装、带副作用的复合赋值、标签跳转、`finally` 等转换风险；本快照中没有未处理的标签跳转、`finally` 或含自增自减左值的复合赋值。还扫描了左右求值次序中直接共享自增自减变量的情况，未发现剩余命中。

**并非每个题目都已经运行了完整评测数据，也没有逐题提交在线评测。** 逐文件动态覆盖情况见 [review-coverage.json](review-coverage.json)；`runtime_checks` 为空的文件仅有相应结构/来源核对及编译结果，不能据此宣称其算法已验证正确。恢复的原作者 C++、手工移植和语法树转换在清单中分别标注。
