function Luke
  pkg load symbolic;
  clear;  clc;
  p=[2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 91, 97, 101, 103, 107, 109, 113, 127];
  k=randi([5,10]);
  a(1)=2;
  deg(1)=20;

  for i=2:k
    a(i)=p(randi([1,32]));
    deg(i)=randi([18,25]);
  end
  el=max(a); n=0;
  for i=1:k
    n+=a(i)^deg(i);
  end

  while((n>2^128)&&(n<2^123))
    k=randi([5,10]);
    a(1)=2;
    deg(1)=20;
    for i=2:k
        a(i)=p(randi([1,32]));
        deg(i)=randi([18,25]);
    end
    el=max(arr);
    n=0;
    for i=1:k
      n=n+a(i)^deg(i);
    end
    %log2(n); %вычисляем логарифм по основанию 2 для x
  end

  n++; 
  %ceil(x) - округление к ближайшему целому, не меньшему, чем x
  for c=2:ceil(log2(n))
    if(mod(c^(n-1),n)==1)
        f=1;
        for i=1:k
            if(mod(c^((n-1)/p(i)),n)==1)
                f=0;
            end
        end
        if(f==1)
            t=a;
        end
    end
  end

  if(t!=0)
    disp(sym(n))
    disp("This number is prime");
  else
   disp(sym(n));
   disp("This number isn't prime");
  end
end
