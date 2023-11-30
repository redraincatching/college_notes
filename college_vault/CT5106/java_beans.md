# java beans
data classes used in java web dev
usually have a request and response handler but can just throw both of these to processRequest like so

```java
protected void processRequest(HttpServletRequest request, HttpServletResponse response)  
throws ServletException, IOException {  
	String username = request.getParameter("username");  
	String password = request.getParameter("password");  
	String email = request.getParameter("email");  
	User u1 = new User (username, password, email);  
	request.setAttribute("user", u1);  
	RequestDispatcher dispatcher = request.getRequestDispatcher("userCreated.jsp");  
	dispatcher.forward(request, response);  
}  
```

because this entire architecture is archaic and stupid, beans need specific getters and setters to function (but they won't error because fuck you)
the pattern is 
field -> getField, setField

> #java #software_engineering 
