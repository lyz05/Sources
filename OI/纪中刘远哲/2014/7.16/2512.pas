var n,i,j,k,m,ans,max,len:longint;
    a:array[1..3] of longint;
begin
  readln(n);
  ans:=0;max:=0;j:=0;len:=1;
  for i:=1 to n do
  begin
    inc(j);
    if j>3 then j:=j-3;
    readln(a[j]);
      if (i>3)and((a[1]=a[2]) or(a[2]=a[3])or (a[1]=a[3])) then
      begin
        writeln(a[j]);
        break;
      end;
  end;
end.
