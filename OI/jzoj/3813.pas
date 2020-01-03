var n,m,i,j,k:longint;
    a,p:array[0..1001,0..1001] of longint;
    b:array[1..2002] of longint;
procedure print;
var i:longint;
begin
  for i:=1 to m+n-1 do write(b[i],' ');
  halt;
end;
procedure dfs(deep,x,y:longint);
var i,j,x1,y1:longint;
begin
  inc(k);b[k]:=a[x,y];
  if deep=m+n-1 then print
  else begin
    x1:=x;
    y1:=y;
    if (p[x+1,y]=0) and (p[x,y+1]=0) then begin
      b[k]:=0;dec(k);
      exit;
    end;
    if (p[x+1,y]=1) and (p[x,y+1]=1) then
      if a[x+1,y]>a[x,y+1] then inc(y1) else inc(x1);
    if (p[x+1,y]=1) and (p[x,y+1]=0) then inc(x1);
    if (p[x+1,y]=0) and (p[x,y+1]=1) then inc(y1);

    dfs(deep+1,x1,y1);

  end;
  b[k]:=0;dec(k);
end;
begin
  //assign(input,'3813.in');reset(input);
  k:=0;
  readln(n,m);
  for i:=1 to n do
    for j:=1 to m do read(a[i,j]);

  p[n,m]:=1;
  for i:=n downto 1 do
    for j:=m downto 1 do
      if p[i,j]=1 then begin
        if a[i-1,j]<>0 then p[i-1,j]:=1;
        if a[i,j-1]<>0 then p[i,j-1]:=1;
      end;

  dfs(1,1,1);
  writeln('Oh,the life is too difficult!');
  //close(input);
end.
1 3 4
7 0 9
5 6 8
