const x=1;y=2;
      f:array[1..8,1..2] of integer=((-1,0),(1,0),(0,-1),(0,+1),(-1,-1),(+1,+1),(-1,+1),(+1,-1));
var n,k,i,j,tmp,min,len:longint;
    map:array[1..1000,1..1000] of char;
    zb:array[1..40000,1..2] of longint;
    p:array[1..100000,1..2] of longint;
procedure dfs(deep,x,y:longint);
var i,j:longint;
begin
  if (deep>(n*n))or((tmp>min)and(min<>maxlongint))then exit;
  if (x=1)or(y=1)or(x=n)or(y=n) then
  begin
    if tmp<min then min:=tmp;
    exit;
  end else
  begin
    if map[x,y]='1' then inc(tmp);
    for i:=1 to 8 do
    begin
      for j:=1 to len+1 do
       if (p[j,1]=x+f[i,1]) and (p[j,2]=y+f[i,2]) then break;
      if j<>len+1 then continue;
      inc(len);p[len,1]:=x;p[len,2]:=y;
       dfs(deep+1,x+f[i,1],y+f[i,2]);
      p[len,1]:=0;p[len,2]:=0;dec(len);
    end;
    if map[x,y]='1' then dec(tmp);
  end;
end;
begin
  //assign(input,'1.in');assign(output,'1.out');
  //reset(input);rewrite(output);
  readln(n,k);
  for i:=1 to n do begin
   for j:=1 to n do read(map[i,j]);
   readln;
  end;
  for i:=1 to k do readln(zb[i,x],zb[i,y]);

  for i:=1 to k do
  begin
    tmp:=0;len:=0;
    min:=maxlongint;
    //tmp:=maxlongint;
    dfs(1,zb[i,x],zb[i,y]);
    writeln(min);
  end;
  //close(input);close(output);
end.
