function [xi, yi, R ] = FindCircle( I )
%Znajdowanie okregu

odstep = 40;

[y,x]=find(I);
[sy,sx]=size(I);
totalpix = length(x);

% maxRx = ceil((max(x) - min(x))/2);
% maxRy = ceil((max(y) - min(y))/2);
% if maxRx > maxRy
%     maxR = maxRx + odstep;
%     minR = maxRy - odstep;
% else
%     maxR = maxRy + odstep;
%     minR = maxRx - odstep;
% end
% if minR < 1
%     minR = 1;
% end

minR = 40;
maxR = 60;
 R = minR:maxR;     %Mozna zoptymalizowac skrypt ograniczaj¹c R od do³u, ale ja nie wiem jak

HM = zeros(sy,sx,maxR-minR);
R2 = R.^2;
sz = sy*sx;

try
for cnt = 1:totalpix
    for cntR = 1:maxR-minR
        b = 1:sy;
        a = (round(x(cnt) - sqrt(R2(cntR) - (y(cnt) - [1:sy]).^2)));
        b = b(imag(a)==0 & a>0);
        a = a(imag(a)==0 & a>0);
        ind = sub2ind([sy,sx],b,a);
        HM(sz*(cntR-1)+ind) = HM(sz*(cntR-1)+ind) + 1;
    end
end

    

for cnt = 1:maxR-minR
    H(cnt+minR) = max(max(HM(:,:,cnt)));
end

[maxval, maxind] = max(H);
[B,A] = find(HM(:,:,maxind-minR)==maxval);

catch err
    fprintf(strcat('Wspolrzedne bledu: ',num2str(cntR), 'vv ', num2str(cnt)));
    rethrow(err);
end

% imshow(I); hold on;
% plot(mean(A),mean(B),'xr')
% text(mean(A),mean(B),num2str(maxind),'color','green')
% t = 0:pi/20:2*pi;
% xdata = (mean(A)+maxind.*cos(t))';
% ydata = (mean(B)+maxind.*sin(t))';
% plot(xdata,ydata);

xi = mean(A);
yi = mean(B);
R = maxind;

end

%function pbDetect_Callback(hObject, eventdata, handles)
% hObject    handle to pbDetect (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% 1. Reading image 
%I = handles.S;
%I =im2bw(I);
%[y,x]=find(I);
%[sy,sx]=size(I);

% 2. Find all the require information for the transformatin. the 'totalpix'
% is the numbers of '1' in the image, while the 'maxrho' is used to find
% the size of the Hough Matrix
%totalpix = length(x);

% 3. Preallocate memory for the Hough Matrix. Try to play around with the
% R, or the radius to see the different results.
%HM = zeros(sy*sx,1);
%R = get(handles.sldR,'value');
%R = max(x) - min(x)+20;
%R2 = R^2;

% 4. Performing Hough Transform. Notice that no "for-loop" in this portion
% of code.

%%
% a. Preparing all the matrices for the computation without "for-loop"
%b = 1:sy;
%a = zeros(sy,totalpix);

%y = repmat(y',[sy,1]);
%x = repmat(x',[sy,1]);

%b1 = repmat(b',[1,totalpix]);
%b2 = b1;
%%
% b. The equation for the circle
%a1 = (round(x - sqrt(R2 - (y - b1).^2)));
%a2 = (round(x + sqrt(R2 - (y - b2).^2)));

%%
% c. Removing all the invalid value in matrices a and b
%b1 = b1(imag(a1)==0 & a1>0 & a1<sx);
%a1 = a1(imag(a1)==0 & a1>0 & a1<sx);
%b2 = b2(imag(a2)==0 & a2>0 & a2<sx);
%a2 = a2(imag(a2)==0 & a2>0 & a2<sx);

%ind1 = sub2ind([sy,sx],b1,a1);
%ind2 = sub2ind([sy,sx],b2,a2);

%ind = [ind1; ind2];

%%
% d. Reconstruct the Hough Matrix
%val = ones(length(ind),1);
%data=accumarray(ind,val);
%HM(1:length(data)) = data;
%HM2 = reshape(HM,[sy,sx]);

% 5. Showing the Hough Matrix
%axes(handles.axes2);
%imshow(HM2,[]);

%%
% 6. Finding the location of the circle with radius of R
%[maxval, maxind] = max(max(HM2));
%[B,A] = find(HM2==maxval);
%axes(handles.axes3);
%imshow(I); hold on;
%plot(mean(A),mean(B),'xr')

%t = 0:pi/20:2*pi;
%xdata = (mean(A)+get(handles.sldR,'value').*cos(t))';
%ydata = (mean(B)+get(handles.sldR,'value').*sin(t))';
%plot(xdata,ydata);


%set(handles.txtX,'string',mean(A));
%set(handles.txtY,'string',mean(B));
%set(handles.txtVal,'string',maxval);
%end