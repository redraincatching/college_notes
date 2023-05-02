# http cookies
- a small piece of data stored on the user's computer by the web browser while browsing a website
- designed to be a reliable mechanism for websites to remember information, or to record browser information
- authentication cookies (what account, if any, the user is logged into) are the most common

## cookie implementation
arbitrary pieces of data (e.g. large random strings), chosen and sent by the server, which are then included by the browser in any further requests
browsers are required to
- store cookies as large as 4096 bytes
- support at least 50 cookies per domain
- support at least 3000 cookies total

### example
the browser requests data for the homepage of www.example.org
```verbatim
	GET /index.html HTTP/1.1
	Host: example.org
	...
```

the server responds
```verbatim
	HTTP/1.0 200 OK
	Content-type: text/html
	Set-Cookie: theme=light
	Set-Cookie: sessionToken=abc123; Expires=Wed, 09 Jun 2021 10:18:14 GMT
	...
```

later client requests will contain these cookies
```verbatim
	GET /index.html HTTP/1.1
	Host: example.org
	Cookie: theme=light, sessionToken=abc123; Expires=Wed, 09 Jun 2021 10:18:14 GMT
	...
```

#### cookie structure
- name
- value
- zero or more attributes, which store data

## session cookies
- a.k.a. in-memory or transient cookies
- browsers normally delete these on closing
- these are defined due to having no expiration date

## persistent cookies
- expire at a specific time/date, or after a set period of time
- for the lifespan of the cookie, its information will be transmitted every time the user accesses the website
- these are sometimes referred to as "tracking" cookies

### session management via persistent cookies
![[session_cookies_1.png]]

---
## [[gdpr]] and cookies
generally, a user's permission must be sought before a cookie is installed on the browser
two exceptions
- communication exception
- strictly necessary exception

### communication exception
this applies to cookies whose sole purpose is for carrying out the transmission of a communication over a network, for example to identify the communication endpoints

e.g. load balancing cookies that distribute traffic between backend servers (session stickiness)

#### session stickiness
a load balancer creates an affinity between a given user and a specific server for the duration of that user's session
subsequently, all traffic from this user is routed to this server

![[session_stickiness.png]]

### strictly necessary exception
must be linked to a web-provided service
the service must have been ***explicitly requested*** by the user
advertising cookie are not strictly necessary

e.g. language preference, shopping cart

> both of these are exceptions because they're solely involved in allowing the service to be performed, and not storing user information

---

> #next_generation_technologies #cybersecurity 