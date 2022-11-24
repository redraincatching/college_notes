# asynchronous programming in javascript
javascript is designed to deal with asynchronous situations
- waiting for resources to arrive over the internet (ajax)
- waiting for user interaction (onclick)
- waiting for time to pass (setTimeout)

_callbacks_ are an elegant way to deal with this
- sending functions as parameters to other functions

## callbacks
callbacks can use named or anonymous functions
// note: remember that functions are objects

sample code: a custom dialog box
```js
<div id="divAlert" style="position:absolute; width:100%; height:100%; overflow:hidden; left:0px; top:0px; text-align:center; display:none; background-color:rgba(0, 0, 0, 0.9); z-index:3;">
    <div style="position:absolute; left:50%; top:50%; width:75%; transform: translate(-50%, -60%); z-index:4;">
        <h1 id='alertHeading'></h1>
        <p id='alertMsg'></p>
        <a class="btn blue" onclick="onClickedAlertOk();">OK</a>
        <a class="btn blue" onclick="onClickedAlertCancel();">Cancel</a>
    </div>
</div>
```

---
### sending callbacks as named functions
```js
function clicked_exit_game() {
    confirm("are you sure?", "exit game", confirm_exit_game, cancel_exit_game);
}

function confirm_exit_game() {
    // do this
}

function cancel_exit_game() {
    // do this instead
}
```

### sending callbacks as anonymous function
```js
// NOTE: ooh, this is spicy...
function clicked_exit_game() {
    confirm("are you sure?", "exit game", function(){
        // do thing
    }, function() {
        // do other thing
    });
}
```

> #javascript #web_dev 