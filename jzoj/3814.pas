type sz=array[1..200000] of longint;
var m,n,i,j,k,y,ans,p:longint;
    s,s1,s2:ansistring;   //change
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
  while a1[i]>m do inc(i);
  while a1[j]<m do dec(j);
  if i<=j then begin
   swap(a1[i],a1[j]);
   inc(i);dec(j);
  end;
 until i>j;
 if l<j then qsort(a1,l,j);
 if i<r then qsort(a1,i,r);
end;
function max(x,y:longint):longint;
begin
  if x>y then exit(x) else exit(y);
end;
function dg(x:longint):longint;
var i,j:longint;
begin
  dg:=0;i:=0;j:=0;
  if s[x]='X' then exit(1);
  inc(p);
  if s[x]='A' then begin
    if s[p]='X' then inc(dg) else dg:=dg+dg(p);
  end else begin
    if s[p]='X' then i:=1 else i:=i+dg(p);
  end;

  inc(p);
  if s[x]='A' then begin
    if s[p]='X' then inc(dg) else dg:=dg+dg(p);
  end else begin
    if s[p]='X' then j:=1 else j:=j+dg(p);
    dg:=dg+max(i,j);
  end;
end;
begin
  n:=0;k:=0;ans:=0;
  readln(s);
  for i:=1 to length(s) do if s[i]='X' then inc(n);
  for i:=1 to n do read(a[i]);
  qsort(a,1,n);
  p:=1;
  k:=dg(1);
  for i:=1 to k do inc(ans,a[i]);
  writeln(ans);
end.
