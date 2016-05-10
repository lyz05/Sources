const	pri:array[1..20] of longint=(2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71);
	mo=1<<17-1;
var	i,j,k,m,n,tmp,ans,cnt,t:longint;
	a:array[0..15] of longint;
	p:array[0..15] of boolean;
procedure fj(x:longint);
begin
	for i:=1 to 20 do begin
		if x mod pri[i]=0 then begin
			inc(a[0]);
			a[a[0]]:=pri[i];
		end;
		while x mod pri[i]=0 do x:=x div pri[i];	
	end;
	if x<>1 then begin
		inc(a[0]);
		a[a[0]]:=x;
	end;
end;
procedure calc(x:longint;flag:boolean);
var	tmp,i:longint;
begin
	if flag then tmp:=1 else tmp:=-1;
	for i:=2 to n do 
		if i<>x then tmp:=(tmp*i) mod mo;
	ans:=(ans+tmp) mod mo;
end;
procedure dfs(dep:longint);
var	i:longint;
begin
	if dep>a[0] then begin
		if tmp<>1 then calc(tmp,odd(cnt));
		exit;
	end;
	for i:=0 to 1 do begin
		if odd(i) then begin
			inc(cnt);
			tmp:=tmp*a[dep];
			p[dep]:=true;
				dfs(dep+1);
			p[dep]:=false;
			tmp:=tmp div a[dep];
			dec(cnt);
		end else begin
			dfs(dep+1);
		end;
	end;
end;
procedure calc1;
var	i,tmp:longint;
begin
	tmp:=1;
	for i:=1 to n do tmp:=(tmp*i) mod mo;
	ans:=tmp-ans;
end;
begin
	assign(input,'1.in');reset(input);
	//assign(output,'.out');rewrite(output);

	readln(t);
	while t>0 do begin
		readln(n,m);
		fj(m);
		tmp:=1;cnt:=0;
		dfs(1);
		calc1;
		writeln(ans);
		dec(t);
	end;
end.
