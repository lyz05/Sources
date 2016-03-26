const mo=10086;maxn=100000;
var	len,n,i,x,y,t:longint;
	ans:int64;
	a,head,last:array[1..maxn] of longint;
	l:array[1..2*maxn,1..3] of longint;
	b:array[1..maxn] of boolean;
function dfs(x:longint):longint;
var	point,point1:longint;
	sum:int64;
begin
	sum:=a[x];
	b[x]:=true;
	point:=head[x];
	while point<>0 do begin
		if not b[l[point,1]] then begin
			l[point,3]:=dfs(l[point,1]);
			b[l[point,1]]:=false;
		end;
		point:=l[point,2];
	end;
	
	point:=head[x];
	while point<>0 do begin
		if not b[l[point,1]] then begin
			point1:=l[point,2];
			while point1<>0 do begin
				if not b[l[point,1]] then
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
		
		inc(len);
		l[len,1]:=y;
		if head[x]=0 then head[x]:=len
			else l[last[x],2]:=len;
		last[x]:=len;
		
		inc(len);
		l[len,1]:=x;
		if head[y]=0 then head[y]:=len
			else l[last[y],2]:=len;
		last[y]:=len;
	end;
	fillchar(b,sizeof(b),false);
	t:=dfs(1);
	writeln(ans);
end.
