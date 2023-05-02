function out = roll_2_dice(no_rolls, seed)
% randomise 2 6-sided dice based on a seed, n times
rng(seed);
out = randi([1 6],1,no_rolls) + randi([1 6],1,no_rolls);
end