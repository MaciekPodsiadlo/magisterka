function [k] = Otsu_method1(histogram)

% P = zeros(1,size(histogram,1));
% m = zeros(1,size(histogram,1));
rho_b = zeros(1,size(histogram,1));

temp_P = 0;
temp_m = 0;
m_g = 0;
rho_g = 0;
total = 0;
rho_m = 0;
k = 0;

for i=1:size(histogram,1)
    m_g = m_g + i*histogram(i);
    total = total + histogram(i);
end

for i=1:size(histogram,1)
   temp_P = temp_P + histogram(i);
   P1 = temp_P;
   if P1 == 0 
       continue;
   end;
   
   temp_m = temp_m + i*histogram(i);
   m = temp_m;
   
   P2 = total - P1;
   if P2 == 0
       break;
   end
   
   m_b = m/P1;
   m_f = (m_g - m)/P2;
   
   rho_b = P1 * P2 * (m_b - m_f)^2;
%    rho_b(i) = ((m_g*P(i) - m(i))^2)/(P(i)*(1-P(i)));
%    rho_g = rho_g + ((i-m_g)^2)*histogram(i);

    if (rho_b >= rho_m)
        rho_m = rho_b;
        if rho_b == rho_m
            k = (k + i)/2;
        else
            k = i;
        end
    end
end

% [max_rho max_k] = max(rho_b);
% 
% if size(max_k, 1) > 1
%     temp = 0;
%     for i = 1:size(max_k)
%         temp = temp + max_k;
%     end
%     max_k = floor(temp/size(max_k, 1));
% end

% ni = rho_b(max_k)/rho_g;