var
  n,m,i,j:longint;
  k:array[0..21]of longint;
  a:array[0..21]of longint;
  b:array[0..21]of boolean;
  flag:boolean;
procedure make;
var
  k1:array[0..21]of longint;
begin
  fillchar(k ,sizeof(k), 0);
  k[1]:=1;
  for i:=2 to n do
  begin
    k1:=k;
    fillchar(k,sizeof(k),0);
    for j:=1 to i do
      k[j]:=k1[j]+k1[j-1];
  end;
end;

procedure dfs(dep,x:longint);
var
  i,j,st:longint;

function ck(ii:longint):boolean;
var
  i,j,l,sum:longint;
  kk:array[0..21]of longint;
  bb:array[0..21]of longint;
begin
  fillchar(kk,sizeof(kk),0);
  for i:=dep+1 to n do
    kk[i-dep]:=k[i];
  l:=n-dep;
  for i:=1 to l-1 do
    for j:=i+1 to l do
      if kk[i]>kk[j] then
      begin
        kk[0]:=kk[i];
        kk[i]:=kk[j];
        kk[j]:=kk[0];
      end;
  bb[0]:=0;
  for i:=1 to n do
    if b[i]=false then
    begin
      inc(bb[0]);
      bb[bb[0]]:=i;
    end;
  sum:=0;
  for i:=1 to l do
    sum:=sum+kk[i]*bb[i];
  if sum+x+ii*k[dep]<m then exit(false);
  sum:=0;
  for i:=1 to l do
    sum:=sum+kk[i]*bb[l-i+1];
  if sum+x+ii*k[dep]>m then exit(false);
  exit(true);
end;
begin
  if flag then exit;
  if dep=n+1 then
  begin
    if x=m then
    begin
      for j:=1 to n do write(a[j],' ');
      writeln;
      flag:=true;
    end;
    exit;
  end;
  if (dep>(n+1) div 2) then begin st:=a[n-dep+1]+1
  end else st:=1;
  for i:=st to n do
  if (not b[i])and(i*k[dep]+x<=m) then
  begin
    b[i]:=true;
    a[dep]:=i;
    if ck(i) then
      dfs(dep+1,x+i*k[dep]);
    b[i]:=false;
  end;
end;

begin
  while not seekeof do
  begin
    readln(n,m);
    if n=0 then exit;
    make;
    fillchar(b,sizeof(b),0);
    flag:=false;
    dfs(1,0);
  end;
end.
