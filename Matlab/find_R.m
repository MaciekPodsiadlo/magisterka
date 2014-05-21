fi2 = -40:0.1:40;
fi3 = -25:0.1:40;
table = zeros(length(fi2)*length(fi3), 4);

for i = 1:length(fi2)
     for j = 1:length(fi3) %i*length(fi3)+1:(i+1)*length(fi3)
         if (abs(fi2(i) - fi3(j)) <= 40)
             z = 670*sin(-degtorad(fi3(j))) + 450*sin(3.14159/2 - degtorad(fi2(i))) + 700;
             R = 450*sin(degtorad(fi2(i)))+ 670*cos(degtorad(fi3(j)));
             table((i-1)*length(fi3)+j,:) = [fi2(i), fi3(j), R, round(z)];
         end
     end
end

%table2 = sortrows(table, 4);
ind = find(table(:,4));
table = table(ind,:);
z_min = min(table(:,4));
z_max = max(table(:,4));
table_end = zeros(z_max - z_min, 3);

for k = 1:z_max-z_min
    ind = find(table(:,4) == k+z_min);
    temp_table = table(ind, :);
    table_end(k, :) = [temp_table(1,4), min(temp_table(:,3)), max(temp_table(:,3))];
end

figure(1);
plot(table_end(:,1),table_end(:,2));
hold on;
plot(table_end(:,1),table_end(:,3));