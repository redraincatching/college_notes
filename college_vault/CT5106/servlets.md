# servlets
![[servlets_0.png]]
// servlets need to be placed in a name package on creation
// servlets can have multiple paths, e.g. /login and /register would call the same servlet

## typical process in a servlet
regardless of the application, servlets usually carry out the folloeing routine
- read any data sent by the user
	- capture data sent by a html form
- look up http information
	- determine browser version, host name of client, etc.
- process the data and generate results
- format the results
	- generate html on the fly
- set appropriate http headers
- send document back to client

first time you run a servlet, it takes longer than any other
-> it has to be compiled first

## servlet life cycle
![[servlets_1.png]]
- load servlet class
- create instance of servlet
- call init()
- call service()
// each other step is only called once, whereas this one is called as many times as necessary
- destroy()

## useful servlet interfaces
- HttpSession
allows state to be stored across multiple user requests
- Cookie
a cookie
- ServletContext
methods to communicate with the servlet container
- Filter
provide means to intercept and pre- or post-process requests and responses

--- 

## basics

servlets typically extend HttpServlet and override doGet or doPost
these can also be used to call each other, if you want behaviour to be uniform
in netbeans, this is done for us, and both methods are sent to processRequest by default

### the HttpRequest object
- request uri
- parameters
- attributes
- session
- headers, request body via getInputStream(), ...

### using query strings to send parameters
for GET requests, these are in the URI after ?
e.g.
```html
form.asp?name=value&name2=value2
```
for POST requests, they go in the body of the html request

these can be seen by right-clicking in the servlet code, and used in the code with request.getParameter("name")

can also find out each parameter's name with getParameterNames, which can then be looped through

parameters are always strings at first, and so have to be parsed

---
## servlet mapping
the urlPattern annotation is used to declare what url patterns a servlet will respond to
they can also be used to route html request as follows:
```java
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

@WebServlet(name = "MyRouterServlet", urlPatterns = {"/app/*"})
public class MyRouterServlet extends HttpServlet {

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws IOException {
        // Extract the path after the servlet mapping
        String pathInfo = request.getPathInfo();

        // Determine the target HTML page based on the pathInfo
        String targetPage;
        if (pathInfo.equals("/home")) {
            targetPage = "/pages/home.html";
        } else if (pathInfo.equals("/about")) {
            targetPage = "/pages/about.html";
        } else {
            targetPage = "/pages/notfound.html";
        }

        // Perform the redirection
        response.sendRedirect(request.getContextPath() + targetPage);
    }
}

```
the pathInfo is obtained from the request, and the user is redirected to another html page based on that

---

#### sending a request from a form
```html
<body>
	<h1> login </h1>
	<form action="LoginServlet" method="post">
		<fieldset>
			<label for="username"> username </label>
			<input type="text" name="username">
			<label for="password"> password </label>
			<input type="text" name="password">
			<input type="submit" value="Submit">
		</fieldset>
	</form>
</body>
```
does this:
<body>
	<h1> login </h1>
	<form action="LoginServlet" method="post">
		<fieldset>
			<label for="username"> username </label>
			<input type="text" name="username">
			<label for="password"> password </label>
			<input type="password" name="password">
			<input type="submit" value="Submit">
		</fieldset>
	</form>
</body>

---
## servlets that generate html
most servlets generate html, ~~because they were invented before nodejs~~
to generate html, you add two steps to the normal process
- tell the browser you're sending it html
this can be done by setting the http content-type response header to text/html
the way to designate html is like this
```html
response.setContentType("text/html");
```
- modify the println statements to build a legal webpage
![[Pasted image 20231128134552.png]]
// this is the actual slide i swear to god i am not joking

> #java #software_engineering 