

% ImageMedian = image_filtering(ImageV, 1);
% figure(1);
% imshow(ImageMedian);
% 
% ImageAverage = image_filtering(ImageV, 2);
% figure(2);
% imshow(ImageAverage);
% 
% ImageGauss = image_filtering(ImageV, 4);
% figure(3);
% imshow(ImageGauss);
% 
% ImageWiener = image_filtering(ImageV, 9);
% figure(4);
% imshow(ImageWiener);

ImageSobel2 = edge(ImageWiener,'sobel');
figure(5);
imshow(ImageSobel2);

ImageCanny = edge(ImageWiener, 'canny');
figure(6);
imshow(ImageCanny);

ImageLaplac = edge(ImageWiener, 'log');
figure(7);
imshow(ImageLaplac);

ImageThresh = To_Binary(ImageWiener);
figure(8);
imshow(ImageThresh);

se1 = strel('disk', 1);
ImageMorph1 = imdilate(ImageCanny, se1);
figure(11); imshow(ImageMorph1);

ImageMorph2 = imfill(ImageMorph1,'holes');
figure(12); imshow(ImageMorph2);

ImageMorph3 = imerode(ImageMorph2, se1);
figure(13); imshow(ImageMorph3);

ImageMorph4 = imopen(ImageMorph3, se1);
figure(14); imshow(ImageMorph4);

ImageMorph5 = imerode(ImageMorph4, se1);
figure(15); imshow(ImageMorph5);

ImageMorph6 = imerode(ImageMorph5, se1);
figure(16); imshow(ImageMorph6);

ImageMorph7 = imerode(ImageMorph6, se1);
figure(17); imshow(ImageMorph7);

ImageMorph8 = imdilate(ImageMorph7, se1);
figure(18); imshow(ImageMorph8);

ImageMorph9 = imdilate(ImageMorph8, se1);
figure(19); imshow(ImageMorph9);


