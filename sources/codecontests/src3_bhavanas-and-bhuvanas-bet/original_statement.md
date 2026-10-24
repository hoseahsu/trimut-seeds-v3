Bhavana and Bhuvana place bet every time they see something interesting that can occur with a probability 0.5. 
Both of them place a bet for a higher amount which they don’t posses at that time. But when one wins she demands other for the bet amount. For example if Bhuvana wins she asks bhavana for the bet amount. 
But Bhavana is unable to pay the amount on that day, so she comes up with this ingenious idea to give a small unit of milky bar worth Rs.1 to Bhuvana on day 1. Another unit on day 2 (worth Rs 1 again). So on till ‘N’ days. 
On Nth day she pays the whole of the bet amount (i.e Rs N) and takes back all her chocolate pieces.  As Bhavana is a possessive girl, she doesn’t want to make N pieces of her chocolate bar, so help Bhavana to make the minimum number of cuts in the chocolate bar that she can mortgage for the bet amount.

Input
First line contains T number of bets that are placed.
Next T lines contain the amount to be paid which is equal to the length of the chocolate.

Output
An integer indicating the minimum number of cuts to be made in the chocolate for each test case in a new line

Constraints
1 ≤ T ≤ 10^5
1 ≤ N<2^64

Sample Input
2
3
10

Sample Output
1
3
Explanation:- 
Test case: 1 
She needs to make only one cut to divide the chocolate into two parts one of 1 unit (rs 1) another of 2units(rs 2).
On day one she gives one piece of rs1. On day 2 she takes the piece which is of rs 1 and gives the piece which is of Rs 2. So at the end of day 2 bhuvana has rs2 worth chocolate. On day3 bhavana repays the money and takes the chocolate back.
Test case: 2 
Bhavana needs to make 3 cuts so that the chocolate bar is divided into pieces worth rs1,  rs2,  rs3, rs4.

Day1- give rs1 worth chocolate.
Day2- take back rs1 worth chocolate, give rs2 worth chocolate.
Day3- take back rs2 worth chocolate, give rs3 worth chocolate.
Day4- take back rs3 worth chocolate, give rs4 worth chocolate.
Day5-give rs1 worth chocolate (which u took back on day1)(so now bhuvana has 4+1=5).
Day6-now take back rs1 worth chocolate. Give rs2 worth chocolate (4+2=6)
Day7-take back rs2 worth chocolate. Give rs3 worth chocolate (4+3=7)
Day8-give rs1 worth chocolate (took back on day 6)(4+3+1=8)
Day9-take back rs1 worth chocolate. Give rs2 worth chocolate (4+3+2=9)
Day10-repay the money and take chocolate pieces back

SAMPLE INPUT
2
3
10

SAMPLE OUTPUT
1
3