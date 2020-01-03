const	maxn=200000;
var	i,n,tmp,ans,tot:longint;
	a:array[1..maxn,1..2] of longint;
	s:string;
	ok:boolean;
procedure dfs(deep:longint);
var	i:longint;
begin
        if deep=n-1 then begin
		if tot>=a[deep,2] then ok:=true;
		if ok and (tmp>ans) then ans:=tmp;
		exit;
        end;
	if a[deep,1]=1 then begin
		for i:=0 to 1 do begin
			if i=0 then begin
				inc(tmp,a[deep,2]);
				inc(tot);
			end else begin
				dec(tot);
				dec(tmp,a[deep,2]);
			end;
			dfs(deep+1);
		end;
	end else begin
		if a[deep,2]<=tot then exit;
                dfs(deep+1);
	end;
end;
begin
	readln(n);
	for i:=1 to n-1 do begin
		readln(s);
		if copy(s,1,1)='d' then a[i,1]:=1 else a[i,1]:=2;
		val(copy(s,3,length(s)-3+1),a[i,2]);
	end;
	dfs(1);
	if ok then writeln(ans) else writeln(-1);
end.
