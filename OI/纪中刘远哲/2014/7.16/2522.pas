const f=1;
      b=2;
      i0=3;
var s,s1,s2:ANSIstring;
    i,j,k,l,len,m,n,ans:longint;
    a:array[1..3,1..2000] of longint;
begin
  readln(s);
  len:=length(s);
  j:=1;k:=1;l:=1;
  for i:=1 to length(s) do
    case s[i] of
      'F':begin
            a[f,j]:=i;
            inc(j);
          end;
      'B':begin
            a[b,k]:=i;
            inc(k);
          end;
      'I':begin
            a[i0,l]:=i;
            inc(l);
          end;
    end;
  ans:=0;
  DEC(J);DEC(K);DEC(L);
  for i:=1 to j do
   for m:=k downto 1 do
     if a[f,i]<a[b,m] then
      for n:=l downto 1 do
       if (a[b,m]<a[i0,n]) then inc(ans);
  writeln(ans);

end.
