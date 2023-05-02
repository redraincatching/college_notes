function [output_grades] = fill_estimates(input_grades)
%fill_estimates
%   replaces any zeroes with the mean of that subject (column)

[r, c] = size(input_grades);
output_grades = zeros(r, c);

    for i = 1:r
        for j = 1:c
            % get a column vector, then retrieve only the nonzero values
            % get the mean of that, and round down
            mean_col = floor(mean(nonzeros(input_grades(:,j))));

            if (input_grades(i, j) == 0)
                output_grades(i, j) = mean_col;
            else
                output_grades(i, j) = input_grades(i, j);
            end
        end
    end
end