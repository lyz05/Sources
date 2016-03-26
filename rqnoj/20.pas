program rqnoj_20;
var a,b,i:longint;
begin
  for i:=1 to 7 do begin
    readln(a,b);
    if a+b>8 then begin
      writeln(i);
      halt;
    end;
  end;
 writeln(0);
end.