var n,k,i,j,max,tmp:longint;
    a:array[0..501] of char;
procedure swap(var x,y:char);
var t:char;
begin
  t:=x;
  x:=y;
  y:=t;
end;
{procedure js;
var i,tmp:longint;
begin
  tmp:=0;
  for i:=1 to n-1 do
    if (a[i]='j') and (a[i+1]='z') then inc(tmp);
  if tmp>max then begin
   max:=tmp;
  end;
end; }
procedure js(i,j,k:longint);
begin
 if k=1 then begin
  if ((a[i]='j') and (a[i+1]='z')) then dec(tmp);
  if ((a[j]='j') and (a[j+1]='z')) then dec(tmp);
  if ((a[i-1]='j') and (a[i]='z')) then dec(tmp);
  if ((a[j-1]='j') and (a[j]='z')) then dec(tmp);
 end else begin
  if ((a[i]='j') and (a[i+1]='z')) then inc(tmp);
  if ((a[j]='j') and (a[j+1]='z')) then inc(tmp);
  if ((a[i-1]='j') and (a[i]='z')) then inc(tmp);
  if ((a[j-1]='j') and (a[j]='z')) then inc(tmp);
 end;
 if tmp>max then max:=tmp;
end;
procedure dfs(deep:longint);
var i,j:longint;
begin
  if deep>k then
  begin
    exit;
  end else
  begin
   for i:=1 to n-1 do
     for j:=i+1 to n do
     begin
       if a[i]=a[j] then continue;
       js(i,j,1);
       swap(a[i],a[j]);
       js(i,j,2);
        dfs(deep+1);
       js(i,j,1);
       swap(a[i],a[j]);
       js(i,j,2);
     end;
  end;
end;
begin
  readln(n,k);
  for i:=1 to n do read(a[i]);
  max:=0;tmp:=0;
  for i:=1 to n-1 do
    if (a[i]='j') and (a[i+1]='z') then inc(tmp);
  max:=tmp;
  dfs(1);
  writeln(max);
end.
