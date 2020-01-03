type sz=array[1..30000] of longint;
var n,h,i,j,k,ans:longint;
    b,e,t:array[1..5000] of longint;
    zs:array[1..30000] of boolean;
    bj,zb:sz;
procedure swap(var x,y:longint);
var t:longint;
begin
  t:=x;
  x:=y;
  y:=t;
end;
procedure qsort(a1:sz;l,r:longint);
var m,i,j:longint;
begin
 m:=a1[(l+r) div 2];
 i:=l;
 j:=r;
 repeat
  while a1[i]>m do inc(i);
  while a1[j]<m do dec(j);
  if i<=j then begin
   swap(a1[i],a1[j]);
   swap(zb[i],zb[j]);
   inc(i);dec(j);
  end;
 until i>j;
 if l<j then qsort(a1,l,j);
 if i<r then qsort(a1,i,r);
end;
begin
  readln(n);
  readln(h);
  for i:=1 to h do
  begin
   readln(b[i],e[i],t[i]);
   for j:=b[i] to e[i] do
   begin
     inc(bj[j])
   end;
   //bj[b[i]]:=1;
   //bj[e[i]]:=1;
  end;

  for i:=1 to h do
  begin
    for j:=b[i] to e[i] do zb[j]:=j;
    qsort(bj,b[i],e[i]);
    k:=b[i];
    while t[i]<>0 do
    begin
      dec(t[i]);
      zs[zb[k]]:=true;
      inc(k);
    end;
  end;
  ans:=0;
  for i:=1 to n do if zs[i] then inc(ans);
  writeln(ans);
end.
