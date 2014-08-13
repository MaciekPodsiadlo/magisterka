syms d1 sT2 cT2 p1 sT3 cT3 p2 sT4 cT4 p3 sT5 cT5 sT6 cT6 p4

A1 = [1 0 0 0; 0 0 -1 0; 0 1 0 d1; 0 0 0 1]
A2 = [-sT2 0 cT2 0; cT2 0 sT2 0; 0 1 0 p1; 0 0 0 1]
A3 = [-sT3 -cT3 0 -p2*sT3; cT3 -sT3 0 p2*cT3; 0 0 1 0; 0 0 0 1]
A4 = [sT4 cT4 0 p3*sT4; -cT4 sT4 0 -p3*cT4; 0 0 1 0; 0 0 0 1]
A5 = [cT5 0 -sT5 0; sT5 0 cT5 0; 0 -1 0 0; 0 0 0 1]
A6 = [sT6 cT6 0 0; -cT6 sT6 0 0; 0 0 1 p4; 0 0 0 1]

wynik1 = A1*A2
wynik2 = wynik1*A3
wynik3 = wynik2*A4
wynik4 = wynik3*A5
wynik5 = wynik4*A6