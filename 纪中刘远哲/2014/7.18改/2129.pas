type sz=array[1..50000] of longint;
var n,i,j,t,c,d:longint;
    a:sz;
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
begin
  readln(n);
  for i:=1 to n do readln(a[i]);
  qsort(a,1,n);
  for i:=1 to n do
    if i mod 2=0 then inc(c,a[i]) else inc(d,a[i]);
  writeln(abs(c-d));
end.
