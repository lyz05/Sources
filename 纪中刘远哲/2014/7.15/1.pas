var n,i,j,k,x,y,ans,max1:longint;
    a:array[1..101] of longint;
    f:array[0..101,0..101] of longint;
function max(x,y:longint):longint;
begin
  if x>y then exit(x) else exit(y);
end;
procedure dfs(deep,x,y:longint);
begin
  if (y<=0) or (x<=0) or (x>y) or (deep>n) then
  begin
   if ans>max1 then max1:=ans;
   exit;
  end else
  begin
    for i:=x to y do
     for j:=i to y do
     begin
      inc(ans,f[i,j]);
      dfs(deep+1,j+1,y);
      dec(ans,f[i,j]);
     end;
    for i:=y downto x do
     for j:=y downto i do
     begin
      inc(ans,f[i,j]);
      dfs(deep+1,x,i-1);
      dec(ans,f[i,j]);
     end;
  end;
end;
begin
  readln(n);
  for i:=1 to n do read(a[i]);

  for i:=1 to n do f[i,i]:=a[i];
  for j:=1 to n do f[1,j]:=max(f[1,j-1]+a[j],abs(a[j]-a[1])*j);
  for i:=1 to n do f[i,n]:=max(f[i+1,n]+a[i],abs(a[n]-a[i])*(n-i+1));
  for i:=2 to n do
   for j:=i+1 to n-1 do
   begin
     f[i,j]:=max(abs(a[j]-a[i])*(j-i+1),f[i,j-1]+a[j]);
   end;
   ans:=0;max1:=0;
   dfs(1,1,n);


  {for i:=1 to n do
    for j:=1 to n do
      for k:=j to n do   //??
      begin
        f[i,j,k]:=f[i-1,1,j-1]+f[i-1,k+1,n];
        if j=k then inc(f[i,j,k],a[j])
          else inc(f[i,j,k],abs(a[k]-a[j])*(k-j+1));
      end;}
  writeln(max1);
end.
