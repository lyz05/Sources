const max=91;
var q,i,j:longint;
    a,b:int64;
    len,ans:array[0..max] of int64;
procedure prepar;//初始化数组，找一数组ans，总长度数组len
var i:longint;
begin
  len[0]:=1;len[1]:=1;
  ans[0]:=0;ans[1]:=1;
  for i:=2 to max do
  begin
    len[i]:=len[i-1]+len[i-2];
    ans[i]:=ans[i-1]+ans[i-2];
  end;
end;
function find(a,l:int64):int64;//找一，在前a个数（包括a）找寻1的个数
begin
  if a=0 then exit(0);
  if a=len[l] then exit(ans[l]);
  find:=0;
  if a<=len[l-1] then find:=find(a,l-1)
    else find:=ans[l-1]+find(a-len[l-1],l-2);
end;
begin
  prepar;
  readln(q);
  for i:=1 to q do
  begin
    readln(a,b);
    writeln(find(b,max)-find(a-1,max));
  end;
end.
