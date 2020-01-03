var num,n,i,j,k:longint;
    a:array[1..51] of longint;
    ch:char;
    s:string;
begin
 readln(num);
 for i:=1 to num do begin
  fillchar(a,sizeof(a),0);
  readln(n);
  for j:=1 to n do begin
   readln(s);
   for k:=1 to length(s) do begin
    ch:=s[k];
    if ch='W' then inc(a[j],3);
    if ch='L' then inc(a[k],3);
    if ch='D' then begin
     inc(a[k],1);
     inc(a[j],1);
    end;
   end;
  end;
  for j:=1 to n do write(a[j],' ');
  writeln;
 end;
end.
