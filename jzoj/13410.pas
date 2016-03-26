var
  a,g1,g2:array[1..200000]of longint;
  f:array[1..300000]of longint;
  i,j,n,m,k:longint;
  t,ans,x,y:int64;

procedure add(x:longint);
begin
  while x<=n do begin
    inc(f[x]);
    x:=x+(x and -x);
  end;
end;

function find(x:longint):longint;
begin
  find:=0;
  while x>0 do begin
    find:=find+f[x];
    x:=x-(x and -x);
  end;
end;

begin

  readln(n);
  for i:=1 to n do begin
    read(x);
    a[x]:=i;
  end;
  fillchar(f,sizeof(f),0);
  for i:=1 to n do begin
    add(a[i]);
    x:=find(a[i]-1);
    y:=n-a[i]-find(n)+find(a[i]);
    ans:=ans+y*(y-1)div 2-y*x;
  end;
  writeln(ans);

end.
