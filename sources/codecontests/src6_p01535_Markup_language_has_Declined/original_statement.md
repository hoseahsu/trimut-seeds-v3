E: Markup language has declined

It's been centuries since we humans have been declining slowly. The earth may already belong to "Progurama". Programa-sans with an average height of 170 cm, 7 heads, high intelligence, and loves Kodingu. I have returned to my hometown of Nibunki, becoming an important international civil servant, "Esui," who is in charge of the relationship between Mr. Programa and people. I chose this job because it's a job that I can do even at my grandfather's age, so I thought it would be easy.

One day, Mr. Programa and his colleagues gave me something like two design documents. According to Mr. Programa, various information can be easily exchanged using texts and scripts.

The first design document was an explanation of the file that represents the sentence structure. The filename of this file ends with .dml and is called a DML file.

In the DML file, the structure of the sentence is expressed by sandwiching it with a character string called a tag. There are start tag and end tag as tags.


<Start tag name> Contents </ end tag name>


It is represented by the element of. At this time, the start tag name and the end tag name are represented by the same character string.

Tags can be nested and can be <tagA> <tagB> </ tagB> </ tagA>. Also, structures like <tagA> <tagB> </ tagA> </ tagB> are not allowed.

The tag name in the DML file is an arbitrary character string except for some special ones. The following five special tags are available.

* Tag name: dml
* Represents the roots of all tags.
* This start tag always appears only once at the beginning of the file, and the end tag of this tag appears only once at the end of the file.
* Tag name: script
* It always appears at the beginning of the dml tag or at the end tag.
* This tag cannot have a nested structure inside.
* Associate the script file enclosed in this tag.
* The character string enclosed in this tag is not output.
* Tag name: br
* A line break will be performed when displaying.
* Does not have an end tag.
* Tag name: link
* This tag cannot have a nested structure inside.
* When the user clicks on the character string enclosed in this tag, the entire current screen is erased and the DML file with the file name represented by that character string is displayed.
* Tag name: button
* This tag cannot have a nested structure inside.
* When the user clicks on the character string enclosed in this tag, the subroutine with the name represented by that character string is executed from the scripts associated with the script tag.



Tag names are represented only in uppercase and lowercase letters. No spaces appear in the tag name. The character strings that appear in the DML file are uppercase and lowercase letters, spaces,'<','>', and'/'. It is also possible that a tag with the same name exists.

Character strings other than tags enclosed by other than script tags are output left-justified from the upper left (0, 0) of the screen, and line breaks do not occur until the screen edge or br tag appears.

The second design document was an explanation of the DS file that shows the operation when the button is pressed in the DML file. Subroutines are arranged in the DS file.


Subroutine name {
formula;
formula;
...;
}


The semicolon marks the end of the expression.

For example, suppose you have a sentence in a DML file that is enclosed in <title>? </ Title>. The possible expressions at that time are the following four substitution expressions.


title.visible = true;
title.visible = false;
title.visible! = true;
title.visible! = false;


Assigning a boolean value to visible changes whether the content of the tag is displayed or not. If it disappears, the text after that will be packed to the left. When the currently displayed DML file is rewritten by clicking the link tag at the beginning, the initial values ​​are all true.

'! ='Represents a negative assignment. In the above example, the 1st and 4th lines and the 2nd and 3rd lines are equivalent, respectively.

The expression can also change multiple values ​​at the same time as shown below.


titleA.visible = titleB.visible = true;


At this time, processing is performed in order from the right. That is,


titleB.visible = true;
titleA.visible = titleB.visible;


Is equivalent to the two lines of. However, this representation is for convenience only, and the tag is not specified on the far right of the statement in the script. Also,


titleA.visible! = titleB.visible = true;


Is


titleB.visible = true;
titleA.visible! = titleB.visible;


Is equivalent to.

The tag is specified by narrowing down with'.'. For example


dml.body.title


Refers to the title tag, which is surrounded by the dml tag and the body tag. However, the script tag and br tag are not used or specified for narrowing down.

