var n,i,j:longint;
    a:array[1..50,1..50] of char;
    s:array[1..50] of longint;
begin
  readln(n);
  for i:=1 to n do begin
   for j:=1 to n do begin
    read(a[i,j]);
    if a[i,j]='W' then inc(s[i],3);
    if a[i,j]='L' then inc(s[j],3);
    if a[i,j]='D' then begin
     inc(s[i]);
     inc(s[j]);
    end;
   end;

  end;
  for i:=1 to n do write(s[i],' ');
end.
