var n,m,x1,x2,y1,y2,i,j,len:longint;
    x,y:array[1..600000] of longint;
    p:array[1..600000] of boolean;
    tmp,min:real;
procedure dfs(deep,x1,y1:longint);
var i,j,x2,y2:longint;
begin
 if deep>len then
 begin
   if tmp<min then min:=tmp;
   exit;
 end else
 begin
   for i:=1 to len do
   begin
     if p[i] then continue;
     p[i]:=true;
     x2:=x[i];
     y2:=y[i];
     tmp:=tmp+sqrt(sqr(x1-x2)+sqr(y1-y2));
     dfs(deep+1,x2,y2);
     tmp:=tmp-sqrt(sqr(x1-x2)+sqr(y1-y2));
     p[i]:=false;
   end;
 end;
end;
begin
  readln(n,m,x1,x2);
  read(y1);
  len:=1;
  x[len]:=x1;y[len]:=y1;
  for i:=2 to n do
  begin
    inc(len);
    x[len]:=x1;
    read(y[len]);
    inc(y[len],y[len-1])
  end;
  inc(len);
  read(y2);
  x[len]:=x2;y[len]:=y2;
  for i:=2 to m do
  begin
    inc(len);
    x[len]:=x2;
    read(y[len]);
    inc(y[len],y[len-1]);
  end;
  tmp:=0;
  min:=maxlongint;
  for i:=1 to len do
  begin
   dfs(1,x[i],y[i]);
  end;
  writeln(min:0:2)
end.
