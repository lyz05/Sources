var n,m,i,j,tmp,start:longint;
    sum,f:array[0..2000000] of longint;
begin
  readln(n,m);
  f[0]:=m;
  for i:=1 to n do
  begin
    read(tmp);
    sum[i]:=sum[i-1]+tmp;
    for j:=start to i-1 do
    begin
      if f[j]>=i*100 then
      begin
        start:=j;
        f[i]:=f[j]+sum[i]-sum[j]-i*100;
        break;
      end;
    end;
  end;
  writeln(f[n]);
end.