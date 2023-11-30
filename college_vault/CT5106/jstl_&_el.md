# jstl and el
## jstl
tags used to simplify programming jsp
some of the core tags are as follows
- <c:out>
like <%-…%>
- <c:if>
used like a normal if
- <c:forEach>
used to loop over collections
- <c:url>
used to specify a url, like a href
- <c:set>
used to set the property of a [[java_beans|java bean]]
```html
<c:set var="salary" scope="session" value="${2000*2}"/>  
<c:out value=“${salary}”/>
```
this is generally avoided, as it breaks the mvc architecture

> to use these, you need to include this line in the header
> ```html
> <%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
> ```

## el
mainly used to access the properties of data classes (beans) which are attached as request or session attributes or whatever
the syntax is ${ expr }
```html
<p> your username is ${user.username} </p>
```
no need to specify context, it will search the page, request, session, and application in that order for the attribute

> #software_engineering #java 