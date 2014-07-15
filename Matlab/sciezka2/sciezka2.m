%% Usuniecie cienia

foreground = rgb2gray(frame8);
background = rgb2gray(frame7);

% hsvImage_foreground = rgb2hsv(frame8);
% foreground = uint8(255.*hsvImage_foreground(:,:,3));
% 
% hsvImage_background = rgb2hsv(frame7);
% background = uint8(255.*hsvImage_background(:,:,3));

% Histogram poczatkowy
hist_beginig = imhist(foreground);

foreground = int16(foreground);
background = int16(background);

substractImage = uint8(abs(foreground - background));

foreground = uint8(foreground);

% temp_substractImage = double(foreground)./double(background+1);
% wsp_substractImage = 510/max(max(temp_substractImage));
% substractImage = uint8(abs(wsp_substractImage.*temp_substractImage - wsp_substractImage));

% substractImage = uint8(foreground);

% Histogram po redukcji cienia
hist_substractImage = imhist(substractImage);

%% Wyg³adzenie

gaus_fil = fspecial('gaussian', [3 3], 0.8);
gaussianImage = imfilter(substractImage, gaus_fil);
hist_gaussianImage = imhist(gaussianImage);

wienerImage = wiener2(substractImage, [5 5]);
hist_wienerImage = imhist(wienerImage);

medianImage = medfilt2(substractImage);
hist_medianImage = imhist(medianImage);

%% Wyznaczenie konturow


% BWSobel = edge(substractImage,'sobel');

BWPrewitt = edge(substractImage,'prewitt');

BWRoberts = edge(substractImage,'roberts');

% BWLoG = edge(substractImage,'log');

% BWZeroCross = edge(substractImage,'zerocross',[]);

% BWCanny = edge(substractImage,'canny');

% bez redukcji cienia
BWSobel2 = edge(foreground,'sobel');

BWPrewitt2 = edge(foreground,'prewitt');

BWRoberts2 = edge(foreground,'roberts');

BWLoG2 = edge(foreground,'log');

BWZeroCross2 = edge(foreground,'zerocross',[]);

BWCanny2 = edge(foreground,'canny');

% wygladzenie Wiener
BWSobel3 = edge(wienerImage,'sobel');

BWPrewitt3 = edge(wienerImage,'prewitt');

BWRoberts3 = edge(wienerImage,'roberts');

BWLoG3 = edge(wienerImage,'log');

% BWZeroCross3 = edge(wienerImage,'zerocross',[]);

BWCanny3 = edge(wienerImage,'canny');

% wygldzenie gauss
BWSobel4 = edge(gaussianImage,'sobel');

BWPrewitt4 = edge(gaussianImage,'prewitt');

BWRoberts4 = edge(gaussianImage,'roberts');

% BWLoG4 = edge(gaussianImage,'log');

BWZeroCross4 = edge(gaussianImage,'zerocross',[]);

% BWCanny4 = edge(gaussianImage,'canny');

% wygldzenie mediana
BWSobel5 = edge(medianImage,'sobel');

BWPrewitt5 = edge(medianImage,'prewitt');

% BWRoberts5 = edge(medianImage,'roberts');

% BWLoG5 = edge(medianImage,'log');

% BWZeroCross5 = edge(medianImage,'zerocross',[]);

% BWCanny5 = edge(medianImage,'canny');

%% Operacje morfologiczne

LastImage = skrypt(gaussianImage);

