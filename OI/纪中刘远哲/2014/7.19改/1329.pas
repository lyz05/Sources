var n,i,j:longint;
    a:array[0..100002] of longint;
    ans,tmp:int64;
function min(x,y:longint):longint;
begin
  if x>y then exit(y) else exit(x);
end;
function max(x,y:longint):longint;
begin
  if x>y then exit(x) else exit(y);
end;
begin
  assign(input,'1329.in');assign(output,'1329.out');
  reset(input);rewrite(output);
  readln(n);
  for i:=1 to n do read(a[i]);

  for i:=2 to n-1 do
  begin
    if (a[i]<a[i-1]) and (a[i]<a[i+1]) then
    begin
      inc(ans,min(a[i-1],a[i+1])-a[i]);
      a[i]:=min(a[i-1],a[i+1]);
    end;
    if (a[i]>a[i-1]) and (a[i]>a[i+1]) then
    begin
      inc(ans,a[i]-max(a[i-1],a[i+1]));
      a[i]:=max(a[i-1],a[i+1]);
    end;
    inc(ans,abs(a[i]-a[i-1]));
  end;
  inc(i);
  inc(ans,abs(a[i]-a[i-1]));
  writeln(ans);
  close(input);close(output);
end.
