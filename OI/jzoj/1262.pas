var	i,j,k,n,l,t,ans,tmp:longint;
	s:string;
	st,m:int64;
procedure dfs(dep,cnt:longint);
var	i:longint;
begin
	if cnt<0 then exit;
	if dep>l-t then begin
		for i:=dep to l-1 do 
			if st and (1<<i)<>0 then dec(cnt);
		if (cnt=0) and (tmp<ans) then ans:=tmp;
		exit;
	end;
	for i:=0 to 1 do begin
		if i=0 then begin
			inc(tmp);
			st:=st xor (m<<dep);
			if st and (1<<dep)<>0 then 
				dfs(dep+1,cnt-1)
			else dfs(dep+1,cnt);
			st:=st xor (m<<dep);
			dec(tmp);
		end else 
			if st and (1<<dep)<>0 then 
				dfs(dep+1,cnt-1)
			else dfs(dep+1,cnt);
	end;
end;
begin
	assign(input,'xlite.in');reset(input);
	assign(output,'xlite.out');rewrite(output);

	st:=0;m:=0;
	readln(l,t);
	readln(s);
	for i:=1 to l do st:=st<<1+ord(s[i])-48;
	readln(s);
	for i:=1 to t do m:=m<<1+ord(s[i])-48;
	
	for i:=0 to l do begin
		ans:=maxlongint;
		dfs(0,i);
		if ans<>maxlongint then begin
			writeln(ans);
			halt;
		end;
	end;

	close(input);close(output);

end.
