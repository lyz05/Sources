var n,k,i,j,m:longint;
    a:array[1..5000000] of longint;
procedure swap(var x,y:longint);
var t:longint;
begin
 t:=x;
 x:=y;
 y:=t;
end;
procedure qsort(l,r:longint);
var i,j,m:longint;
begin
 i:=l;j:=r;m:=a[l];
 repeat
  while m>a[i] do inc(i);
  while m<a[j] do dec(j);
  if i<=j then begin
   swap(a[i],a[j]);
   inc(i);dec(j);
  end;
 until i>j;
 if l<j then qsort(l,j);
 if i<r then qsort(i,r);
end;
begin
 readln(n,k);
 for i:=1 to n do read(a[i]);
 qsort(1,n);
 m:=a[k];
 while m=a[k] do inc(k);
 dec(k,2);
 for i:=1 to k do write(a[i],' ');
end.
