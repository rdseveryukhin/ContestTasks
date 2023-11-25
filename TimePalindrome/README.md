Time-palindrome

In electronic watches, the time is displayed on the display in the format NN:MM, the palindrome time is set 16 times per day.
Remember that a palindrome is a string that reads the same from left to right as from right to left.
Namely, at the times 00:00, 01:10, 02:20, 03:30, 04:40, 05:50, 10:01, 11:11, 12:21, 13:31, 14:41. 15:51, 20:02, 21:12, 22:22 and 23:32.

How many palindromes in hours can be calculated if the day did not have 24 hours a day, and one hour did not have 60 minutes per hour.

You need to determine by the number of hours in a day n and the number of minutes in an hour m (1 <= n,m < 10^5) how many times
per day, the clock display will show the palindromic time. The number of digits in the table to the left and right of the two dots are the same and
equal to the maximum of the lengths of the numbers (n - 1) and (m - 1) - the maximum measurements for hours and minutes. Just like a regular watch,
empty cells are assigned zeros.

For example, if n = 12, m = 1234, then the table accepts values from 0000:0000 to 0011:1233. Such a clock would output 4 palindromes per day: 0000:0000, 0001:1000, 0010:0100, 0011:1100.

Input format

The first and analytical line of the input data contains two integers n and m - the number of hours in
days and the number of minutes per hour, respectively. Restrictions: 1 <= n, m < 10^5. Both numbers are shown without leading zeros.

Output Format

You enter one number - the number of times per day when the clock display shows the palindromic time.

Example 1

Input: 24 60

Output: 16

Example 2

Input: 12 1234

Output: 4
