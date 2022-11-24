"use strict";
var car = {
    colour:'red',
    wheels:[true,true,true,true],
    engine:{capacity:1000, power:200}
};

function car_colour() {
    alert("the car is " + car.colour);
}

function change_colour() {
    let new_colour = prompt("what colour should the car be?", "enter a colour:");
    car.colour = new_colour;
}

function back_right_and_spare() {
    (car.wheels[3]) ? alert("this car's 4th wheel exists") : alert("this car's 4th wheel does not exist");
    (car.wheels[4]) ? alert("this car's 5th wheel exists") : alert("this car's 5th wheel does not exist");

}

function power_check() {
    alert("this car's power is " + car.engine.power);
}

function add_val() {
    let newval = prompt("enter a new value for the car", "enter:");
    car.value = newval;
}

function display() {
    let cringe = JSON.stringify(car);
    alert(cringe);
}
