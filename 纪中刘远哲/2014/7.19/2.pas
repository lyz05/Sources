var n,m,i,j,min:longint;
    x:qword;
    z,y:int64;
    a,b:array[1..2000000] of longint;
procedure dfs(deep:longint);
var i,j,jl:longint;
begin
  if m>=n*100 then begin
    if min<y then y:=min;
    exit;
  end else begin
    for i:=1 to m div 100 do
    begin
      if a[i]=0 then continue;
      m:=m-i*100;
      for j:=i downto 1 do
       if a[j]=0 then break else
       begin
         m:=m+a[j];
         a[j]:=0;
       end;
      jl:=j;
      inc(min,i*100);
       dfs(deep+1);
      dec(min,i*100);
      a[i]:=jl;
      for j:=i downto jl+1 do
      begin
       a[j]:=b[j];
       m:=m-a[j];
      end;
      m:=m+i*100;
    end;
  end;
end;
begin
  x:=0;y:=0;
  readln(n,m);
  for i:=1 to n do
  begin
    read(a[i]);
    inc(x,a[i]);
  end;
  inc(x,m);
  dec(x,n*100);
  y:=maxlongint;
  b:=a;
  dfs(1);
  z:=x-y;
  writeln(z);
end.
