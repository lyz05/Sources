const fx:array[1..8,1..2] of shortint=((0,-1),(-1,-1),(-1,0),(-1,+1),(1,0),(0,1),(1,1),(1,-1));
var n,k,i,j,l,min,tmp:longint;
    map:array[1..1000,1..1000] of char;
      f:array[0..1001,0..1001] of longint;
    x,y:array[1..40000] of longint;
{function min(x,y:longint):longint;
begin
  if x<y then exit(x) else exit(y);
end;  }
procedure ans(x1,y1:longint);
var i,min,tmp:longint;
begin
  if f[x1,y1]<>maxlongint then exit;
  for i:=1 to 8 do
  begin
    ans(x1+fx[i,1],y1+fx[i,2]);
    tmp:=f[x1+fx[i,1],y1+fx[i,2]];
    if tmp<min then min:=tmp;
  end;
  if map[x1,y1]='1' then inc(f[x1,y1]);
end;
begin
  assign(input,'1403.in');assign(output,'1403.out');
  reset(input);rewrite(output);
  readln(n,k);
  for i:=1 to n do
  begin
    for j:=1 to n do begin
      read(map[i,j]);
      f[i,j]:=maxlongint;
    end;
    readln;
  end;

  for i:=1 to n do
  begin
   val(map[1,i],f[1,i]);
   val(map[i,1],f[i,1]);
   val(map[i,n],f[i,n]);
   val(map[n,i],f[n,i]);
  end;

  for i:=1 to k do
  begin
    readln(x[i],y[i]);
    ans(x[i],y[i]);
    writeln(f[x[i],y[i]]);
  end;

  close(input);close(output);
end.
