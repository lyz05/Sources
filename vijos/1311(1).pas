var	i,j,k,m,n,ans:longint;
	v:array[1..10] of longint;
	s:array[1..10] of string;
	ch:char;
procedure dfs(x,l:longint);
var	i,j,len:longint;
	s1,s2:string;
begin
	if v[x]>2 then exit;
	if l>ans then ans:=l;

	len:=length(s[x]);
	for j:=1 to len-1 do begin
		s1:=copy(s[x],len-j+1,j);
		for i:=1 to n do begin
			if j=length(s[i]) then continue;
			s2:=copy(s[i],1,j);
			if s1=s2 then begin
				inc(v[i]);
				dfs(i,l+length(s[i])-j);
				dec(v[i]);
			end;
		end;
	end;
end;
begin
	assign(input,'1311.in');reset(input);

	readln(n);
	for i:=1 to n do readln(s[i]);
	readln(ch);
	ans:=0;
	for i:=1 to n do 
		if s[i][1]=ch then begin
			v[i]:=1;
			dfs(i,length(s[i]));
			v[i]:=0;
		end;
	writeln(ans);
end.
