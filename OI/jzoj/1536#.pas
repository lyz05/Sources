var s:string;
    l,i,ans,j:longint;
    b,f:array[0..400000]of longint;
begin
    readln(s);
    l:=length(s);
    for i:=2 to l-1 do begin
        //while (j>0)and(s[j+1]<>s[i]) do j:=b[j];
        if s[j+1]=s[i] then b[i]:=j+1;
        j:=b[i];
    end;
    b[0]:=-1;
    while j>-1 do begin
          if s[j+1]=s[l] then begin
             inc(ans);
             f[ans]:=j+1;
          end;
          j:=b[j];
    end;
    for i:=ans downto 1 do write(f[i],' ');
    write(l);
end.
