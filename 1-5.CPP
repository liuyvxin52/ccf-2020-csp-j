输入：数组L, n ≥ k。输出：按非递减顺序排序的 L。
算法 BubbleSort：
    1. FLAG ← n //标记被交换的最后元素位置
    2. while FLAG > 1 do
    3・   k ← FLAG -1
    4・   FLAG ← 1
    5・   for j=1 to k do
    6.       if L(j) > L(j+1) then do
    7・         L(j)  ↔ L(j+1)
    8・         FLAG ← j
    对 n 个数用以上冒泡排序算法进行排序，最少需要比较多少次?（ ）。

A、n^2

B、n-2

C、n-1

D、n


参考答案：C