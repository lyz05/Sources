var n,i,j,x,y,z:longint;{xÔ¤¼Æ£¬y×Ô¼º£¬zÂèÂè}
begin
 y:=0;
 z:=0;
 for i:=1 to 12 do begin
  inc(y,300);
  readln(x);
  y:=y-x;
  if y<0 then begin
   writeln('-',i);
   halt;
  end else if y>=100 then begin
   inc(z,y div 100);
   y:=y mod 100;
 end;
 end;
 writeln(z*120+y);
end.
