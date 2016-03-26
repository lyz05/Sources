const fx:array[1..8,1..2] of shortint=((0,-1),(-1,-1),(-1,0),(-1,+1),(1,0),(0,1),(1,1),(1,-1));
var n,k,i,j,l,min,tmp:longint;
    map:array[1..1000,1..1000] of char;
      f:array[0..1001,0..1001] of longint;
    x,y:array[1..40000] of longint;
{function min(x,y:longint):longint;
begin
  if x<y then exit(x) else exit(y);
end;  }
begin
  assign(input,'1403.in');assign(output,'1403.out');
  reset(input);rewrite(output);
 readln(n,k);
 for i:=1 to n do
 begin
  for j:=1 to n do read(map[i,j]);
  readln;
 end;
 for i:=1 to k do readln(x[i],y[i]);

 for i:=1 to n do
   for j:=1 to n do
   begin
    min:=maxlongint;tmp:=0;
    for l:=1 to 4 do
    begin
     tmp:=f[i+fx[l,1],j+fx[l,2]];
     if tmp<min then min:=tmp;
    end;
     f[i,j]:=min;
    if map[i,j]='1' then inc(f[i,j]);
   end;

  for i:=n downto 1 do
   for j:=n downto 1 do
   begin
    min:=maxlongint;tmp:=0;
    for l:=5 to 8 do
    begin
     tmp:=f[i+fx[l,1],j+fx[l,2]];
     if tmp<min then min:=tmp;
    end;
    if map[i,j]='1' then dec(f[i,j]);
    if f[i,j]>min then f[i,j]:=min;
    if map[i,j]='1' then inc(f[i,j]);
   end;

  for i:=1 to n do
   for j:=1 to n do
   begin
    min:=maxlongint;tmp:=0;
    for l:=1 to 8 do
    begin
     tmp:=f[i+fx[l,1],j+fx[l,2]];
     if tmp<min then min:=tmp;
    end;
    if map[i,j]='1' then dec(f[i,j]);
    if f[i,j]>min then f[i,j]:=min;
    if map[i,j]='1' then inc(f[i,j]);
   end;

 for i:=1 to k do write(f[x[i],y[i]],' ');
  close(input);close(output);
end.
