program r133;
var a:array[0..200000]of longint;
    i,j,n,total,now:longint;
procedure qsort(l,r:longint);
var m,i,j:longint;
begin
 m:=a[(l+r) div 2];
 i:=l;
 j:=r;
 repeat
  while a[i]<m do inc(i);
  while a[j]>m do dec(j);
  if i<=j then begin
   a[0]:=a[i];
   a[i]:=a[j];
   a[j]:=a[0];
   inc(i);dec(j);
  end;

 until i>j;
 if l<j then qsort(l,j);
 if i<r then qsort(i,r);
end;
begin
    readln(n);
    for i:=1 to n do
      readln(a[i]);
    qsort(1,n);
    now:=a[1];
    total:=1;
    for i:=2 to n do
      if a[i]=now then inc(total)
      else
        begin
          writeln(now,' ',total);
          now:=a[i];
          total:=1;
        end;
    writeln(now,' ',total);
end.
