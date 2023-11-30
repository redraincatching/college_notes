# programming paradigms
going to look at three languages
- c
most modern we'll be doing
procedural programming
- lisp
LISt Processing
just functions
one of the worst languages he's ever seen
functional programming
- prolog
programming en logique
french
slow but precise
logical/declarative programming

programming isn't about solving problems, it's about abstracting away from them

## a pattern or model of programming

various types of programming languages, some are better suited to specific problems than others
c is fast and precise, java is higher level but slower
python doesn't compile, so if a piece of code doesn't execute the code just isn't looked at

> often, compilers change syntax, so 2 + 3 would change into a tree with + as the root, and the operands as the leaf nodes

c used to be a multipass language, the compiler would read through the code three times before compiling
recursion was a bit fucky, for example, so early compilers needed to define it
now new compilers just need a function prototype

### syntax
refers to the rules of the language
allows us to form valid expressions and statements
tells you what form the language takes

### semantics
the meanings of those statements

programming languages can be classified according to features they have with respect to conceptual and implementation level
programming paradigms are, essentially, a collection of abstract features that categorise a group of languages

> "the poplarity of a paradigm is due to one community deciding which problems are important to solve, and then supporting the most promising paradigm for attacking those problems"
> - thomas kuhn

---

## influences on paradigms
- computer capabilities
vacuum tubes to transistors to integrated circuits to microcomputers ...
- applications
scientific, business, industrial, entertainment, communication applications
- programming methods
language designs have evolved to reflect changing understanding of good methods for writing large and complex programs
- implementation methods
early compilers to optimised compilers, structured engineering to software engineering, data abstraction to oo
handwritten assembly is slower than compiled c - why? 
-> optimisers
- theoretical studies
formal maths methods have deepened our understanding of strengths and weaknesses of language features and thus influenced the choice and inclusion of those features
- standardisation
has proved to be a strong conservative influence on the evolution of programming language design


> "there are two ways of constructing software design. one is to make it so simple that there are obviously no deficiencies. the other is to make it so complicated that there are no obvious deficiencies"
> - c.a.r. hoare

> "everyone knows that debugging is twice as hard as writing a program in the first place. so if you're as clever as you can be when you write it, how will you ever debug it?"
> – brian kernighan

> "a language that doesn't affect the way you think about programming isn't worth knowing"
> - alan perlis

---

## why is learning alternative paradigms useful?
- different paradigms make different tradeoffs
	- what's tricky in one can be almost trivial in another
	e.g. passing functions to other functions in c vs in lisp, or recursion in java vs haskell
- changing paradigms forces you to "change gear"
	- how to reverse an ordered list in java? c? scheme? prolog?
- it may become mainstream
	- oop was once an alternative paradigm
- alternative paradigms influence the mainstream
	- garbage collection came from functional programming
- will prepare you for learning languages you haven't heard of / that don't exist yet
- help you compare languages & find the best tool for the job
- help you understand languages more deeply

### why learn functional programming?
- one of the oldest paradigms (lisp: 1958, still widely used)
- heavily based on mathematical concepts (proofs, lambda calculations)
- elegant solutions (recursion)
- other paradigms can be interpreted in terms of functional programming

good at symbols, bad at numbers
logical structures and stuff

### why learn logical programming?
- long history
- allows implementation that are very difficult in other paradigms
- VERY different
- helps to conceptualise logical problems

// data and code aren't different, data is just code that doesn't do anything
// interpreted, not compiled, so very slow

### why learn imperative programming?
- earliest paradigm - as far back as punch cards and magnetic loops
// older, even, see jacquard 
- much closer representation of how the machine actually works
- can help to recognise some computational bottlenecks and optimisation issues
- contextualises other systems like unix, linux

### why learn oop?
- don't
- oop tries to represent real-world constraints
- uses abstraction and inheritance

---
## OOP

### fundamentals of oop
- everything is an object
- computation is performed by message passing
- every object is an instance of a class which is a grouping of similar objects
- inheritance describes the relationship between classes

oop focuses on the objects the code represents and the behaviours they exhibit

### 4 major principles of oop
- encapsulation
- abstraction
- inheritance
- polymorphism

#### encapsulation
data is hidden as if "encapsulated" within the object
- direct access to data is restricted
- we use methods to get, set, and manipulate that data
object callers don't need to know what's going on behind the scenes

#### abstraction
functionality can be defined without being implemented
- high-level interfaces provide methods types/names without implementation
- allow case-specific implementation
- allows one programmer to define functionality, and another to implement
- allows representation to be changed without affecting the "public" view of a class
helpful when designing large systems, if i can write an interface for a function and be sure that it will return a String, i can keep writing my code and not worry about implementing it right now

#### inheritance
- code can inherit functionality without re-implementing
- prevents code duplication
- encourages well-structured codebase

#### polymorphism
poly, meaning many
morphism, meaning shape

objects of one class can be treated as others
an object of type \<Bike\> can be cycled
an object of type \<RacingBike\> can also be cycled
two \<Number\>s, say an int and a float, can be added and subtracted as if they were the same type

---
## imperative programming
e.g. assembly (also fortran and sometimes basic)
- list of instructions
- GOTO statements
- little or no structure

telling the computer to perform a set of actions, one after the other
most programming languages have imperative aspects

// moves through statements one after another

---

## procedural programming
e.g. c, pascal, ada (also fortran and basic, sometimes)
// ada is like multi-threading pascal
- code is structured
- uses functions, or procedures
// procedural functions are distinct from functional programming
- encourages code re-use
- encourages encapsulation and composition

splits actions into procedures or tasks
procedures can be made up of other procedures (composition, recursion...)

// "has functions"

---
## structured programming
basically everything but assembly

- code is structured
- while, for, if, else, switch, class, function, etc.
- less emphasis on GOTO
- creating a structure to manage instructions
- allows more complex programs to be built
- easier to understand
- avoids GOTO bugs and spaghetti code


> #paradigms
