const maxsz=10000000;
var q,a,b,i,j,k,ans:longint;
    sz,tmp:array[1..2*maxsz] of shortint;
begin
  //assign(output,'00.out');rewrite(output);
  k:=1;sz[1]:=1;
  while k<=maxsz do
  begin
    fillchar(tmp,sizeof(tmp),0);
    i:=1;
    for j:=1 to k do
      if sz[j]=1 then
      begin
        tmp[i]:=1;inc(i);
        tmp[i]:=0;inc(i);
      end else
      begin
        tmp[i]:=1;inc(i);
      end;
    sz:=tmp;
    k:=i-1;
  end;
  //for i:=1 to maxsz do write(sz[i]);

  readln(q);
  for i:=1 to q do
  begin
    ans:=0;
    readln(a,b);
    for j:=a to b do
      if sz[j]=1 then inc(ans);
    writeln(ans);
  end;
  //close(output);
end.
