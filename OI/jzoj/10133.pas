var
   i,j,n,s,x,y,m:longint;
   f:array[0..10000] of boolean;
function song(x,y:longint):longint;
var
   r:longint;
begin
   r:=x mod y;
   while r<>0 do
   begin
      x:=y;
      y:=r;
      r:=x mod y;
   end;
   exit(y);
end;
begin
   readln(x,y);
   m:=y div x;
   for i:=trunc(sqrt(m)) downto 1 do
   begin
       if m mod i=0 then
          if song(i,m div i)=1 then
          begin
             writeln((m div i-i)*x);
             break;
          end;
   end;
end.
