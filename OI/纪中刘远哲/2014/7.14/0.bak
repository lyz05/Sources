var n,i,j,k,x,y:longint;
    p:array[1..21,1..21] of integer;
    a:array[0..21] of boolean;
procedure dk(j,k:longint);
begin
  if p[j,k]>=50 then a[k]:=false
  else if p[j,k]<50 then a[j]:=false;
end;
begin
   readln(n);
   for i:=1 to 2*n do
     for j:=1 to 2*n do
       read(p[i,j]);
   for i:=1 to 2*n do a[i]:=true;

   a[21]:=true;
   repeat
     j:=0;k:=0;
     while (j<=2*n) and (k<=2*n) do
     begin
       while not a[j] do inc(j);
       while (not a[k]) or (j=k) do inc(k);
       if k=21 then break;
       if a[j] then
       begin
           dk(j,k);
           j:=k+1;
           k:=k+1;
       end;
     end;
   until k=21;
   for i:=1 to 2*n do if a[i] then
   begin
     writeln(i);
     halt;
   end;
end.
