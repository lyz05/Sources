var n,m,i,j:longint;
    a,c:array[1..100] of longint;
    f:array[0..100,0..1000] of longint;
function max(x,y:longint):longint;
begin
 if x>y then exit(x) else exit(y);
end;
begin

 readln(n,m);
 for i:=1 to m do readln(a[i],c[i]);

 for i:=1 to m do begin
  for j:=1 to n do
   if j>=a[i] then f[i,j]:=max(f[i-1,j],f[i-1,j-a[i]]+c[i])
   else f[i,j]:=f[i-1,j];
 end;
 writeln(f[m,n]);

end.
