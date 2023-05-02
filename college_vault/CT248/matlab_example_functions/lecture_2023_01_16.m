%{
challenge 1: plot a graph

    clear;

    a = 2;
    b = 20;
    c = -100;
    x = -50:50;
    
    y = a*(x.^2) + b*x + c; % element-wise squaring with dot operator
    
    plot(x,y);
%}

%{
challenge 2: lgoical vector filtering
    clear;
    x = 1:5;
    y = x(x > mean(x));
    disp(y);
%}