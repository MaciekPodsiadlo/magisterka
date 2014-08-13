function BWfinal = skrypt(I)

[BWs, threshold] = edge(I, 'log');
fudgeFactor = 1.4;
BWs = edge(I,'log', threshold * fudgeFactor);

se90 = strel('line', 3, 80);
se0 = strel('line', 3, 0);

BWsdil = imdilate(BWs, [se90 se0]);

BWdfill = imfill(BWsdil, 'holes');

seD = strel('disk',3);
BWfinal = imerode(BWdfill,seD);
BWfinal = imerode(BWfinal,seD);

end