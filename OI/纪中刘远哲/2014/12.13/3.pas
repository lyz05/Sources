const	mo=1234567;maxn=5000;maxm=5000;
var	i,m,n,tmp:longint;
	ans:int64;
	a:array[0..maxn] of longint;
	b:array[0..maxm] of longint;
	p:array[1..maxm] of boolean;
	p1:array[0..maxn] of boolean;
procedure color(x:longint);
var	i,j:longint;
begin
	j:=b[x];
	for i:=1 to 5 do begin
		p1[j]:=true;
		j:=a[j];
	end;
end;
procedure work(x:longint);
var	i,tot:longint;
begin
        fillchar(p1,sizeof(p1),false);
	for i:=1 to m do
		if p[i] then color(i);
	tot:=0;
	for i:=0 to n-1 do
		if not p1[i] then inc(tot);

	if odd(x) then begin
		if tot=0 then inc(ans) else ans:=(ans+10*tot) mod mo;
	end else begin
		if tot=0 then dec(ans) else ans:=(ans-10*tot) mod mo;
	end;
end;
procedure dfs(dep,x:longint);
var	i:longint;
begin
	if dep>m then begin
		if tmp=x then work(x);
		exit;
	end;
	for i:=0 to 1 do begin
                if (tmp=x) and (i=0) then continue;
                if i=0 then begin
			inc(tmp);
			p[dep]:=true;
			dfs(dep+1,x);
			p[dep]:=false;
			dec(tmp);
		end else dfs(dep+1,x);
	end;
end;
begin
	assign(input,'3.in');reset(input);
	//assign(output,'.out');rewrite(output);

	readln(n,m);
	for i:=1 to n-1 do begin
		readln(a[i]);
	end;
	for i:=1 to m do readln(b[i]);
	for i:=1 to m do begin
		tmp:=0;
		dfs(1,i);
	end;
	writeln(ans);
end.
