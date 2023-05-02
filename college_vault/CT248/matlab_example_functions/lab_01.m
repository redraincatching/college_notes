clear;
d = roll_2_dice(10000, 100);
[freq, prop] = tabulate_2_dice(d);
disp(freq);
disp(prop);