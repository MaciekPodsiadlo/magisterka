
wsp_z = 720 + 95 + 40 + 75;  %z = wysokosc stolu + dlugosc ostatniego zlacza + dlugosc znacznika + pozostalosc chwytaka = 930 mm



% for wsp_x = -950:1700
%     for wsp_y = -892:950
%         sim('test_kin_odwrotnej');
%     end
% end

wsp_x = 500;
wsp_y = 400;
www= sim('test_kin_odwrotnej')
