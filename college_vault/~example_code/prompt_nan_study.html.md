```html
<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8">
        <title>prompt and nan</title>

        <script>

            "use strict";

            function ask_for_int() {
                var ask = prompt("enter a number between 1 and 100");
                if (isNaN(ask))
                    alert("that's not a number");   // first check if it's a number
                else {
                    var int = parseInt(ask);    // then, if it is, convert to int
                    if (int > 0 && int < 100) {
                        var up_to_int = "<p>"   // start par
                        for (var i = 1; i < int + 1; i++) {
                            up_to_int += i;    // (i+1) works for concat
                            if (i%10==0) {
                                up_to_int += "<br>";
                            }
                            else {
                                up_to_int += " &nbsp; ";
                            }
                        }
                        up_to_int += "</p>";
                        document.getElementById("output_here").innerHTML = up_to_int;
                    }
                    else
                        alert("that number is not in the given range");
                }
            }

        </script>
    </head>
    <body onload="ask_for_int();">  <!--- onload isn't case sensitive --->
        <div id="output_here"> </div>
    </body>
</html>

```
#html #javascript 