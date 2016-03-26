var i,j,x,y,n,m,q:longint;
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

  j:=a[1];k:=a[2];x:=a[3];y:=a[4];
  f[0,j,k,x,y]:=q;
  for i:=1 to m do
   for j:=0 to 9 do 
    for k:=0 to 9 do
     for x:=0 to 9 do
      for y:=0 to 9 do 
      begin 
         f[i,j,k,x,y]:=f[i-1,j+1,k+1,x+1,y+1]-c[1]
      end;
end. 