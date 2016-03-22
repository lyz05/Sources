var	i,j,k,m,n,ans:longint;
	v:array[1..10] of longint;
	s:array[1..10] of string;
	ch:char;
procedure dfs(now:ansistring);
var	i,j,len:longint;
	s1,s2:string;
begin
	len:=length(now);
	if len>ans then 
		ans := len;

	for i:=1 to n do 
	if (v[i]<2) then 
	for j:=2 to length(now) do begin
		s1:=copy(now,j,length(now));
		s2:=copy(s[i],1,length(now)-j+1);
		if s1=s2 then begin
			inc(v[i]);
			dfs(now+copy(s[i],length(now)-j+2,length(s[i])));
			dec(v[i]);
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
			dfs(s[i]);
			v[i]:=0;
		end;
	writeln(ans);
end.
