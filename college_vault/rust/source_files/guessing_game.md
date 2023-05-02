```rust
use std::io;    // import io from standard library
use rand::Rng;  // the Rng trait defines methods that random number generators implement
use std::cmp::Ordering; // another enum with the variants Less, Equal, and Greater

  

fn main() {

    println!("guess a number: ");

    let secret = rand::thread_rng().gen_range(1..=100); // range is lower-inclusive, and takes the form <start>..=<end>

  

    loop {

        let mut guess = String::new();  // variables are immutable by default in rust, so mut must be specified
        // <a>::<b> means <b> is an associated function of library or type <a>

  

        // if we hadn't imported io, we could just call std::io::stdin
        io::stdin()
            .read_line(&mut guess)
            .expect("failed to read line");
        // & means a reference
        // readline returns an enum of type Result

  

        // Result has an expect method

        let guess: u32 = match guess.trim().parse() {
            Ok(num) => num,
            Err(_) => continue,
        };

        // here we're shadowing the name guess, which is why we can have two variables of the same name
        // often used for type conversion
        // trim() eliminates leading spaces or trailing newlines
        // parse performes the type conversion
        // : tells rust we're annotating the variable's type
        // parse returns the Result enum, so it has the variants Ok and Err
        // _ is a catchall value, and continue sends the program to the next iteration of this loop
  
        // a match expression is made up of arms, which are run if they match the given pattern

        match guess.cmp(&secret) {
            Ordering::Less => println!("Too small"),
            Ordering::Greater => println!("Too big"),
            Ordering::Equal => {
                println!("correct, the answer was {secret}");
                // placeholders work like js ${} or like c flags, with "{}", x
                break;
            }
        }
    }
}
```

> #rust