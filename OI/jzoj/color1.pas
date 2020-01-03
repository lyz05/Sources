var n,t,i:longint;
function solve:int64;
var t,ans,x,y,z:int64;
    tmp:longint;
begin
 solve:=0;
 if n mod 2=0 then tmp:=2 else tmp:=-2;
 x:=2;y:=n;z:=12345678;
 ans:=1; t:=x;
 while y>0 do
  begin
    if odd(y) then ans:=ans*t mod z;
    y:=y div 2;
    t:=t*t mod z;
  end;
 solve:=ans+tmp;
end;
begin
 assign(input,'color.in');assign(output,'color.out');
 reset(input);rewrite(output);
 readln(t);
 for i:=1 to t do begin
  readln(n);
  if n=1 then writeln(3) else writeln(solve);
 end;
 close(input);close(output);
end.
