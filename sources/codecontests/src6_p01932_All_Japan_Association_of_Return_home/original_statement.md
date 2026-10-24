problem

AOR Co., Ltd. (Association Of Return home) has $ N $ employees.

Employee $ i $ wants to use the elevator to go down to the $ 1 $ floor and arrives in front of the elevator on the $ F_i $ floor at time $ t_i $. You decide to remotely control an elevator that has only $ 1 $ on the $ 1 $ floor at time $ 0 $ and send all employees to the $ 1 $ floor. The elevator can only carry up to $ D $ people. Elevators can move upstairs or stay in place per unit time. Employee $ i $ only takes the elevator if the elevator is on the $ F_i $ floor at time $ t_i $ and does not exceed capacity. When I can't get on the elevator at time $ t_i $, I'm on the stairs to the $ 1 $ floor. The time it takes to get on and off can be ignored.

Find the minimum total time each employee is in the elevator. However, if there are even $ 1 $ people who cannot take the elevator to the $ 1 $ floor, output $ -1 $.



output

Output the minimum total time each employee is in the elevator. However, if there are even $ 1 $ people who cannot take the elevator to the $ 1 $ floor, output $ -1 $. Also, output a line break at the end.

Example

Input

2 2
2 2
3 3


Output

5