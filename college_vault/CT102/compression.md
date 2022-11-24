# Compression
reducing the space a file occupies
specifically: encoding information using fewer bits than the original representation

**why?**
- to save space when storing
- to save time/bandwidth when transmitting

**how?**
most techniques are based on the fact that most files have redundancy

**two components**
- _encoding_
- _decoding_

![[encoding_decoding.png]]

**goal:**
- the encoded message has fewer bits than the original
- the decoded message is approximately the same

**downsides**
to be used, the message must undergo the opposite process of decompression
example of _space-time complexity tradeoff_ in computing

**high level categorisation of compression algorithms**
- lossy
- lossless
- hybrid

---
## Huffman encoding
_lossless_ data compression technique
produces optimal data prefix codes which are generated from a set of probabilities based on frequency of occurrence

guarantees _prefix property_ - no code is a prefix of another code
used as backend of gzip, jpeg, etc
    
if good letter probabilities are available and not too costly to obtain, huffman is good, and can obtain an average of _2.23 bits per symbol_

#### obtaining letter probabilities
- can use generic ones derived from english language domain
- can use actual frequencies found in text (requires a frequency table to be stored with message)

### prefix code representation
the "trick" with huffman encoding is to represent the prefix codes using a binary tree where:
- each symbol is a leaf node
- the code for each symbol is given by following a path from root to leaf, and appending (by convention) a 0 when left-hand branch is taken, and a 1 when right-hand branch is taken

> ![[binary_tree.png]]
> **binary tree**
> definition:
> consists of a set of non-linear nodes such that there is
> - one distinct root node
> - all other nodes are arranged such that each parent node has at most two child nodes

**code trees (weighted binary trees)**
each leaf node represents a symbol
each branch has a binary weight
// lhb are 0, rhb are 1

### Huffman compression algorithm
_input_: symbols and their frequencies
1) create a trivial tree (node) for each letter
2) assign a weight to each node (initially its frequncy)
3) order trees by weight (priority queue), smallest to largest
4) decide on rule for ties - will not affect code length but must be consistent for encoding and decoding stages
-> if there is a tie for single-node trees, order alphabetically
-> if otherwise, order by tree size
5)
```pseudocode
while (len_queue > 0) {
    merge the two trees at the top of the priority queue (those with the smallest weights) to create a new tree such that:
        - root of tree has, as its weight, the summation of the weight of the sub-trees
        - tree at the top of the queue is a left sub-child of the root, the next tree is a right sub-child
    re-sort new tree in queue
}
```
6) label edges of final tree
_output_: huffman code tree for all input symbols

example:
TODO: scan that diagram

### huffman decompression algorithm
_input_: symbols, their frequencies, sequence of binary codes
1) build huffman tree exactly the same as compression
2) for each encoded sequence, follow tree to a leaf node
_output_: original message

---
## Arithmetic Encoding
encodes a stream of symbols (rather than a single symbol) as a floating point in the range \[0,1)
text, so must be lossless

##### General approach
_input_:
message, symbols, their frequencies
_general steps_:
work with intervals and sub-intervals where each interval represents a proportion relative to the probability of the occurrence of the message
_output_:
real number in range \[0,1)

### encoding algorithm
- begin with interval \[0, 1)
- get all symbols and probabilities of occurrence
- order symbols (smallest first, alphabetically if equal)
- place ordered symbols in queue
- while symbols left in queue{
	- for current interval, divide the interval according to the probabilities of all symbols occurring, and the order of these, starting at the lowest range of interval
	- let current interval = symbol at top of queue
	- find in which interval current message symbol lies, this becomes the new interval, divide as before
	- get next symbol
 }

_note_: size of interval is limited by computer's capability, can only go so small

#### Example
_inputs_:
- symbols are: a c r
- probabilities are: p(r) = 0.2, p(a) = 0.4, p(c) = 0.4
- message = car

_approach_:
order symbols according to probabilities first, alphabetically second:
-> r a c

_first iteration of loop_:
- assign each symbol to the an interval in range:
	- r -> \[0.0, 0.2)
    - a-> \[0.2, 0.6)
    - c-> \[0.6, 1.0)
- first symbol of message is c, so new interval is \[0.6, 1.0)
![[arithmetic_encoding_1.png]]

we take the current symbol (c) and use that interval in the next step
![[arithmetic_encoding_2.png]]
![[arithmetic_encoding_3.png]]
therefore, the interval with "car" is \[0.68,0.712)

// note: the length of the message then has to be specified
// fixed length message units can be used to keep this low

in reality, rather than transmitting the full interval, we just send a real number (binary representation)

##### Practical concerns
the longer the text stream (sequences/message) encode the more precise the interval to encode it becomes but machines have finite precision
fixed length message units help with this

### decoding algorithm
_input_: binary number and symbol length
(assuming symbols, their order and frequencies known)

_general approach_:
get real number, follow the same approach as for encoding, but at each stage consider next current digit to find correct interval
stop when at sub-interval of the correct length

_output_:
symbols from message

> #algorithms 