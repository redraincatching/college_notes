# enterprise java beans
the components that carry out the business logic/processes
use interface to make that functionality availbale to clients ([[mvc]])

three kinds
- session beans
- entity beans
- message-driven beans

![[Pasted image 20231129123707.png]]

## session beans
business logic invoked by client
lifecycle / state managed by ejb container
- stateless
    - shared by multiple clients
    - the container can pool them to provide to clients
- stateful
    - client-specific instances
- singleton
    - one instance per application

shocking no one, this is usually handled via annotations

## entity beans
data, see [[java_beans]] for more

## message-driven beans
allow asynchronous message processing
usually a jms listener, mapped to a jms queue

event-driven
- when a message arrives, the container calls the onMessage method to process it

---

## mvc architecture with session beans
the entity and session beans act as a façade to hide the details of the [[jpa]]


![[Pasted image 20231129124522.png]]

### java ee containers
the entity classes are managed by the persistence provider
the session beans are managed by the ejb container
views are rendered in jsps, which are managed by the web container


![[Pasted image 20231129124757.png]]

### entity manager
see [[jpa#jpa entity manager|entity manager]] for more information


---
## implementing a façade 
- avoids tight coupling between clients and business objects
- cuts down on calls between client and server
- abstracts underlying interactions
- uses the container to manage the lifecycle

> netbeans generates session beans
> code common to all classes is factored out into AbstractFacade
> the AbstractFacade class provides a few basic jps methods to find related entities
> this uses the CriteriaQuery api, but honestly don't even worry about it
> i hate netbeans with a burning passion

> #software_engineering #java
