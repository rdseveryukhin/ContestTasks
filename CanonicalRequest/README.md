Canonical query

The programmer needs to analyze which queries load SQL-Cepsep the most. Since requests
there is a lot in the log, you need to bring all SQL queries to canonical form so that you can group them
requests that differ only in the values of the call parameters.

The canonical form of a query is determined by the following rules:

1. The entire request must consist of one line in lowercase.

2. All consecutive whitespaces must be collapsed into a single space ' ' (without quotes),
in this case, after the opening parenthesis '(' (without quotes) and before the closing parenthesis ')' (without
quotes) there should not even be single spaces. All whitespace characters must also be removed from
end of the request.

3. All query parameter values must be replaced with the question mark character '?' (without quotes)

4. Everything that is inside the brackets of the in section (param1, param2 ... paramN) must be replaced with three dots
"..." without quotes.

For example, for the request:
SELECT
	id, name
FROM users
WHERE
	family = “Petrov” and
	(
	  group_id = "1" or manager_id in ( "17, "3", "8" , "92" )
	);

Canonical form will be:
select id, name from users where family = ? and (group_id = ? ог manager_id in (...));

Input format

The input receives n lines, 1 <= n <= 1000, containing the body of the request. Strings may contain characters with ASCII-
codes 32-127, as well as the tab character. The request body must contain at least one significant (non-whitespace)
symbol. The total length of all lines does not exceed 200,000 characters. All request parameters are specified in double
in quotation marks"

Output Format

Print a single line with the canonical form of the request

Example 1
Input

select id from tasks
where query_part
in ( ";" , " in ( ?, ? )",
"in" )
and task_owner = "Vasily";

Output
select id from tasks where query part in (...) and task_owner = ?;

Example 2
Input

select t.id
from topics t
inner join readers r
on r.t_id = t.id
where (
ifnull( t.ref, "n" ) = "a"
or t.name = "messages"
or t.name like "%'"
);

Output
select t.id from topics t inner join readers r on r.t_id = t.id where (ifnull(t.ref, ?) = ? or t.namе = ? or t.name like ?);

Note

It is guaranteed that only query parameter values can be enclosed in double quotes. Inside values
parameters specified in double quotes, there are no escaped double quotes, but single quotes
occur only in query parameter values (that is, only inside double quotes).

There must be whitespace characters before and immediately after the in operator.

Line breaks in the request body are counted as whitespace characters. If you read the request line by line
functions that trim the newline character, do not forget to add them before processing.
