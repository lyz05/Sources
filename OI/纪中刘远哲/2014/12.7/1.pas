const	maxn=800;maxm=maxn;maxk=maxn;
var	i,j,k,l,m,n:longint;
	a:array[1..maxn,1..maxm] of integer;
	b:array[1..maxm,1..maxk] of longint;
	p,lp:array[1..maxn] of boolean;
	ch:char;
procedure print;
begin
	for i:=1 to m do begin
		for j:=1 to k do write(b[i,j],' ');
		writeln;
	end;
        halt;
end;
procedure dfs(dep,tot,ll:longint);
var	i:longint;
	bz:boolean;
begin
	if dep>m then begin
		print;
		exit;
	end;
	for i:=1 to n do begin
		lp[i]:=p[i];
		p[i]:=false;
	end;

	for i:=1 to n do begin
		bz:=false;
		if a[i,dep]=0 then continue;
		if (not lp[i]) and (dep<>1) then begin
			if ll+1>l then continue;
			inc(ll);
			bz:=true;
		end;
		p[i]:=true;
		inc(tot);
		b[dep,tot]:=i;
		if tot=k then begin
                        dfs(dep+1,0,0);
		        b[dep,tot]:=0;
		        dec(tot);
		        p[i]:=false;
			if bz then dec(ll);
                end;

	end;
        fillchar(b[dep],sizeof(b[dep]),0);
end;
begin
	//assign(input,'1.in');reset(input);
	//assign(output,'.out');rewrite(output);

	readln(n,m,k,l);
	for i:=1 to n do begin
		for j:=1 to m do begin
			read(ch);
			if ch='1' then a[i,j]:=1 else a[i,j]:=0;
		end;
		readln;
	end;
	dfs(1,0,0);
	writeln(-1);
end.
