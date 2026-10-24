You are given a string S consisting of letters `b`, `d`, `p` and `q`. Determine whether S is a mirror string.

Here, a mirror string is a string S such that the following sequence of operations on S results in the same string S:

1. Reverse the order of the characters in S.

2. Replace each occurrence of `b` by `d`, `d` by `b`, `p` by `q`, and `q` by `p`, simultaneously.

Constraints

* 1 \leq |S| \leq 10^5
* S consists of letters `b`, `d`, `p`, and `q`.

Input

The input is given from Standard Input in the following format:


S


Output

If S is a mirror string, print `Yes`. Otherwise, print `No`.

Examples

Input

pdbq


Output

Yes


Input

ppqb


Output

No