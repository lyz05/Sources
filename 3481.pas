const	maxm=10*100;mo=905229641;
var	m,n:longint;
	a:array[1..maxm] of longint;
	p:array[0..maxm] of boolean;
	ans:int64;
function calc(x:longint):int64;
var	i:longint;
begin
	calc:=1;
	for i:=1 to x do calc:=(calc*i)mod mo;
end;
procedure dfs(dep,last:longint);
var	i,t:longint;
begin
	if n<0 then exit;
	if n=0 then begin
		ans:=(ans+calc(dep-1)) mod mo;
		exit;
	end;
	for i:=last to n do begin
		t:=i mod m;
		if p[t] then continue;
		
		p[t]:=true;
		dec(n,i);
		a[dep]:=i;
			dfs(dep+1,i);
		a[dep]:=0;
		inc(n,i);
		p[t]:=false;
	end;
end;
begin
	assign(input,'3481.in');reset(input);
	//assign(output,'.out');rewrite(output);
	
	readln(n,m);
	ans:=0;
	dfs(1,0);
	writeln(ans);
	//close(input);close(output);
end.
