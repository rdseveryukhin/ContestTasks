The company develops software for working with infinite arithmetic progressions. It is necessary to develop a data structure that will store arithmetic progressions and support the following operations:
1) The first type of operation allows you to add a new arithmetic progression to the structure.
2) The second type of operation allows you to remove a given arithmetic progression from the structure.
3) The third type of operation finds an arithmetic progression with the minimum first element and returns
found element, having previously replaced the starting element in the progression with the next one in it. If there are several such progressions, then the progression with the minimum identifier is processed.

Input format
The input is one positive integer (1 < q < 10^5) — the number of operations.
Next q lines are supplied as input in the following format:
If this is an operation of the first type, then the input is four numbers 1, a, d, id (0 <= | a | , | d | <= 10^9, 1 <= id <= 10^9) - the first element and the difference of the added progression, as well as its identifier.
If this is an operation of the second type, then two numbers 2 are supplied as input, id is the identifier of the progression that needs to be deleted.
If this is an operation of the third type, then one number 3 is given as input. At this moment, at least one progression will be in the structure.
It is guaranteed that all ids of arithmetic progressions are different. The progression to be removed is guaranteed to be in data structure.

Output Format
Print the answers to each query of the third type, one per line.
