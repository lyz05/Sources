uses	math;
var
	n,i,j,tn,s,m,k:longint;
procedure print(x,y:longint); //ģ�����ڲ�
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
	m:=min(i,min(j,min(n-i+1,n-j+1))); //�жϲ���
	i:=i-m+1; j:=j-m+1; //��ȥ������ľ����е�����
	tn:=n;
	s:=1;
	for k:=1 to m-1 do begin //ȥ�����
		inc(s,4*tn-4);
		dec(tn,2)
	end;
	print(i,j);

End.
