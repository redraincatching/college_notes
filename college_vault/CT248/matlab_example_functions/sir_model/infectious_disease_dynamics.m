clear;
% initialise given values
alpha = 0.25;   % proportion removed from infectious stock
beta = 0.02;    % proportion hospitalised
gamma = 0.1;    % proportion removed from hospital stock
infectivity = 0.125;

% contacts: twenty evenly-spaced values from 3 to 8
contacts = linspace(3,8,20);

% initial conditions
time_vec = 0:.25:100;
init_vec = [9999 1 0 0 0];  % S + I + R + H + RH = N

% initialise output structures
out_in_hospital = zeros(401, length(contacts));
out_infected = zeros(401, length(contacts));

% run for each value of contacts
for i = 1:length(contacts)
    [t, y] = ode45(@SIR,...
                time_vec, ...
                init_vec, ...
                odeset, ...
                contacts(i), ...
                infectivity, ...
                alpha, ...
                beta, ...
                gamma);

    % set current column of output structure
    out_in_hospital(:, i) = y(:, 4);
    out_infected(:, i) = y(:,2);

end

% then plot somehow
% infected stock over time
figure;
subplot(3,1,1);     % breaks figure window into mxn and returns the pth handle
plot(time_vec, out_infected);
title("infected stock over time");
xlabel("time");
ylabel("infected stock");

% people in hospital over time
subplot(3,1,2);
plot(time_vec, out_in_hospital);
title("number of inpatients over time");
xlabel("time");
ylabel("inpatients");

% max amount in hospital for each level of contacts
subplot(3,1,3);
scatter(contacts, max(out_in_hospital));
title("peak hospitalisations for each contact value");
xlabel("no. average daily contacts");
ylabel("peak inpatients");