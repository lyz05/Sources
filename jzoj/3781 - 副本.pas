var i,j,m,n,ans,len:longint;
    a:array[1..1000000] of longint;
    p:boolean;
begin
  readln(n);
  for i:=1 to n do read(a[i]);

  ans:=0;len:=0;
  while (n-len)<>1 do begin
    inc(ans);
    p:=false;
    for i:=1 to n do
      if a[i]<>-1 then
      begin
        if (a[i]=0) then begin
          if p then begin
            a[i]:=-1;
            inc(len);
            p:=false;
          end else p:=true;
        end else dec(a[i]);
      end;
  end;
  writeln(ans);
end.
