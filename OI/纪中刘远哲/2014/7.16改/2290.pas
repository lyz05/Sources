var n,m,c:qword;
    i,j,t:longint;
function jc:qword;
var i:longint;
    jc1,jc2:qword;
begin
{  jc1:=1;
  for i:=(n-m)+1 to n do begin
    jc1:=jc1*i;
  end;
  jc2:=1;
  for i:=1 to m do begin
    jc2:=jc2*i;
  end;     }
  jc1:=1;jc2:=1;i:=n;j:=m;jc:=1;
  while (i>=n-m+1) or (j>=1) do
  begin
    jc1:=jc1*i;
    jc2:=jc2*j;
    if jc1 mod jc2=0 then
    begin
      jc1:=jc1 div jc2;
      jc2:=1;
    end;
    if i>=n-m+1 then dec(i);
    if j>=1 then dec(j);
  end;
  jc:=jc1 div jc2;
end;

begin
  readln(t);
  for i:=1 to t do
  begin
    readln(n,m);
    //c:=jc1 div jc(n-m);
    c:=jc;
    writeln(c);
  end;
end.
