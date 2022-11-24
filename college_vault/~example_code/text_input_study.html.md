```html
<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8">
        <title> factors of numbers </title>

        <script>
            "use strict";

            function get_factors() {
                var to_factorise = parseInt(document.getElementById("number_entry").value); // our input number
                var output = document.getElementById("output"); // our output div
                var factors = "the factors of "; // our string for the output
                var num_of_fact = 0; // checks if prime

                if (isNaN(to_factorise))
                    output.innerHTML = to_factorise + " is not an integer.";  // nan
                else {
                    factors += to_factorise + " are: ";
                    if (to_factorise > 0) {
                        for (var i = 1; i < to_factorise + 1; i++) {    // iterate
                            if (to_factorise % i == 0 && i < (to_factorise)) {  // most of them
                                factors += i + ", ";
                                num_of_fact++;
                            }
                            else if (to_factorise % i == 0 && i == to_factorise) {  // no trailing comma
                                factors += i;
                                num_of_fact++;
                            }
                        }
                        factors += ".";
                        if (num_of_fact != 2) { // number of factors
                            factors += "<br>there are " + num_of_fact + " factors of " + to_factorise + ".";
                            output.innerHTML = factors;
                        }
                        else {  // prime
                            factors = to_factorise + " is a prime number.";
                            output.innerHTML = factors;
                        }
                    }
                    else {  // negative
                        output.innerHTML = "please enter a positive integer.";
                    }
                }
            }
        </script>
    </head>
    <body>
        <input type="text" id="number_entry" value="enter a positive integer:" style="width:220px">
        <button onclick="get_factors();"> show factors </button>
        <br>
        <div id="output"></div>
    </body>
</html>

```
#html #javascript 