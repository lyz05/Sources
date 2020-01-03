const	maxn=20;
var	i,j,k,m,n,t:longint;
	c:array[1..maxn,1..maxn] of longint;
	v:array[1..maxn] of boolean;
	a:array[1..maxn] of longint;
	flag:boolean;
procedure prepar;
var	i,j:longint;
begin
	c[1,1]:=1;
	for i:=2 to maxn do begin
		for j:=1 to i do c[i,j]:=c[i-1,j]+c[i-1,j-1];	
	end;
end;
procedure dfs(dep,t:longint);
var	i:longint;
begin
	if t<0 then exit;
	if dep>n then begin
		if t=0 then begin
			flag:=true;
			for i:=1 to n-1 do write(a[i],' ');
			writeln(a[n]);
		end;
		exit;
	end;
	for i:=1 to n do begin
		if not v[i] then begin
			v[i]:=true;
			a[dep]:=i;
				dfs(dep+1,t-c[n,dep]*i);
			a[dep]:=0;
			v[i]:=false;
			if flag then exit;
		end;
	end;
end;
begin
	assign(input,'easy.in');reset(input);
	assign(output,'easy.out');rewrite(output);

	prepar;
	while true do begin
		//if eof then break;
		readln(n,t);
		if (n=0) and (t=0)then break;
		flag:=false;
		dfs(1,t);
	end;
	close(input);close(output);

end.
