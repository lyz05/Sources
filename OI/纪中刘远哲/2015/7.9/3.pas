var	i,ans,len1,len2:longint;
	s1,s2:ansistring;		//change
function dfs(l,r,dep,last:longint):boolean;
var	i:longint;
begin
	if dep>len1 then begin
		if (last=r) or (s1[dep-1]='*') then
		       exit(true)
		else exit(false);
	end;
	if (s1[dep]='*') then begin
		if dfs(l,r,dep+1,last) then exit(true);
	end else begin
		for i:=last+1 to r do begin
			if s2[i]=s1[dep] then begin
				if (i-last>1) and (s1[dep-1]<>'*') then
					continue;
				 if dfs(l,r,dep+1,i) then exit(true);
			end;
		end;
	end;
	exit(false);
end;
begin
	assign(input,'3.in');reset(input);
	readln(s1);
	readln(s2);
	len2:=length(s2);
	s2:=s2+s2;
	i:=1;
	while i<length(s1) do begin
		if (s1[i]='*') and (s1[i+1]='*') then 
			delete(s1,i+1,1)
		else
			inc(i);
	end;
	len1:=length(s1);
	ans:=0;
	for i:=1 to len2 do begin
		if dfs(i,i+len2-1,1,i-1) then
                        inc(ans);
	end;
	writeln(ans);
end.
