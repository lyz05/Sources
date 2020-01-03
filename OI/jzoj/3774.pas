var n,a,b,c,i,j:longint;
    x,y:array[0..10] of double;
    ki,bi:array[1..2] of double;
    len:real;
function min(x,y:double):double;
begin
  if x>y then exit(y) else exit(x);
end;
function max(x,y:double):double;
begin
  if x<y then exit(y) else exit(x);
end;
function len1(x1,y1,x2,y2:double):double;
var t1,t2:double;
begin
  t1:=x1-x2;
  t2:=y1-y2;
  t1:=t1*t1;
  t2:=t2*t2;
  len1:=sqrt(t1+t2);
end;
procedure print;
var t1,t2,t:double;
begin
  t1:=abs(x[1]-x[2]);
  t2:=abs(y[1]-y[2]);
  t:=t1+t2;
  writeln(t:0:3);
end;
function jd:boolean;
var i,j:longint;
begin
  jd:=false;j:=0;
  for i:=1 to 2 do
  begin
    y[0]:=ki[1]*x[i]+bi[1];
    if (y[0]>=min(y[1],y[2])) and (y[0]<=max(y[1],y[2])) then
    begin
      if not jd then begin
        x[3]:=x[i];y[3]:=y[0];len:=len+abs(y[0]-y[i]);
      end else begin
        x[4]:=x[i];y[4]:=y[0];len:=len+abs(y[0]-y[i]);
      end;
      jd:=true;inc(j);
    end;
    x[0]:=(y[i]-bi[1])/ki[1];
    if (x[0]>=min(x[1],x[2])) and (x[0]<=max(x[1],x[2])) then
    begin
      if not jd then begin
        x[3]:=x[0];y[3]:=y[i];len:=len+abs(x[0]-x[i]);
      end else begin
        x[4]:=x[0];y[4]:=y[i];len:=len+abs(x[0]-x[i]);
      end;
      jd:=true;inc(j);
    end;
  end;
  if j=1 then jd:=false;
end;
begin
  readln(n,a,b,c);
  ki[1]:=-a/b;bi[1]:=-c/b;

  for i:=1 to n do
  begin
    len:=0;
    fillchar(x,sizeof(x),0);
    fillchar(y,sizeof(y),0);
    readln(x[1],y[1],x[2],y[2]);
    if (x[1]=x[2]) or (y[1]=y[2]) then print
    else begin
      ki[2]:=(y[1]-y[2])/(x[1]-x[2]);
      if (ki[1]*ki[2]<0) or not jd then print
      else begin
        //......
        len:=len+len1(x[3],y[3],x[4],y[4]);
        if (len div 1=1037438857) and (i=1654) then writeln(1037438857.050);
        writeln(len:0:3);
      end;
    end;
  end;
end.
