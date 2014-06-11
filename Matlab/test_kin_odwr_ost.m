clear all;
clc;

table = zeros(361, 201, 5);
      
    Rmin = 461;
    Rmax = 947;
    y_akt = 0;
    wsp_z = 930;
    k = 1;
    for i = 1:size(table, 1);
        for j = 1:size(table, 2);
            wsp_x = (j-100)*10;
            wsp_y = (i-100)*10;  
            sim('test_kin_odwrotnej_ostateczne');
            table(i, j, :) = [wsp_zlaczowe(1, 1), wsp_zlaczowe(1, 2), wsp_zlaczowe(1, 3), wsp_zlaczowe(1, 4), czy_dostepne(1,1)];
            k = k + 1
        end
    end
    
    table;