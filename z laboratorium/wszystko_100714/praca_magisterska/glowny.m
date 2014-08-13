% using_mlib_init();

frame = getPhoto();

foreground = rgb2gray(frame);

gaus_fil = fspecial('gaussian', [3 3], 0.3);
Output = imfilter(foreground, gaus_fil);

BWCanny = edge(Output,'prewit');

se30 = strel('line', 3, 100);
se0 = strel('line', 3, 30);

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
    if bwarea(BWlabelTemp) > 1200
        k = k+1;
        BWlabel{k} = BWlabelTemp;
    end
end

s = regionprops(double(BWlabel{1}), 'centroid');
centroids = cat(1, s.Centroid);

image_x = centroids(1,1)
image_y = centroids(1,2)

imshow(BWlabel{1});
hold on;
plot(image_x, image_y, 'b*');
hold off;

% Hodw = [
%    0.0332962943317  -0.9160163139977   833.8600910794114;
%    0.8546162863211  -0.0879463708952   320.1430322552461;
%   -0.0000269961043  -0.0000462882880   1.0340499142841];

Sodw = [
      -0.000020060291381   0.000163147625499  -0.145192672476107;
  -0.000174453696984   0.000006261203606  -0.048345626608316;
  -0.000000021821776   0.000000004338258  -0.000173790498716];

D = Hodw*[image_x; image_y; 1];
F = Sodw*[image_x; image_y; 1];

real_x = D(1); 
real_y = D(2);
real_z = 1100;

real_xF = F(1)/F(3)
real_yF = F(2)/F(3)

using_mlib(real_x, real_y, real_z);