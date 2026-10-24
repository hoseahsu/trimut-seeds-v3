The russian intelligence agency KGB make an encryption technique to send their passwords. Originally the password is of 3 characters. After encryption the password is converted into 3 numbers A-B-C.

Now, Sherlock wants to decrypt the password encryption technique of KGB. Sherlock knows that every number  has only 2 possible values which are following:

POSSIBLE VALUES OF "A":   K, X

POSSIBLE VALUES OF "B":   G, Y

POSSIBLE VALUES OF "C":   B, Z

Help Sherlock to detect the encryption technique of the KGB and tell him the original password.
[See problem explanation for further clarifiaction]

INPUT:

The first line consist number of test cases T followed by T lines, each line consist of 3 space separated integers A, B, C.

OUTPUT

Print the correct message in format of C-C-C

Constraints:

1 ≤ T ≤ 50000

1 ≤ A, B, C ≤ 1000000000

SAMPLE INPUT
2
27 25 4
25 26 16

SAMPLE OUTPUT
K-G-B
X-Y-B

Explanation

For test case 1, the password sent is 27-25-4, then 27 can be either 'K' or 'X', similar case for 25 & 4. After applying the encryption 27 is converted into K, 25 is converted into G and 4 is converted into B.