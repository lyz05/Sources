type sz=array[1..1000] of longint;
const name='function';
function ss(x:longint):boolean;
var i:longint;
begin
 if x<2 then exit(false);
 for i:=2 to trunc(sqrt(x)) do
  if x mod i=0 then exit(false);
 ss:=true;
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
begin
  assign(input,name+'.in');assign(output,name+'.out');
  reset(input);rewrite(output);

  close(input);close(output);
end.
