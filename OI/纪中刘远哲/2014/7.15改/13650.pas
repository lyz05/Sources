const
nn=91;  //进行92次的数列扩展后，数列长度就会超过给定的数据范围,
var
f,ft:array[0..nn] of int64;
q,i,j,l1,l2:longint;
a,b:qword;
  procedure prapre;{预处理}
    var i:longint;
    begin
      f[0]:=1;f[1]:=1;
      ft[0]:=0;ft[1]:=1;
      for i:=2 to nn do
        begin
          f[i]:=f[i-1]+f[i-2];
          ft[i]:=ft[i-1]+ft[i-2];
        end;
    end;
  function find(a:int64;ll:longint):int64;{求这个数列的前a个有多少个1}
    begin
      if a=0 then exit(0);
      find:=0;
      if a=f[ll] then find:=ft[ll] else
      if a<=f[ll-1] then find:=find(a,ll-1)
                    else find:=ft[ll-1]+find(a-f[ll-1],ll-2);
    end;
begin
//assign(input,'infinit.in');reset(input);
//assign(output,'infinit.out');rewrite(output);
  prapre;
  readln(q);
  for i:=1 to q do
    begin
      readln(a,b);
      writeln(find(b,nn)-find(a-1,nn));
    end;
//close(input);close(output);
end.
