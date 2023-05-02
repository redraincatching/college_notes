function [img_output] = pic2grayscale(img_input)
%pic2grayscale 
%   NTSC standard rgb to grayscale transformation
%   i really want to spell it greyscale but whatever

%   first convert to ntsc colour space
%   start by extracting the red, green, and blue components
%   these are stored in their own channels, so a 2x2 matrix in the third
%   dimension
r = double(img_input(:, :, 1));
g = double(img_input(:, :, 2));
b = double(img_input(:, :, 3));

%   then apply the standard transformation 
%   i did steal this from wikipedia, all i know about luminance comes from
%   photography, but i'm assuming it has something to do with the amount of
%   green cones in the human eye being larger
lum = (0.2989 * r) + (0.5870 * g) + (0.11408 * b);

%   normalise to range [0,1]
min_lum = min(lum(:));
max_lum = max(lum(:));
lum = (lum - min_lum) / (max_lum - min_lum);

%   and convert the luminance values to the range 0-255 by multiplying by
%   255 and casting to an unsigned int to get a greyscale version
img_output = uint8(lum * 255);

end

