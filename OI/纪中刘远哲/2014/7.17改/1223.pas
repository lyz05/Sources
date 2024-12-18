type sz=array[1..200000] of longint;
var n,c,i,j,ans,len:longint;
    a:sz;
    b:array[0..200000,1..2] of longint;
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
  readln(n,c);
  for i:=1 to n do read(a[i]);
  qsort(a,1,n);
  len:=0;
  for i:=1 to n do
  begin
    if a[i]=b[len,1] then inc(b[len,2]) else
    begin
      inc(len);
      b[len,1]:=a[i];
      inc(b[len,2]);
    end;
  end;
  i:=1;j:=2;ans:=0;
  while j<=len do
  begin
    while (b[j,1]-b[i,1]<c) and (j<=len) do inc(j);
    while (b[j,1]-b[i,1]>c) and (i<=len) do inc(i);
    if b[j,1]-b[i,1]=c then
    begin
     inc(ans,b[j,2]*b[i,2]);
     inc(i);inc(j);
    end;
  end;
  writeln(ans);
end.
