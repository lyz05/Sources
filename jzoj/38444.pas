const
	mo=10086;
var
	l0,n,i,x,y,t:longint;
	ans:int64;
	a,head,last:array[1..100000] of longint;
	l:array[1..300000,1..3] of longint;
	b:array[1..100000] of boolean;

function dfs(x:longint):longint;
var
	point,point1:longint;
	sum:int64;
begin
	sum:=a[x];
	b[x]:=true;
	point:=head[x];
	while point<>0 do begin
		if b[l[point,1]]=false then begin
			l[point,3]:=dfs(l[point,1]);
			b[l[point,1]]:=false;
		end;
		point:=l[point,2];
	end;

	point:=head[x];
	while point<>0 do begin
		if b[l[point,1]]=false then begin
			point1:=l[point,2];
			while point1<>0 do begin
				if b[l[point,1]]=false then
					ans:=(ans+int64(l[point,3])*l[point1,3]*a[x]) mod mo;
				point1:=l[point1,2];
			end;
			b[l[point,1]]:=true;
			sum:=(sum+int64(a[x])*l[point,3]) mod mo;
		end;
		point:=l[point,2];
	end;
	ans:=(ans+sum) mod mo;
	exit(sum);
end;

begin
	readln(n);
	for i:=1 to n do read(a[i]);
	for i:=1 to n-1 do begin
		readln(x,y);
		inc(l0);
		l[l0,1]:=y;
		if head[x]=0 then head[x]:=l0
		else l[last[x],2]:=l0;
		last[x]:=l0;

		inc(l0);
		l[l0,1]:=x;
		if head[y]=0 then head[y]:=l0
		else l[last[y],2]:=l0;
		last[y]:=l0;
	end;

	fillchar(b,sizeof(b),false);
        t:=dfs(1);
        writeln(ans);

end.

