function frame = getPhoto()
% Uruchamia kamere, pobiera i zapisuje jedna klatke z kamery oraz zamyka
% polaczenie
vid = videoinput('winvideo',1);
frame = getsnapshot(vid);
delete(vid);
clear vid;