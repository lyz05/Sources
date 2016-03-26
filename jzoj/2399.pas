var m,n,i,j,c,b,w,ans,k:longint;
begin
  readln(n);
  for i:=1 to n do
  begin
    readln(c);
    if i mod 2=0 then
    begin
      if (k<>c) and (c=0) then
      begin
        inc(w,b);
        b:=0;
        k:=c;
      end;
      if (k<>c) and (c=1) then
      begin
        inc(b,w);
        w:=0;
        k:=c;
      end;
    end;

    if c=1 then begin
      if (k<>c) and (b<>0) then b:=0;
      inc(b);
    end else begin
      if (k<>c) and (w<>0) then
      begin
        inc(ans,w);
        w:=0;
      end;
      inc(w);
    end;
    k:=c;
  end;
  inc(ans,w);
  w:=0;
  writeln(ans);
end.
