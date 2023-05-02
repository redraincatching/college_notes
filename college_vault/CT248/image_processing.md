# image processing
## image types
- binary
2-d arrays that assign one numerical value from the set {0,1} to each pixel in the image, often called logical images. can be represented as a bitstring.
zero corresponds to black, one corresponds to white
- intensity/greyscale
2-d arrays that assign one numerical value to each pixel, representing the intensity of that point. range is bounded by the bit resolution of that image
- rgb
3-d array which assigns three numerical values to each pixel, each corresponding to the red, green, and blue channels.
pixels in matlab are accessed by I(row,column,channel)

## key functions
- imread(filepath)
reads an image from a graphics file, converts it to a matlab array
- imshow(object)
displays an image

## sample matlab image
```matlab
clear;

locs = linspace(0,255,4);
sq1 = uint8(locs(1)) * ones(64,64);
sq2 = uint8(locs(2)) * ones(64,64);
sq3 = uint8(locs(3)) * ones(64,64);
sq4 = uint8(locs(4)) * ones(64,64);

sq = [sq1 sq2; sq3 sq4];
imshow(sq);
```

output:
![[matlab_grey_squares.png]]

---
## operations on pixels
the most basic type of image processing is a point transform which maps the values at individual points (pixels) in the input image to corresponding point in the output image
in the mathematical sense, it's a one-to-one functional mapping from input to output

### types of operations
- pixel addition and subtraction
- thresholding
- rgb to greyscale
- rotation
- simple cropping

---
## thresholding
using a logical vector to convert a greyscale or colour image to binary
```matlab
A = 
	1 2 3 
	4 5 6 
	7 8 9 

>> A > 5 
ans = 3×3 logical array 
	0 0 0 
	0 0 1 
	1 1 1
```

> #matlab #modelling 