var i,j,n,m,q:longint;
    f:array[0..1000,0..9,0..9,0..9,0..9] of longint;
    a,c:array[1..4] of longint;
function max(x,y:longint):longint;
begin
  if x>y then exit(x) else exit(y);
end;
begin
  readln(n,m,q);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do read(c[i]);

  f[0,a[1],a[2],a[3],a[4]]:=1;
  for i:=
end. 