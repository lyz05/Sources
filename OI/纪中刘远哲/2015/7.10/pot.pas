var n,i,j,m,ki,di:longint;
    a:array[1..200000] of integer;
procedure solve;
var i,j,k,ans,tmp:longint;
begin
 ans:=0;
 tmp:=0;
 for i:=1 to n do
  for j:=i to n+i-2 do begin
   tmp:=0;
   for k:=i to j do inc(tmp,a[k]);
   if tmp>ans then ans:=tmp;
  end;
 writeln(ans);
end;
begin
 readln(n);
 for i:=1 to n do begin
  read(a[i]);
  a[i+n]:=a[i];
 end;
 //test
 readln(m);
 for i:=1 to m do begin
  readln(ki,di);
  a[ki]:=di;
  a[ki+n]:=di;
  solve;
 end;
end.
