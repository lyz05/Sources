var n,k,i,j,max,t1,t2,maxx:longint;
    a:array[1..500] of char;
procedure swap(var x,y:char);
var t:char;
begin
  t:=x;
  x:=y;
  y:=t;
end;
procedure js;
var i,tmp:longint;
begin
  tmp:=0;
  for i:=1 to n-1 do
    if (a[i]='j') and (a[i+1]='z') then inc(tmp);
  if tmp>max then max:=tmp;
  if max=maxx then
  begin
   writeln(max);
   halt;
  end;
end;
procedure dfs(deep:longint);
var i,j:longint;
begin
  if deep>k then
  begin
    js;
    exit;
  end else
  begin
   for i:=1 to n do
     for j:=i+1 to n do
     begin
       if a[i]=a[j] then continue;
       swap(a[i],a[j]);
       js;
        dfs(deep+1);
       swap(a[i],a[j]);
     end;
  end;
end;
begin
  readln(n,k);
  t1:=0;t2:=0;
  for i:=1 to n do begin
    read(a[i]);
    if a[i]='j' then inc(t1) else inc(t2);
  end;
  if t1<t2 then maxx:=t1 else maxx:=t2;
  max:=0;
  js;
  dfs(1);
  writeln(max);
end.