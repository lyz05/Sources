var m,n,a,b,c,i,j,x1,y1,x2,y2,x3,y3,xi,yi,xj,yj:longint;
    ki,bi,a1,b1,c1:real;
function jd:boolean;
var p:boolean;
begin
    p:=false;xi:=0;yi:=0;xj:=0;yj:=0;
    y3:=ki*x1+bi;
    if (y3>min(y1,y2)) and (y3<max(y1,y2)) then 
    begin
      p:=true;
      if xi=0 then
        xi:=x1;yi:=y3
      else
        xj:=x1;yj:=y3
    end;
    y3:=ki*x2+bi;
    if (y3>min(y1,y2)) and (y3<max(y1,y2)) then 
    begin
      p:=true;
      if xi=0 then
        xi:=x2;yi:=y3
      else
        xj:=x2;yj:=y3
    end;
    x3:=(y1-bi)/ki;
    if (x3>min(x1,x2)) and (x3<max(x1,x2)) then 
    begin
      p:=true;
      if xi=0 then
        xi:=x3;yi:=y1
      else
        xj:=x3;yj:=y1
    end;
    x3:=(y2-bi)/ki;
    if (x3>min(x1,x2)) and (x3<max(x1,x2)) then 
    begin
      p:=true;
      if xi=0 then
        xi:=x3;yi:=y2
      else
        xj:=x3;yj:=y2
    end;
    exit(p);
end;
begin
  readln(n,a,b,c);
  ki:=-a/b;bi:=-c/b;
  for i:=1 to n do 
  begin
    readln(x1,y1,x2,y2);
    if (x1=x2) or (y1=y2) then 
    begin
      writeln(ans(x1,y1,x2,y2));
      continue;
    end;
    if (not jd) or (jd and fx<0) then 
    begin
      writeln(ans(x1,y1,x2,y2));
      continue;
    end else 
    begin
      a1:=ans(x1,y1,x2,y2);
      a2:=len(xi,yi,xj,yj);
    end;
  end;
end.
