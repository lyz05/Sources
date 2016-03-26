var	n,l,r,i,j,k,ans:longint;
	a:array[1..20] of longint;
	p:array[1..20] of boolean;
function gcd(x,y:longint):longint;
begin
	if x mod y=0 then exit(y) else exit(gcd(y,x mod y));
end;
function lcm(x,y:longint):longint;
begin
	exit((x*y) div gcd(x,y));
end;
procedure solve;
var i,x,tmp:longint;
begin
	x:=1;
	for i:=1 to n do
		if p[i] then
			x:=lcm(x,a[i]);
	tmp:=(r div x)-((l-1) div x);
	if odd(k) then dec(ans,tmp) else inc(ans,tmp);
end;
procedure dfs(deep,x:longint);
var i:longint;
begin
	if (x=0) or (deep>n) then begin
                if x=0 then solve;
		exit;
	end else begin
		for i:=1 downto 0 do begin
			if i=1 then begin
				p[deep]:=true;
				dec(x);
				dfs(deep+1,x);
				inc(x);
				p[deep]:=false;
			end else dfs(deep+1,x);
		end;
	end;
end;
begin
	readln(n,l,r);
	for i:=1 to n do read(a[i]);

	ans:=r-l+1;
	for k:=1 to n do begin
		dfs(1,k);
	end;
	writeln(ans);
end.
