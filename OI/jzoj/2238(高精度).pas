const mo=100000;
      mo2=80000;
type sz=array[1..mo] of longint;
var n,m,i,j:longint;
    a,b,c:sz;
    s1,s2:string;
function len(var x:sz):longint;
var i:longint;
begin
  i:=mo;
  while x[i]=0 do dec(i);
  len:=i;
end;
procedure qm(var x:sz);
begin
  for i:=mo2 to mo do
    x[i]:=0;
end;
{function jf(x,y:sz):sz;//高精度加法
var i,j,lenx,leny,lenmax,k:longint;
    z:sz;
begin
  fillchar(z,sizeof(z),0);
  lenx:=len(x);leny:=len(y);
  if lenx>leny then lenmax:=lenx else lenmax:=leny;
  k:=0;
  for i:=1 to lenmax do
  begin
    z[i]:=x[i]+y[i]+k;
    k:=z[i] div 10;
    z[i]:=z[i] mod 10;
  end;
  if k>0 then z[i+1]:=k;
  jf:=z;
end;}
function cf(x,y:sz):sz;
var i,j,lenx,leny,lenmin,k:longint;
    z:sz;
begin
  fillchar(z,sizeof(z),0);
  lenx:=len(x);leny:=len(y);
  for i:=1 to lenx do
  begin
    k:=0;
    for j:=1 to leny do
    begin
      z[i+j-1]:=z[i+j-1]+k+x[i]*y[j];
      k:=z[i+j-1] div 10;
      z[i+j-1]:=z[i+j-1] mod 10;
    end;
    z[i+j]:=k;
  end;
  cf:=z;
end;
procedure solve;
var t,ans:sz;
    i,leng:longint;
begin
  fillchar(t,sizeof(t),0);
  fillchar(ans,sizeof(ans),0);
  ans[1]:=1;i:=1;
  while n<>0 do
  begin
    t[i]:=n mod 10;
    n:=n div 10;
    inc(i);
  end;
  while m>0 do
  begin
    if odd(m) then
    begin
    ans:=cf(ans,t);
    qm(ans);
    end;
    m:=m div 2;
    t:=cf(t,t);
    qm(t);
  end;
  leng:=len(ans);
  if leng>50 then leng:=50;
  for i:=leng downto 1 do write(ans[i]);//...
end;
begin
  readln(n,m);
  solve;
end.

      x3x2x1
     *y3y2y1
--------------
    z4z3z2z1
  z5z4z3z2
z6z5z4z3
