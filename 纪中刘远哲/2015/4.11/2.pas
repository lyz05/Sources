const	maxn=20;
var	i,j,k,m,n:longint;
	a:array[1..maxn,1..maxn] of double;
	p:array[1..maxn] of boolean;
	tmp,ans:double;
	flag:boolean;
procedure dfs(dep:longint);
var	i:longint;
begin
	if dep>n then begin
		flag:=true;
		if tmp>ans then ans:=tmp;
		exit;
	end;
	for i:=1 to n do begin
		if a[dep,i]=0 then continue;
		if not p[i] then begin
			p[i]:=true;
			tmp:=tmp*a[dep,i];
				dfs(dep+1);
			tmp:=tmp/a[dep,i];
			p[i]:=false;
		end
	end;
end;
begin
	assign(input,'2.in');reset(input);
	//assign(output,'.out');rewrite(output);

	readln(n);
	for i:=1 to n do 
		for j:=1 to n do begin
			read(a[i,j]);
			a[i,j]:=a[i,j]/100;
		end;
	ans:=0;tmp:=1;flag:=false;
	dfs(1);
	if flag then writeln(ans*100:0:6) else writeln('0.000000');
end.
