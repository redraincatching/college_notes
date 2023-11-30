# introduction to jakarta and java

## what is java ee?
the java platform, enterprise edition builds on the java se platform and provides a set of technologies for developing and running portable, robust, scalable, reliable, and secure server-side applications
so not just web logic, but also business logic, object persistence, messaging, security...
client-server model, in particular we'll look at mvc applications - model-view controller

java ee is a set of interoperable api specifications
was known as jee and then j2ee, now jakarta ee
-> java ee 8 became jakarta 8
-> was handed off from oracle to the eclipse foundation

### important specifications
- web specs
	- [[servlets|servlet]]
		basic entity, defines how you can manage http requests in a synchronous or asynchronous way
	- websocket
		provides a set of apis to facilitate connections
	- [[jsf|java server faces]]
		helps building guis from components
		superseded by frameworks a little now
	- [[jstl_&_el|unified expression language]]
		simple language made to facilitate web app devs
- web service specs
	- api for restful services
	- api for json processing
	- api for json binding
	- api for xml binding
- enterprise specs
	- contexts and dependency injection
	- enterprise javabean
		apis to provide transactions, remote procedure calls, and concurrency control
	- persistence api
		relational mapping
	- transaction api
		contains interfaces and annotations to establish interaction between transactions
	- java message service
		provides a common way to creaate, send, and read messages
- other specs
	- validation
	- batch applications
		provides the means to run long-running background tasks which involve a large volume of data and need to be periodically executed
	- java ee connector architecture
		connects servers to enterprise information systems

---
## application servers
hosts your jee application, running the components you develop within containers, which provide the interfaces to manage them

lots of commercial and open source application servers
each has their own versions, which support their own versions of the jee spec, though not always all of it
e.g. apache tomcat supports servlets and jsp, the basic web components, but to use back-end business logic you'd need tomEE

we used payara, ~~which is probably as out of date as the rest of this fucking module~~

---
## java ee application
in a jee app we have
- the model
	business-layer functionality represented by javabeans or ejbs
- the view
	the presentation layer functionality represented by jsps or jsfs in a web app
- the controller
	servlet mediating between the model and the view
must accomodate input from various input, such as http requests from web clients

### ejb - enterprise java bean
- server-side components that encapsulate business logic
- transactions and security
- sits on top of persistence layer as an entry point for presentation-tier technologies
- can be built by annotating a pojo that will be deployed into a container
	- (pojo: plain old java object)

#### types of ejb
- session beans and message-driven beans
	- session beans are used to encapsulate high-level business logic and can be
		- stateful: 
		the values of instance variables are maintained across multiple method calls.
		because the client interacts with this bean, it's often called the conversational state of a bean
		- stateless:
		contains no conversational invocations, so any instance can be used for any client
		- singleton:
		a single bean shared between clients that supports concurrent access
see: [[ejb]]
---
 ## packaging a jee web app
a webapp module contains
	- servlets, jsps, jsfs, ejbs, and web services
	- html and xhtml pages, css, javascript, images, videos, etc.

all of these packaged into a java archive (.jar) file, with the .war (web archive) file

### mvc - typical example
using the controller servlet to act as a router / dispatcher for incoming http requests
- session bean acts as a façade hiding the complexity of the jpa interface, while the jpa api does the object mapping for us

#### can start small
pretty easy to build a robust webapp just using servlets, java server pages, and sql
(editor's note: this is blatantly untrue)




> #software_engineering #java 