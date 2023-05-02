clear;
% values of K to loop through
time_vec = 1:100;
init_vec = 1000;
k_vec = linspace(1000, 1000000, 50);
r = 0.15;   % i have no idea how to get r so this is a guess


out = zeros(length(time_vec),length(k_vec));


%logistic growth of a population p
%   dP/dt = rP (1 - P/K)
dp_dt = @(t,x,r,k)[r*x*(1-x/k)];


for i = 1:length(k_vec)
    [t,y] = ode45(dp_dt,time_vec,init_vec,odeset,r,k_vec(i));

    % set current column of output matrix
    out(:, i) = y;
end

plot(t,out);