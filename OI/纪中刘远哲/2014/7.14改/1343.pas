type sz=array[1..5000] of longint;
var n,h,i,j,k,ans:longint;
    b,e,t:sz;
    zs:array[1..30000] of boolean;
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
   swap(b[i],b[j]);
   swap(t[i],t[j]);
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
  end;

  qsort(e,1,h);
  for i:=1 to h do
  begin
    for j:=e[i] downto b[i] do
    begin
      if zs[j] then dec(t[i]);
      if t[i]=0 then break;
    end;
    if t[i]<>0 then
      for j:=e[i] downto b[i] do
        if not zs[j] then
        begin
          zs[j]:=true;
          dec(t[i]);
          if t[i]=0 then break;
        end;
  end;
  ans:=0;
  for i:=1 to n do if zs[i] then inc(ans);
  writeln(ans);
end.
