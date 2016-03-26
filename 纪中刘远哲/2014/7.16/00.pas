var n,i,j,k,k1,k2,leng:longint;
    p:boolean;
    s:array[0..3] of string;
    a:array[1..10000] of longint;
    x,y:char;
function len(x,y:char):longint;
var i:longint;
    z:char;
begin
  len:=-1;
  for i:=-13 to 13 do
  begin
   z:=chr(ord(y)+i);
   if x=z then
   begin
     len:=i;
     break;
   end;
  end;

end;
function len1(x,y:char):longint;
var i:longint;
begin
  len1:=-1;
  for i:=-6 to 6 do
   if x=chr(ord(y)+i) then
   begin
    len1:=i;
    break;
   end;
end;
begin
  read(x,y);
  writeln(len(x,y));
end.
begin
  readln(n);
  for i:=1 to 3 do readln(s[i]);

  for i:=1 to n do
  begin
    k1:=2;k2:=3;
    case i of
      2:k1:=1;
      3:k2:=1;
    end;
    leng:=length(s[i]);
    //分配指针
    s[0]:='';
    for j:=1 to leng do s[0]:=s[i,j]+s[0];
    //初始化s[0]
    if len1(s[k1,1],s[0,1])<>-len1(s[k2,1],s[0,1]) then continue;
    //与s[0]的距离判断
    for j:=1 to leng-1 do a[j]:=len(s[0,j],s[0,j+1]);
    //初始化a数组
    p:=false;
    for j:=1 to leng-1 do
       if (a[j]<>len(s[k1,j],s[k1,j+1])) or (a[j]<>len(s[k2,j],s[k2,j+1])) then
       begin
          p:=true;
          break;
       end;
    if p then continue;
    //比较与a数组的差异
  end;
end.
