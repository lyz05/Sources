var n,k,tmp,i,j,l,xf,ans:longint;
    a:array[1..500000] of boolean;
    s:ansistring;//change
begin
  assign(input,'0.in');assign(output,'0.out');
  reset(input);rewrite(output);

  readln(n,k);
  readln(s);
  for i:=1 to n do
  begin
    val(s[i],tmp);
    if tmp=1 then a[i]:=true;
  end;

  for l:=1 to n do
  begin
    xf:=0; ans:=0; i:=1;
    while i<=n do
    begin
      if a[i] then
      begin
        for j:=i to i+l-1 do
          if a[j] then inc(xf);
        i:=i+l-1;
        inc(ans);
      end;
      inc(i);
    end;
    if ans=k then
    begin
      writeln(l);
      exit;
    end;
  end;
  close(input);close(output);
end.
