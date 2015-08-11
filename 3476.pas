const	maxn=18+1;
var	i,n,l,r,cnt:longint;
	now,ans:int64;
	a:array[1..maxn] of int64;
	p:array[1..maxn] of boolean;
function gcd(x,y:int64):int64;
begin
	if y=0 then exit(x);
	exit(gcd(y,x mod y));
end;
function lcm(x,y:int64):int64;
var	t:longint;
begin
	t:=gcd(x,y);
	exit((x*y) div t);
end;
function calc(x:int64):int64;
begin
	calc:=r div x-(l-1) div x;
end;
procedure dfs(dep:longint);
var	i:longint;
	tnow:int64;
begin
	tnow:=now;
	if dep>n then begin 
		if now<>1 then begin
			if odd(cnt) then 
				inc(ans,calc(now))
			else	dec(ans,calc(now));
		end;
		exit;
	end;
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
	for i:=1 to n do begin
		read(a[i]);
		if a[i]=1 then begin
			writeln(0);
		end;
	end;
	now:=1;cnt:=0;
	dfs(1);
	ans:=(r-l+1)-ans;
	writeln(ans);
end.
