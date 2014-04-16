function [Output] = image_filtering(Input, option)
% Filtracja obrazu
% Wybór opcji:
% 1 - filtr medianowy
% 2 - filtr usredniajacy
% 3 - filtr rozmazujacy (dysk)
% 4 - filtr gaussowski
% 5 - filtr laplacowski
% 6 - filtr logarytmiczny
% 7 - filtr prewitta
% 8 - filtr sobela
% 9 - filtr wienera

switch option
    case 1
        Output = medfilt2(Input, [5 5]);
    case 2
        ave_fil = fspecial('average');
        Output = imfilter(Input, ave_fil);
    case 3 
        disk_fil = fspecial('disk', 3);
        Output = imfilter(Input, disk_fil);
    case 4
        gaus_fil = fspecial('gaussian', [3 3], 0.3);
        Output = imfilter(Input, gaus_fil);
    case 5
        lap_fil = fspecial('laplacian', 0.6);
        Output = imfilter(Input, lap_fil);
    case 6
        log_fil = fspecial('log');
        Output = imfilter(Input, log_fil);
    case 7
        prew_fil = fspecial('prewitt');
        Output = imfilter(Input, prew_fil);
    case 8
        sob_fil = fspecial('sobel');
        Output = imfilter(Input, sob_fil);
    case 9
        Output = wiener2(Input, [5 5]);
    otherwise
        Output = Input;
end

% figure();
% imshow(Output);

end