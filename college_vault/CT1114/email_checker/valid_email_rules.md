/\*  
4 parts to email:
- recipient name
- @ symbol
- domain name
- top-level domain

name:
- max 64 characters
- can consist of
	- a-z, A-Z
	- 0-9
	- special characters !#$%&'*+-/=?^_`{|}~
	- dot (.) provided that is not the first or last character, or consecutive (unless quoted)

note: if quoted the local part of the email can contain spaces, hzl tab, any ascii graphic except backslash, quote, and a quoted pair consisting of backslash followed by hzl tab, space, or any ascii graphic

can also have a comment in parentheses, as long as it is the start or end of the name

domain:
may consist of
- letters
- digits, provided that the top-level domain name is not all numeric
- a hyphen (provided that it is not at the end)

this is known as the ldh rule (letters, digits, hyphen)
the domain can also be an ip literal, as long as it is enclosed in square brackets []
\*/

#email_checker 