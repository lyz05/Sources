var n,i,j,t,m,ans:longint;
begin
 assign(output,'1.out');rewrite(output);
 for n:=1 to maxlongint do begin
  ans:=0;
  for i:=1 to n do begin
   m:=i;
   while m<>0 do begin
    t:=m mod 10;
    m:=m div 10;
    if t=1 then inc(ans);
   end;
  end;
  writeln(ans);
 end;
 close(output);
end.
