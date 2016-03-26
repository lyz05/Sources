var i,j:longint;
    g,m,n,k,x:qword;
function jc:qword;
var i:longint;
begin
  jc:=1;
  for i:=n-m+1 to n do jc:=jc*i;
end;
begin
  readln(k,x);
  g:=1;
  for i:=1 to x do g:=g*x mod 1000;
  m:=g-k;
  n:=k;
  writeln(jc);
end.
