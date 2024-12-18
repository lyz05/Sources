type sz=array[1..4950] of longint;
const name='1751';
var n,m,i,j,tot,min,tmp:longint;
    t1,t2,t3:sz;
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
   swap(t1[i],t1[j]);
   swap(t2[i],t2[j]);
   inc(i);dec(j);
  end;
 until i>j;
 if l<j then qsort(a1,l,j);
 if i<r then qsort(a1,i,r);
end;
function pd:boolean;
var i,j,k:longint;
begin
 pd:=false;
 for i:=1 to m-1 do
  for j:=i+1 to m do
    for k:=1 to m do
end;
begin
  assign(input,name+'.in');assign(output,name+'.out');
  reset(input);rewrite(output);

  readln(tot);
  for i:=1 to tot do
  begin
    readln(n,m);
    for j:=1 to m do
      readln(t1[j],t2[j],t3[j]);
    if m<(n-1) then
    begin
      writeln(-1);
      continue;
    end;
    qsort(t3,1,m);
    min:=maxlongint div 2;
    for j:=1 to m-n+2 do
    begin
      tmp:=t3[j]-t3[j+n-2];
      if (tmp<min) and pd then min:=tmp;
    end;
    writeln(min);
  end;

  close(input);close(output);
end.
