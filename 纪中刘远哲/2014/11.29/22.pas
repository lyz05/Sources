const	maxn=1000;
var	i,j,k,n,m,s,tmp,ans,max:longint;
	a:Array[1..maxn] of longint;
procedure dfs(deep,x,y:longint);
var	i,j,t,k:longint;
begin
	if tmp>ans then exit;
	if x=y then begin
		ans:=tmp;
		exit;
	end;
	j:=0;
	for i:=x to y do begin
		if j+a[i]>m then break;
		inc(j,a[i]);
	end;
	j:=i-1;
	for i:=x to j do begin
		inc(tmp);
		dfs(deep+1,i+1,y);
		dec(tmp);
	end;
end;
begin
	max:=0;
	readln(n,s);
	for i:=1 to n do begin
		read(a[i]);
		if a[i]>max then max:=a[i];
	end;
	for i:=n+1 to 2*n do a[i]:=a[i-n];
	for i:=1 to s do begin
		read(m);
		if m<max then begin
			writeln('NO');
			continue;
		end;
		ans:=maxlongint;
		for j:=1 to n do begin
			tmp:=0;
			dfs(1,j,j+n);
		end;
                writeln(ans);
	end;
end.
