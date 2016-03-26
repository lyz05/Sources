var n,w,i,j,min,tmp,weight:longint;
    a:array[1..20] of longint;
    p:array[1..20] of boolean;
procedure dfs(deep:longint);
var i,j;longint;
begin
  if deep>n then begin
    if tmp<min then min:=tmp;
    exit;
  end else 
  begin
    for i:=1 to n do 
     if not p[i] then
     begin
       if weight+a[i]>w then
       begin
         inc(tmp);
         weight:=0;
       end;
       p[i]:=true;
       inc(weight,a[i]);
        dfs(deep+1);
       dec(weight,a[i]);
       p[i]:=false;
       if weight+a[i]>w then
       begin
         dec(tmp);
         weight:=0;
       end;
     end;
  end;
end;
begin
  readln(n,w);
  for i:=1 to n do readln(a[i]);
  
  tmp:=0;min:=maxlongint;
  dfs(1);
  writeln(min);
end.