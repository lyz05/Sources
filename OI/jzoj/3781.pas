type sz=array[0..1000000] of longint;
var i,j,k,m,n,len,ans,tmp:longint;
    a:sz;
    p:boolean;
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
  //assign(input,'3781.in');assign(output,'3781.out');
  //reset(input);rewrite(output);
  readln(n);
  for i:=1 to n do read(a[i]);
  qsort(a,1,n);

  a[0]:=0;
  len:=0;ans:=0;
  for i:=1 to n do begin
    if (a[i-1]<>a[i]) then
    begin
      for j:=1 to a[i]-k do
      begin
        tmp:=len mod 2;
        len:=len div 2+tmp;
      end;
      k:=a[i];
    end;
    inc(len);
  end;
  j:=0;
  while len<>1 do
  begin
    inc(j);
    tmp:=len mod 2;
    len:=len div 2+tmp;
  end;
  writeln(a[n]+j);
  //close(input);close(output);
end.
