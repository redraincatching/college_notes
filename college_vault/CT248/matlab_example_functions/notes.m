%{
Here's a cheatsheet of MATLAB syntax and modeling:

Basic Syntax:

Use % to add comments to your code.
Use ; at the end of a line to suppress output.
Use clear to clear the workspace.
Use clc to clear the command window.
Use help followed by a function name to access the function's documentation.
Use doc followed by a function name to access the function's documentation in a separate window.
Variables:

Use = to assign a value to a variable.
Use who to display the variables in the workspace.
Use whos to display the variables in the workspace with additional information, such as their size and class.
Use disp to display the value of a variable.
Data Types:

Use double to create a variable of type double.
Use int to create a variable of type integer.
Use char to create a variable of type character.
Use logical to create a variable of type logical.
Vectors and Matrices:

Use : to create a vector of evenly spaced values.
Use linspace to create a vector of evenly spaced values with a specified number of elements.
Use zeros to create a matrix of zeros.
Use ones to create a matrix of ones.
Use eye to create an identity matrix.
Use rand to create a matrix of random values.
Operations:

Use + to add two values.
Use - to subtract two values.
Use * to multiply two values.
Use / to divide two values.
Use ^ to raise a value to a power.
Functions:

Use sin, cos, and tan to calculate the trigonometric functions.
Use sqrt to calculate the square root of a value.
Use exp to calculate the exponential function.
Use log to calculate the natural logarithm.
Plotting:

Use plot to create a 2D line plot.
Use scatter to create a 2D scatter plot.
Use surf to create a 3D surface plot.
Use contour to create a 2D contour plot.
Modeling:

Use ode45 to solve ordinary differential equations.
Use fsolve to solve nonlinear equations.
Use fmincon to minimize a function subject to constraints.
Use linprog to solve linear programming problems.
These are just a few of the most commonly used MATLAB functions and operations. For more detailed information, be sure to consult the MATLAB documentation.
%}


% Example MATLAB script file for using ode45()

% Define the differential equation: y' = f(t,y)
f = @(t,y) -y + t^2;

% Define the initial conditions: y(0) = 1
y0 = 1;

% Define the time interval for the solution: t = [0, 2]
tspan = [0, 2];

% Solve the differential equation using ode45()
[t, y] = ode45(f, tspan, y0);

% Plot the solution
plot(t, y)
title('Solution of y'' = -y + t^2')
xlabel('t')
ylabel('y')

% Define a system of two differential equations: y1' = y2 and y2' = -y1
f = @(t,y) [y(2); -y(1)];

% Define the initial conditions: y1(0) = 0, y2(0) = 1
y0 = [0; 1];

% Define the time interval for the solution: t = [0, 10]
tspan = [0, 10];

% Solve the system of differential equations using ode45()
[t, y] = ode45(f, tspan, y0);

% Plot the solution
plot(t, y(:,1))
title('Solution of y1'' = y2, y2'' = -y1')
xlabel('t')
ylabel('y1')

%{
In this script file, we first define a simple differential equation y' = f(t,y) with initial condition y(0) = 1. We then define the time interval for the solution as tspan = [0, 2] and use ode45() to solve the differential equation. The output of ode45() is a vector of time values t and a corresponding vector of solution values y, which we then plot using plot().

Next, we define a more complex system of two differential equations y1' = y2 and y2' = -y1 with initial conditions y1(0) = 0 and y2(0) = 1. We again define the time interval for the solution as tspan = [0, 10] and use ode45() to solve the system of differential equations. The output of ode45() is a matrix of solution values y, where the first column corresponds to y1 and the second column corresponds to y2. We then plot the solution for y1 using plot().

Note that the ode45() function can be used to solve a wide variety of differential equations and systems of differential equations, including those with varying coefficients, boundary conditions, and more. Consult the MATLAB documentation for more information on using ode45().
%}