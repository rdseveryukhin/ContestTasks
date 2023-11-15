Game on the tree

There is a tree of n vertices whose root is vertex 1. Two players play the following game. At the root of a tree
worth the chip. Players take turns, and on their turn the player must move a piece to one of the descendants
current vertex. Each leaf of the tree is a winner, a loser, or a neutral. If the chip is
on the sheet, the player who just moved it there ends the game with the result indicated on it
leaf.

If the piece is at distance k from the root and not on the sheet, the player can say “reverse” before moving it, - 
then all the results on the leaves will change to the opposite. Note that "reverse" may be said
no more than once per game.

How will the game end if both players act optimally?

Input format

The first line contains two numbers and k (2 <= n <= 5000, 0 <= k <= n) the number of vertices and the depth at which you can
do reverse.

The following is a string of n characters. The i-th character of this string is "+" if the i-th vertex is a leaf and
winning, "-" if the i-th vertex is a leaf and losing, "0" if the i-th vertex is a leaf and
neutral, and "." otherwise (the vertex is not a leaf).

Next, n - 1 lines are written, each containing two numbers u, u (1 <= u, v <= n) edges of the tree.

Output Format

Output First, Second or Draw, depending on who wins.

Example 1

Input: 

8 1

..-0..-+

1 2

2 3

2 4

1 5

5 6

6 7

6 8

Output: First

Example 2

Input:

8 1

..-0..0+

1 2

2 3

2 4

1 5

5 6

6 7

6 8

Output: Draw
