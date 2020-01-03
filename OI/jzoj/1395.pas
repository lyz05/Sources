var s:array[0..3] of ansistring;
    zm:array[1..26*2] of char;
    i,j,n,m,len,k,k1,k2,k3:longint;
    //c,d:char;
    p:boolean;
function leng(y,x:char):longint;
var i,j:longint;
    z:char;
begin
  leng:=-1;
  for i:=-13 to 13 do
  begin
    j:=ord(y)-ord('a')+1;
    if j<=13 then inc(j,26);
    z:=zm[j+i];
    if x=z then exit(i);
  end;

end;
{begin
  for i:=1 to 26 do zm[i]:=chr(ord('a')+i-1);
  for i:=27 to 26*2 do zm[i]:=zm[i-26];
  readln(c,d);
  writeln(leng(c,d));
end. }
begin
  assign(input,'000.in');assign(output,'000.out');
  reset(input);rewrite(output);
  readln(len);
  for i:=1 to 3 do readln(s[i]);
  for i:=1 to 26 do zm[i]:=chr(ord('a')+i-1);
  for i:=27 to 26*2 do zm[i]:=zm[i-26];
  for k1:=1 to 3 do
  begin
    k2:=2;k3:=3;
    case k1 of
      2:k2:=1;
      3:k3:=1;
    end;
    s[0]:='';
    for i:=1 to len do begin
      s[0]:=s[k1,i]+s[0];
    end;
    k:=leng(s[0,1],s[k2,1]);
    k:=-leng(s[0,1],s[k3,1]);
    if k<>-leng(s[0,1],s[k3,1]) then continue;
    k:=abs(k);
    p:=true;
    for i:=1 to len do
      if (abs(leng(s[0,i],s[k2,i]))<>k) or (abs(leng(s[0,i],s[k3,i]))<>k)
        then p:=false;
    if not p then continue else writeln(s[0]);
    exit;
  end;
  close(input);close(output);
end.
