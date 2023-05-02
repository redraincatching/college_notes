function [out_grades] = create_grades(no_students, no_subjects, lower, upper, rng_seed)
%create_grades
%   generate synthetic grades for a class of students
rng(rng_seed);
out_grades = randi([lower upper], no_students, no_subjects);
end