const	maxn=18+1;
var	i,n,l,r,ans,now,cnt:longint;
	a:array[1..maxn] of longint;
	p:array[1..maxn] of boolean;
function gcd(x,y:longint):longint;
begin
	if y=0 then exit(x);
	exit(gcd(y,x mod y));
end;
function lcm(x,y:longint):longint;
var	t:longint;
begin
	t:=gcd(x,y);
	exit(t*x div t*y div t);
end;
function calc(x:longint):longint;
begin
	calc:=r div x-(l-1) div x;
end;
procedure dfs(dep:longint);
var	i,tnow:longint;
begin
	if dep>n then begin 
		if now<>1 then begin
			if odd(cnt) then 
				inc(ans,calc(now))
			else	dec(ans,calc(now));
		end;
		exit;
	end;
	tnow:=now;
	for i:=0 to 1 do begin
		if odd(i) then begin
			now:=lcm(now,a[dep]);
			p[dep]:=true;
			inc(cnt);
				dfs(dep+1);
			dec(cnt);
			p[dep]:=false;
			now:=tnow;
		end else begin
			dfs(dep+1);
		end;
	end;
end;
begin
	//writeln(lcm(15,5),' ',lcm(20,8),' ',lcm(3,7));
	assign(input,'3476.in');reset(input);
	readln(n,l,r);
	for i:=1 to n do read(a[i]);
	now:=1;cnt:=0;
	dfs(1);
	ans:=(r-l+1)-ans;
	writeln(ans);
end.
