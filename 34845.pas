uses	math;
const	maxst=200+5;maxs=30000;
var	x,y,ans,lens,lenst:longint;
	s,st:ansistring;				//change
	a:array[1..maxst,-1..maxs] of longint;
function pos(ch:char;s:ansistring;l:longint):longint;
var	i:longint;
begin
	for i:=l to length(s) do 
		if s[i]=ch then exit(i);
	exit(0);
end;
procedure dfs(dep,last:longint);
var	i:longint;
begin	
	if dep=2 then x:=last-1;
	if dep>lenst then begin
		y:=(lens-last+2);
		ans:=max(ans,x*y);
	end;
	for i:=1 to a[dep,0] do begin
		if a[dep,i]<last then begin
			a[dep,-1]:=i;
			continue;
		end;
		last:=a[dep,i]+1;
		dfs(dep+1,last);
	end;
end;
procedure work;
var	i,j:longint;
begin
	for i:=1 to lenst do begin
		for j:=1 to lens do begin
			if s[j]=st[i] then begin
				inc(a[i,0]);
				a[i,a[i,0]]:=j;
			end;
		end;
	end;
end;
begin
	//assign(input,'3484.in');reset(input);
	//assign(output,'.out');rewrite(output);
	readln(s);lens:=length(s);
	readln(st);lenst:=length(st);
	work;
	dfs(1,0);
	writeln(ans);
	//close(input);close(output);
end.
