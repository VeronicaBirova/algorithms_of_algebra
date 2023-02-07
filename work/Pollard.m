function Pollard
  clear;  clc;
  n=input('Enter a composite number: ');
  p=2;  i=2;  k=1;

  d0(1)=gcd(p-1,n); %наибольший общий делитель
  d1(k)=n/d0(k);
  while(gcd(p-1,n)==1)
    p=rem(p^i,n); %остаток от деления p^i на n
    i++;
    d0(k)=gcd(p-1,n);
    d1(k)=n/d0(k);
    if((isprime(d0(k))==true)&&(isprime(d1(k))==true))
      disp(d0)
      disp(d1)
    elseif((isprime(d0(k))==true)&&(isprime(d1(k))==false))%||...
           %((isprime(d0(k))==false)&&(isprime(d1(k))==true)))%||...
           %((isprime(d0(k))==false)&&(isprime(d1(k))==false)))
        n=d1(k);
        p=2;  i=2;  k++;
        %disp(d0)
        %disp(d1)
    end
  end
  %disp(d0)
  %disp(d1)
end

