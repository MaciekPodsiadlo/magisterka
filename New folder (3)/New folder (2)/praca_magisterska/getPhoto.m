function frame = getPhoto()
% Uruchamia kamere, pobiera i zapisuje jedna klatke z kamery oraz zamyka
% polaczenie
vid = videoinput('winvideo',1,'RGB555_768x576');
frame = getsnapshot(vid);
delete(vid);
clear vid;