const	maxn=10000;
var	i,n:longint;
	flag:array[0..maxn] of boolean;
	path:array[1..maxn+1] of longint;
	p:boolean;
{procedure check;
var	pp:boolean;
	i:longint;
begin
	flag[n]:=true;
	pp:=true;
	for i:=1 to n+1 do begin
		if path[i]>ans[i] then begin
			pp:=false;
			break;
		end;
	end;
	if not pp then 
		for i:=1 to n+1 do ans[i]:=path[i];
end;
}
procedure print;
var	i:longint;
begin
	write(path[1]);
	for i:=2 to n+1 do write(' ',path[i]);
	writeln;
	halt;
end;
procedure dfs(dep,x:longint);
var	i,y:longint;
begin
	path[dep]:=x;
	flag[x]:=true;
	if (x=0) and p then begin
		flag[x]:=false;
		p:=false;
	end;
	if dep=n+1 then print;
	for i:=1 to 2 do begin
		if odd(i) or (x=0) then y:=x<<1+1 else y:=x<<1;
		y:=y mod n;
		if not flag[y] then dfs(dep+1,y);
	end;
	flag[x]:=false;
end;
begin
	//assign(input,'circle.in');reset(input);
	//assign(output,'circle.out');rewrite(output);
	

	readln(n);
	fillchar(flag,sizeof(flag),false);	
	p:=true;
	dfs(1,0);
	writeln(-1);

	//close(input);close(output);
end.
