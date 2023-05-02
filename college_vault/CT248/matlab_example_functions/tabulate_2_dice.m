function [freq, prop] = tabulate_2_dice(dice_vector)
%tabulate the results of the dice rolls
[~, columns] = size(dice_vector);
disp(columns);

range = [1:12];
freq = hist(dice_vector, range);

for i = 1:12
    prop(i) = freq(i) / columns;
end
end

