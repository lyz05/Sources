uses math;
type sz=array[1..65535] of longint;
var n,i,j,k,n1,n2:longint;
    a:sz;
    s:array[1..65535] of string;
procedure swap(var x,y:longint);
var t:longint;
begin
  t:=x;
  x:=y;
  y:=t;
end;
procedure qsort(var a1:sz;l,r:longint);
var m,i,j:longint;
begin
 m:=a1[(l+r) div 2];
 i:=l;
 j:=r;
 repeat
  while a1[i]<m do inc(i);
  while a1[j]>m do dec(j);
  if i<=j then begin
   swap(a1[i],a1[j]);
   inc(i);dec(j);
  end;
 until i>j;
 if l<j then qsort(a1,l,j);
 if i<r then qsort(a1,i,r);
end;
procedure px(n:longint);
var i,j:longint;
t:string;
begin
  for i:=1 to n-1 do
    for j:=i+1 to n do
      if s[i]>s[j] then
        begin
          t:=s[i];
          s[i]:=s[j];
          s[j]:=t;
        end;
end;
begin
  readln(n);
  for i:=1 to n do read(a[i]);
  qsort(a,1,n);
  k:=trunc(log2(n+1)); n1:=1;
  for i:=0 to k-1 do
  begin
   fillchar(s,sizeof(s),0);
   n2:=1;
   for j:=1 to i do n2:=n2*2;
   n2:=n1+n2-1;
   //if n1=1 then n2:=1;
   for j:=n1 to n2 do str(a[j],s[j-n1+1]);
   px(n2-n1+1);
   for j:=n1 to n2 do val(s[j-n1+1],a[j]);
   n1:=n2+1;
  end;
  for i:=1 to n-1 do write(a[i],' ');
  writeln(a[n]);
end.

var
  n,i,j:longint;
  t:string;
  a:array[1..10000] of string;
begin
  readln(n);
  for i:=1 to n do readln(a[i]);

  for i:=1 to n do writeln(a[i]);
end.
