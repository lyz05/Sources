var n,k,i,j:longint;
function factor(n,k:longint):longint;
var i:longint;
begin
 factor:=0;
 for i:=1 to trunc(sqrt(n)) do begin
  if n mod i=0 then inc(factor,2);
 end;
end;
begin
end;
begin
 readln(k);
 for n:=1 to 20000 do 
  if factor(n,k) then begin
   writeln(n);
   exit;
  end;
 writeln('NO SOLUTION');

end.