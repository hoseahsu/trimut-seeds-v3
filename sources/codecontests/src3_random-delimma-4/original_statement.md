Manu is a very bright student and had learned c++ Programming on her own.She has covered loops and if/else.She is a very inquisitive child and always love to discover new things.Same applies to programming she learns various syntax.One day while reading the documentation of a cstdlib library she came across a function called as rand().To test it's applicabilty she writes the following code.

//Program generates a random number in the range from 1 to n both inclusive and stores it in the array a the number of elements being k

#include<iostream>
#include<cstdlib>
using namespace std;

int main()
{
    int k,n;
    cin>>k;
    cin>>n;
    int a[k];
    for(int i=0;i<k;i++)
        a[i]=rand()%n+1;
    for(int i=0;i<k;i++)
    cout<<a[i]<<endl;
    return 0;
}

She executes this program and sees that the number in the array are not unique but are repeating.Now she wonders after iterating for the fixed value of k what is the probability of two numbers in the array being same(in value).

Constraints

n & k are less than 2000.

Input

First line consist of T representing the number of test cases.T lines follow.Each line consist of two values k representing the number of iteration and n representing the range of elements in n.(ie 1 to n).

Output

For each input values output a single value representing the probability. Output the answer rounded up to 9 decimal places  

SAMPLE INPUT
2
4 10
7 6

SAMPLE OUTPUT
0.496000000
1.000000000