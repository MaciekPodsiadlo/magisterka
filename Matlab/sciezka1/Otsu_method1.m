function [max_k] = Otsu_method1(histogram)

P = zeros(1,size(histogram,1));
m = zeros(1,size(histogram,1));
rho_b = zeros(1,size(histogram,1));

temp_P = 0;
temp_m = 0;
for i=1:size(histogram,1)
   temp_P = temp_P + histogram(i);
   P(i) = temp_P;
   temp_m = temp_m + i*histogram(i);
   m(i) = temp_m;
end

m_g = m(end);
rho_g = 0;

for i=1:size(histogram,1)
   rho_b(i) = ((m_g*P(i) - m(i))^2)/(P(i)*(1-P(i)));
   rho_g = rho_g + ((i-m_g)^2)*histogram(i);
end

[max_rho max_k] = max(rho_b);

if size(max_k, 1) > 1
    temp = 0;
    for i = 1:size(max_k)
        temp = temp + max_k;
    end
    max_k = floor(temp/size(max_k, 1));
end

ni = rho_b(max_k)/rho_g;