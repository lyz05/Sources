var n,i,j,tmp,ans:longint;
    a:array[0..10000,1..4] of longint;
function jz:longint;
var i:longint;
begin
  jz:=0;
  for i:=1 to n do inc(jz,a[i,a[i,4]]);
end;
procedure dfs(deep:longint);
var i,j:longint;
begin
  if deep>n then
  begin
    a[0]:=a[n];
    for i:=1 to n-1 do
    begin
      if (a[i-1,4]>a[i,4]) and (a[i+1,4]>a[i,4]) then continue;
      if (a[i-1,4]<a[i,4]) and (a[i+1,4]<a[i,4]) then continue;
      exit;
    end;
    tmp:=jz;
    if tmp>ans then ans:=tmp;
    exit;
  end else
  begin
    for i:=1 to 3 do
    begin
      a[deep,4]:=i;
      if (deep<>1) and (a[deep-1,4]=a[deep,4]) then continue;
       dfs(deep+1);
      a[deep,4]:=0;
    end;
  end;
end;
begin
  readln(n);
  for i:=1 to n do readln(a[i,1],a[i,2],a[i,3]);

  dfs(1);
  writeln(ans);
end.