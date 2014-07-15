foreground = rgb2gray(frame8);

BWCanny = edge(foreground,'canny');

seD = strel('disk', 1);

BWfill = imfill(BWCanny, 'holes');

BWopen = imopen(BWfill, seD);

[L num] = bwlabel(BWopen, 8);

BWlabel = {num};

k = 0;
for i = 1:num
    [row col, val] = find(L == i);
    BWlabelTemp = bwselect(L, col, row);
    if bwarea(BWlabelTemp) > 50
        k = k+1;
        BWlabel{k} = BWlabelTemp;
    end
end

s = regionprops(BWlabel{1}, 'centroid');
centroids = cat(1, s.Centroid);

image_x = centroids(1,1);
image_y = centroids(1,2);

imshow(BWlabel{1});
hold on;
plot(image_x, image_y, 'b*');
hold off;

real_y = 843 - image_y*1.1142;
real_x = image_x *0.9675 + 272;