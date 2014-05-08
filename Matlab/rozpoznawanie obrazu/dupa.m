function [Output] = dupa(Image4)
centroids = finding_centers(Image4);

Image5 = 255 * double(bwmorph(Image4, 'remove'));
Image6 = imadd(Image, Image5);
figure(); 
imshow(Image6);
hold on;
for i = 1:size(centroids,1);
    plot(centroids(i,:,1), centroids(i,:,2), 'b*');
    centers(i,:) = centroids(i,:,:);
end

Output = Image4;