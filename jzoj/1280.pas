type sz=array[1..100000] of longint;
const name='1280';
var n,k,i,j,l,max,min:longint;
    a,b,c:sz;
    ans:qword;
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

  readln(n,k);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do read(b[i]);

  qsort(a,1,n);
  qsort(b,1,n);
  for i:=1 to n do c[i]:=abs(a[i]-b[n-i+1]);
  qsort(c,1,n);

  ans:=0;
 //repeat
  for i:=1 to k do inc(ans,c[i]);
  //until (i>=k) or (j>=l);
  writeln(ans);

  close(input);close(output);
end.
