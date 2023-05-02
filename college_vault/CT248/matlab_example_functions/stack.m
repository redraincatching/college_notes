function [push, pop, peek] = stack()
%STACK basic filo data structure
%   returns push, pop, and peek as anonymous subfunctions
    % vector concatenation
    push = @(in, val) [in, val]; 
    % returning a slice of the vector
    pop = @(in) in(1:end-1);    
    % returns last value
    peek = @(in) in(end);
end