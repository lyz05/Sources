var k,i:longint;
    sn:real;
begin
 readln(k);
 sn:=1;
 i:=1;
 while sn<=k do begin
  inc(i);
  sn:=sn+1/i;
 end;
 writeln(i);
end.
