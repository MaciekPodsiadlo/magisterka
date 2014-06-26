function [k1_final, k2_final] = Otsu_method2(histogram)

hist_length = size(histogram,1);

P1 = zeros(1,hist_length);
m1 = zeros(1,hist_length);
P2 = zeros(hist_length, hist_length);
m2 = zeros(hist_length, hist_length);
rho_b = zeros(hist_length, hist_length);

temp_P1 = 0;
temp_m1 = 0;
for i=1:hist_length
    temp_P1 = temp_P1 + histogram(i);
    P1(i) = temp_P1;
    temp_m1 = temp_m1 + i*histogram(i);
    m1(i) = temp_m1/P1(i);
    temp_P2 = 0;
    temp_m2 = 0;
    for j = i+1:hist_length;
       temp_P2 = temp_P2 + histogram(i);
       P2(i,j) = temp_P2;
       temp_m2 = temp_m2 + i*histogram(i);
       m2(i,j) = temp_m2/P2(i,j);
    end
end

m_g = temp_m1;
rho_g = 0;

for i=1:hist_length
    for j = i+1:hist_length
        rho_b(i,j) = P1(i)*(m1(i)-m_g)^2 + P2(i,j)*(m2(i,j)-m_g)^2+((-P1(i)*m1(i)-P2(i,j)*m2(i,j))^2)/(1-P1(i)-P2(i,j));
    end
    rho_g = rho_g + ((i-m_g)^2)*histogram(i);
end

[k1 k2] = find(rho_b == max(max(rho_b)));

if length(k1) > 1
    temp_k1 = 0;
    temp_k2 = 0;
    for i = 1:length(k1)
        temp_k1 = temp_k1 + k1(i);
        temp_k2 = temp_k2 + k2(i);
    end
    temp_k1 = floor(temp_k1/length(k1));
    temp_k2 = floor(temp_k2/length(k2));
    if k1 < k2
        k1_final = temp_k1;
        k2_final = temp_k2;
    else
        k1_final = k1(1);
        k2_final = k2(1);
    end
else
    k1_final = k1;
    k2_final = k2;
end

ni = rho_b(k1_final, k2_final)/rho_g;