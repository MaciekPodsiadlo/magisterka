
wsp_z = 720 + 95 + 40 + 75;  %z = wysokosc stolu + dlugosc ostatniego zlacza + dlugosc znacznika + pozostalosc chwytaka = 930 mm

x = -849:2050;
y = -849:850;
table = zeros(length(x), length(y), 5);

for wsp_x = -10:10
    for wsp_y = -10:10
        sim('test_kin_odwrotnej');
        table(wsp_x-min(x), wsp_y-min(y), :) = [wsp_zlaczowe, czy_dostepne];
    end
end
