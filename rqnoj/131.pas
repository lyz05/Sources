var n,i:longint;
function ss(x:longint):boolean;
var j:longint;
begin
 ss:=true;
 for j:=2 to trunc(sqrt(x)) do if x mod j=0 then ss:=false;
end;
procedure gd(x:longint);
var j:longint;
begin
 for j:=2 to x div 2 do
  if ss(j) and (ss(x-j)) then begin
    writeln(x,'=',j,'+',x-j);
    exit;
  end;
end;
begin
 readln(n);
 for i:=2 to n div 2 do gd(i*2);
end.
