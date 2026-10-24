Dr .: Peter. I did.

Peter: See you again? What kind of silly invention is this time?

Dr .: You invented the detector for that phantom elementary particle axion.

Peter: Speaking of Axion, researchers such as the European Organization for Nuclear Research (CERN) are chasing with a bloody eye, aren't they? Is that true?

Dr .: It's true. Although detailed explanation is omitted, a special phototube containing a very strong magnetic field shines to detect the passing axion.

Peter: It's a Nobel Prize-class research comparable to Professor Koshiba's neutrino detection if it is detected first. With this, you can get rid of the stigma such as "No good laboratory", which is doing only useless research.

Dr .: That's right. In honor of Professor Koshiba's "Super-Kamiokande," this device was named "Tadajaokande" (to put it badly).

Peter: Is it a bit painful or subservient?

Dr .: That's fine, but this device has a little quirks. When the axion particles pass through a phototube, the upper, lower, left, and right phototubes adjacent to the phototube react due to the sensitivity.

Figure 1 | | Figure 2
--- | --- | ---
| | ★ | ● | ● | ● | ●
--- | --- | --- | --- | ---
● | ● | ● | ★ | ●
● | ● | ● | ● | ●
● | ● | ● | ● | ●
● | ● | ★ | ● | ●
|
---

->


| ○ | ○ | ● | ○ | ●
--- | --- | --- | --- | ---
○ | ● | ○ | ○ | ○
● | ● | ● | ○ | ●
● | ● | ○ | ● | ●
● | ○ | ○ | ○ | ●
| | | ● | ○ | ○ | ● | ○
--- | --- | --- | --- | ---
○ | ★ | ★ | ○ | ☆
● | ● | ○ | ● | ●
○ | ● | ● | ○ | ●
● | ○ | ○ | ○ | ●
|
---

->


| ● | ● | ● | ● | ●
--- | --- | --- | --- | ---
● | ● | ● | ○ | ●
● | ○ | ● | ● | ○
○ | ● | ● | ○ | ●
● | ○ | ○ | ○ | ●



Peter: In other words, when a particle passes through the phototube marked with a star on the left side of Fig. 1, it lights up as shown on the right side. (The figure shows an example of 5 x 5. Black is off and white is on. The same applies below.)

Dr .: Also, the reaction is the reversal of the state of the photocell. In other words, the disappearing phototube glows, and the glowing phototube disappears.

Peter: In other words, when a particle passes through the ★ and ☆ marks on the left side of Fig. 2, it will be in the state shown on the right side.

Dr .: A whopping 100 (10 x 10) of these are placed in a square and stand by.

Peter: Such a big invention, the Nobel Prize selection committee is also "Hotcha Okande".

Dr .: Oh Peter, you seem to be familiar with the style of our laboratory. It feels good. Let's start the experiment now. First of all, this device is currently randomly lit with phototubes, so please reset it to the state where everything is off so that you can start the experiment. Well, all you have to do is think about which phototube you should hit the axion particles to make them all disappear. Isn't it easy?

Peter: It's nice to think about it, but Dr. In order to hit it, you must have a device that can generate and drive phantom axion particles.

Dr .: ...

Dr. and Peter (at the same time) Collya Akande! -:

With that said, it's the doctor's laboratory that is going to be harmonious today, but as usual, the story is unlikely to proceed at all. It can't be helped, so please create a program for Peter. The program looks like this:

A. Enter the photocell status of the device as a 10x10 array. 0 indicates that the light is off, and 1 indicates that the light is on. It does not contain any data other than 0 and 1.

B. In order to turn off all the input device states, the position where the axion particles pass is calculated and output. It represents the position of the phototube in the same 10x10 array as the input. "0 does not pass" and "1 does not pass". There is always only one way to turn everything off.



Input

Given multiple datasets. The first line gives the number of datasets n (n ≤ 20). Each dataset is given in the following format:


a1,1 a1,2 ... a1,10
a2,1 a2,2 ... a2,10
::
a10,1 a10,2 ... a10,10


ai, j represent an integer (0 or 1) indicating the state of the photocell in the i-th row and j-th column of the device.

Output

For each data set, output the position through which the particles pass in the following format.


b1,1 b1,2 ... b1,10
b2,1 b2,2 ... b2,10
::
b10,1 b10,2 ... b10,10


bi, j represent an integer (0 or 1) indicating whether the particle is passed through the phototube in the i-th row and j-th column of the device.

Example

Input

1
0 1 0 0 0 0 0 0 0 0
1 1 1 0 0 0 0 0 0 0
0 1 0 0 0 0 0 0 0 0
0 0 0 0 1 1 0 0 0 0
0 0 0 1 0 0 1 0 0 0
0 0 0 0 1 1 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 1 0
0 0 0 0 0 0 0 1 1 1
0 0 0 0 0 0 0 0 1 0


Output

0 0 0 0 0 0 0 0 0 0
0 1 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 1 1 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 1 0
0 0 0 0 0 0 0 0 0 0