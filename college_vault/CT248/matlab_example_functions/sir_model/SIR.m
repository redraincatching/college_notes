function y = SIR(t, inp_vec, contacts, infectivity, alpha, beta, gamma)
% returns a vector of the rates of change of each factor in the SIR model
% equations
    % output array
    y = [0;0;0;0;0];

    % read inputs and get N
    S = inp_vec(1);
    I = inp_vec(2);
    R = inp_vec(3);
    H = inp_vec(4);
    RH = inp_vec(5);
    N = S + I + R + H + RH; % always 10000 but this is better in principle

    % calculate from model equations
    y(1) = -contacts*S*(I/N)*infectivity;       % dS/dt
    y(2) = contacts*S*(I/N)*infectivity - (alpha * I); % dI/dt
    y(3) = (alpha * I) - (beta * R); % dR/dt
    y(4) = (beta * R) - (gamma * H); % dH/dt
    y(5) = gamma * H; % dRH/dt

end

