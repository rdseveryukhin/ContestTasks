Experienced team

It is important for every team leader to monitor the experience of his team. Namely, to single out the most experienced member of your
team and understand how his experience compares with the experience of the rest of his team

A team is a living organism; its composition is constantly changing. Sometimes new engineers join it, sometimes
someone is leaving. It happens that someone returns to the team after leaving and even does this several times.

Given a list of pairs <name, moment in time", ordered in non-decreasing order of time and describing the events
happening to the team. Initially, the team composition is empty. If the command does not currently contain
engineer with that name, the event means that he joins the team at a given point in time. Otherwise,
that on the contrary he is leaving the team

Experience is the total amount of time a particular engineer has spent on the team. More formally,
experience is the sum of the differences between the current moment (or the moment of departure) and the corresponding moment
joining the team for all periods of the engineer’s work in the team.

After processing each event, it is necessary to determine the most experienced member of the team and how much total
the experience of the rest of the team (that is, everyone except the most experienced) is greater than the experience of the most experienced member
teams

Input format

The first line contains a single number N (1 <= M <= 300,000) - the number of events
Next, in each of the N lines, two parameters S and T are given, separated by a space.

S - team member's name (consists of lowercase and uppercase Latin letters, 1 <= |S| <= 10)
T-point in time (1 <= T <= 1,000,000,000)

All events are ordered in non-decreasing order of time. In other words, it is guaranteed that for any i < j
Ti <= Tj

All events are unique. In other words, for any i != j it is true that either Si != Sj or Ti != Тj

It is also guaranteed that after each event the team consists of at least one person.

Output Format

It is necessary to output N lines - one after processing each of the events

Each line should consist of two values - the name of the most experienced team member and the difference between the total
the experience of other team members and the experience of the most experienced team member

If there are several team members with maximum experience, you need to display the one whose name is lexicographically
minimally

Attention! Given the limitations, the volume of output data can be quite large. Keep this in mind and
take care of output efficiency

Example

Input:

9

Ivan 1

Anton 1

Victor 2

Anton 3

Ivan 5

Denis 10

Victor 11

Anton 11

Ivan 12

Output:

Ivan 0

Anton 0

Anton 0

Ivan -1

Victor -3

Victor -8

Denis - 1

Anton -1

Ivan 1
