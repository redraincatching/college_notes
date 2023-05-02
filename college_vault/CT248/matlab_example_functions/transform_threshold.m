function [img_output] = transform_threshold(img_input, threshold)
%transform_threshold
%   based on a converts to binary by returning a logical array based on the
%   provided comparison
img_output = img_input > threshold; 
end