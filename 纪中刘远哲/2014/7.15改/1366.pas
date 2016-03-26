var n,i,j,k,max:longint;
    a:array[1..100] of longint;
    f:array[0..101,0..101] of longint;
begin
  readln(n);
  for i:=1 to n do read(a[i]);

  for i:=1 to n do f[i][i]:=a[i];
  for i:=n-1 downto 1 do
    for j:=i+1 to n do
    begin
      max:=0;
      for k:=i to j-1 do
      begin
        f[i,j]:=f[i,k]+f[k+1,j];
        if f[i,j]>max then max:=f[i,j];
      end;
      f[i,j]:=abs(a[j]-a[i])*(j-i+1);
      if f[i,j]>max then max:=f[i,j];
      f[i,j]:=max;
    end;
  writeln(f[1,n]);
end.
