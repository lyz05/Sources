const	maxn=100000;
var	i,j,k,n,tmp,ans:longint;
	a:array[1..maxn] of longint;
	p,pp:array[1..maxn] of boolean;
function pd:boolean;
begin
	fillchar(pp,sizeof(pp),false);
	for i:=1 to n do
		if not p[i] then
			if p[a[i]] then pp[a[i]]:=true;
	for i:=1 to n do
		if pp[i]<>p[i] then exit(false);
	exit(true);
end;
procedure dfs(deep:longint);
var 	i:longint;
begin
	if deep>n then begin
		if (tmp>ans) and pd then begin
                        ans:=tmp;
                end;
		exit;
	end;
	for i:=0 to 1 do begin
		if i=0 then begin
			inc(tmp);
			p[deep]:=true;
		end else begin
			dec(tmp);
			p[deep]:=false;
		end;
		dfs(deep+1);
	end;
end;
begin
	assign(input,'gen.in');reset(input);
	assign(output,'gen.out');rewrite(output);

	readln(n);
	for i:=1 to n do read(a[i]);

	dfs(1);
        writeln(ans);

	close(input);close(output);
end.
