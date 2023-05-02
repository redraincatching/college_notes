# social engineering
###### cybersecurity - cisco definition
cybersecurity is the practice of protecting systems, networks, and programs from digital attacks. these cyberattacks are usually aimed at accessing, changing, or destroying sensitive information; extorting money from users; or interrupting normal business processes

> "don't get caught"
> - dr. michael schukat, 2022

###### social engineering - definition
social engineering is the term used for a broad range of malicious activities accomplished through human interactions. it uses psychological manipulation to trick users into making security mistakes or giving away sensitive information

---
###### hackers
- black hat
malicious or destructive actors
- white hats
professional defense actors, employed for security purposes
- grey hats
bitta both ig
- suicide hackers
hackers who act with no regard to consequences, often terrorists/activists wishing to make a statement for a cause
---
## human security
"if you design something idiot-proof, the universe will design a better idiot"

### password
a memorised secret used to confirm the identity of the user
a purely numeric secret is a personal identification number
the secret is memorised by a party called the claimant, while the verifying party is the verifier
they communicate using an authentication protocol
see also: [[bits_of_entropy]]

#### alternatives to passwords
- one-time passwords, possibly time-sensitive (otps)
- biometric methods
- cognitive passwords (question and answer)

online banking uses a list of transaction authentication numbers (**tan**s), which can only be used once

##### algorithmic generation of otps
paper-based tans are hard to manage, as are black and tans
otps can be generated from past otps used
an example credited to leslie lamport uses a one-way (hash) function

## one-way functions
a one-way function H produces a fixed-size output h based on a variable input size s
$H(s) = h$
H is a hash function, h is the hash
for a given hash code h it is infeasible to find s such that H(s) = h

### lamport's algorithm
for every claimant a random seed s is chosen
a hash function is repeatedly applied, n times, to the seed, giving a value of $H^n(s)$, which is stored by the verifier
the claimant keeps the seed s

the user's first login uses an otp derived by applying H n-1 times, or $H^{(n-1)}(s)$
the verifier can authenticate this as $H(p) = H^n(s)$
the value stored is replaced by p

the next login is accompanied by the otp $H^{(n-2)}(s)$, and this is verified as $H(p_2) = p$

// this continues as necessary

### time synchronised otp
each user has a specific piece of hardware called a security token which generates an otp
inside the token is a clock, synchronised with the verifier
both the claimant token and verifier calculate identical otps using the time as a seed
![[time-synchronised_otp.png]]
![[accurate_token_clock.png]]
// these are really difficult to build and synchronise
// fuck physics, man

---
## biometric methods
- hand geometry
	measurement and comparison of the (unique) different physical characteristics of the hand
- palm vein authentication
	uses an infrared beam to penetrate the users hand as it is waved over the system;the veins within the palm of the user are returned as black lines
- retina scan
	provides an analysis of the capillary blood vessels located in the back of the eye
- iris scan
	provides an analysis of the rings, furrows and freckles in the colored ring that surrounds the pupil of the eye
- face recognition, signature and voice analysis

however, cyberpunk

### behavioural biometrics
![[behavioural_biometrics.png]]

---
## multi-factor authentication
usually some combination of the following
- physical object
- secret
- physical characteristic
- geolocation

2013, a google study concluded most people's passwords are generated from readily available information
1) pet names
2) a notable date, such as a wedding anniversary
3) a family member’s birthday
4) your child’s name
5) another family member’s name
6) your birthplace
7) a favourite holiday
8) something related to your favourite sports team
9) the name of a significant other

---

## social engineering
![[social_engineering.png]]
the use of deception to manipulate individuals into divulging confidential or personal information that may be used for fraudulent purposes

### phishing
involves sending malicious emails from supposed trusted sources to as many people as possible
### spear phishing
user is disgised as a trusted individual
### whaling
phishing targeting one specific high-level target, e.g. a CEO

### smishing
sms phishing, usually a link to a trojan
### vishing
voip phishing
sir DO NOT REDEEM
- https://www.youtube.com/watch?v=BEHl2lAuWCk
- https://www.youtube.com/watch?v=PWVN3Rq4gzw

### pretexting
presenting oneself as someone else in order to obtain private information
it is more than just creating a lie, in some cases it can be creating a whole new identity to manipulate the receipt of information

### quid pro quo
promises a service or benefit based on the execution of a certain action
"greetings, i am the crown prince of nigeria..."

### watering hole
injecting malicious code into public web pages of a site that the target visits
typically the site is decided based on the specific group that the attacker wishes to target, e.g. blackboard for students

### pharming
redirect to popular site and farming data entered or session cookies

#### pharming via dns poisoning/spoofing
![[pharming_0.png]]
also includes domain spoofing

### baiting
attacks that exploit human curiosity
e.g. usb drop attacks -> https://www.redteamsecure.com/blog-usb-drop-attacks-the-danger-of-lost-and-found-thumb-drives
leaving infected usb drives out in the open and waiting for people to 

### tailgaiting
attacker seeking physical entry to a restricted area without proper authentication


> #next_generation_technologies #cybersecurity 