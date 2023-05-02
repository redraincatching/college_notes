function [output_grades] = clean_grades(input_grades)
%clean grades
%   takes any negative integers in the synthetic data and replaces them
%   with 0
[r, c] = size(input_grades);
output_grades = zeros(r, c);
    for i = 1:r
        for j = 1:c
            if (input_grades(i, j) < 0)
                output_grades(i, j) = 0;
            else
                output_grades(i, j) = input_grades(i, j);
            end
        end
    end
end