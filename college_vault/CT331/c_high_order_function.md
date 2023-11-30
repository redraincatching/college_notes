# high order functions in c
functions that take one or more other functions as arguments, or return a function as a result
can be implemented using function pointers in c


## function pointer definition
```c
// syntax
type (*name) (arg_0, arg_1, ..., arg_n);
// e.g.
int (*do_maths) (int, int);

// this is technically a prototype, so no need to name the variables in the args
```

## motivating example - sorting
```c
void sort(int* array, int (*compare) (int, int)) {
	// ...
	if (compare(array[i], array[j])) {
		swap(array[i], array[j]);
	}
	// ...
}

// this function can be passed any function of the defined format, like
int compare_less_than (int a, int b) {
	return a < b;
}

int compare_greater_than (int a, int b) {
	return a > b;
}

// like this
int main() {
	// ...
	int* sorted_array = sort(array, &compare_less_than)
}
```

### typedef
can make the above much simpler
```c
typedef int (*compare_function) (int, int);

int sort(int* arr, compare_function compare) {
	// ...
}
```


see also: https://medium.com/nerd-for-tech/higher-order-functions-in-c-74f6c4b550ee

> #paradigms #c