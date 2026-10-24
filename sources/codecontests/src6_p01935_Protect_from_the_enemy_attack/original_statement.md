problem

There are $ V $ islands, numbered $ 0, 1, ..., V-1 $, respectively. There are $ E $ bridges, numbered $ 0, 1, ..., E-1 $, respectively. The $ i $ th bridge spans island $ s_i $ and island $ t_i $ and is $ c_i $ wide.

The AOR Ika-chan Corps (commonly known as the Squid Corps), which has a base on the island $ 0 $, is small in scale, so it is always being killed by the Sosu-Usa Corps (commonly known as the Sosuusa Corps) on the island $ V-1 $. .. One day, the squid group got the information that "the Sosusa group will attack tomorrow." A large number of Sosusa's subordinates move across the island from the Sosusa's base, and if even one of their subordinates reaches the Squid's base, the Squid will perish ...

Therefore, the squid group tried to avoid the crisis by putting a road closure tape on the bridge to prevent it from passing through. The length of the tape used is the sum of the widths of the closed bridges. Also, if all the subordinates of the Sosusa group always pass through a bridge with a width of $ 1 $, the squid group can ambush there to prevent them from passing through the Sosusa group.

The length of the tape it holds is $ 10 ^ 4 $. Considering the future, I would like to consume as little tape as possible. Find the minimum length of tape used to keep Sosusa's subordinates from reaching the squid's base. However, if the tape is not long enough and you are attacked by all means, output $ -1 $.



output

Output the minimum length of tape used to prevent Sosusa's subordinates from reaching the Squid's base. However, if the tape is not long enough and you are attacked by all means, output $ -1 $. Also, output a line break at the end.

Example

Input

4 4
0 1 3
0 2 4
1 3 1
2 3 5


Output

4