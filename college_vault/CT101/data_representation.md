# Data Representation
Computer systems store, present, and help us modify data such as text, audio, video and images.
Computing systems are finite, and so the amount of data they can store is finite.
&nbsp&nbsp&nbsp&nbsp→ can be represented in two ways: **analog** or **digital**.

**Analog:** Continuous representation, analogous to actual information
**Digital**: Discrete representation, data must be broken up into discrete pieces

Both signals undergo degradation over time, as the voltage of the signal fluctuates due to environmental effects. 
&nbsp&nbsp&nbsp&nbsp→ _"signal jitter"_

As soon as an analog signal degrades, information is irretrievably lost, as any voltage within the range is valid.
A digital signal can degrade, but since it only jumps between a high or low energy value, the information can be retrieved through a process called _"reclocking"._
&nbsp&nbsp&nbsp&nbsp→ the _signal integrity_ can be maintained

![[excalidraw_7.png]]

---

### ASCII & Unicode

American Standard Code for Information Interchange
- used only 1 byte of information, even then the last digit was unused or used for parity conservation
- 7-bit code → 2^7 unique codes, 128
- 95 **graphic** codes, 33 **control** codes
-> graphic to display characters on a console
-> control to control features of the console

Common control codes

-   CR - 0D - carriage return
-   LF - 0A - line feed
-   HT - 09 - horizontal tab
-   DEL - 7F - delete
-   NULL - 00 - null


**Escape Sequences**

Extend the capabilities of the ASCII set to control terminals
&nbsp&nbsp&nbsp&nbspescape code itself (ESC) is 1B, \[ is 5B
&nbsp&nbsp&nbsp&nbspe.g. ESC\[2J → erase display
&nbsp&nbsp&nbsp&nbspESC\[K → erase line


#### Unicode

Superset of ASCII, so first 128 characters (first 256 counting extended ascii) are the same
Uses 16 bits per character, so 2^16 (65,536) characters possible
&nbsp&nbsp&nbsp&nbsp// however, there are 17 "planes" of Unicode, so over a million characters can be stored
Current version is Unicode 14, released September 2021
&nbsp&nbsp&nbsp&nbsp→ added 838 new characters, current total now 144,697

---

### Audio Information Representation

Audio is percieved due to air compressions vibrating a membrane in the ear
A stereo sends an electrical signal to a speaker to produce sound
&nbsp&nbsp&nbsp&nbsp→ this wave is an analog representation of the sound

To digitise the signal, we "sample" thousands of times a second by periodically measuring the voltage. Usually 40,000 times a second is a high enough speed for a good aural representation.

![[excalidraw_8.png]]
Limitations of digital sampling

**Audio Formats**

.wav, .aiff, .vqf, .mp3

→ .mp3 is the dominant format for compressing audio. It does this by removing any frequencies that are imperceptible to the human ear
&nbsp&nbsp&nbsp&nbsp.mp3 is short for mpeg-2, audio layer 3

Compression formatshave 2 types, _lossy_ or _lossless._
-   Lossy → compression by removing inconsequential pieces of data
-   Lossless → keeps the ability to reproduce the original file in its entirety

---

#### Colour

→ perception of the various frequencies of light that reach the retinas of our eyes
→ 3 photoreceptor categories: red, green, blue
→ colour is stored as a 3-number value (RGB), each between 0 and 255 (1 byte each)

The amount of data used to represent a colour is the **colour depth**.

HiColour → 16-bit. 5 red, 5 blue, 6 green, as the human eye is more sensitive to green.
TrueColour → 24-bit depth, so a full 8 bits each.

These are usually stored as [[numbering_systems#^b1fcd8|hex codes]].

---

##### Digital Images and Graphics

Digitising a picture on a pixel-by-pixel basis uses what is known as the raster-graphics format.
no. of pixels = resolution

.bmp (bitmap), .jpeg, .gif are all raster-graphics formats

**Vector graphics**

Instead of assigning colours to pixels, a vector-graphics format describes an image in terms of lines and geometric shapes.

-   can be resized mathematically, allows for greater magnification
-   small file size, no need to account for every single pixel
-   not as good at real-world images

---

### Video
frame rate: number of still images (frames) recorded each second → fps
resolution: no. of pixels, expressed as horizontal x vertical
aspect ratio: ratio of width to height
video codec compressor/decompressor → methods used to reduce file size
&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbspalmost all use _lossy_ compression

2 types of video compression
-   Temporal compression → looks for differences between consecutive frames
-   Spatial compression → removes redundant information within a frame

→ Different layers of video transmission and storage alter this compression as well

---

### Text Compression

**Keyword encoding**
Frequently used words get replaced by a single character

**Run-length encoding**
If a single character is repeated many times, it can be replaced by a flag, followed by the repeated character, and how many times it has been repeated
&nbsp&nbsp&nbsp&nbspaaaaaeeee → _a5_e4

**Huffman encoding**
Use fewer bits to encode more commonly used characters
&nbsp&nbsp&nbsp&nbsp→ important characterisctic, no bit string is the prefix of another bit string
see also: [[compression#Huffman encoding|huffman encoding]]


>[[overview_of_systems]]
>#computing_systems 