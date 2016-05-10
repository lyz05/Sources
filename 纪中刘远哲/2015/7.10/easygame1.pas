var n,i,j,k,ans,len:longint;
    s1,s2:string;
procedure dfs(deep:longint);
var i,j:longint;
    tmp1:char;
    tmp:string;
begin
 if deep>len then begin
  if s2<=s1 then inc(ans);
 end else if deep<>k then begin
  for i:=0 to 9 do begin
   str(i,tmp);
   tmp1:=tmp[1];
   s2[deep]:=tmp1;
   dfs(deep+1);
   s2[deep]:='0';
  end;
 end else dfs(deep+1);

end;
begin
 readln(n);
 str(n,s1);
 len:=length(s1);
 s2:='';
 for i:=1 to len do s2:=s2+'0';
 for k:=len downto 1 do begin
  s2[k]:='1';
  dfs(1);
 end;
 writeln(ans);
end.
