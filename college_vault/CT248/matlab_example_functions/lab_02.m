clear;
[push, pop, peek] = stack();

running_stack = [];
% empty vector

running_stack = push(running_stack, 100);
running_stack = push(running_stack, 200);
% for testing purposes
out = peek(running_stack);
disp(out);

running_stack = pop(running_stack);
out = peek(running_stack);
disp(out);