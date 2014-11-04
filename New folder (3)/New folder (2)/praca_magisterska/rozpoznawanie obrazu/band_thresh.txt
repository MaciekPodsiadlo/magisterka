function [picture] = band_thresh(im, lowband, highband)

picture = zeros(size(im));

[vec col] = find(im < lowband | im > highband);
for i = 1:length(vec)
        picture(vec(i),col(i)) = 1;
end

imshow(picture);