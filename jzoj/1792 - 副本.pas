var n,m,i,j,k,l,x1,y1,x2,y2:longint;
    a:array[1..100000] of longint;
    p:boolean;
function ans(x1,y1,x2,y2:longint):longint;
begin
  exit(abs(x1-x2)+abs(y1-y2));
end;
function max(x,y:longint):longint;
begin
  if x>y then exit(x) else exit(y);
end;
function min(x,y:longint):longint;
begin
  if x<y then exit(x) else exit(y);
end;
begin
  readln(n);
  for i:=1 to n do read(a[i]);
  readln(m);
  for i:=1 to m do
  begin
    readln(x1,y1,x2,y2);
    if ((y1>0) and (y2>0)) or ((y1<0) and (y2<0)) then
      writeln(ans(x1,y1,x2,y2)) else
    begin
      p:=false;
      k:=maxlongint;l:=maxlongint;
      for j:=1 to n do
      begin
        if (a[j]<=max(x1,x2)) and (a[j]>=min(x1,x2)) then
        begin
          writeln(ans(x1,y1,x2,y2));
          p:=true;
          break;
        end;
        //k,l
        if abs(a[j]-min(x1,x2))<k then k:=abs(a[j]-min(x1,x2));
        if abs(a[j]-max(x1,x2))<l then l:=abs(a[j]-max(x1,x2));
      end;
      if not p then
      begin
        writeln(min(k,l)*2+ans(x1,y1,x2,y2));
      end;
    end;
  end;
end.
