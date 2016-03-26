var i,j,max,min:longint;
    s,s1:ansistring;
    tmp:char;
    a:array[1..101] of char;
    b:array[1..100] of integer;
function zs(x:longint):boolean;
var i,j:longint;
begin
 if (x=1) or (x=0) then exit(false);
 for i:=2 to trunc(sqrt(x)) do if x mod i=0 then exit(false);
zs:=true;
end;
begin
 readln(s);
 for i:=1 to length(s) do begin
  tmp:=s[i];
  for j:=1 to 101 do begin
   if (a[j]=tmp) or (a[j]=chr(0)) then break;
  end;
  a[j]:=tmp;
  inc(b[j]);
 end;
 max:=0;
 min:=9999;
 i:=1;
 while a[i]<>chr(0) do begin
  if max<b[i] then max:=b[i];
  if min>b[i] then min:=b[i];
  inc(i);
 end;
 if zs(max-min) then begin
  writeln('Lucky Word');
  writeln(max-min);
 end else begin
  writeln('No Answer');
  writeln(0);
 end;

end.
