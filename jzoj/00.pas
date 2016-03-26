var
  s:array[1..1000] of string;
  n,i:longint;
  procedure sort(l,r:longint);
  var
    i,j:longint;
    x,y:string;
  begin
    i:=l; j:=r; x:=s[(l+r) div 2];
    repeat
      while s[i]<x do inc(i);
      while x<s[j] do dec(j);
      if not(i>j) then
      begin
        y:=s[i];
        s[i]:=s[j];
        s[j]:=y;
        inc(i); dec(j);
      end;
    until i>j;
    if l<j then sort(l,j);
    if i<r then sort(i,r);
  end;
begin
  writeln;
  writeln('Please input the number of the names:');
  readln(n);
  writeln('Please input the names:');
  for i:=1 to n do readln(s[i]);
  sort(1,n);
  writeln;
  for i:=1 to n do writeln(s[i]);
  readln;
end.
