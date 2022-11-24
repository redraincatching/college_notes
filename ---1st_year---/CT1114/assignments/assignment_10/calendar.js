"use strict";
let week = ["sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday"];
let month_list = ["january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december"]

function is_leap(year) {
    if ((year % 4) == 0 && ((year % 400) == 0 || (year % 100) != 0))
        return 1;
    else
        return 0;
    // leap year if year is divisble by 4, but not 100, unless also divisible by 400
}

function no_of_days(month, year) {     // get the number of days for  given month
    if (month == 9 || month == 4 || month == 6 || month == 11)
        return 30;
    if (month != 2)
        return 31;
    else
        return (28 + is_leap(year));
}

function starting_day(month, year) {
    let since_year_start = 0;    // days since january 1st, 1990
    let leap_days = 0;      // how many feburaury 29ths were there

    for (let i = month-1; i > 0; i--)   // adds the days in each month since start of year
        since_year_start += no_of_days(i, year);

    let years_since = year - 1900;
    for (let i = year; i > 1900; i--) {
        if (is_leap(i))         // add a leap day for every leap year between 1990 and year
            leap_days++;
    }

    return (1 + since_year_start + 365*years_since + leap_days) % 7;
    // return starting day according to the formula (1+days_since_epoch) % 7;
}

function make_calendar() {
    let month = document.getElementById("month").value;
    let year = parseInt(document.getElementById("year").value);
    if (isNaN(year) || year < 1900) {
        alert("not a valid year. please enter a year 1900 or later.")
        return;
    }
    let day = starting_day(month, year);
    let month_len = no_of_days(month, year);


    let cal_table = "<table>";              // starts off our table
    let d = 1;                              // for actually writing the date in

    for (let i = 0; i<7; i++) {             // first row of the table
        if (i == 0)
            cal_table += "<tr>";
        cal_table += `<td class = "headers">${week[i]}</td>`;
        if (i == 7)
            cal_table += "<tr>";
    }

    let rows = Math.ceil((parseInt(month_len) + parseInt(day)) / 7);    // figure out how many rows we need

    for (let i = 0; i < ((7 * rows)); i++) {
        if (i % 7 == 0)
            cal_table += "<tr>";                // start a row
        if (i < day || d > month_len)
            cal_table += '<td class="blank"></td>';
        else if ((i < day + month_len)) {
            cal_table += `<td class="day">${d}</td>`;
            d++;
        }
        if (i % 7 == 6)
            cal_table += "<tr>";
    }

    cal_table += "</table>";
    document.getElementById("table_div").innerHTML = cal_table;
    document.getElementById("title").innerHTML = `${month_list[month-1]}, ${year}`;
}
