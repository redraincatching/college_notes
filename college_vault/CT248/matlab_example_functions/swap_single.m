function out = swap_single(in, targ, rep)
% different take on swap function
% create a logical vector based on comparisons to target, and then use that
% to filter o, and replace
out = in;
out(out == targ) = rep;
end