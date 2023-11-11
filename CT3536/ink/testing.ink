this is writing
this is writing on a different paragraph

// c-like comments

this is whatever # but it is tagged, which isn't normal text

// choices

hello!
*   hello back!
    nice to see you today
*   [title for response]
    i'm responding to you!

    // can also mix and match like this
"how are you?" he asked
*   "tired[."], it's been a long day"

// before brackets shows in choices and output
// brackets only show in choices
// after only shows in output

=== knots ===
knots are delimited by two or more equals signs at the start
    // the 
the start is a header, what follows is the contents
the name of a know must be a single word, no spaces

when using knots, we need to end the flow with
-> END

=== diverts ===
-> like_this

=== like_this ===
diverts tell the flow which knot to move to next
diverts are invisible in output, and can even happen mid-sentence

note: by default, each new line produces a newline, but you may want to separate lines for readability
can do this by appending <> to a line (called "glue")

=== go_home ===
so we went -> home

=== go_home_glue ===
so we went <>
-> home

=== home ===
home as soon as we could

// these both produce the same output:
    // so we went home as soon as we could



=== branching_and_joining_example ===

=== back_in_london ===

We arrived into London at 9.45pm exactly.

*	"There is not a moment to lose!"[] I declared.
	-> hurry_outside

*	"Monsieur, let us savour this moment!"[] I declared.
	My master clouted me firmly around the head and dragged me out of the door.
	-> dragged_outside

*	[We hurried home] -> hurry_outside


=== hurry_outside ===
We hurried home to Savile Row -> as_fast_as_we_could


=== dragged_outside ===
He insisted that we hurried home to Savile Row
-> as_fast_as_we_could


=== as_fast_as_we_could ===
<> as fast as we could.


the story flow is flat, there's no callstack, and 


=== includes_and_stitches ===
knots can have sub-knots

= stitch_one
...

= stitch_two
...

these are all marked with a single equals sign

could be used so that a knot is a single scene, and stitches are points in the scene, for example

diverting to a stitch is done with its address (outside the knot)
-> includes_and_stitches.stitch_one

inside the knot, you can just divert to it with its name, as if it were a knot
    // this means stitches and knots can't share names, but multiple knots can share a stitch name

if you divert to a knot that has stitches (with no content before them) you automatically enter the first stitch
otherwise, you WILL NEED TO DIVERT OUT OF THAT CONTENT

you can split content across multiple files using
INCLUDE name.ink
INCLUDE file/othername.ink

separating files has no effect on namespacing


=== choices_and_loops ===
by default, choices can only be used once
you can have a fallback choice, denoted
*   -> wherever
which is "chosen" by the game if no other options exist
*   ->
    there can be content in that default like this -> go_elsewhere
+ choices can be made sitcky like this


=== conditional_choices ===
ink has a lot of logic, but the simplest is jsut "has a player seen this content?"
*	{ not visit_paris } 	[go to paris] -> visit_paris
+ 	{ visit_paris 	 } 		[return to paris] -> visit_paris

*	{ visit_paris.met_estelle } [ telephone mme estelle ] -> phone_estelle

can have multiple conditions
{one} {not two} [Do This] -> this


can also use logical operators and brackets, written
* and, or, not
* &&, ||, !

// using not over ! is recommended because the compiler may think {!text} is a once-only list

= labels_are_read_counts 
the test
*	{seen_clue} [accuse mr jefferson]
is actually testing an integer, not a boolean
therefore, we can also do this
* {seen_clue > 3} [flat-out arrest mr jefferson]

there's more logic, so i'll put all that in another file

=== variable_text ===
alternatives are selected from depending on some kind of rule, and are denoted with {}
each element is separated by |
= sequences
