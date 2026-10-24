#!/usr/bin/env python3
from pathlib import Path
import json
B=Path(__file__).resolve().parents[1]
s=json.loads((B/'release_summary.json').read_text())
text=f'''# TriMut-300 Strict：300 道公开原题及三层变异

本包包含 **300 道不同公开原题、1200 份完整题面**，每道题有 Raw、L1、L2、L3。机读入口是 [prompts.jsonl](prompts.jsonl)，逐题目录见 [INDEX.md](INDEX.md)，程序、测试和证据索引见 [seeds.jsonl](seeds.jsonl)。这是重新构建的严格版，旧 `trimut_seed300` 保留作历史记录，不作为本包实验入口。

## 四种条件的精确定义

| 条件 | 题面与数学任务 | 数据约束 | 正式测试 |
|---|---|---|---|
| Raw | 未变异的公开原题；保留原始规则、I/O、样例 | 原题原生约束 | 原样例、合法边界、小规模差分、原上界案例及精选来源测试 |
| L1 | 保持数学语义的叙事、实体或形式对象解释变异 | 与 Raw 完全相同 | **直接引用 Raw 的同一测试清单、输入、答案和资源预算** |
| L2 | 原规则不变，修改规模上限及必要联动约束 | 相对真正原题扩大 | Raw 全集 + 至少一条确实超出原界的合法扩大域测试 |
| L3 | 修改比较、逻辑、聚合、状态转移等算子；同步更新相关解释和样例答案 | 原题输入域保持不变 | 与 Raw 相同的输入列表，按新逻辑生成答案 |

Raw 的“未变异”指不改题目语义和原生约束。CodeContests 中排版丢失的上标、公式和插图链接按公开来源恢复；Library Checker 的原文模板用官方参数和样例展开。所有恢复操作保存在每题 `raw_provenance.json`，不将这些格式恢复算成变异。原始来源快照另存于 `sources/`。

L1 共 {s['l1_kinds'].get('narrative_entity_relabel',0)} 题叙事/实体替换、{s['l1_kinds'].get('formal_object_reinterpretation',0)} 题形式对象重释。每题有可逆编辑证书，核对数字、数学符号、受保护样例以及源文重建；形式题不冒称拥有完整故事换皮。

## 已完成的验证与边界

300 题均有真实扩大域见证、L3 独立小规模判定程序及至少一个能区分 Raw/L3 的输入；参考程序在冻结预算内通过所记录的合法测试。L3 独立小用例累计 **{s['l3_independent_small_case_total']}**，记录的区分见证累计 **{s['l3_distinguishing_witness_total']}**。计数是各题执行案例数，并非彼此独立的统计样本。

正式评测用例出现次数：Raw **{s['test_occurrences_by_condition']['raw']}**，L1 **{s['test_occurrences_by_condition']['l1']}**，L2 **{s['test_occurrences_by_condition']['l2']}**，L3 **{s['test_occurrences_by_condition']['l3']}**。Raw/L1 完全共享数据，Raw/L3 共享输入，这些数字不能相加称为独立输入数。

**L2 的 300/300 指真实规模扩大、合法输入和参考解执行通过。只有 {s['l2_algorithm_separation_count']} 题额外验证了“同一慢程序原界通过、扩大域超时”。** 其余题不能直接用于宣称必然发生算法范式迁移；这一状态逐题保存在 `l2_algorithm_resource_separation_validated`。若论文分析 PSR/算法跃迁，请单独使用已校准子集或补充基线校准。

验证采用有限测试、独立小域对拍、结构案例数学期望和构造性论证，不能保证所有合法输入永无错误。部分大型 L3 答案由经过小域独立验证的高效参考解生成，未逐一独立穷举；每例元数据区分实际证据。上游损坏测试、失败尝试、参考程序容量和平台兼容修复均保留记录。没有填入目标模型准确率、人工盲审或未经执行的实验结果。

## 开始实验

`prompts.jsonl` 每行只有 `seed_id`、`condition`、完整 `prompt` 和题面哈希。调用被测模型时，只发送 `prompt` 内容，统一附加输出代码的指令；不要发送答案、变异解释、程序或验证报告。

从本目录运行，环境要求 Linux、Python 3、g++、bubblewrap：

```bash
# 核对全部题面、程序、输入、答案与测试清单的完整性
python3 tools/audit_release.py

# 对一个模型生成的 C++17 或 Python 文件评测
python3 tools/judge.py --seed TM002 --condition l3 --source /absolute/path/answer.cpp

# 使用内置参考程序检查入口；--limit 2 只用于快速试运行
python3 tools/judge.py --seed TM002 --condition l3 --reference --limit 2
```

去掉 `--limit` 评测该条件全部正式用例。`--case NAME` 可复跑一个用例。程序编译和执行均进入无网络 bubblewrap 沙箱；资源上限读取逐题冻结元数据。输出含 AC/WA/TLE/RE 等逐例结果，完整日志写入 `runs/`。自定义答案题由相应 checker 判定，不用字符串相等强行比较不同合法构造。

Raw/L1/L2/L3 的模型输出应分别生成；L1 共用 Raw 测试不等于复用 Raw 的模型答案。每道种子作为配对分析单位，**1200 份题面不等于 1200 道独立原题**。同一原题四个版本及相近题族不得跨训练/测试划分；`family_split_groups` 给出已知分组，默认 `unsplit`，不声称穷尽所有语义相似关系。

## 文件组织

- `tasks/TM001/` … `tasks/TM300/`：四份完整题面、来源/编辑证书、冻结输入与答案。
- `evaluation/TMxxx/`：**统一评测入口**的 Raw、L2、L3 清单；L1 引用 Raw。L2 在这里合并原域和扩大域。
- `contracts/`：逐题原界、扩大轴、L3 规则、证明思路、执行预算、程序和证据绑定。
- `validation/`：真实运行记录、独立核验、失败历史与整包完整性审计。
- `sources/`：公开原题、来源测试、上游参考代码及许可说明；原始快照不被覆盖。
- `assets/`、`native/`、`library_work/`、`replacements/`：标程、独立判定程序、严格输入校验器、生成器及重建工具。
- `recipes/`：复用的实现/比较器辅助模块，其中旧版弱约束实验字段是历史实现元数据，**不用于本包题面、约束、预算或评测选择**。这些以 `seeds.jsonl → evaluation/、contracts/` 为准。
- `release_summary.json`：实际计数、发布状态与校验哈希。

逐题来源保留原平台题号、CodeContests 行索引或 Library Checker 标识。部分 CodeContests 原平台链接无法确认，明确只给数据集链接与来源快照，不将通用数据集主页冒称原题专属链接。公开题面、图像及上游代码的原许可/版权各自保留；本地研究包不赋予额外的统一转载许可。

13 道原题引用的 24 张原始插图已归档在 `sources/original_illustrations/`，URL 与本地路径及哈希映射见 `url_map.json`。19 张已目视检查；5 张 BMP 因预览工具不支持，仅核对原文件与哈希，明确保留这一检查限制。原图对应 Raw，不作为其他变体已完成图文适配认证的依据。

## 导出包

`trimut_seed300_strict_prompts.zip` 用于查看、导入 1200 份题面，包含逐题文本及 `prompts.jsonl`；它不包含判题数据。完整实验与重现使用 `trimut_seed300_strict_full.tar.zst`，解压命令：

```bash
tar --zstd -xf trimut_seed300_strict_full.tar.zst
cd trimut_seed300_strict
python3 tools/audit_release.py
```

完整包保留源代码、输入/答案、合同与运行报告；排除可重新编译的临时程序和 Python 缓存。包外 `trimut_seed300_strict_artifacts.json` 提供导出包大小、哈希与打包核验结果。

5 道存在未解决原始描述歧义的候选被不同公开原题替换，记录见 `replacements/index.json`。TM101 的官方样例特意缩短每日字符串，保留为说明用例并单独执行；正式输入域仍要求每天 1440 字符。详细例外见逐题合同。
'''
(B/'README.md').write_text(text)
print('README written')
