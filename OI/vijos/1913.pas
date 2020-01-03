uses	math;
var
	n,i,j,tn,s,m,k:longint;
procedure print(x,y:longint); //模拟所在层
begin
	if x=1 then begin writeln(s+y-1); exit end;
	s:=s+tn-1;
	if y=tn then begin writeln(s+x-1); exit end;
	s:=s+tn-1;
	if x=tn then begin writeln(s+tn-y); exit end;
	s:=s+tn-1;
	writeln(s+tn-x)
end;
Begin
	readln(n,i,j);
	m:=min(i,min(j,min(n-i+1,n-j+1))); //判断层数
	i:=i-m+1; j:=j-m+1; //在去掉外层后的矩阵中的坐标
	tn:=n;
	s:=1;
	for k:=1 to m-1 do begin //去掉外层
		inc(s,4*tn-4);
		dec(tn,2)
	end;
	print(i,j);

End.
