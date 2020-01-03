const	maxn=500+5;
var	i,j,k,m,n,sum:longint;
	a,b:array[1..maxn+1] of longint;
	mark:array[0..maxn+1] of longint;
	map:array[1..maxn+1,1..maxn+1] of boolean;
procedure dfs(deep,x:longint);
	forward;
function judge(x:longint):boolean;
var	i:longint;
begin
	for i:=1 to n+1 do begin
		if i<>x then 
			if i<>1 then 
				dfs(1,1,i,a[i]-b[i]) else 
					dfs(1,2,i,a[i]-b[i])
	end;
end;
procedure dfs(deep,x,p:longint);
var	i:longint;
begin
	for i:=0 to 1 do begin
		if i=0 then begin
			inc(b[])
		end;
	end;
end;
begin
	assign(input,'3.in');reset(input);
	//assign(output,'.out');rewrite(output);
	
	sum:=0;
	readln(n);
	for i:=1 to n+1 do begin
		readln(a[i]);
		inc(sum,a[i]);
	end;
	for i:=1 to n+1 do begin
		if odd(sum-a[i]) then continue;
		if not judge(i) then continue;
		inc(mark[0]);
		mark[mark[0]]:=i;	
	end;
	writeln(mark[0]);
	for i:=1 to mark[0] do writeln(mark[i]);
end.
