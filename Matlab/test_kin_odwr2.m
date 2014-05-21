wsp_z = 930;

table = zeros(4, 5);

points = [ %100  200;  900  400;  1000  100;  900  1600;
           %100 -200;  900 -400;  1000 -100;  800 -600;
           -100 -200; -900 -500; -1000 -100; -700 -700;  -400 -100; -900 -100];
%           -100  200; -900  400; -1000  100; -900  1600; -400  100; -900  100];
      
    Rmin = 459;
    Rmax = 949;
    y_akt = 0;
    
for i = 1:size( points, 1);
    wsp_x = points(i, 1);
    wsp_y = points(i, 2);  
    sim('test_kin_odwrotnej');
    %R = sqrt(wsp_x^2+wsp_y^2);
    %Fi = atan(wsp_y/wsp_x);
    %yMin = 513*sqrt(1-(wsp_x/513)^2);
    %yMax = 802*sqrt(1-(wsp_x/802)^2);
    table(i, :) = [points(i, 1), points(i, 2), wsp_zlaczowe(1, 1), wsp_zlaczowe(1, 4), czy_dostepne(1,1)];
end

table