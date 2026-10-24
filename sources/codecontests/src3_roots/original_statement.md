Bosky needs your help in completing his maths homework today. He has to solve some questions as homework from a book named Jungly Mathematics. He knows that Jungly Mathematics contains certain quadratic equations which have imaginary roots. He is not yet introduced to the concept of imaginary roots and is only concerned with the questions having real roots.
The book contains N quadratic equation of the form a[i]x^2 + b[i]x + c[i] = 0 where a[i] != 0 and i represents the index of the question.

You have to make a program which will take N, a, b and c as input and tell him how many questions he can solve out of those N questions (i.e. You have to find how many quadratic equations in the book have real roots).

Input

Input will contain a number N denoting the number of quadratic equations.

N line follow, each one consisting of three space separated integers a[i], b[i] and c[i] representing the quadratic equation a[i]x^2 + b[i]x + c[i] = 0. where [0 ≤ i < N].

Output

Print a single integer denoting the number of quadratic equations Bosky can solve.

Constraints

1 ≤  N ≤ 100  

-100 ≤ a[i] , b[i], c[i] ≤ 100

SAMPLE INPUT
2
1 0 -1
1 1 1

SAMPLE OUTPUT
1

Explanation

The book contains only 2 quadratic equations:

1: x^2 - 1 = 0 
2: x^2 + x +1 = 0   

1st equation has two roots x = 1, -1, thus it can be solved by Bosky. 
2nd equation has complex roots, hence it can't be solved by Bosky.

Therefore, Bosky can solve only 1 question from the book.