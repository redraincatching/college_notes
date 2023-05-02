```rust
use std::io;

fn main() {
    let mut input = String::new();
    
    println!("enter a number:");
    io::stdin()
        .read_line(&mut input)
        .expect("failed to read number");
        
    // this failed at first because i forgot to trim trailing whitespace
    let input = input
        .trim()
        .parse()
        .expect("not a number");

    let output = fibb(input);

    println!("fibbonacci number {input}: {output}");
}

  

fn fibb(i : i32) -> i32 {
    if i <= 1 {
        return 1;
    }
    // note the return keyword, similar to break <value>; in a loop
    fibb(i - 1) + fibb(i - 2)
}
```

> #rust #algorithms 