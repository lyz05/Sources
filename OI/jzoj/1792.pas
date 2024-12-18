type sz=array[1..100000] of longint;
var n,m,i,j,k,l,x1,y1,x2,y2:longint;
    a:sz;
    p:boolean;
function ans(x1,y1,x2,y2:longint):longint;
begin
  exit(abs(x1-x2)+abs(y1-y2));
end;
function max(x,y:longint):longint;
begin
  if x>y then exit(x) else exit(y);
end;
function min(x,y:longint):longint;
begin
  if x<y then exit(x) else exit(y);
end;

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

function find1:longint;
var l,r,m:longint;
begin
  l:=1;r:=n;
  m:=(l+r) div 2;
  while l<=r do
  begin
    if (a[m]>=min(x1,x2)) and (a[m]<=max(x1,x2)) then break;
    if (a[m]>max(x1,x2)) then r:=m-1;
    if (a[m]<min(x1,x2)) then l:=m+1;
    m:=(l+r) div 2;
  end;
  //r min l max
  if l<=r then find1:=0 else
  begin
   if l=n+1 then l:=n;
   if r=0 then r:=1;
   find1:=min(abs(a[r]-min(x1,x2)),abs(a[l]-max(x1,x2)));
  end;
end;

begin
  readln(n);
  for i:=1 to n do read(a[i]);
  qsort(a,1,n);
  readln(m);
  for i:=1 to m do
  begin
    readln(x1,y1,x2,y2);
    if ((y1>0) and (y2>0)) or ((y1<0) and (y2<0)) then
      writeln(ans(x1,y1,x2,y2)) else
    begin
      writeln(ans(x1,y1,x2,y2)+2*find1);
    end;
  end;
end.
