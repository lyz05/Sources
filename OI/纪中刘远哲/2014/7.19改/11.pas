var i,j,k,l,m,n,oo,a:longint;
    f,sum:Array[0..2000000]of longint;
begin
  readln(n,m);
  f[0]:=m;
  for i:=1 to n do
  begin
    read(a);
    sum[i]:=sum[i-1]+a;
    for j:=oo to i-1 do
      if f[j]>=i*100 then
      begin
        oo:=j;
        f[i]:=f[j]+sum[i]-sum[j]-i*100;
        break;
      end;
  end;
  writeln(f[n]);
end.
