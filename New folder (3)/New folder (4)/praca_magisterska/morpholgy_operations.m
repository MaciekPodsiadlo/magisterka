function [Output] = morpholgy_operations(Input)
% Operacje morfologiczne

se1 = strel('disk', 5);

Image1 = imfill(Input);
Image2 = imerode(Image1, se1);
Image3 = imerode(Image2, se1);
Image4 = imdilate(Image3, se1);
Image5 = imdilate(Image4, se1);

Output = Image5;
% figure();
% imshow(Output);

end