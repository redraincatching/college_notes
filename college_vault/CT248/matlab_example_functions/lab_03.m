clear;

eng1 = imread("Engineering-Building.jpg");

eng1_gs = pic2grayscale(eng1);

eng1_gs_inv = transform_pic(eng1_gs);

eng1_gs_bin_50 = transform_threshold(eng1_gs,50);

eng1_gs_bin_75 = transform_threshold(eng1_gs,75);

eng1_gs_bin_100 = transform_threshold(eng1_gs,100);