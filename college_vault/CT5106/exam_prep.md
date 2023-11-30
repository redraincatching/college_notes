# 3rd year exam prep

## 1.a _Explain using an example the purpose of the urlPatterns annotation as found in servlets, and how they can be used in servlets to turn them into routers for HTTP requests._

urlPatterns is used to specify the url patterns a servlet should respond to, for example this annotation would tell the servlet to respond to the patterns ending in "/login" and "/register"
```java
@WebServlet(name = "myServlet", urlPatterns = {"/login", "/register"})
public class myServlet extends HttpServlet {
    // ...
```

given that a servlet can respond to multiple paths, then, it can perform any amount of actions based on what that path is, for example, the servlet could send the client to a different html page based on the input, something along these lines
```java
@Override
protected void doGet(req, res) {
    String pathInfo = req.getPathInfo();
    if (pathInfo.equals("something") {
        // send to the appropriate page, and continue with however many if/else branches you want
    }
}
```

## 1.b _Explain the difference in scope between the request, session, and application, in JSP/Servlet applications_
request scope: unique to that specific request, falls out of scope on a new html request
session scope: persists across a session, so is visible to all requests in that session, so essentially persists for a single user session
application scope: persists for the entire duration of the application (i.e. until the server shuts down). accessible by all jsps and servlets in the same application

## 1.c _add JPA annotations to the following JavaBean class to store in the table PRODUCT, assuming the primary key is "barcode", which is not generated automatically_
```java
@Entity
@Table(name = "PRODUCT")
public class Product implements Serializable {
    @Id
    private String barcode;
    private String name;
    private double price;
// getters and setters
}
```

## 1.d _explain how the mvc architecture can be implemented using servlets and jsps, include a brief description of what could be used for the model layer, and use a simple diagram_

[mvc diagram]
jsps function as the view, clients can interact with them to interface with the model without having to actually interact directly with the underlying architecture
the servlets are the controller, and so manage user input and the underlying model to perform as an interface between the view and model
the model could be pojo, or ejbs

## 1.e _assuming the following lines are in a servelt, and that is then dispatched to a jsp, write the jsp code necessary to print out the product's name and price, stating all assumptions_

```html
<!--- assuming the Product has the relevant getPrice and getName methods --->

<%
    Product product = (Product) request.getAttribute("product");
    String productName = product.getName();
    double productPrice = product.getPrice();
%>Explain, using an example, the use of <context-param> in Java EE applications.

<!--- and then in the body of the jsp --->

<p> name <%= productName %> </p>
<p> price <%= productPrice %> </p>


```

## 1.f _explain the role of the "service" method in a jsp. where would either of the following lines be executed and what could the potential use be?_

```html
<%! int count = 0; %>
<%= count++ %>
```

the first time a jsp is called, the jspInit method is used, but all subsequent calls are done by the service method, until shutdown
the first line is a variable that will be initialised in the \_jspInit method, therefore will be session-scoped, but the second will be called in service, and will increment count each time the page is requested
this may be used to count the number of request a user makes of this page

## _1.g Explain of the role of the Entity Manager and the Persistence Unit in using the Java Persistence API (JPA)._

the entity manager is an interface with the underlying database, and is used to perform crud operations on it, and to manage entity lifecycles
the persistence unit is the configuration unit in jpa that defines a set of managed classes and other metadata. it is also used to create an entitymanagerfactory, which can create entity managers

## 1.h _explain, with an example, the use of <context-param> in jakarta_

in the web.xml file, <context-param> is used to define parameters that are consistent across the application, and can be used by servlets, jsps, and other parts of the application
for example, if you wanted to set the maximum number of items that could be shown on a given page, you could do the following
```xml
<context-param>
    <param-name> itemsPerPage </param-name>
    <param-value> 10 </param-value>
</context-param>
```


## 2 _A servlet creates a List of Employee objects, where each Employee object has the properties name, position and salary. The servlet adds this List to the session object and forwards to a JSP page where the list of employees is displayed as a table, using JSTL to handle the retrieval of the list of employees from the session, and the display of the list of employee as a table._
a) write the jsp code to display the table of employees
b) explain with sample code how to implement a simple filtering system to display only employees earning above a given salary

a)
```jsp
<%@ whatever relevant imports, including jstl/core %>

<head and shit>
<body>

    <table border="1">
        <thead>
            <tr>
                <th>Name</th>
                <th>Position</th>
                <th>Salary</th>
            </tr>
        </thead>
        <tbody>
            <c:forEach var="employee" items="${sessionScope.employeeList}">
                <tr>
                    <td>${employee.name}</td>
                    <td>${employee.position}</td>
                    <td>${employee.salary}</td>
                </tr>
            </c:forEach>
        </tbody>
    </table>
</body>
```

b)
idea - user input via a form, to take in the threshold, then modify the forEach loop to have the rows within a c:if block, as follows
```jsp
<c:if test="${employee.salary > param.minSalary}">
```

## 3 _Assume you have a Java Bean entity class, called Employee, which has the following properties._
```java
private String name;
private String position;
private double salary
```
_You may assume that a Façade session bean class has been created for Employee. A HTML form is used to submit a request to a servlet. The request contains the necessary input parameters to create a new Employee object._

a) write the jpa-annotated entity class, specifying the table and columns to be mapped to. name is the pk, no need for getters or setters
b) write the html input
c) write the servlet code to retrieve the request, and use the facade class to create and persist the entity

a)
```java
@Entity
@Table(name="EMPLOYEE")
public class Employee implements Serializable {
    @Id
    @Column(name = "name")
    private String name;

    // ... and so on
}
```

b)
```html
<form action="createEmployee" method="post">
    <label for="name"> name: </label>
    <input type="text" id="name" name="name"><br>
    // and so on
    <button type="submit" value="submit">    
</form>
```


> #software_engineering #java 
