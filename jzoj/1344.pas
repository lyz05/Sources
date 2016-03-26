//type sz=array[1..100000] of longint;
const qm=1000;
var i,j,k,x,n:longint;
    ans:qword;
{function len(var x:sz):longint;
var i:longint;
begin
  i:=mo;
  while x[i]=0 do dec(i);
  len:=i;
end;
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
end;}
function gcd(x,y:longint):longint;
begin
  if y=0 then gcd:=x
  else gcd:=gcd(y,x mod y);
end;
function jc(x,y:longint):qword;
var i:longint;
begin
  jc:=1;
  for i:=x to y do jc:=jc*i;
end;
function g(x:longint):longint;
var i:longint;
begin
  g:=1;
  for i:=1 to x do g:=g*x mod qm;
end;
function c(m,n:longint):qword;
var b,d:array[1..10000] of longint;
    i,j,g,k,l:longint;
begin
  fillchar(b,sizeof(b),0);
  fillchar(d,sizeof(d),0);
  k:=0;
  for i:=n downto m+1 do
  begin
    inc(k);
    b[k]:=i;
  end;
  l:=0;
  for i:=n-m downto 2 do
  begin
    inc(l);
    d[l]:=i;
  end;
  i:=1;j:=1;
  while true do
  begin
   g:=gcd(b[i],d[j]);
   b[i]:=b[i] div g;
   d[j]:=d[j] div g;
   if (b[i]<>1) then inc(j) else inc(i);
   if j=l+1 then j:=1;
   if i=k+1 then break;
  end;
  //c:=jc(m+1,n) div jc(1,n-m);
end;
begin
  readln(k,x);
  n:=g(x);
  ans:=c(k-1,n-1);
  writeln(ans);
end.
