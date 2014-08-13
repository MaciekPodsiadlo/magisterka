
%% Usuniecie cienia

% foreground = rgb2gray(frame8);
% background = rgb2gray(frame7);

hsvImage_foreground = rgb2hsv(calibration1);
foreground = uint8(255.*hsvImage_foreground(:,:,3));

hsvImage_background = rgb2hsv(frame7);
background = uint8(255.*hsvImage_background(:,:,3));

% Histogram poczatkowy
hist_beginig = imhist(foreground);

foreground = int16(foreground);
background = int16(background);

substractImage = uint8(abs(foreground - background));

% temp_substractImage = double(foreground)./double(background+1);
% wsp_substractImage = 510/max(max(temp_substractImage));
% substractImage = uint8(abs(wsp_substractImage.*temp_substractImage - wsp_substractImage));

% substractImage = uint8(foreground);

% Histogram po redukcji cienia
hist_substractImage = imhist(substractImage);

%% Fitry wygladzajace

medianImage = medfilt2(substractImage);
hist_medianImage = imhist(medianImage);

ave_fil = fspecial('average');
averageImage = imfilter(substractImage, ave_fil);
hist_averageImage = imhist(averageImage);

disk_fil = fspecial('disk', 3);
bluleringImage = imfilter(substractImage, disk_fil);
hist_bluleringImage = imhist(bluleringImage);

gaus_fil = fspecial('gaussian', [3 3], 0.8);
gaussianImage = imfilter(substractImage, gaus_fil);
hist_gaussianImage = imhist(gaussianImage);

wienerImage = wiener2(substractImage, [5 5]);
hist_wienerImage = imhist(wienerImage);

%% Filtry wyostrzajace

lap_fil = fspecial('laplacian', 0.3);
laplacianImage = imfilter(gaussianImage, lap_fil);

log_fil = fspecial('log');
logImage = imfilter(gaussianImage, log_fil);

prew_fil = fspecial('prewitt');
prewittImage = imfilter(gaussianImage, prew_fil);

sob_fil = fspecial('sobel');
sobelImage = imfilter(gaussianImage, sob_fil);

%% Binearyzacja

% przygotowanie do progowania
histogram_laplacianImage = imhist(laplacianImage);
percentile = prctile(histogram_laplacianImage, 80); %hist_Image histogram obrazu do binearyzacji
maskImage = im2bw(laplacianImage, percentile/255);
toTresholdImage = uint8(maskImage).*substractImage;
hist_toTresholdImage = imhist(toTresholdImage);
hist_toTresholdImage = hist_toTresholdImage(2:end);

% metoda Otsu

k1 = Otsu_method1(hist_toTresholdImage);

lastImage = im2bw(gaussianImage, k1/255);

%% Operacje morfologiczne

SE = strel('disk', 3);
lastImage2 = imopen(lastImage, SE);
