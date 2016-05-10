const 	maxn=100;
	mo=1000000007;
var	n,k,m,i,j,ans,x,kk:longint;
	a,b,p:array[1..maxn] of boolean;
	s:string;			//change
function judge:boolean;
begin
	for i:=1 to n do
		if a[i]<>b[i] then exit(false);
	exit(true);
end;
procedure dfs(deep:longint);
var	i:longint;
begin
	if (kk=k) then begin
		if judge then begin
                        ans:=(ans+1) mod mo;
                end;
		exit;
	end;
        if deep>n then exit;
	for i:=0 to k-kk do begin
		if odd(i) then a[deep]:=not a[deep];
		inc(kk,i);
		dfs(deep+1);
		dec(kk,i);
                if odd(i) then a[deep]:=not a[deep];
	end;
end;
begin
	assign(input,'coin.in');reset(input);
	assign(output,'coin.out');rewrite(output);

	readln(n,k,m);
	k:=k*m;
	readln(s);
        for i:=1 to n do
		if s[i]='1' then a[i]:=true else a[i]:=false;
	readln(s);
	for i:=1 to n do
		if s[i]='1' then b[i]:=true else b[i]:=false;
	kk:=0;
	dfs(1);
        ans:=(ans*2) mod mo;
	writeln(ans mod mo);
	close(input);close(output);
end.

