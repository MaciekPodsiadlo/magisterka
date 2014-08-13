function [] = toHSV(In)

    OutMatlab = rgb2hsv(In);
    Red   = double(In(:,:,1)); 
    Green = double(In(:,:,2)); 
    Blue  = double(In(:,:,3));

    L = 0.2126*Red + 0.7152*Green + 0.0722*Blue;
    S = max(max(Red,Green),Blue) - min(min(Red,Green),Blue);

    Hprim = acos((Red-0.5*Green-0.5*Blue)./sqrt(Red.^2 + Green.^2 + Blue.^2 -Red.*Green - Red.*Blue -Blue.*Green));

    if(Blue>Green)
        H = 2*pi-Hprim;
    else
        H = Hprim;
    end
    
    Out(:,:,1) = H;
    Out(:,:,2) = L;
    Out(:,:,3) = S;
    
    imshow(In);
    figure();
    imshow(Out);
    figure()
    imshow(OutMatlab);
    figure();
    imshow(H);
    figure();
    imshow(OutMatlab(:,:,1));
    figure();
    imshow(S);
    figure();
    imshow(OutMatlab(:,:,2));
    figure();
    imshow(L);
    figure();
    imshow(OutMatlab(:,:,3));
    figure();
    imshow(rgb2grey(In));
end