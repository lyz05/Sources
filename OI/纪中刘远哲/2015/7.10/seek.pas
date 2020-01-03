var s,s1,s2:ansistring;
    i,j,m:longint;
begin
 readln(s);
 for m:=1 to length(s) do begin
  s1:=copy(s,1,m);
  s2:=copy(s,length(s)-m+1,m);
  if s1=s2 then write(m,' ');
 end;
end.
