function [Output] = to_Binary (Input)
% Wyciecie tla i przekszta³cenie obrazu w obiekt binarny

[counts,x] = imhist(Input);
stem(x,counts);

[max_hist, max_hist_locs] = max(counts);
counts2 = max_hist - counts;
[peaks, locs] = findpeaks(counts2, 'MINPEAKHEIGHT', 0.97*max_hist);
locs_left = find(locs < max_hist_locs);
locs_right = find(locs > max_hist_locs);
treshold_left = x(locs(locs_left(end)));
treshold_right = x(locs(locs_right(1)));

ImageBW_1 = im2bw(Input, treshold_left);
ImageBW_2 = im2bw(Input, treshold_right);
Output = imadd(~ImageBW_1,ImageBW_2);

% figure(); 
% imshow(Output);

end