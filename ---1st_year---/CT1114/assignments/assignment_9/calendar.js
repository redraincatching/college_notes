"use strict";

var week = ["sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday"];
// essentially an enum


function make_calendar(month_len, day) {
    let cal_table = "<table>";              // starts off our table
    let date = new Date();
    let curr_day = date.getDate();  // gets the date
    let d = 1;                              // for actually writing the date in

    for (var i = 0; i<7; i++) {             // first row of the table
        if (i == 0)
            cal_table += "<tr>";
        cal_table += `<td class = "headers">${week[i]}</td>`;
        if (i == 7)
            cal_table += "<tr>";
    }

    var rows = Math.ceil((parseInt(month_len) + parseInt(day)) / 7);    // figure out how many rows we need

    for (var i = 0; i < ((7 * rows)); i++) {
        if (i % 7 == 0)
            cal_table += "<tr>";                // start a row
        if (i < day || d > month_len)
            cal_table += '<td class="blank"></td>';
        else if ((i < day + month_len)) {
            cal_table += `<td class=${(d == curr_day) ? "current_day" : "day"}>${d}</td>`;
            d++;
        }    
        if (i % 7 == 6)
            cal_table += "<tr>";
    }

    cal_table += "</table>";
    document.getElementById("table_div").innerHTML = cal_table;
}

function get_starting_data() {
    let day = -1;
    let month_len = +prompt("how many days are in the month?", "how many days?");

    if (isNaN(month_len)) {
        alert("that's not a valid number of days.");
        month_len = prompt("how many days are in the month?", "how many days?");
    }

    let start_day = prompt("what day of the week does the month start on?", "which day?");
    start_day = start_day.toLowerCase();

    while (day < 0) {
        for (var i = 0; i < 7; i++) {
            if (start_day == week[i]) {
                day = i;
                break;
            }
        }
        if (day < 0) {
            alert("that's not a day");
            start_day = prompt("what day of the week does the month start on?", "which day?");
        }
    }

    make_calendar(month_len, day);
}
