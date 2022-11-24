```js
"use strict";

function check_name(name) {
    if (/^[a-z ]+$/i.test(name))     // the regex took forever to get right
        return 1;
    else
        return 0;
}

function check_email(e) {
    if (/(?<!@)@{1}(?!@)/g.test(e)) {
        if (/\./.test(e))
            return 1;
    }
    return 0;
}

function check_form() {
    let q = document.getElementById("q_text").value;
    let name = document.getElementById("name").value;
    let email = document.getElementById("email").value;
    let valid = 1;

    if (q == "") {
        alert("please enter a question.");
        valid = 0;
    }
    if (name == "" || !check_name(name)) {
        alert("please enter a valid name.");
        valid = 0;
    }
    if (!check_email(email)) {
        alert("please enter a valid email.");
        valid = 0;
    }

    if (valid == 1) {
        alert("your message is valid. submitting...");
    }
}

```

#web_dev #javascript #email_checker 