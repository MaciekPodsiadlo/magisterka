%informacja na temat kamery, 'matrox' to przykladowa nazwa adaptera
imaqhwinfo;
imaqhwinfo('winvideo');
%utworzenie obiektu video
vid = videoinput('winvideo');
%informacje o video source
get(vid,'Source');
%ustawienie u¿ywanego source
vid.SelectedSourceName = 'CH1';
getselectedsource('vid');
%Wyciecie zdjecia
frame = getsnapshot(vid);
%czyszczenie - zawsze u¿ywamy po zrobieniu ujecia
delete(vid);
clear vid;
