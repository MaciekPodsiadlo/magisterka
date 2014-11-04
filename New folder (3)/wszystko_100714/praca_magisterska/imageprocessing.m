function [centers] = imageprocessing(Input)

% Zamiana na HSV
HSVImage = rgb2hsv(Input);
Image = HSVImage(:,:,3);
imshow(Image);

Image2 = image_filtering(Image, 9);
figure();
imshow(Image2);

Image3 = to_Binary(Image2);
figure();
imshow(Image3);

Image4 = morpholgy_operations(Image3);
% figure();
% imshow(Image4);

centroids = finding_centers(Image4);

Image5 = 255 * double(bwmorph(Image4, 'remove'));
Image6 = imadd(Image, Image5);
figure(); 
imshow(Image6);
hold on;
% for i = 1:size(centroids,1);
%     plot(centroids(i,:,1), centroids(i,:,2), 'b*');
%     centers(i,:) = centroids(i,:,:);
% end

% Output = Image4;
centers = [centroids(1,:,1), centroids(1,:,2)];

end