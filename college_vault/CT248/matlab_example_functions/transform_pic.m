function [img_output] = transform_pic(img_input)
%transform_pic 
%   inverts the value of every unsigned integer in an array relative to the
%   range 0-255
img_output = 255.-img_input;
end

