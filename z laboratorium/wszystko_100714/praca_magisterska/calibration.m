function [image_x, image_y, BWlabel] = calibration(Input)

cal = rgb2gray(Input);

hist_cal = imhist(cal); stem(hist_cal);

bw_cal = im2bw(cal, 186/255);

bw_cal_fill = imfill(bw_cal, 'holes');

[L num] = bwlabel(bw_cal_fill, 8);

BWlabel = {num};

k = 0;
for i = 1:num
    [row col, val] = find(L == i);
    BWlabelTemp = bwselect(L, col, row);
    if bwarea(BWlabelTemp) > 200
        k = k+1;
        BWlabel{k} = BWlabelTemp;
    end
end

s = regionprops(double(BWlabel{1}), 'centroid');
centroids = cat(1, s.Centroid);

image_x = centroids(1,1);
image_y = centroids(1,2);

imshow(BWlabel{1});
hold on;
plot(image_x, image_y, 'b*');
hold off;

end