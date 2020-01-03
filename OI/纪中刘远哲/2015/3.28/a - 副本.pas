type	node=record
		cnt,cnt1,cnt2:longint;
	end;
var	i,j,k,m,n:longint;
	t1,t2:node;
	a:array[1..maxn] of longint;
	f:array[1..maxn,1..maxn] of node;
procedure cp(var x,y:node;order,num:longint);
begin
	x:=y;
	case order of
		1:x.cnt1:=y.cnt1 xor num;
		2:x.cnt2:=y.cnt2 xor num;
	end;
	x.cnt:=x.cnt1+x.cnt2;
end;
begin
	readln(n);
	for i:=1 to n do read(a[i]);

	fillchar(f,sizeof(f),0);
	for i:=1 to n do 
		for j:=1 to n do begin
			cp(t1,f[i-1,j],2,a[i]);
			cp(t2,f[i-1,j-1],1,a[i]);
			if t1.cnt>=t2.cnt then
				cp(f[i,j],t1,0,0)
			else cp(f[i,j],t2,0,0);
		end;
	maxx:=0;
	for i:=1 to n do 
		if f[n,i].cnt>maxx then begin
			
		end;
end.
