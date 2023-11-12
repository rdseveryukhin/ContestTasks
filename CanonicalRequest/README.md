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

For example, for the request
