%{ 
challenge 1: function y = f(x)

function [avg, stdev] = stats(x) 
% comments here are displayed with "help <function_name>"
    avg = mean(x);
    stdev = std(x);
end


% stats is the name of the function, so put this in stats.m
% x is the local variable and input

% the values in square brackets are the return arguments
% can have as many as you want
% brackets are optional with only one argument

% so this would be called like
    v = 1:5;
    [a,s] = stats(v);

% and then output
    >> a = 3
    >> s = 1.5811
%}
