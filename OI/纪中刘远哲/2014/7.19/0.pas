var n,i,j:longint;
    a:array[0..100002] of longint;
    ans,tmp:int64;
procedure swap(var x,y:longint);
var t:longint;
begin
  t:=x;
  x:=y;
  y:=t;
end;
procedure dfs(deep:longint);
var i,j,jl,k,l:longint;
begin
  if deep>n then
  begin
    if tmp<ans then ans:=tmp;
    exit;
  end else
  begin
    if a[deep-1]<a[deep+1] then
    begin
      k:=a[deep-1];l:=a[deep+1];
    end else
    begin
      k:=a[deep+1];l:=a[deep-1];
    end;
    if deep=1 then begin
      k:=a[deep];
      l:=a[deep+1];
    end else
    if deep=n then begin
      k:=a[deep-1];
      l:=a[deep];
    end;
    if k>l then swap(k,l);
    for i:=k to l do
    begin
      jl:=a[deep];
      if deep<>1 then
       inc(tmp,abs(i-a[deep-1]));
      inc(tmp,abs(i-a[deep]));
      a[deep]:=i;
        dfs(deep+1);
      a[deep]:=jl;
      dec(tmp,abs(i-a[deep]));
      if deep<>1 then
       dec(tmp,abs(i-a[deep-1]));
    end;
  end;
end;
begin
  readln(n);
  for i:=1 to n do read(a[i]);
  ans:=maxlongint;tmp:=0;
  dfs(1);
  writeln(ans);
end.
