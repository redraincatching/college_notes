# basics

cargo new, build, run, and check are convention, rather than rustc

cargo build --release is the most optimised version

crate: collection of rust source files
> cargo is really good at handling crates, you just need to add the dependencies to the cargo.toml file

when we include an external dependency, cargo fetches the latest versions of everything that dependency needs from the registry, which is a copy of data from crates.io. 
crates.io is where people in the rust ecosystem post their open source rust projects for others to use.

cargo creates a lock on your version on build, and the version can be updated with cargo update
-> however, cargo will ignore 0.9.x if you're using 0.8.x, and similar major updates, that would have to be done manually

note: if using vscode's rust-analyser, use it in the actual folder, so that the extension can find the cargo.toml file

