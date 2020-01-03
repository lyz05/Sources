const	maxn=1000;
var	i,n,minn:longint;
	a:array[1..maxn] of int64;
	p,flag:array[1..maxn] of boolean;
	maxx:int64;
procedure check(k:longint);
var	i,kk:longint;
	cnt,cnt1,cnt2:int64;
begin
	cnt1:=0;cnt2:=0;
	for i:=1 to n do begin
		if p[i] then 
			cnt1:=cnt1 xor a[i]
		else 
			cnt2:=cnt2 xor a[i];
	end;
	cnt:=cnt1+cnt2;
	//kk:=n div 2-k;
	if (cnt>maxx) or ((cnt=maxx) and (cnt1<minn)) then begin
		{if cnt1=minn then begin
			for i:=1 to n do 
			if flag[i] then write(1,' ') else write(2,' ');
			writeln;
		end;}
		maxx:=cnt;
		minn:=cnt1;
		flag:=p;
	end;
end;
procedure dfs(dep,cnt:longint);
var	i:longint;
begin
	if (cnt=0) or (dep>n) then begin
		check(cnt);
		exit;
	end;
	for i:=0 to 1 do begin
		if odd(i) then begin
			p[dep]:=true;
				dfs(dep+1,cnt-1);
			p[dep]:=false;	
		end else dfs(dep+1,cnt);
	end;
end;
begin
	assign(input,'a.in');reset(input);
	//assign(output,'.out');rewrite(output);

	readln(n);
	for i:=1 to n do read(a[i]);
	
	minn:=maxlongint>>1;
	dfs(1,n div 2);
	
	for i:=1 to n do 
		if flag[i] then write(1,' ') else write(2,' ');
	writeln;
	
end.
