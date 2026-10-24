Prime numbers are those numbers which have only 2 factors, 1 and the number itself. For example, 3 is a prime number have factors 1 and 3 only.

Now, all the prime numbers are arranged sequentially in ascending order. i.e:- 2, 3, 5,7...and so on. Now, your task is to calculate those prime numbers which are present at a prime position. For example, 2 is present at position 1 which is not a prime number while 3 is present at position 2 which is a prime  number, hence 3 is the first prime positioned number. Now, these primed positioned prime numbers are numbered is ascending order such that:

first prime positioned number is 3. So, it is given number 1.

second prime positioned number is 5. So, it is given number 2. 

and so on. Now, we are given 2 numbers n and m which denotes the nth and mth prime positioned numbers. Now, your task is to calculate the multiplication of prime positioned number present at nth and mth position. Since the answer may be large, output the answer modulo 10^9 + 7.

INPUT

First line contains an integer t denoting the number of test cases. The next t lines contains two integers n and m separated by space, denoting the prime positioned numbers which are given numbers n and m.

OUTPUT

A single integer (one per line) for each test t, that is the answer to the question.

CONSTRAINTS

1 ≤ t ≤10^6

1 ≤ n,m ≤10000

SAMPLE INPUT
2
1 2
2 3

SAMPLE OUTPUT
15 
55

Explanation

Test case 1: Here n=1 and m=2. Now, 1st and 2nd prime positioned numbers are 3 and 5 respectively. So, answer is 3*5=15.

Test case 2: Here n=2 and m=3. Now, 2nd and 3rd prime positioned numbers are 5 and 11 respectively. So, answer is 55.