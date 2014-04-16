function [Output] = morpholgy_operations(Input)
% Operacje morfologiczne

se1 = strel('disk', 2);
figure(1);
Image1 = imclose(Input, se1);
imshow(Image1);
figure(2);
Image2 = imfill(Input, 'holes');
imshow(Image2);
figure(3);
Image3 = imerode(Image2, se1);
imshow(Image3);
figure(4);
Image4 = imopen(Image3, se1);
imshow(Image4);
% figure(5);
% Image5 = imdilate(Image4, se1);
% imshow(Image5);

Output = Image4;
% figure();
% imshow(Output);

end