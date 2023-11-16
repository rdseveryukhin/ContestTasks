Scheduler

There are n workers, numbered from 1 to m, and k task queues, numbered from 1 to k.
Initially the queues are empty. The system has n tasks to complete: the i-th task will be queued with number qi on the si-th
second and will require ti seconds to execute.

Every second the following happens:

- New tasks may be added to the end of some queues (but no more than one task per queue)

- While this is possible, the idle executor with the lowest number and a non-empty queue is selected, from which
Tasks took the longest time to get picked up. If there are several such queues, then the queue with the lowest number is selected.
The executor takes the task from the queue and becomes busy for the duration of its execution.

For each task, determine when and which performer will begin performing it.

Input format

The first line contains the numbers n, m, k (1 <= n,m,k <= 2 * 10^5).

Each i-th of the next n lines contains 3 numbers: si, qi and ti (1 <= si,ti <= 10^9; 1 <= qi <= k) - time in seconds
placing the i-th task in the queue, the queue number and the time in seconds required to complete the task, respectively.

It is guaranteed that si <= sj for < i < j.

Output Format

For each task in the order they appear in the input data, print 2 numbers: the number of the performer and the time in: seconds,
when it picks up this task from its queue. That is, in total you need to output 2n numbers

Example 1

Input:

5 1 2

1 1 5

1 2 3

2 2 1

3 1 2

4 1 3

Output:

1 1

1 6 

1 11

1 9

1 12

Example 2

Input:

5 2 2

1 1 5

1 2 3

2 2 1

3 1 2

4 1 3

Output:

1 1

2 1

1 6

2 4

2 6
