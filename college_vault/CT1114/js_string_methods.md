# string methods
## .split()
-> splits a string into an array of substrings, made according to the given delimiter argument
_// note: the contents of a textarea are not html, so escape characters are required_

## .sort()
sorts an array
with no argument -> sorts alphabetically, even numbers
with an argument -> sorts using a custom function

## .sort(compare_function)
sending the function as an argument (no round brackets, it's not being executed)
this function is called whenever the sort function wants to compare two elements

compare_function is sent the two elements as arguments, and should return
- a negative number if unsorted
- a positive number if sorted
- a 0 if the numbers are equal

// in this case, compare_function is referred to as a "[[js_asynchronous_programming#callbacks|callback]]"
// less sending the function itself, more sending its location in memory, that's why it's sent with no brackets

> #javascript  #web_dev 