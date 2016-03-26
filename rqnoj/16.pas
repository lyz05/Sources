var n,i,j,money,maxmoney,ans:longint;
    s,k:string;
    b:array[1..6] of string;
    a:array[1..6] of longint;
begin
 readln(n);
 ans:=0;
 maxmoney:=0;
 k:='';
 for i:=1 to n do begin
  readln(s);
  money:=0;
  s:=s+' ';
  j:=0;
  while pos(' ',s)<>0 do begin
   inc(j);
   b[j]:=copy(s,1,pos(' ',s)-1);
   delete(s,1,pos(' ',s));
  end;
  for j:=1 to 6 do val(b[j],a[j]);
  if (a[2]>80) and (a[6]>=1) then inc(money,8000);
  if (a[2]>85) and (a[3]>80) then inc(money,4000);
  if (a[2]>90) then inc(money,2000);
  if (a[2]>85) and (b[5]='Y') then inc(money,1000);
  if (a[3]>80) and (b[4]='Y') then inc(money,850);
  if money>maxmoney then begin
   maxmoney:=money;
   k:=b[1];
  end;
  inc(ans,money);
 end;
 writeln(k);
 writeln(maxmoney);
 writeln(ans);
end.
{a[1     2    3    4    5    6]
  姓名  期末 班级 干部 西部 论文

}
