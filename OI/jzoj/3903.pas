const	map:array[1..24,1..6] of integer=(
          (1,2,3,4,5,6),
		(4,2,1,6,5,3),
		(6,2,4,3,5,1),
		(3,2,6,1,5,4),
		(5,3,6,1,4,2),
		(1,3,5,2,4,6),
		(2,3,1,6,4,5),
		(6,3,2,5,4,1),
		(4,6,2,5,1,3),
		(5,6,4,3,1,2),
		(3,6,5,2,1,4),
		(2,6,3,4,1,5),
		(1,5,4,3,2,6),
		(3,5,1,6,2,4),
		(6,5,3,4,2,1),
		(4,5,6,1,2,3),
		(2,4,6,1,3,5),
		(1,4,2,5,3,6),
		(5,4,1,6,3,2),
		(6,4,5,2,3,1),
		(3,1,2,5,6,4),
		(5,1,3,4,6,2),
		(4,1,5,2,6,3),
		(2,1,4,3,6,5));
	mo=186;maxn=4+1;
var	i,j,k,m,n,ans:longint;
	s,s1:string;
	color,c:array[1..maxn,1..6] of longint;
	p:array[0..mo] of longint;
procedure solve;
var i,max,tmp:longint;
begin
	tmp:=0;
	for i:=1 to 6 do begin
		fillchar(p,sizeof(p),0);
		max:=0;
		for j:=1 to n do inc(p[c[j,i]]);
		for j:=1 to mo do
			if p[j]>max then begin
				max:=p[j];
			end;
		max:=n-max;
		inc(tmp,max);
	end;
	if tmp<ans then begin
                ans:=tmp;
        end;
end;
procedure dfs(deep:longint);
var i:longint;
begin
	if deep>n then begin
		solve;
		exit;
	end;
	for i:=1 to 24 do begin
		for j:=1 to 6 do c[deep,j]:=color[deep,map[i,j]];
		dfs(deep+1);
	end;
end;
begin
	while true do begin
		ans:=maxlongint;
		readln(n);
          fillchar(color,sizeof(color),0);
		if n=0 then exit;
		for i:=1 to n do begin
			readln(s);
                        s:=s+' ';
			for j:=1 to 6 do begin
				s1:=copy(s,1,pos(' ',s)-1);
				delete(s,1,pos(' ',s));
				for k:=1 to length(s1) do begin
					color[i,j]:=(color[i,j]*26+ord(s1[k])-ord('a')+1) mod mo;
				end;
			end;
                end;
		c[1]:=color[1];
		dfs(2);
		writeln(ans);
	end;
end.

