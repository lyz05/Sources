var n,i,j,k,l:longint;
    s,s1:string;
    p:boolean;
    dir:array[0..100000] of string;
begin
  l:=0;
  readln(n);
  for k:=1 to n do
  begin
    readln(s);
    delete(s,1,1);
    s:=s+'/';
    s1:='';
    for i:=1 to length(s) do
    begin
      s1:=s1+s[i];
      if s[i]='/' then
      begin
        p:=false;
        for j:=l downto 1 do
          if dir[j]=s1 then
          begin
            p:=true;
            break;
          end;
        if not p then
        begin
          inc(l);
          dir[l]:=s1;
        end;
      end;
    end;
    writeln(l);
  end;
end.
