# throwing exceptions in java

simply use the throw statement, and specify the exception that you wish to throw
```java
throw new Exception("exception message");
```
// this is a generic exception, which is quite limiting to use, as it's hard to catch

## using the throws keyword
indicates that this method could throw this type of exception. the exception thrown has to then be handled by a try-catch block enclosing the method call
syntax:
```java
type method_name(args) throws exception_list
```
so an example might look like
```java
void sample() throws ArithmeticException, ArrayIndexOutOfBoundsException {
	// whatever
}
```
and this would be handled as follows
```java
public class Test {
	public static void main(String args[]) {
		try {
			sample();
		} catch (Exception e) {
			e.printStackTrace();	
		}
	}
}
```

---
# the exception class

```java
package java.lang; 
public class Exception extends Throwable { 
	static final long serialVersionUID = -3387516993124229948L; 
	
	public Exception() { 
		super(); 
	} 
	
	public Exception(String message) { 
		super(message); 
	} 
	
	public Exception(String message, Throwable cause) { 
		super(message, cause); 
	} 
	
	public Exception(Throwable cause) { 
		super(cause); 
	} 
	
	protected Exception(String message, Throwable cause, boolean enableSuppression, boolean writableStackTrace) { 
		super(message, cause, enableSuppression, writableStackTrace); 
	}

}
```

---
# types of exceptions

## checked (compile time) exceptions

must be caught and handled at runtime. if the compiler doesn't see a try/catch block to handle an exception of this type, it won't compile.

example:
```java
FileInputStream fis = null; 
try { 
	fis = new FileInputStream("C:/file.txt"); 
} catch (FileNotFoundException e) { 
	e.printStackTrace(); 
}
```

## unchecked (runtime) errors

occur during execution, and cause the program to end

for example, this division by zero will throw an ArithmeticError which causes the program to crash:
```java
public class Main() {
	public static void main(String args[]) {
		int a = 10, b = 0;
		System.out.println(a/b);
	}
}
```

---
> ***errors vs. exceptions***
> errors are thrown by the jvm and cannot be handled
> they derive from java.lang.Error, and occur due to some issue in the environment, such as a stack overflow, which require the program to halt

---
# custom exceptions
supplementing the base exceptions with custom ones to provide the user with relevant information is often necessary
the best practice is to extend the ```java.lang.Exception``` class.

example:
```java
public class HandledException extends Exception {
	private String code;
	
	public HandledException(String code, String message) {
		super(message);
		this.setCode(code);
	}
	
	public HandledException(String code, String message, Throwable cause) { 
		super(message, cause); 
		this.setCode(code); 
	}
	
	public String getCode() {
		return code;
	}
	
	public void setCode(String code) {
		this.code = code;
	}
}
```

---
# try/finally
for code to be excecuted no matter what, you can use the try/catch/finally structure
syntax:
```java
try {
	// risky code
} catch (Exception e) {
	// handle
} finally {
	// cleanup
}
```

---
## extensions of the throwable class
```java
java.lang.Throwable  
  java.lang.Error  
  java.lang.Exception  
    java.lang.IOException  
    java.lang.RuntimeException  
      java.lang.ArithmeticException  
      java.lang.IllegalArgumentException  
      java.lang.IndexOutOfBoundsException  
      java.lang.NullPointerException
```

> #java #programming 