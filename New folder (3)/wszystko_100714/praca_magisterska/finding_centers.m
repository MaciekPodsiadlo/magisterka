function [centroids] = finding_centers(Input)

[L, num] = bwlabel(Input, 8);
figure(); imshow(Input);
hold on;
for i = 1:num
    [r, c] = find(L == i);
    Image = bwselect(Input, c, r, 8);
%     figure(); imshow(Images(i,:,:));
    stats = regionprops(Image, 'centroid');
    centroids(i,:,:) = cat(1, stats.Centroid);
    plot(centroids(i,:,1), centroids(i,:,2), 'b*');
end

end