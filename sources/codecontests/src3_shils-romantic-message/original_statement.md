Shil is now finally in a relationship with Uttu. Both of them like to exchange love letters. However, to avoid exposing their relationship, they use "encryption" to send their messages. They use the famous Caesar cipher to encrypt their messages, which mathematically explained is as follows:

Encryption of a letter x by a shift n can be described mathematically as,

En(x) = (x + n) mod 26

For example: The shift of letter 'a' by 2 will give letter 'c'. Shift of letter 'z' by 1 will give 'a'.

In sent message, the original letter will be replaced by encrypted letter.

Recently, Shil sent a message to Uttu. However, he forgot to mention the shift n, which would have helped Uttu to decrypt the message. However, Uttu is sure that his beloved will send him a message which would be lexicographically minimum, when decrypted.

Help Uttu to decrypt the message by choosing appropriate shift n, that will give lexicographically minimum original message, among all possible messages. Your task is to find the decrypted message for Uttu.

INPUT

First line will contain T, the number of messages you need to decrypt.
Next T lines will contain a string S, the message sent by Shil to Uttu.

OUTPUT

You have to output T lines, i^th line containing the answer to the i^th message.

CONSTRAINTS

T ≤ 10^6
|S| ≤ 10^6

All characters in input message consist of only lowercase latin characters ('a'-'z').

Total number of characters in a test file ≤ 10^6

SAMPLE INPUT
1
phqghumeay

SAMPLE OUTPUT
asbrsfxplj