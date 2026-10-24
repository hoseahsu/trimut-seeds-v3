# Library Checker 严格版子集（TM221–TM300）

本子集含 80 道不同的公开原题。`contracts/library/TMxxx.json` 是逐题交付合同，schema 为 `trimut.strict.library.v1`。`library_work/native_strict_plan.json` 保留源包位置、原始参数、时间限制、变异说明及 L2 上界改动。所有路径均相对于 `data/trimut_seed300_strict`。

## 题面与测试

- **Raw**：`tasks/TMxxx/raw.txt` 忠实展开源 `task.md` 的英文及共享内容，代入原 `info.toml` 参数并恢复全部原样例；没有重新概括题意或降低规模上界。源模板、参数、官方测试哈希清单保留在 `sources/library-checker-problems-master`。`raw_provenance.json` 保存逐文件与逐样例 SHA256。
- **L1**：由专门作者完成叙事变异；本合同要求它引用与 Raw 完全相同的 `raw_test_manifest.json` 及输入、预期输出文件。Raw/L1 测试范围是可复现的实验子集，不是完整官方隐藏测试集。
- **L2**：`l2.txt` 只修改原 Constraints 中选定的规模上界，其他题面字节保持一致。每题至少一个原生规模上界严格增加；两条扩大域输入均经扩大上界后的源验证器接受，并超过旧上界。优化程序在原生 CPU 时限内通过，与源参考解语义一致。
- **L3**：`l3.txt` 修改逻辑算子并完整保留原生 Constraints；原样例输入不变、答案重新计算。L3 使用 Raw 同一套原域输入，答案位于 `tests/l3`。合同包含正确性论证、独立小样本比较和使 Raw 答案失效的见证。

80 题共有 122 个原样例，输入和输出均与官方 `hash.json` 一致。冻结清单包含 1,142 个 Raw/L1 原域用例、相同的 1,142 个 L3 输入和 160 个 L2 扩大域用例。每题至少一条输入实际达到一个原生规模上界。895 个小用例完成独立 Raw/L3 oracle 比较，共记录 678 个区分见证。

## 证据的适用范围

`l2.native_upper_bound_strictly_expanded` 与 `l2.fast_program_passed_frozen_expanded_tests` 为真。`l2.algorithm_resource_separation_validated` 为假：尚未证明某个自然的低效算法在原题上界内通过、扩大后失败，旧包的弱域对比不适用于此结论。

L3 的大用例答案由优化程序生成；独立的枚举或扫描 oracle 验证小用例。有限测试与论证不等于全输入形式化证明，也不声称变异题在公开题库中从未出现。TM253 的原样例含 `N=10^9`，早期自动尝试直接枚举 oracle 时两次触及 CPU 限制；失败记录保留在 `oracle_attempts_outside_small_domain`，不计为独立答案比较。该题另有 9 个小用例的双 oracle 比较与 9 个见证，原样例 Raw 官方哈希和 L3 优化程序运行均通过。

所有参考程序、oracle 与生成器的编译/执行均在无网络的 bubblewrap 隔离中进行。实验内存为 1,024 MiB；源 `info.toml` 未注明内存上限，因此不将此值称为原题内存限制。原参考解用于生成 L2 预期输出时可使用较长预算；性能结论只依据合同里的 `l2_fast` 在原生 CPU 时限下的运行。

## 程序与容量修复

合同 `programs` 区分 `raw_source_reference`、`l2_source_reference`、`l2_fast`、`l3_fast` 和两个小 oracle，并绑定源码与本地头文件 SHA256。`output_checker` 只引用实际基础 checker，L2 使用 Raw 判定语义，不依赖旧包的弱域生成适配器。原域与扩大域输入验证器及各自 `params.h` 分开绑定。

扩大规模所需的固定缓冲、位集合、数组或节点池调整，仅作用于 `library_work/l2_packages`，每题 `strict_edit_log.json` 记录改动，冻结上游源包不变。`program_overrides.json` 另记录两个优化程序修复：TM231 去掉会在原域溢出的无用区间总和状态，只保存查询所需最小/最大值与懒标记；TM276 将 Raw/L2 固定位集合容量从 40 增至 42，原域 L3 保持原上界。修复后相关原域与扩大域证据已复核。

## 复现与汇总

从论文项目根目录运行：

```sh
python3 data/trimut_seed300_strict/library_work/summarize_progress.py
python3 data/trimut_seed300_strict/library_work/build_contracts.py
python3 data/trimut_seed300_strict/library_work/audit_final_integrity.py
```

最后一个命令只检查题面还原、来源绑定、测试/程序 SHA256、预算证据与见证，不重新运行解题程序。结果写入 `library_work/final_integrity_report.json`。

需要生成缺失的验证证据时，使用串行执行器；`--resume` 保留现有 manifest，不重复已完成的耗时验证：

```sh
taskset -c 1 python3 data/trimut_seed300_strict/library_work/run_serial.py native --ids TM221
taskset -c 1 python3 data/trimut_seed300_strict/library_work/run_serial.py l2 --ids TM221
```

执行器要求独占 CPU1，并由 bubblewrap 运行程序。读取已有证据请使用 `progress.json`、`contract_status.json` 与 `final_integrity_report.json`；`native_tests_status.json`、`l2_tests_status.json` 等批次日志只反映最近一次调用，不能当作全部 80 题的状态总表。
