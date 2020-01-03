var n,i,j,k,n2,ans,step:longint;
    p:array[1..1025,1..1025]of integer;
    d:array[0..11,0..1025] of real;
function mu(x,m:longint):longint;
var i:longint;
begin
  mu:=1;
  for i:=1 to m do mu:=mu*x
end;
begin
  readln(n);
  n2:=mu(2,n);
  for i:=1 to n2 do
    for j:=1 to n2 do
      read(p[i,j]);

  for j:=1 to n2 do d[0,j]:=1;
  for i:=1 to n do
    for j:=1 to n2 do
    begin
      step:=(j-1) div mu(2,i)*mu(2,i);
      if step+mu(2,i-1)>=j then inc(step,mu(2,i-1));
      //d[i,j]:=d[i-1,j]*sum(d[i-1,k]*p[j,k]/100)
      for k:=step+1 to step+mu(2,i-1) do d[i,j]:=d[i,j]+d[i-1,k]*p[j,k]/100;
      d[i,j]:=d[i-1,j]*d[i,j];
    end;
  ans:=1;
  for i:=2 to n2 do
  if d[n,i]>d[n,ans] then ans:=i;
  writeln(ans);

end.
