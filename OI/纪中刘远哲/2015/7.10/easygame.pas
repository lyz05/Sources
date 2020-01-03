var n,i,j:longint;
    ans,l,k:qword;
    s:string;
begin
 readln(n);
 str(n,s);
 l:=1;
 for i:=length(s) downto 1 do begin
  k:=n div(l*10)+1;
  if s[i]='0' then dec(k) else begin
   if s[i]='1' then begin
    dec(k);
    inc(ans,n mod l+1);
   end;
  end;
  inc(ans,k*l);
  l:=l*10;
 end;
 writeln(ans);
end.
