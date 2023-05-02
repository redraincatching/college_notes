clear;
A = create_grades(20, 5, -100, 100, 6);

A1 = clean_grades(A);

A2 = fill_estimates(A1);

disp(A2);