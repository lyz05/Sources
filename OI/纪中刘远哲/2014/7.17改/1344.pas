const qm=1000;
      max=100000;
type sz=array[1..max] of longint;
var i,j,k,x,n1,n,m:longint;
    ans:sz;

function len(var x:sz):longint;
var i:longint;
begin
  i:=max;
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
end;

function g(x,y:longint):longint;//¿ìËÙÃÝ
var i:longint;
begin
  g:=1;
  if y=1 then exit(x);
  g:=g*sqr(g(x,y div 2)) mod qm;
  if y mod 2=1 then g:=g*x mod qm;
  //for i:=1 to x do g:=g*x mod qm;
end;

procedure fj(var a:sz;x:qword;var len:longint);
var y,i:qword;
begin
  i:=2;
  while i<=trunc(sqrt(x)) do
  begin
   if x mod i=0 then
   begin
     a[len]:=i;
     inc(len);
     y:=x div i;
     fj(a,y,len);
     exit;
   end;
   inc(i);
  end;
  a[len]:=x;
  inc(len);
end;

function c(n,m:qword):sz;
var a,b,tmp:sz;
    lena,lenb,j,lent:longint;
    i:qword;
begin
  //a=(m+1)*...*n
  //b=1*2*...*(n-m)
  fillchar(a,sizeof(a),0);
  fillchar(b,sizeof(b),0);

  j:=1;
  i:=1;
  while i<=(n-m) do
  begin
    fj(b,i,j);
    inc(i);
  end;
  lenb:=j-1;

  fillchar(c,sizeof(c),0);
  j:=1;
  i:=m+1-1;
  repeat
   inc(i);
   fj(a,i,j);
  until i>=n;
  lena:=j-1;


  i:=1;
  repeat
  j:=1;

   while (b[j]=1) do inc(j);
   if b[j]=0 then break;
   if a[i] mod b[j]=0 then
   begin
     a[i]:=a[i] div b[j];
     b[j]:=1;
   end;
   inc(i);
   if i>lena then i:=i-lena;
  until false;

  c[1]:=1;
  for j:=1 to lena do
  begin
    lent:=0;
    fillchar(tmp,sizeof(tmp),0);
    while a[j]<>0 do
    begin
      inc(lent);
      tmp[lent]:=a[j] mod 10;
      a[j]:=a[j] div 10;
    end;
    c:=cf(c,tmp);
  end;
end;

begin
  readln(k,x);
  n1:=g(x,x);
  n:=n1-1;m:=k-1;
  ans:=c(n,m);
  for i:=1 to len(ans) do write(ans[i]);
end.

{function c(m,n:longint):qword;
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
   //g:=gcd(b[i],d[j]);
   b[i]:=b[i] div g;
   d[j]:=d[j] div g;
   if (b[i]<>1) then inc(j) else inc(i);
   if j=l+1 then j:=1;
   if i=k+1 then break;
  end;
end;}
{begin
readln(k,x);
writeln(g(k,x))
end.
}
