var n,m,i,j,min:longint;
    a,f:array[1..100001] of longint;
    q:array[1..50000] of longint;
    p:array[1..100001] of boolean;
procedure dfs(deep,k:longint);
var i,j:longint;
begin
  if k=n+1 then
  begin
    deep:=deep-1;
    if deep<min then min:=deep;
    exit;
  end else
  begin
    if f[k]<>0 then
    begin
      dfs(deep+f[k],n+1);
      exit;
    end;
    p[k]:=true;
    for i:=1 to n+1 do
     if i<>k then
     begin
       if (i>k) and (i-k>a[k]) then continue;
       if p[i] then continue;
        dfs(deep+1,i);
     end;
    p[k]:=false;
  end;
end;
begin
  readln(n,m);
  for i:=1 to n do read(a[i]);
  for i:=1 to m do read(q[i]);

  for i:=n downto 1 do
   if (n-i+1)<a[i] then f[i]:=1;
  for i:=1 to m do
  begin
    min:=maxlongint;
    dfs(1,q[i]);
    f[q[i]]:=min;
    write(min,' ');
  end;
end.
