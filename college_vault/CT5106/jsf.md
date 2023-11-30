# java server faces

jsf is an mvc framework for webapps
focused on connecting ui components with data sources and event handlers

## jsf architecture
### model
![[Pasted image 20231129170436.png]]
the model here is a managed bean, which in turn may interact with data access object (dao) classes or ejbs, which are the real underlying model in our application, but in jsf the managed beans are also considered part of the model

### view
made up of ui components on the page, rendered by jsf
generally either use facelets (special html tag library) or jsp

### controller
in jsf, the controller which routes incoming requests and selects a view for display (the FacesServlet) is provided by the framework and defined in web.xml

```xml
<servlet>
    <servlet-name>Faces Servlet</servlet-name>
    <servlet-class>jakarta.faces.webapp.FacesServlet</servlet-class>
    <load-on-startup>1</load-on-startup>
</servlet>
<servlet-mapping>
    <servlet-name>Faces Servlet</servlet-name>
    <url-pattern>/faces/*</url-pattern>
</servlet-mapping>
```

this FacesServlet performs the role of brokering incoming requests from clients to the right places
the managed beans then handle the logic for the application, and interact with back-end systems or components like ejbs

## example jsf page
![[Pasted image 20231129171855.png]]
![[Pasted image 20231129171909.png]]
then we update LoginBean.java
we add the String property errorMsg (and mutators), and call a validate method in the bean on form submission
![[Pasted image 20231129172043.png]]
this method returns a string, that the jsf uses to navigate to another page (here welcome.xhtml)

---
## managed bean
plain old java object inside a container
- sits behind the jsf page
- doesn't need to be instantiated manually

### annotations
#### @Named
gives us the bean that we can refere to in the xhtml

#### @RequestScoped
an instance is created when requested, and destroyed when the page has loaded in the browser

### initialising data in managed bean
initialisation is done in the init() method, annotated with @PostConstruct



> #software_engineering #java
