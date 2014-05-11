wsp_z = 930;

table = zeros(20, 8);

points = [100   200; 700   500; 1000   100; 500   1700;
          100  -200; 700  -500; 1000  -100; 500  -500;
          -100 -200; -700 -500; -780 -50;  -500 -500; -490 -100; -600 -100;
          -100  200; -700  500; -780  50;  -500  500; -490  100; -600  100];

for i = 1:size( points, 1);
    wsp_x = points(i, 1);
    wsp_y = points(i, 2);
    sim('test_kin_odwrotnej');
    R = sqrt(wsp_x^2+wsp_y^2);
    Fi = atan(wsp_y/wsp_x);
    yMin = 513*sqrt(1-(wsp_x/513)^2);
    yMax = 802*sqrt(1-(wsp_x/802)^2);
    table(i, :) = [points(i, 1), points(i, 2), wsp_zlaczowe(1, 1), wsp_zlaczowe(1, 4), czy_dostepne(1,1), yMin, yMax, Fi];
end

table