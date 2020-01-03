var n,i,j,k,leng,jl:longint;
    s:array[1..3] of string;
    a:array[1..10000] of integer;
function len(x,y:char):longint;
begin
    len:=ord(y)-ord(x);
   ///len:=ord(x)-ord(y);
  if 26-len<len then len:=26-len;
end;
begin
  readln(n);
  for i:=1 to 3 do readln(s[i]);

  for i:=1 to 3 do
  begin
    leng:=length(s[i]);
    for j:=1 to 3 do
      if j<>i then
        if jl=0 then jl:=len(s[j][1],s[i][leng])
          else if jl<>len(s[j][1],s[i][leng]) then continue;
    for j:=leng downto 2 do
    begin
      a[leng-j+1]:=len(s[i][j],s[i][j-1])
    end;
    for k:=1 to 3  do
      if k<>i then
        for j:=leng downto 2 do
          if a[leng-j+1]<>len(s[k][j],s[k][j-1])
            then continue;
    for j:=leng downto 1 do write(s[i][j]);
  end;
end.
