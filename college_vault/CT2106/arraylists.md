# arraylists
basically an array, but dynamically resizing
zero-indexed, thank fuck
the ArrayList variable itself is referencing the ArrayList object, that's why we need to instantiate with one
// note: must be imported if used at the top of the class
// import java.util.ArrayList;

## syntax 
### declaration
```java
private ArrayList<data_type> name;
```

### instantiation
```java
name = new ArrayList<>();
```

### adding objects
```java
name.add(obj_name);     // reference variable, adding with methods

```

### returning indices
using sample code
```java
public Student get_student(int index) {
	if (group.get(index) != null) {         
			// note: can't use NULL, in java all primitives are lowercase
		return group.get(index);
	}
	else {
		// error message
		return null;        // cause return type is a reference to student
	}
}
```

### removing
```java
name.remove(index);     // if doing this in a method, maybe return bool instead of void
```

> #java #programming 