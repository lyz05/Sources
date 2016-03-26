var n,i,j,k,len,l,tmp:longint;
    s:string;
    dir:array[0..100000] of longint;
begin
  l:=0;
  readln(n);
  for k:=1 to n do
  begin
    readln(s);
    delete(s,1,1);
    s:=s+'/';

    tmp:=0;
    len:=0;
    for i:=1 to length(s) do
    begin
      tmp:=tmp*26+ord(s[i])-110;
      if s[i]='/' then
      begin
        for j:=1 to l+1 do
          if dir[j]=tmp then break;
        if j=l+1 then begin
          inc(l);
          dir[l]:=tmp;
        end;
      end;
    end;
    writeln(l);
  end;
end.