At this time, please note that the elements to be narrowed down are not always directly enclosed. For example, when <a> <b> <c> </ c> </ b> </a>, both a.b.c and a.c can point to c.

Also, if there are tags with the same name, the number of specified tags is not limited to one. If the specified tag does not exist, the display will not be affected, but if it appears when changing multiple values ​​at the same time, it will be evaluated as if it existed.

BNF is as follows.


<script_file> :: = <subroutine> | <script_file> <subroutine>
<subroutine> :: = <identifier>'{' <expressions>'}'
<expressions> :: = <expression>';' | <expressions> <expression>';'
<expression> :: = <visible_var>'=' <visible_exp_right>
| <visible_var>'! ='<Visible_exp_right>
| <visible_var>'=' <expression>
| <visible_var>'! ='<Expression>
<visible_exp_right> :: ='true' |'false'
<visible_var> :: = <selector>'.visible'
<selector> :: = <identifier> | <selector>'.' <Identifier>
<identifier> :: = <alphabet> | <identifier> <alphabet>
<alphabet> :: ='a' |'b' |'c' |'d' |'e' |'f' |'g'
|'H' |'i' |'j' |'k' |'l' |'m' |'n'
|'o' |'p' |'q' |'r' |'s' |'t' |'u'
|'v' |'w' |'x' |'y' |'z'
|'A' |'B' |'C' |'D' |'E' |'F' |'G'
|'H' |'I' |'J' |'K' |'L' |'M' |'N'
|'O' |'P' |'Q' |'R' |'S' |'T' |'U'
|'V' |'W' |'X' |'Y' |'Z'


It's going to hurt my head. Isn't it? Is that so.

The user clicks the coordinates (x, y) on the screen after the first DML file is displayed. Then, the screen changes according to the link or button at that location. What if I click anywhere else? Nothing happens. As expected.

What can we do? I will watch over while handing over my favorite food, Enajido Rinku.

Input

The input is given in the following format.


N
filename1
file1
filename2
file2
...
filenameN
fileN
M
w1 h1 s1 startfile1
x11 y11
...
x1s1 y1s1
...
wM hM sM startfileM
xM1 y11
...
xMsM yMsM
...


N (1 <= N <= 20) represents the number of files, after which the file name and the contents of the file are given alternately. filename is represented by any 16 letters of the alphabet plus'.dml' or'.ds'. If it ends with'.dml', it is a DML file, and if it ends with'.ds', it is a DS file. The character string of the file is given in one line and is 500 characters or less.

M (1 <= M <= 50) represents the number of visiting users. For each user, screen width w, height h (1 <= w * h <= 500), number of operations s (0 <= s <= 50), start DML file name, and clicked coordinates of line s x, y (0 <= x <w, 0 <= y <h) is given.

There are no spaces in the DS file. Also, the tags in the given DML file are always closed. The subroutine name with the same name does not appear in the script throughout the input.

Output

Output the final screen with width w and height h for each user. The part beyond the lower right of the screen is not output. If there are no more characters to output on a certain line, output'.' Until the line becomes w characters.

Sample Input 1


1
index.dml
<dml> <title> Markup language has Declined </ title> <br> Programmers world </ dml>
1
15 3 0 index


Sample Output 1


Markup language
has Declined ..
Programmers wor


Sample Input 2


2
hello.dml
<dml> <link> cut </ link> </ dml>
cut.dml
<dml> hello very short </ dml>
1
10 2 1 hello
Ten


Sample Output 2


hello very
short ....


Sample Input 3


2
index.dml
<dml> <script> s </ script> slip <fade> akkariin </ fade> <br> <button> on </ button> <button> off </ button> </ dml>
s.ds
on {fade.visible = true;} off {fade.visible! = true;}
2
15 3 0 index
15 3 3 index
3 1
1 1
3 1


Sample Output 3


slipakkariin ...
on off .........
...............
slip ..........
on off .........
...............






Example

Input

1
index.dml
<dml><title>Markup language has Declined</title><br>Programmers world</dml>
1
15 3 0 index


Output

Markup language
 has Declined..
Programmers wor