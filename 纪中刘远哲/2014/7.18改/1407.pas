type sz=array[1..100001,1..2] of longint;
var n,m,i,j,ans,q,min1,len:longint;
    a,min,f:array[1..100000] of longint;
    b:sz;
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
 m:=a1[(l+r) div 2,1];
 i:=l;
 j:=r;
 repeat
  while a1[i,1]>m do inc(i);
  while a1[j,1]<m do dec(j);
  if i<=j then begin
   swap(a1[i,1],a1[j,1]);
   swap(a1[i,2],a1[j,2]);
   inc(i);dec(j);
  end;
 until i>j;
 if l<j then qsort(a1,l,j);
 if i<r then qsort(a1,i,r);
end;
procedure solve(k:longint);
var i:longint;
begin
  if f[k]<>0 then
  begin
    inc(ans,f[k]);
    exit;
  end;
  if k+a[k]>=n+1 then begin
   inc(ans);
   exit;
  end else
  begin
    for i:=1 to n do
      if b[i,2]<=k+a[k] then
      begin
        inc(ans);
        solve(b[i,2]);
        break;
      end;
  end;
end;
{procedure solve(k:longint);
var i:longint;
begin
  if k+a[k]>=n+1 then inc(ans) else
  begin
    for i:=1 to len do
     if k+a[k]>=min[i] then
     begin
       inc(ans);
       solve(b[i,2]);
       break;
     end;
  end;
end; }
begin
  assign(input,'1407.in');assign(output,'1407.out');
  reset(input);rewrite(output);
  readln(n,m);
  for i:=1 to n do begin
    read(a[i]);
    b[i,1]:=a[i]+i;
    b[i,2]:=i;
  end;
  qsort(b,1,n);
  len:=0;min1:=maxlongint;
 { for i:=1 to n do
    if b[i,1]=b[i+1,1] then begin
     if b[i,2]<min1 then min1:=b[i,2];
    end else begin
      if min1=maxlongint then min1:=b[i,2];
      inc(len);
      min[len]:=min1;
      min1:=maxlongint;
    end; }
  {for i:=1 to n do
   if b[i,1]<n+1 then break;
  len:=i-1;}
  for i:=1 to m do
  begin
    ans:=0;
    read(q);
    solve(q);
    f[q]:=ans;
    write(ans,' ');
  end;
  close(input);close(output);
end.


//����4��00 8.8
