using_mlib_init();

frame = getPhoto();

foreground = rgb2gray(frame);

BWCanny = edge(foreground,'prewitt');

se30 = strel('line', 3, 20);
se0 = strel('line', 3, 0);

seD = strel('disk', 1);

BWdill = imdilate(BWCanny, [se30 se0]);

BWfill = imfill(BWdill, 'holes');

BWopen = imopen(BWfill, seD);

BWnobord = imclearborder(BWopen, 4);

[L num] = bwlabel(BWnobord, 8);

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

real_y = 843 - image_y*1.1142
real_x = image_x *0.9675 + 272
real_z = 1300

using_mlib(real_x, real_y, real_z);