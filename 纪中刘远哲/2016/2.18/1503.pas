var
  n,m,a,b,x,xx,y,i,sum:longint;
  c,f:array[1..50000] of longint;
function getfather(x:longint):longint;
begin
  if f[x]=x then getfather:=x
  else
    begin
    getfather:=getfather(f[x]);
    c[x]:=(c[x]+c[f[x]]) mod 300;
    f[x]:=getfather;
    end;
end;
begin
	assign(input,'1503.in');reset(input);
  readln(n,m);
  sum:=0;
  for i:=1 to n do
    f[i]:=i;
  for i:=1 to m do
    begin
    readln(a,b,xx);
    x:=getfather(a);
    y:=getfather(b);
    if x=y then
      begin
      if (c[b]-c[a]+300) mod 300<>xx then inc(sum);
      end
    else
      begin
      f[y]:=a;
      c[y]:=(xx-c[b]+300) mod 300;
      end;
    end;
   writeln(sum);
end.

