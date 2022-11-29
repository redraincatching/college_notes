# working with strings and pattern matching

%
0 or more characters
_
exactly one character

// note: %a% means "has a in it"
// both of these use the keyword LIKE

can use regular expressions for more complicated string matching
^   - matches position at the beginning of a string
$   - matches the end of the string
\[\]  - matches anything inside the brackets
\[^\] - matches anything not in the brackets
\*   - preceeding character 0 or more times
\+   - preceeding character 1 or more times
|   - or
{n} - matches preceeding character n times

// note: this uses the keyword REGEXP

> #databases #sql