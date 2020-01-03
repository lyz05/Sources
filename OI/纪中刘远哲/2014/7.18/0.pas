var n,i,j,num,tmp,ans:longint;
    p:boolean;
    a:array[1..4,0..100000] of longint;
function max(x,y,z:longint):longint;
begin
   if (x>y) and (x>z)  then max:=1;
   if (y>x) and (y>z)  then max:=2;
   if (z>x) and (z>y)  then max:=3;
end;
begin
  readln(n);
  for i:=1 to n do readln(a[1,i],a[2,i],a[3,i]);
  a[1,0]:=10;a[2,0]:=20;a[3,0]:=30;


  for i:=1 to n do
  begin
    num:=max(a[1,i],a[2,i],a[3,i]);
    a[4,i]:=a[num,0];
  end;

  for i:=1 to 4 do a[i,0]:=a[i,n];
  repeat
  p:=true;
  for i:=1 to n do
  begin
    if (a[4,i-1]>a[4,i]) and (a[4,i+1]>a[4,i]) then continue;
    if (a[4,i-1]<a[4,i]) and (a[4,i+1]<a[4,i]) then continue;
    num:=a[4,i] div 10;
    tmp:=0;
    for j:=1 to 3 do
      if a[num,i]>a[num,j] then
       if tmp<a[num,j] then tmp:=a[num,j];
    if tmp=0 then writeln('error');
    p:=false;
    break;
  end;
  until p;
  ans:=0;
  for i:=1 to n do inc(ans,a[(a[4,i] div 10),i]);
  writeln(ans);

end.
